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
    int i = 0;
    Line *line;
    /* Linear search */
    while (VECiter(&db->lines, &i, (void **)&line)) {
        if (strcmp(line->name, name) == 0) {
            if (index != NULL)
                *index = --i;
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
    Line *line = wrap_calloc(1, sizeof(Line), db, args);
    line->name = args->args[1];
    /* Remove the pointer to the name from the args struct
            so it won't be freed later */
    args->args[1] = NULL;
    VECinsert(&db->lines, db->lines.length, (void *)line, db, args);
    return;
}

/*
    Prints all stops of a given line
*/
void describe_line(Line *line, int invert) {
    DLNode *node = NULL;
    int i = 0;

    /* If line has no connections break*/
    if (line->path.length == 0) {
        return;
    }
    
    if (invert) {
        DLLISTiter_iver(&line->path, &i, &node);
        printf("%s", ((StopNode *)node->value)->stop->name);
        while (DLLISTiter_iver(&line->path, &i, &node))
            printf(", %s", ((StopNode *)node->value)->stop->name);
    } else {
        DLLISTiter(&line->path, &i, &node);
        printf("%s", ((StopNode *)node->value)->stop->name);
        while (DLLISTiter(&line->path, &i, &node))
            printf(", %s", ((StopNode *)node->value)->stop->name);
    }
    putchar('\n');
}

/*
    Prints all lines and their data
*/
void list_lines(Data *db) {
    int i = 0;
    Line *line = NULL;
    while (VECiter(&db->lines, &i, (void **)&line)) {
        printf("%s ", line->name);
        /* Don't print origin and destination if they don't exist*/
        if (line->path.length > 0) {
            printf("%s ", ((StopNode *)line->path.head->value)->stop->name);
            printf("%s ", ((StopNode *)line->path.tail->value)->stop->name);
        }
        printf("%d %.2f %.2f\n", line->path.length, line->cost, line->duration);
    }

    return;
}
