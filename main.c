#include "commands.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>


int main() {
  char** strHolder;
  char* input;

  printf("\nWELCOME TO RADO'S SHELL\n");
  while(1) {
    printf(">> ");
    input = malloc(2000);

    //Get input and remove the newline character at the end of the string
    char c = 0;
    int k = 0;
    while (c != EOF && c != '\n') {
      c = getchar();
      input[k] = c;
      k++;
    }
      input[strlen(input)-1] = 0;

    //Split input into tokens so as to work with each one seperately
    strHolder = split(input);


    //Cases for info,cd,pwd,execution and background execution
    if (strcmp(strHolder[0],"info") == 0 ||
        strcmp(strHolder[0],"cd") == 0   ||
        strcmp(strHolder[0],"pwd") == 0  ||
        strcmp(strHolder[0],"ex") == 0   ||
        strcmp(strHolder[0], "exb") == 0 ) {
          if ( strHolder[2] == NULL) {
        commands(strHolder);
        free(input);
      }
        else {
          if (strcmp(strHolder[2],"|") == 0) {
            pipeline(strHolder);
            free(input);
          }
          else if (strcmp(strHolder[2],">") == 0) {
            red(strHolder);
            free(input);
          }
        }
      }
      //Handles exit
     else if (strcmp(strHolder[0],"exit") == 0) {
        free(strHolder);
        free(input);
        exit(EXIT_SUCCESS);
    }
  }
  free(strHolder);
  free(input);
  return 0;
}
