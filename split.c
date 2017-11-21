#include <string.h>
#include <stdlib.h>


char** split(char* input) {
    char* part;       //Holds the tokens returned by strtok before storing them in holder
    char** holder = calloc(200,sizeof(char**));       //Stores the tokens that will be used later
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
