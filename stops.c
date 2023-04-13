/*
  File: stops.c
  Author: Gabriel ist1107030
  Description: Includes the handling of the 'p' command and required functions
  to handle the creation, listing, and searching of stops, and the 'i' command 
  which concerns the listing of stops with connections to different lines.
*/

#include "proj.h"

/*
  Handles 'p' command
*/
void handle_stop(Data *db, Args *args) {
  if (args->argc == 1) {
    list_stops(db);
    return;
  }

  if (args->argc == 2) {
    describe_stop(db, args->args[1]);
    return;
  }
  
  create_stop(db, args);
}

/*
  Attempts to create a stop with the given name, and location
*/
void create_stop(Data *db, Args *args) {
  double lat, lon;
  char *name = args->args[1];
  Stop *stop = get_stop(db, name, NULL);
  DLNode *node;

  if (stop != NULL) {
    printf("%s: stop already exists.\n", name);
    return;
  }

  stop = wrap_calloc(1, sizeof(Stop), db, args);
  stop->name = name;
  /* Remove the pointer to the name from the args struct
      so it won't be freed later */
  args->args[1] = NULL;
  sscanf(args->args[2], "%lf", &lat);
  sscanf(args->args[3], "%lf", &lon);
  stop->lat = lat;
  stop->lon = lon;
  node = DLLISTpush(&db->stops, db->stops.tail, stop, db, args);
  HASHMAPinsert(&db->stop_hs, node, name, db, args);
}

/*
  Prints the location of a stop of a given name
*/
void describe_stop(Data *db, char *name) {
  Stop *stop = get_stop(db, name, NULL);
  if (stop != NULL) {
    printf("%16.12f %16.12f\n", stop->lat, stop->lon);
  } else {
    printf("%s: no such stop.\n", name);
  }
}

/*
  Prints all stops and their data
*/
void list_stops(Data *db) {
  int i = 0;
  DLNode *node = NULL;
  while (DLLISTiter(&db->stops, &i, &node)) {
    Stop *stop = node->value;
    printf("%s: ", stop->name);
    printf("%16.12f %16.12f %d\n", stop->lat, stop->lon, stop->lines.length);
  }
  return;
}

/*
  Returns the name of a stop by it's given DLNode
*/
char *get_stop_name(void *stop_node) {
  return ((Stop *)((DLNode *)stop_node)->value)->name;
}

/*
  Returns the pointer to a stop with name == name[]
  or a null pointer if there is none
  Saves its DLNode to the given node pointer if not NULL
*/
Stop *get_stop(Data *db, char *name, DLNode **node) {
  DLNode *temp = NULL;
  Stop *stop = NULL;
  /* Searchs in the stop's HashMap */
  HashObj *object = HASHMAPget(&db->stop_hs, name, get_stop_name);
  /* If we weren't given a node pointer just use temp */
  if (node == NULL)
    node = &temp;
  /* If there was no such stop in the HashMap */
  if (object == NULL) {
    *node = NULL;
    return NULL;
  }
  *node = object->value;
  stop = (*node)->value;
  return stop;
}

/*
  Handles 'i' command
*/
void handle_inter(Data *db) {
  int i = 0, j;
  DLNode *node = NULL;
  /* Iterate for every stop */
  while (DLLISTiter(&db->stops, &i, &node)) {
    Stop *stop = node->value;
    char *line_name = NULL;
    /* If there is more than one line in the stop print all their names */
    if (stop->lines.length < 2)
      continue;

    printf("%s %d:", stop->name, stop->lines.length);
    
    j = 0;
    while (VECiter(&stop->lines, &j, (void**)&line_name)) {
      printf(" %s", line_name);
    }
    putchar('\n');
  }
}
