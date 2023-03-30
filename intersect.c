#include "proj.h"

/*
    Handles 'i' command
*/
void handle_inter(Data *db) {
    int i, j;
    Stop *stop;
    for (i = 0; i < db->stop_idx; i++) {
        stop = db->stops[i];
        if (stop->node_idx > 1) {
            printf("%s %d:", stop->name, stop->node_idx);
            for (j = 0; j < stop->node_idx; j++) {
                printf(" %s", stop->nodes[j]->line->name);
            }
            putchar('\n');
        }
    }
}