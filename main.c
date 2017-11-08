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
      // printf("IT IS: %s\n", strHolder[1]);
      chdir(strHolder[1]);
      free(input);
    }

    //Cases for info, pwd and exit
    else if (strcmp(strHolder[0],"info") == 0 || strcmp(strHolder[0],"pwd") == 0 || strcmp(strHolder[0],"exit") == 0) {
      char* result = commands(input);
      free(input);
      printf("%s\n",result);
    }

    //Handles the case when the user wants to run a program
    if (strcmp(strHolder[0],"ex") == 0) {
      pid_t pid = fork();
      //Execute the program using the child
      if (pid == 0) {
        execl(strHolder[1], "", (char*)0);
      }
      //Fork failed
      else if (pid < 0) {
        printf("Fork has failed!");
        exit(-1);
      }
      //Parent waits for child for child to complete task
      else {
        wait(NULL);
      }
      free(input);
    }
  }
  free(strHolder);
  // free(input);
  return 0;
}
