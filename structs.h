#define MAX_ARGS 6

struct Args {
    char *args[MAX_ARGS];
    int argc;
};

struct Node {
    struct Line *line;
    struct Stop *stop;
    struct Node *next, *prev;
    double cost, duration;
};

struct Stop {
    char *name;
    double lat, lon;
    struct Node **nodes; /* Sorted alphabetically by line name */
    int node_idx;
};

struct Line {
    char *name;
    double cost, duration;
    struct Node *first, *last;
    int stop_idx;
};

struct Data {
    int stop_idx;
    int line_idx; 
    struct Stop **stops;
    struct Line **lines;
};

typedef struct Args Args;
typedef struct Node Node;
typedef struct Stop Stop;
typedef struct Line Line;
typedef struct Data Data;