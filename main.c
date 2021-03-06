/*
Author: Radomir Boyanov Stanchev
*/

#include "commands.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main() {
  char** strHolder;   //The array holding the tokens
  char* input;    //The initial, not-tokenized input from the user

  colour("\nWELCOME TO RADO'S SHELL\n","blue");
  while(1) {
    colour("\nrado$: ","yellow");
    input = calloc(200,sizeof(char*));
    if (input == NULL) {       //Check if memory has been allocated
      colour("Error! Failed to allocate memory\n!","red");
      exit(EXIT_FAILURE);
    }

    /*Get input and remove the newline character at the end of the string*/
    char c = 0;
    int k = 0;
    while (c != EOF && c != '\n') {
      c = getchar();
      input[k] = c;
      k++;
    }
    input[strlen(input)-1] = 0;       //Put a null character on the end

    /*Split input into tokens so as to work with each one seperately*/
    strHolder = split(input);

    /*Determine the type of command and execute corresponding pice of code*/
    determine(strHolder,input);
  }
  return 0;
}
