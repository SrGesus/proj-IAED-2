#include "proj.h"

/*
    A wrapper for malloc that cleans everything and exits the program
    if allocation request fails
*/
void *wrap_calloc(size_t n, size_t size, Data *db, Args *args) {
    void *ptr = calloc(n, size);
    if (ptr == NULL&& n*size != 0) {
        printf("No Memory.\n");
        clean_db(db);
        clean_args(args);
        exit(0);
    }
    return ptr;
}

/*
    A wrapper for realloc that cleans everything and exits the program
    if allocation request fails
*/
void *wrap_realloc(void *ptr, size_t n, size_t size, Data *db, Args *args) {
    ptr = realloc(ptr, n * size);
    if (ptr == NULL && n*size != 0) {
        printf("No Memory.\n");
        clean_db(db);
        clean_args(args);
        exit(0);
    }
    return ptr;
}

/* 
    Frees all dynamic memory of an Args struct
*/
void clean_args(Args *args) {
    int i;
    for(i = 0; i < args->argc; i++) {
        free(args->args[i]);
    }
    args->argc = 0;
    return;
}

/*
    Frees all dynamic memory of a Data struct
*/
void clean_db(Data *db) {
    int i;
    for (i = 0; i < db->line_idx; i++) {
        free_line(db->lines[i]);
    }
    if (i != 0)
        free(db->lines);
    for (i = 0; i < db->stop_idx; i++) {
        free_stop(db->stops[i]);
    }
    if (i != 0)
        free(db->stops);
    db->lines = NULL;
    db->stops = NULL;
    db->stop_idx = 0;
    db->line_idx = 0;
}


/*
    Frees a Line struct and all its Nodes
    Does not remove the pointer to the Node in the Stop struct
*/
void free_line(Line *line) {
    Node *next, *node = line->first;
    free(line->name);
    /* If line is circular start on next stop */
    if (node != NULL && line->first == line->last) {
        node = node->next;
    }
    while (node != line->last) {
        next = node->next;
        free(node);
        node = next;
    }
    /* Free last stop */
    free(node);
    free(line);
}

/*
    Frees a Line struct and all its Nodes
    Does remove the pointer to the Node in the Stop struct
*/
void free_line_clean(Line *line, Data *db, Args *args) {
    Node *next, *node = line->first;
    free(line->name);
    /* If line is circular start on next stop */
    if (node != NULL && line->first == line->last) {
        node = node->next;
    }
    while (node != line->last) {
        next = node->next;
        free_node(node, db, args);
        node = next;
    }
    /* Free last stop */
    free_node(node, db, args);
    free(line);
}

/*
    Frees a node struct
*/
void free_node(Node *node, Data *db, Args *args) {
    Stop *stop = node->stop;
    int i;
    for(i = 0; stop->nodes[i] == node; i++);
    VECremove((void **)stop->nodes, i, &stop->node_idx, db, args);
}

/*
    Frees a Stop struct
*/
void free_stop(Stop *stop) {
    free(stop->name);
    free(stop->nodes);
    free(stop);
}

/*
    Inserts value into position i of the vector and expands it
*/
void *VECinsert(void **vec, void *value, int i, int *size, Data *db, Args *args) {
    int j;
    (*size)++;
    vec = wrap_realloc(vec, *size, sizeof(void *), db, args);
    for(j = (*size)-1; j > i; j--) {
        vec[j] = vec[j-1];
    }
    vec[i] = value;
    return vec;
}

/*
    Removes the value on index i from the vector and shrinks it
*/
void *VECremove(void **vec, int i, int *size, Data *db, Args *args) {
    for (; i < (*size)-1; i++) {
        vec[i] = vec[i+1];
    }
    (*size)--;
    return wrap_realloc(vec, *size, sizeof(void *), db, args);
}