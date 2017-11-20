#include "commands.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#define KBLU  "\x1B[34m"

int main() {
  char** strHolder;
  char* input;


  printf("\nWELCOME TO RADO'S SHELL\n");
  while(1) {
    printf("rado$: ");
    printf(KBLU "R A D O:\n");
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

    determine(strHolder);
  }
  free(strHolder);
  free(input);
  return 0;
}
