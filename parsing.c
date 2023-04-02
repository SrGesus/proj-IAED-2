#include "proj.h"

/*
    Reads a line and returns it as an args struct
*/
Args read_line(Data *db) {
    int i;
    char c = '\0';
    char arg[BUFSIZ];
    char *arg_ptr = NULL;
    Args args = {0};

    for (i = 0; c != '\n' && c != EOF; args.argc = ++i) {
        c = read_name(arg);

        arg_ptr = wrap_calloc(strlen(arg)+1, sizeof(char), db, &args);
        args.args[i] = strcpy(arg_ptr, arg);
    }

    return args;
}

/*
    Reads a name which might include ""
    from stdin into str
    returns last inputed character 
    which will be ' ', '\n', or EOF
*/
char read_name(char str[]) {
    char c;
    int i = 0, open_aspas = false, non_white = false;

    while(true)
        switch (typing_name(&c, &open_aspas, &non_white)) {
            case CONTINUE:
                break;
            case TYPE:
                str[i++] = c;
                break;
            case EXIT:
                str[i++] = '\0';
                return c;
        };
}

/*
    Handles char input for names
    returns whether char should be typed, 
    ignored, or input is finished
*/
enum NextAction typing_name(char *c, int *open_aspas, int *non_white) {
    *c = getchar();
    if (*c == '"') {
        *open_aspas = !*open_aspas;
        return CONTINUE;
    }

    /* register that a non whitespace was found */
    if (*c != ' ')
        *non_white = true;

    /* exit if space is found without empty quotes or a newline/EOF */
    if (*c != EOF && *c != '\n' && (*c != ' ' || !*non_white || *open_aspas)) {
        return TYPE;
    } else {
        return EXIT;
    }
}

/* 
    Checks if word matches with a flag given a min_size
    returns true if it fits
*/
int read_flag(char str[], char flag[], int min_size) {
    int i;
    for (i = 0; true; i++) {
        if (str[i] == '\0') {
            if (i < min_size) {
                return false;
            }
            return true;
        }
        if (str[i] != flag[i]) {
            return false;
        }
    }
    return true;
}