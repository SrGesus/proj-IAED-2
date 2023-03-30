#include "proj.h"

/*
    Handles 'r' command
*/
void remove_line(Data *db, Args *args) {
    int i = 0;
    Line *line = get_line(db, args->args[1], &i);
    if (line == NULL) {
        printf("%s: no such line.", args->args[1]);
        return;
    }

    /*
        Free memory and move all other elements left
    */
    for (free_line(line); i < db->line_idx-1; i++) {
        db->lines[i] = db->lines[i+1];
    }
    db->line_idx--;
}

/*
    Handles 'e' command
*/
void remove_stop(Data *db, Args *args) {
    int i = 0, j;
    Stop *stop = get_stop(db, args->args[1], &i);
    if (stop == NULL) {
        printf("%s: no such stop.", args->args[1]);
        return;
    }

    for(j = 0; j < stop->node_idx; j++) {
        Node *node = stop->nodes[j];

        if (node->prev != NULL) {
            node->prev->next = node->next;
        } else {
            node->line->cost -= node->cost;
            node->line->duration -= node->duration;
            node->line->first = node->next;
        }

        if (node->next != NULL) {
            node->next->prev = node->prev;
        } else {
            if (node->prev != NULL) {
                node->line->cost -= node->prev->cost;
                node->line->duration -= node->prev->duration;
                node->prev->cost = 0.0;
                node->prev->duration = 0.0;
            }
            node->line->last = node->prev;
        }

    }

    /*
        Free memory and move all other elements left
    */  
    free_stop(stop);
    db->stops = VECremove((void **)db->stops, i, &db->stop_idx, db, args);
}