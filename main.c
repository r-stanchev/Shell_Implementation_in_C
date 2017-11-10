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
    fgets(input,2000,stdin);
    input[strlen(input)-1] = 0;

    strHolder = split(input);

    //Cases for info,cd,pwd,execution and background execution
    if (strcmp(strHolder[0],"info") == 0 || strcmp(strHolder[0],"cd") == 0 || strcmp(strHolder[0],"pwd") == 0 || strcmp(strHolder[0],"ex") == 0 || strcmp(strHolder[0], "exb") == 0) {
      commands(strHolder);
      free(input);
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
