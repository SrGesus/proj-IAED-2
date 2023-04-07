#include "proj.h"

/*
    Handles 'i' command
*/
void handle_inter(Data *db) {
    int i = 0, j;
    DLNode *node = NULL;
    while (DLLISTiter(&db->stops, &i, &node)) {
        Stop *stop = node->value;
        if (stop->lines.length > 1) {
            char *line_name = NULL;
            
            printf("%s %d:", stop->name, stop->lines.length);
            
            j = 0;
            while (VECiter(&stop->lines, &j, (void**)&line_name)) {
                printf(" %s", line_name);
            }
            putchar('\n');
        }
    }
}
