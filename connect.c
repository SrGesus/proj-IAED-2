#include "proj.h"


/*
    Handles 'l' command
*/
void handle_connect(Data *db, Args *args) {
    Line *line = get_line(db, args->args[1], NULL);
    Stop *origin = get_stop(db, args->args[2], NULL);
    Stop *destination = get_stop(db, args->args[3], NULL);
    double cost, duration;
    Node *origin_node = NULL, *destination_node = NULL;

    if (!valid_connect(args, line, origin, destination, &cost, &duration))
        return;

    line->cost += cost;
    line->duration += duration;

    if (line->first != NULL && destination == line->first->stop) {
        destination_node = line->first;
    } 

    if (line->last != NULL && origin == line->last->stop) {
        origin_node = line->last;
    }

    connect_connection(db, args, line, origin, destination, 
        origin_node, destination_node, cost, duration
    );

}

void connect_connection(
    Data *db, Args *args, Line *line, 
    Stop *origin, Stop *destination,
    Node *origin_node, Node *destination_node,
    double cost, double duration
) {
    /* If line is circular*/
    if (origin_node != NULL && destination_node != NULL) {
        line->last = destination_node;
        line->stop_idx++;
    }

    /* If there's no node for the destination yet create one */
    if (destination_node == NULL) {
        destination_node = create_node(line, destination, db, args);
        insert_node(destination, destination_node, db, args);
        
        line->last = destination_node;
        line->stop_idx++;
    }

    if (origin == destination && origin_node == NULL) {
        origin_node = destination_node;
        line->first = origin_node;
        line->stop_idx++;
    }
    /* If there's no node for the origin yet create one */
    if (origin_node == NULL) {
        origin_node = create_node(line, origin, db, args);
        insert_node(origin, origin_node, db, args);
        line->first = origin_node;
        line->stop_idx++;
    }
    
    origin_node->cost = cost;
    origin_node->duration = duration;
    origin_node->next = destination_node;
    destination_node->prev = origin_node;
}

Node *create_node(Line *line, Stop *stop, Data *db, Args *args) {
    Node *node = wrap_calloc(1, sizeof(Node), db, args);
    node->line = line;
    node->stop = stop;
    return node;
}

/* 
    Inserts a node into a stop alphabetically
*/
void insert_node(Stop *stop, Node *node, Data *db, Args *args) {
    int i;

    /* Find the first position where the target line name fits alphabetically */
    for(i = 0; i < stop->node_idx; i++)
        if (strcmp(stop->nodes[i]->line->name, node->line->name) >= 0)
            break;
    
    /* Insert the line into the position */
    stop->nodes = VECinsert((void **)stop->nodes, node, i, &stop->node_idx, db, args);
}

/*
    Checks whether the arguments create a valid connection
*/
enum NextAction valid_connect(
    Args *args, Line *line, Stop *origin, Stop *destination, 
    double *cost, double *duration
) {
    
    sscanf(args->args[4], "%lf", cost);
    sscanf(args->args[5], "%lf", duration);

    /* if any line/stop doesn't exist exit*/
    if (line == NULL) {
        printf("%s: no such line.\n", args->args[1]);
        return EXIT;
    }

    /* origin doesn't match any stop */
    if (origin == NULL) {
        printf("%s: no such stop.\n", args->args[2]);
        return EXIT;
    }

    /* destination doesn't match any stop */
    if (destination == NULL) {
        printf("%s: no such stop.\n", args->args[3]);
        return EXIT;
    }

    if (*cost < 0 || *duration < 0) {
        printf("negative cost or duration.\n");
        return EXIT;
    }

    /* if there are stops in the line 
    and the connection is between invalid stops */
    if (line->first != NULL && 
    (destination != line->first->stop && 
    origin != line->last->stop)) {
        printf("link cannot be associated with bus line.\n");
        return EXIT;
    }

    return CONTINUE;
}