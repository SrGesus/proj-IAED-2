#include "proj.h"

/*
    Inserts value into position i of the vector and expands it
*/
void VECinsert(Vec *vec, int i, void *value, Data *db, Args *args) {
    int j;
    vec->length++;
    if (vec->size < vec->length) {
        if (vec->size == 0) {
            vec->size++;
        }
        vec->size *= 2;
    }
    vec->values = wrap_realloc(vec->values, vec->size, sizeof(void *), db, args);
    /* Shift items to the right of i one step right */
    for(j = vec->length-1; j > i; j--) {
        vec->values[j] = vec->values[j-1];
    }
    vec->values[i] = value;
}

/*
    Removes the value on index i from the vector and shrinks it
*/
void VECremove(Vec *vec, int i, Data *db, Args *args) {
    if (i >= vec->length || vec->length <= 0) {
        return;
    }

    /* Shift items to the right of i one step left */
    for (; i < vec->length-1; i++) {
        vec->values[i] = vec->values[i+1];
    }

    vec->length--;
    if (vec->size/2 > vec->length) {
        vec->size /= 2;
    }
    vec->values = wrap_realloc(vec->values, vec->size, sizeof(void *), db, args);
}

/*
    Frees every node on the Vec and uses 
    a function it receives as an argument to free its values
*/
void VECdestroy(Vec *vec, void (*free_value)(void *)) {
    int i = 0;
    void *value = 0;
    while(VECiter(vec, &i, &value)) {
        (*free_value)(value);
    }
    free(vec->values);
    vec->values = NULL;
    vec->size = 0;
    vec->length = 0;
}

/*
    Sets value to the ith value of the vector if there is one
    Returns false if outside vector
*/
int VECiter(Vec *vec, int *i, void **value) {
    if (*i >= vec->length) {
        return false;
    }
    *value = vec->values[*i];
    (*i)++;

    return true;
}
