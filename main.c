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


  printf("\nPlease enter your command:\n");
  while(1) {
    printf(">> ");
    input = malloc(2000);

    //Get input and remove the newline character at the end of the string
    fgets(input,2000,stdin);
    input[strlen(input)-1] = 0;

    strHolder = split(input);

    //Handles the case when the user wants to change directory
    if (strcmp(strHolder[0],"cd") == 0) {
      chdir(strHolder[1]);
      free(input);
    }

    //Cases for info, pwd and exit
    else if (strcmp(strHolder[0],"info") == 0 || strcmp(strHolder[0],"pwd") == 0 || strcmp(strHolder[0],"exit") == 0 || strcmp(strHolder[0],"ex") == 0) {
      commands(strHolder);
      free(input);
    }
  }
  free(strHolder);
  // free(input);
  return 0;
}
