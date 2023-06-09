/*
  File: hashmap.c
  Author: Gabriel ist1107030
  Description: Functions that provide abstraction to the HashMap struct
*/

#include "./proj.h"


/*
  Creates a HashObj and inserts it into the HashMap on the right index
  might result in an extension of the hashtable size if it is 75% full.
*/
void HASHMAPinsert(
  HashMap *hashmap, void *value, char *key, Data *db, Args *args
) {
  HashObj *object = wrap_calloc(1, sizeof(HashObj), db, args);
  unsigned int hash = get_hash(key);
  unsigned int i;
  if (hashmap->table == NULL) {
    hashmap->table = wrap_calloc(HT_MIN_SIZE, sizeof(HashObj *), db, args);
    hashmap->size = HT_MIN_SIZE;
  }
  hashmap->length++;
  if (hashmap->length > (hashmap->size * 3 / 4)) {
    int new_size = get_new_size(hashmap);
    if (new_size > 0) {
      HASHMAPresize(hashmap, new_size);
    }
  }
  i = hash % hashmap->size;
  object->value = value;
  object->hash = hash;
  object->next = hashmap->table[i];
  hashmap->table[i] = object;
}

/*
  Returns a pointer to HashObj with the desired key
*/
HashObj *HASHMAPget(HashMap *hashmap, char *key, char *get_key(void *)) {
  unsigned int hash = get_hash(key);
  HashObj *object;
  if (hashmap->table == NULL)
    return NULL;
  object = hashmap->table[hash % hashmap->size];
  while (object != NULL) {
    /* First only check if the hash is eq which is less expensive */
    if (hash == object->hash && !strcmp(key, (*get_key)(object->value)))
      return object;
    object = object->next;
  }
  /* Couldn't find key */
  return NULL;
}

/*
  Removes the value from the hashtable and frees the HashObj
  doesn't free the value, the value shouldn't be freed before the HashObj
*/
void HASHMAPremove(HashMap *hashmap, char *key, char *get_key(void *)) {
  unsigned int hash = get_hash(key);
  HashObj *object = hashmap->table[hash % hashmap->size];
  HashObj *prev = NULL;
  while (object != NULL) {
    /* First only check if the hash is eq which is less expensive */
    if (hash == object->hash && !strcmp(key, (*get_key)(object->value)))
      break;
    prev = object;
    object = object->next;
  }
  if (object == NULL)
    /* Couldn't find key */
    return;
  if (prev != NULL)
    prev->next = object->next;
  else
    hashmap->table[hash % hashmap->size] = object->next;
  hashmap->length--;
  free(object);
}

/*
  Frees every HashObj (not their values), and resets the HashMap back to 0 size
*/
void HASHMAPdestroy(HashMap *hashmap) {
  int i;
  HashObj *next = NULL, *head;
  for (i = 0; i < hashmap->size; i++) {
    head = hashmap->table[i];
    while (head != NULL) {
      next = head->next;
      free(head);
      head = next;
    }
  }
  free(hashmap->table);
  hashmap->size = 0;
  hashmap->length = 0;
  hashmap->table = NULL;
}


/*
  This is a simple implementation of the djb2 hashing algorithm
*/
unsigned int get_hash(char *str) {
  unsigned int hash;
  for (hash = 5381; *str != '\0'; str++) {
    /* hash * 33 ^ char */
    hash = ((hash << 5) + hash) ^ *str;
  }
  return hash;
}

/*
  Given a new size, this function creates a new hash table and inserts every
  element of the previous one on the new. 
*/
void HASHMAPresize(HashMap *hashmap, int new_size) {
  HashObj **new_table = calloc(new_size, sizeof(HashObj *));
  int i;
  /* If we are not able to alloc a new hashtable simply don't */
  if (!new_table)
    return;
  /* Insert old HashObj in new table */
  for (i = 0; i < hashmap->size; i++) {
    HashObj *head = hashmap->table[i];
    HashObj *next = NULL;
    while (head != NULL) {
      unsigned int j = head->hash % new_size;
      next = head->next;

      head->next = new_table[j];
      new_table[j] = head;

      head = next;
    }
  }
  free(hashmap->table);
  hashmap->table = new_table;
  hashmap->size = new_size;
}

/*
  Finds the greatest prime number smaller than double of the hash table size
*/
int get_new_size(HashMap *hashmap) {
  /* Had to use unsigned int because int would overflow and since that's UB 
  for signed the compiler just optimized my bound checks out of existence :/ */
  unsigned int i, j, new_size = 2*hashmap->size;
  int * primes = malloc(sizeof(int)*new_size);
  if (!primes) {
    printf("No Memory.\n");
    return 0;
  }

  /* Yes this will set every byte to one, which means an int will be 0x01010101 
  but this isn't an issue, it just needs to be different than 0 */
  memset(primes, 1, sizeof(int)*new_size);

  /* sieve of erastothenes algorithm */
  /* aprox O(n*loglogn) */
  for (i = 2; i < (unsigned int)hashmap->size; i++) {
    if (i*i > new_size)
      break;
    if (primes[i]) {
      for (j = i*i; j < new_size; j += i) {
        primes[j] = 0;
       }
    }
  }

  /* Find the first prime counting from the end*/
  for (i = new_size-1; !primes[i]; i--)
    continue;

  free(primes);

  return i;
}
