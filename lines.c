#include "proj.h"


/*
    Handles 'c' command
*/
void handle_line(Data *db, Args *args) {
    int invert = false;
    Line *line;

    /* List lines if there's only one argument */
    if (args->argc == 1) {
        list_lines(db);
        return;
    }

    line = get_line(db, args->args[1], NULL);
    
    /* Create a line if it doesn't exist */
    if (line == NULL) {
        create_line(db, args);
        return;
    }
    
    /* Check for "inverso" flag */
    if (args->argc > 2) {
        if (read_flag(args->args[2], "inverso", 3))
            invert = true;
        else {
            printf("incorrect sort option.\n");
            return;
        }
    }

    describe_line(line, invert);
    
}

/*
    Returns the pointer to a line with name == name[]
    or a null pointer if there is none
    writes index to index if not NULL
*/
Line *get_line(Data *db, char *name, int *index) {
    int i;
    struct Line *line;
    /* Linear search */
    for(i = 0; i < db->line_idx; i++) {
        line = db->lines[i];
        if (strcmp(line->name, name) == 0) {
            if (index != NULL)
                *index = i;
            return line;
        }
    }
    return NULL;
}

/*
    Allocates a line struct and adds it to the database
    fetches its name from the args
*/
void create_line(Data *db, Args *args) {
    int *i = &db->line_idx;
    Line *line = wrap_calloc(1, sizeof(Line), db, args);
    line->name = args->args[1];
    /* Remove the pointer to the name from the args struct
            so it won't be freed later */
    args->args[1] = NULL;
    db->lines = VECinsert((void **)db->lines, line, *i, i, db, args);
    return;
}

/*
    Prints all stops of a given line
*/
void describe_line(Line *line, int invert) {
    Node *node;

    /* If line has no connections break*/
    if (line->first == NULL) {
        return;
    }
    
    if (invert) {
        node = line->last;
        printf("%s", line->last->stop->name);
        /* If connection is circular print now */
        if (node->prev != NULL && line->first == line->last) {
            node = node->prev;
            printf(", %s", node->stop->name);
        }
        while (node != line->first) {
            node = node->prev;
            printf(", %s", node->stop->name);
        }

    } else {
        node = line->first;
        printf("%s", line->first->stop->name);
        /* If connection is circular print now */
        if (node->next != NULL && line->first == line->last) {
            node = node->next;
            printf(", %s", node->stop->name);
        }
        while (node != line->last) {
            node = node->next;
            printf(", %s", node->stop->name);
        }
    }
    putchar('\n');
}

/*
    Prints all lines and their data
*/
void list_lines(Data *db) {
    int i;
    struct Line *line;
    for(i = 0; i < db->line_idx; i++) {
        line = db->lines[i];
        printf("%s ", line->name);
        /* Don't print origin and destination if they don't exist*/
        if (line->first != NULL) {
            printf("%s ", line->first->stop->name);
            printf("%s ", line->last->stop->name);
        }
        printf("%d %.2f %.2f\n", line->stop_idx, line->cost, line->duration);
    }

    return;
}
