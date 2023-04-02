#include "proj.h"

/*
    Handles 'r' command
*/
void remove_line(Data *db, Args *args) {
    int i = 0;
    Line *line = get_line(db, args->args[1], &i);
    if (line == NULL) {
        printf("%s: no such line.\n", args->args[1]);
        return;
    }

    /*
        Free memory and move all other elements left
    */
    clean_line(line);
    VECremove(&db->lines, i, db, args);
}

/*
    Cleanly frees a line struct, handling its stops
*/
void clean_line(Line *line) {
    free(line->name);
    DLLISTdestroy(&line->path, clean_node_line);
    free(line);
}

/*
    Cleanly frees a DLNode containing a StopNode, and removes it
    from the node list on the stops struct
    used for when removing lines
*/
void clean_node_line(DLNode *dlnode) {
    int i;
    DLNode *dlnode_iter = NULL;
    char *line_name = NULL;
    Stop *stop = NULL;

    if (dlnode == NULL)
        return;

    stop = ((StopNode *)dlnode->value)->stop;

    /* Remove node from stop->nodes */
    i = 0;
    while (VECiter(&stop->nodes, &i, (void **)&dlnode_iter))
        if (dlnode == dlnode_iter) {
            VECremove(&stop->nodes, --i, NULL, NULL);
            break;
        };

    /* Remove line name from stop->lines */
    i = 0;
    while (VECiter(&stop->lines, &i, (void **)&line_name))
        /* We can compare the pointer to the string 
            instead of the string itself*/
        if (((StopNode *)dlnode->value)->line->name == line_name) {
            VECremove(&stop->lines, --i, NULL, NULL);
            break;
        };

    free_node(dlnode);
}

/*
    Handles 'e' command
*/
void remove_stop(Data *db, Args *args) {
    int i = 0, j = 0;
    Stop *stop = get_stop(db, args->args[1], &i);
    DLNode *dlnode = NULL;
    if (stop == NULL) {
        printf("%s: no such stop.\n", args->args[1]);
        return;
    }

    while (VECiter(&stop->nodes, &j, (void **)&dlnode)) {
        StopNode *node = dlnode->value;

        if (dlnode->prev) {
            StopNode *prev = dlnode->prev->value;
            if (dlnode->next) {
                prev->duration += node->duration;
                prev->cost += node->cost;
            } else {
                node->line->duration -= prev->duration;
                node->line->cost -= prev->cost;
                prev->duration = 0.0;
                prev->cost = 0.0;
            }
        } else {
            node->line->duration -= node->duration;
            node->line->cost -= node->cost;
        }

        DLLISTremove(&node->line->path, dlnode);
        free(node); 
    }

    VECremove(&db->stops, i, db, args);
    free(stop->name);
    free(stop->lines.values);
    free(stop->nodes.values);
    free(stop);
}