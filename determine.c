#include "commands.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

/*
This file contains the function definition for the determine-function.
This function contains the code for separating between "info","pwd","cd","ex" and "exb" from pipelining, from redirecting program output to file, from exiting.
*/

char** determine(char** strHolder,char* input) {
  /*Cases for info,cd,pwd,execution and background execution*/
  if (strcmp(strHolder[0],"info") == 0 ||
      strcmp(strHolder[0],"cd") == 0   ||
      strcmp(strHolder[0],"pwd") == 0  ||
      strcmp(strHolder[0],"ex") == 0   ||
      strcmp(strHolder[0], "exb") == 0 ||
      strcmp(strHolder[0],"ls") == 0 ) {
      if ( strHolder[2] == NULL) {
        commands(strHolder);
        free(input);
    }
    /*Case for pipelining and redirecting to file*/
      else {
        /*Pipelining*/
        if (strcmp(strHolder[2],"|") == 0) {
          pipeline(strHolder);
          free(input);
        }
        /*Redirecting output of program to file*/
        else if (strcmp(strHolder[2],">") == 0) {
          red(strHolder);
          free(input);
        }
      }
    }
    /*Case for exit*/
   else if (strcmp(strHolder[0],"exit") == 0) {
      free(strHolder);
      free(input);
      exit(EXIT_SUCCESS);
  }
}
