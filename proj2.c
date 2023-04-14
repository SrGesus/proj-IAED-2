/*
  File: proj.c
  Author: Gabriel ist1107030
  Description: The main file, containing the main function and prompt_command
  that calls a function relative to the required command.
  This program handles the creation of public transportation lines, stops,
  and connections, their listing and their removal, through receiving
  as input 8 different commands.
*/

#include "./proj.h"

int main() {
  Data db = {0};
  Args args = read_line(&db);
  /* Terminates when EXIT is returned */
  while (prompt_command(&db, &args)) {
    clean_args(&args);
    args = read_line(&db);
  }
  clean_args(&args);
  clean_db(&db);
  return 0;
}

/*
    Handles the execution of commands
    returns EXIT (which is = 0) 
    or CONTINUE (which = 1)
*/
enum NextAction prompt_command(Data *db, Args *args) {
  char c;
  switch ((c = args->args[0][0])) {
    case 'q':
      return EXIT;
    case 'c':
      handle_line(db, args);
      return CONTINUE;
    case 'p':
      handle_stop(db, args);
      return CONTINUE;
    case 'l':
      handle_connect(db, args);
      return CONTINUE;
    case 'i':
      handle_inter(db);
      return CONTINUE;
    case 'r':
      remove_line(db, args);
      return CONTINUE;
    case 'e':
      remove_stop(db, args);
      return CONTINUE;
    case 'a':
      clean_db(db);
      return CONTINUE;
    default:
      return CONTINUE;
  }
}
