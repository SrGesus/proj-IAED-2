#ifndef PROJ_H
#define PROJ_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define true 1
#define false 0

#define MAX_ARGS 6
#define HT_MIN_SIZE 5333
#define BUFFER_SIZE 65535 


enum NextAction{EXIT=0, CONTINUE, TYPE};

/* Dynamic Vector */
typedef struct Vec {
    void **values;
    int length;
    int size;
} Vec;

/* Doubly Linked List Abstraction */
typedef struct DLNode {
    struct DLNode *next, *prev;
    void *value;
} DLNode;
typedef struct {
    DLNode *head, *tail;
    int length;
} DLList;

/* Hash Map */ 
typedef struct HashObj {
  void *value;
  unsigned int hash;
  struct HashObj *next;
} HashObj;
typedef struct {
  HashObj **table;
  int length;
  int size;
} HashMap;

/* 
  Struct storing the name, total cost and duration, 
  and the list of StopNodes of a line path
*/
typedef struct {
  char *name;
  double cost, duration;
  DLList path;
} Line;

/*
  Struct storing the name, latitude and longitude of a stop
  as well as a vec of DLNode containing StopNodes 
  and a sorted vec of line names
*/
typedef struct {
  char *name;
  double lat, lon;
  Vec nodes; 
  Vec lines; /* Sorted alphabetically by line name */
} Stop;

/* 
  Represents a stop in a line path, containing the line, the stop
  and the cost and duration between the next one
*/
typedef struct {
  Line *line;
  Stop *stop;
  double cost, duration; /* Between this one and the next */
} StopNode;

/*
  The Data struct contains a linked list of stops and lines
  and one hashmap for each
*/
typedef struct {
  DLList stops;
  HashMap stop_hs;
  DLList lines;
  HashMap line_hs;
} Data;

/*
  A struct to store the arguments and the argument count
*/
typedef struct {
    char *args[MAX_ARGS];
    int argc;
} Args;


/* proj2.c */
enum NextAction prompt_command(Data *db, Args *args);

/* parsing.c */
Args read_line(Data *db);
char read_name(char *str);
enum NextAction typing_name(char *c, int *open_aspas, int *non_white);
int read_flag(char *str, char *flag, int min_size);

/* vec.c */
void VECinsert(Vec *vec, int i, void *value, Data *db, Args *args);
void VECremove(Vec *vec, int i, Data *db, Args *args);
void VECdestroy(Vec *vec, void (*free_value)(void *));
int VECiter(Vec *vec, int *i, void **value);
void VECprint(Vec *vec, char *(*key)(void *));

/* list.c */
void *DLLISTpush(DLList *list, DLNode *previous, void *value, Data *db, Args *args);
void *DLLISTremove(DLList *list, DLNode *node);
void DLLISTdestroy(DLList *list, void (*free_value)(DLNode *));
int DLLISTiter(DLList *list, int *i, DLNode **node);
int DLLISTiter_iver(DLList *list, int *i, DLNode **node);

/* hashmap.c */
void HASHMAPinit(HashMap *hashmap, Data *db, Args *args);
unsigned int get_hash(char *str);
int get_new_size(HashMap *hashmap);
void HASHMAPinsert(HashMap *hashmap, void *value, char *key);
HashObj *HASHMAPget(HashMap *hashmap, char *key, char *get_key(void *));
void HASHMAPremove(HashMap *hashmap, char *key, char *get_key(void *));
void HASHMAPresize(HashMap *hashmap, int new_size);

/* memory.c */
void *wrap_calloc(size_t n, size_t size, Data *db, Args *args);
void *wrap_realloc(void *ptr, size_t n, size_t size, Data *db, Args *args);
void clean_args(Args *args);
void clean_db(Data *db);
void do_nothing(void *value);
void free_stop(DLNode *stop_void);
void free_line(DLNode *line_void);
void free_node(DLNode *dlnode);

/* stops.c */
void handle_stop(Data *db, Args *args);
void create_stop(Data *db, Args *args);
void list_stops(Data *db);
void describe_stop(Data *db, char *name);
char *get_stop_name(void *stop_node);
Stop *get_stop(Data *db, char *name, DLNode **index);

/* lines.c */
void handle_line(Data *db, Args *args);
Line *get_line(Data *db, char *name, DLNode **node);
void create_line(Data *db, Args *args);
void describe_line(Line *line, int invert);
void list_lines(Data *db);

/* connect.c */
void handle_connect(Data *db, Args *args);
enum NextAction valid_connect(
    Args *args, Line *line, Stop *origin, Stop *destination, 
    double *cost, double *duration
);
StopNode *create_node(Line *line, Stop *stop, Data *db, Args *args, int start);
void insert_node(Stop *stop, DLNode *node, Data *db, Args *args);

/* intersect.c */
void handle_inter(Data *db);

/* remove.c */
void remove_line(Data *db, Args *args);
void clean_line(Line *line);
void clean_node_line(DLNode *dlnode);
void remove_stop(Data *db, Args *args);
void clean_node_stop(void *value);

#endif
