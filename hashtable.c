#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "hashtable.h"

/****************************************************************************/
/*  Author: Gadisa Amenu                                                    */
/*  ID: UGR/8440/ 12                                                        */
/*  Section: 2                                                              */
/****************************************************************************/


//defining number of buckets
#define BUCKET_COUNT  1024


// defining structs of hashtable 
struct HashTable{
    Binding * buckets[BUCKET_COUNT];
};

//defining structs of binding
struct Binding{
    const char *key;
    int  value;
    Binding *next;
};



// implementation of create function
HashTable* create(){
    HashTable* hash_table =(HashTable *) malloc(sizeof(HashTable));

    //making all pointers null
    for (int i =0; i < BUCKET_COUNT;i++){
        hash_table->buckets[i] = NULL;
    }
    return hash_table;
}

// implementation of hash function
unsigned int hash(const char* key){
    enum {HASHCODE = 65599};
    size_t i;
    size_t  h = 0;
    for (i =0; key[i] != '\0'; i++)
        h = h* HASHCODE + (size_t)key[i];
    
    return h % BUCKET_COUNT;

}

// a function that creates binding of key with value
Binding* bind(const char * key, int value){
    Binding*  binding = malloc(sizeof(Binding));
    binding-> key = key;
    binding->value = value;
    binding->next = NULL;
    return binding;
}

// implementation of add function
bool add(HashTable* table, const char* key,int value){
    if (!table){
        return false;
    }
    unsigned int hash_value  = hash(key);

    Binding *position = table->buckets[hash_value];
    
    // check if hash_value is setted before
    if ( position == NULL){
        table->buckets[hash_value]= bind(key,value);
        return true;
    }

    Binding* pre;

    // interating through the Bindings of a hashvalue
    while (position != NULL){
        if (strcmp(position->key, key) == 0){
            position-> value = value;
            return false;
        }
        pre = position;
        position = pre->next;
    }

    //appending at the end
    pre->next = bind(key,value);
    return true;

}

//implementation of find function 
Binding* find(HashTable* table, const char* key){
    if (!table){
        return NULL;
    }
    unsigned int hash_value = hash(key);
    //check if hash_value slot is empty
    if (table->buckets[hash_value] == NULL){
        return NULL;
    }
    Binding *position = table->buckets[hash_value];

    //iterates over bindings of at the hash_value
    while (position != NULL){
       
        if (strcmp(position->key, key) == 0){
            return position;
        }
        position = position->next;
    }

    return NULL;

}

//implementation of remove 
bool remove(HashTable* table, const char* key){
    if (table== NULL){
        return false;
    }
    unsigned int hash_value = hash(key);
    Binding* position = table->buckets[hash_value];
    

    //checking emptyness of the position
    if (position == NULL)
       return false;
    Binding *pre = NULL;

    //searching for the key in bindings
    while (position != NULL){
        if (strcmp(position->key,key) == 0 ){
            if (pre == NULL){
                table->buckets[hash_value] = position->next;
            }
            else{
                pre->next = position->next;
            }
            position->next = NULL;
            
            // free the heap space
            free(position);
            return true;
        }
        pre = position;
        position = pre->next;
    }
    return false;
}

//implementation of delete_table 
void delete_table(HashTable* table){
    //free each bucket if not null
    for( int i = 0 ; i < BUCKET_COUNT ; i++){
        if (table->buckets[i] != NULL){
            Binding* temp = table->buckets[i];
            Binding* next ;

            while ( temp!=NULL){
                next = temp->next;
                free(temp);
                temp = next;
            }
        }
    }

    // free the table it self
    free(table);
}
