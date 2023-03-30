#ifndef PROJ_H
#define PROJ_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define true 1
#define false 0

#include "structs.h"

enum NextAction{EXIT=0, CONTINUE, TYPE};

/* proj2.c */
enum NextAction prompt_command(Data *db, Args *args);

/* utilities.c */
enum NextAction typing_name(char *c, int *open_aspas, int *non_white);
char read_name(char *str);
int read_flag(char *str, char *flag, int min_size);
struct Args read_line(Data *db);

/* memory.c */
void *wrap_calloc(size_t n, size_t size, Data *db, Args *args);
void *wrap_realloc(void *ptr, size_t n, size_t size, Data *db, Args *args);
void clean_args(Args *args);
void clean_db(Data *db);
void free_line(Line *line);
void free_line_clean(Line *line, Data *db, Args *args);
void free_node(Node *node, Data *db, Args *args);
void free_stop(Stop *stop);
void *VECinsert(void **vec, void *value, int i, int *size, Data *db, Args *args);
void *VECremove(void **vec, int i, int *size, Data *db, Args *args);

/* lines.c */
void handle_line(Data *db, Args *args);
Line *get_line(Data *db, char *name, int *index);
void create_line(Data *db, Args *args);
void describe_line(Line *line, int invert);
void list_lines(Data *db);

/* stops.c */
void handle_stop(Data *db, Args *args);
void create_stop(Data *db, Args *args);
void list_stops(Data *db);
void describe_stop(Data *db, char *name);
Stop *get_stop(Data *db, char *name, int *index);

/* connect.c */
void handle_connect(Data *db, Args *args);
void connect_connection(
    Data *db, Args *args, Line *line, 
    Stop *origin, Stop *destination,
    Node *origin_node, Node *destination_node,
    double cost, double duration
);
enum NextAction valid_connect(
    Args *args, Line *line, Stop *origin, Stop *destination, 
    double *cost, double *duration
);
Node *create_node(Line *line, Stop *stop, Data *db, Args *args);
void insert_node(Stop *stop, Node *node, Data *db, Args *args);

/* intersect.c */
void handle_inter(Data *db);

/* remove.c */
void remove_line(Data *db, Args *args);
void remove_stop(Data *db, Args *args);


#endif