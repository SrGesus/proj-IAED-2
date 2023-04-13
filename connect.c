/*
  File: connect.c
  Author: Gabriel ist1107030
  Description: Includes the handling of the 'l' command and required functions
  to handle the connections between stops
*/

#include "proj.h"

/*
  Handles 'l' command
*/
void handle_connect(Data *db, Args *args) {
  Line *line = get_line(db, args->args[1], NULL);
  Stop *origin = get_stop(db, args->args[2], NULL);
  Stop *destination = get_stop(db, args->args[3], NULL);
  DLNode *head, *tail;
  double cost, duration;
  StopNode *origin_node = NULL;

  if (!valid_connect(args, line, origin, destination, &cost, &duration))
    return;

  line->cost += cost;
  line->duration += duration;

  tail = line->path.tail;
  head = line->path.head;

  /* Insert at the end */
  if (tail != NULL && origin == ((StopNode *)tail->value)->stop) {
    ((StopNode *)tail->value)->cost = cost;
    ((StopNode *)tail->value)->duration = duration;
    create_node(line, destination, db, args, false);
    return;
  }

  /* Insert at the start */
  origin_node = create_node(line, origin, db, args, true);
  origin_node->cost = cost;
  origin_node->duration = duration;

  if (head != NULL) {
    return;
  } 

  /* If line was originally empty we still need to add the last node */
  create_node(line, destination, db, args, false);
}

/* 
  Create a new node and push it to the line path
*/
StopNode *create_node(Line *line, Stop *stop, Data *db, Args *args, int start) {
  StopNode *node = wrap_calloc(1, sizeof(StopNode), db, args);
  DLNode *dlnode = NULL;
  node->line = line;
  node->stop = stop;
  /* Insert it at the start or end depending on the passed value */
  if (start) {
    dlnode = DLLISTpush(&line->path, NULL, node, db, args);
  } else {
    dlnode = DLLISTpush(&line->path, line->path.tail, node, db, args);
  }
  insert_node(node->stop, dlnode, db, args);
  return node;
}

/* 
  Inserts a node into a stop alphabetically
*/
void insert_node(Stop *stop, DLNode *dlnode, Data *db, Args *args) {
  int i = 0, res;
  StopNode *node = dlnode->value;
  char *name = NULL;

  VECinsert(&stop->nodes, stop->nodes.length, dlnode, db, args);

  /* Find the first position where the target line name fits alphabetically */
  while (VECiter(&stop->lines, &i, (void **)&name)) {
    res = strcmp(name, node->line->name);
    /* Name already on list */
    if (res == 0)
      return;

    if (res > 0) {
      i--;
      break;
    }
  }
  
  /* Insert the name into the position */
  VECinsert(&stop->lines, i, node->line->name, db, args);
}

/*
  Checks whether the arguments create a valid connection
*/
enum NextAction valid_connect(
  Args *args, Line *line, Stop *origin, Stop *destination, 
  double *cost, double *duration
) {
  
  sscanf(args->args[4], "%lf", cost);
  sscanf(args->args[5], "%lf", duration);

  /* if any line/stop doesn't exist exit*/
  if (line == NULL) {
    printf("%s: no such line.\n", args->args[1]);
    return EXIT;
  }

  /* origin doesn't match any stop */
  if (origin == NULL) {
    printf("%s: no such stop.\n", args->args[2]);
    return EXIT;
  }

  /* destination doesn't match any stop */
  if (destination == NULL) {
    printf("%s: no such stop.\n", args->args[3]);
    return EXIT;
  }

  if (*cost < 0 || *duration < 0) {
    printf("negative cost or duration.\n");
    return EXIT;
  }

  /* if there are stops in the line 
  and the connection is between invalid stops */
  if (line->path.head != NULL && 
  (destination != ((StopNode *)line->path.head->value)->stop && 
  origin != ((StopNode *)line->path.tail->value)->stop)) {
    printf("link cannot be associated with bus line.\n");
    return EXIT;
  }

  return CONTINUE;
}