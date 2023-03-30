#include "proj.h"


/*
    Handles 'p' command
*/
void handle_stop(Data *db, Args *args) {
    if (args->argc == 1) {
        list_stops(db);
        return;
    }

    if (args->argc == 2) {
        describe_stop(db, args->args[1]);
        return;
    }
    
    create_stop(db, args);
}

/*
    Attempts to create a stop with the given name, and location
*/
void create_stop(Data *db, Args *args) {
    double lat, lon;
    char *name = args->args[1];
    Stop *stop = get_stop(db, name, NULL);
    int *i;

    if (stop != NULL) {
        printf("%s: stop already exists.\n", name);
        return;
    }

    stop = wrap_calloc(1, sizeof(Stop), db, args);
    stop->name = name;
    /* Remove the pointer to the name from the args struct
            so it won't be freed later */
    args->args[1] = NULL;
    sscanf(args->args[2], "%lf", &lat);
    sscanf(args->args[3], "%lf", &lon);
    stop->lat = lat;
    stop->lon = lon;
    i = &db->stop_idx;
    db->stops = VECinsert((void **)db->stops, stop, *i, i, db, args);
}

/*
    Prints the location of a stop of a given name
*/
void describe_stop(Data *db, char *name) {
    Stop *stop = get_stop(db, name, NULL);
    if (stop != NULL) {
        printf("%16.12f %16.12f\n", stop->lat, stop->lon);
    } else {
        printf("%s: no such stop.\n", name);
    }
}

/*
    Prints all stops and their data
*/
void list_stops(Data *db) {
    int i;
    struct Stop *stop;
    for(i = 0; i < db->stop_idx; i++) {
        stop = db->stops[i];
        printf("%s: ", stop->name);
        printf("%16.12f %16.12f %d\n", stop->lat, stop->lon, stop->node_idx);
    }
    return;
}

/*
    Returns the pointer to a stop with name == name[]
    or a null pointer if there is none
    Saves index to index if not NULL
*/
Stop *get_stop(Data *db, char *name, int *index) {
    int i;
    struct Stop *stop;
    for(i = 0; i < db->stop_idx; i++) {
        stop = db->stops[i];
        if (strcmp(stop->name, name) == 0) {
            if (index != NULL)
                *index = i;
            return stop;
        }
    }
    return NULL;
}
