#include <string.h>
#include <stdlib.h>


char** split(char* input) {
    char* part;
    char** holder = malloc(2000);
    int i = 0;

    part = strtok(input," ");

    //Fill the array with strings, each string being for example a command, argument, executable, etc.
    while (part != NULL) {
        holder[i] = part;
        i++;
        part = strtok(NULL," ");
    }
    return holder;
}
