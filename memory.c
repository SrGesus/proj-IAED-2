/*
  File: memory.c
  Author: Gabriel ist1107030
  Description: Includes several functions that handle the freeing and allocation
  of memory, including a wrapper for calloc and realloc.
*/

#include "proj.h"

/*
  A wrapper for malloc that cleans everything and exits the program
  if allocation request fails
*/
void *wrap_calloc(size_t n, size_t size, Data *db, Args *args) {
  void *ptr = calloc(n, size);
  
  /* Frees all data and exits program with a non-zero value */
  if (ptr == NULL && n*size != 0) {
    printf("No Memory.\n");
    clean_db(db);
    clean_args(args);
    exit(NO_MEMORY_STATUS);
  }
  return ptr;
}

/*
  A wrapper for realloc that cleans everything and exits the program
  if allocation request fails
*/
void *wrap_realloc(void *ptr, size_t n, size_t size, Data *db, Args *args) {
  ptr = realloc(ptr, n * size);

  /* Frees all data and exits program with a non-zero value */
  if (ptr == NULL && n*size != 0) {
    printf("No Memory.\n");
    clean_db(db);
    clean_args(args);
    exit(NO_MEMORY_STATUS);
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
  DLLISTdestroy(&db->stops, free_stop);
  DLLISTdestroy(&db->lines, free_line);
  HASHMAPdestroy(&db->stop_hs);
}

/*
  Just a function that does nothing to be used to uncleanly free the stop Vec
*/
void do_nothing(void *value) {
  (void)value;
  return;
}

/*
  Frees a stop struct, assumes everything will be freed as well
*/
void free_stop(DLNode *node) {
  Stop *stop;
  if (node == NULL)
    return;
  stop = node->value;
  free(stop->name);
  VECdestroy(&stop->nodes, do_nothing);
  VECdestroy(&stop->lines, do_nothing);
  free(stop);
  free(node);
}

/*
  Frees a line struct, assumes everything will be freed as well
*/
void free_line(DLNode *node) {
  Line *line;
  if (node == NULL)
    return;
  line = node->value;
  free(line->name);
  DLLISTdestroy(&line->path, free_node);
  free(line);
  free(node);
}

/*
  Frees a DLNode and its value
*/
void free_node(DLNode *dlnode) {
  if (dlnode != NULL)
    free(dlnode->value);
  free(dlnode);
}
