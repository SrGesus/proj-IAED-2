#ifndef PROJ_H
#define PROJ_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define true 1
#define false 0

#define MAX_ARGS 6

enum NextAction{EXIT=0, CONTINUE, TYPE};

/* Dynamic Vector */
typedef struct Vec {
    void **values;
    int length;
    int size;
} Vec;

/* Doubly Linked List */
typedef struct DLNode {
    struct DLNode *next, *prev;
    void *value;
} DLNode;
typedef struct {
    DLNode *head, *tail;
    int length;
} DLList;

typedef struct {
    char *name;
    double cost, duration;
    DLList path;
} Line;

typedef struct {
    char *name;
    double lat, lon;
    Vec nodes; 
    Vec lines; /* Sorted alphabetically by line name */
} Stop;

/* For connections */
typedef struct {
    Line *line;
    Stop *stop;
    double cost, duration; /* Between this one and the next */
} StopNode;

typedef struct {
    DLList stops;
    DLList lines;
} Data;

typedef struct {
    char *args[MAX_ARGS];
    int argc;
} Args;


/* proj2.c */
enum NextAction prompt_command(Data *db, Args *args);

/* parsing.c */
enum NextAction typing_name(char *c, int *open_aspas, int *non_white);
char read_name(char *str);
int read_flag(char *str, char *flag, int min_size);
Args read_line(Data *db);

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
