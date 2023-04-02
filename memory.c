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
    Free all dynamic memory of the Data struct
*/
void clean_db(Data *db) {
    VECdestroy(&db->stops, free_stop);
    VECdestroy(&db->lines, free_line);
}


void do_nothing(void *value) {
    (void)value;
    return;
}

/*
    Frees a stop struct, assumes everything will be freed as well
*/
void free_stop(void *stop_void) {
    Stop *stop = stop_void;
    free(stop->name);
    VECdestroy(&stop->nodes, do_nothing);
    VECdestroy(&stop->lines, do_nothing);
    free(stop);
}

/*
    Frees a line struct, assumes everything will be freed as well
*/
void free_line(void *line_void) {
    Line *line = line_void;
    free(line->name);
    DLLISTdestroy(&line->path, free_node);
    free(line);
}

/*
    Frees a DLNode and its value
*/
void free_node(DLNode *dlnode) {
    if (dlnode != NULL)
        free(dlnode->value);
    free(dlnode);
}