
/****************************************************************************/
/*  Author: Gadisa Amenu                                                    */
/*  ID: UGR/8440/ 12                                                        */
/*  Section: 2                                                              */
/****************************************************************************/


/*prototypes of  structs*/
struct HashTable;
struct Binding;

typedef struct HashTable HashTable;
typedef struct Binding Binding;

/**
*This function  creates and initialize a HashTable and  return it
*/
HashTable* create();

/**
*Hashes the key and returns an integer mod BUCKET_COUNT
*/
unsigned int hash(const char* key);

/**
*Associates the value 'value' using the key 'key'.
* if the key does not  exists in the HashTable. It 
*creates a struct Binding with key 'key' and value 'value', hash the key
*and insert the binding into the table using the hash value of the key.
*and return true.

*If the key already exists in the HashTable. It updates  the
* Bindings old value to the new supplied 'value' if it exists, if not add 
* append to the end of linked list chain and return false.
*/
bool add(HashTable* table, const char* key, int value);

/**
*Search for the key 'key' in the HashTable and return
the Binding if it finds one with the key. Otherwise it  returns
null.
*/
Binding* find(HashTable* table, const char* key);

/**
*Tries to remove a binding with key 'key' from the
*HashTable. It returns true if it is able to remove/delete the
*binding otherwise it returns false.
*
*/
bool remove(HashTable* table, const char* key);

/**
*Removes the hashtable and  free all dynamically allocated memory for the HashTable
'table'.
*/
void delete_table(HashTable* table);


