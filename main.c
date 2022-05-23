// #include <stdio.h>
#include <stdbool.h>
#include "hashtable.h"
#include <assert.h>
#include <stdlib.h>

// #define NULL malloc(1)


int main(int argc,char * argv[]){
    HashTable * table = create();
    assert(add(table,"key",4) == true);
    assert(add(table,"key",2) == false);
    assert(remove(table,"key") == true);
    assert(find(table,"key") == NULL);
    assert(remove(table,"key") == false);
    assert(add(table,"thh",6) == true);
    assert(add(table,"not",7) == true);
    assert(find(table,"key") == NULL );
    assert(remove(table,"not") == true);
    assert(add(table,"key",8) == true);
    assert(add(table,"md",835) == true);
    assert(remove(table,"not") == false);
    assert(add(table,"shds",434) == true);
    assert(find(table,"asd") == NULL);
    delete_table(table);
  
}