#include "commands.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

char** determine(char** strHolder) {
  //Cases for info,cd,pwd,execution and background execution
  if (strcmp(strHolder[0],"info") == 0 ||
      strcmp(strHolder[0],"cd") == 0   ||
      strcmp(strHolder[0],"pwd") == 0  ||
      strcmp(strHolder[0],"ex") == 0   ||
      strcmp(strHolder[0], "exb") == 0 ) {
        if ( strHolder[2] == NULL) {
      commands(strHolder);
    }
      else {
        if (strcmp(strHolder[2],"|") == 0) {
          pipeline(strHolder);
        }
        else if (strcmp(strHolder[2],">") == 0) {
          red(strHolder);
        }
      }
    }
    //Handles exit
   else if (strcmp(strHolder[0],"exit") == 0) {
      free(strHolder);
      exit(EXIT_SUCCESS);
  }
}
