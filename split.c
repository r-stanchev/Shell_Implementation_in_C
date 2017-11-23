#include <string.h>
#include <stdlib.h>

/*
This file contains the code for the split-function.
The function's purpose is to take the raw user input and split it up into tokens.
It stores all these tokens in an array and returns that array.
*/

char** split(char* input) {
    char* part;       //Holds the tokens returned by strtok before storing them in holder
    char** holder = calloc(200,sizeof(char**));       //Stores the tokens that will be used later
    if (holder == NULL) {       //Check if memory has been allocated
      colour("Error! Failed to allocate memory\n!","red");
      exit(EXIT_FAILURE);
    }
    int i = 0;
    part = strtok(input," ");     //Tokenize

    /*Tokenize the raw user input based on detected spaces and store each token as a member of the new array*/
    while (part != NULL) {
        holder[i] = part;
        i++;
        part = strtok(NULL," ");
    }
    return holder;
}
