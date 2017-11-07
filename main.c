#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "commands.h"

int main() {
    char* part;
    const char* space = " ";
    int i = 0;

    printf("\nPlease enter your command:\n");
    while(1) {
        printf(">> ");
        char* input = malloc(200 * sizeof(char));

        //Get input and remove the end-of-line character at the end of the string
        fgets(input,500,stdin);
        input[strlen(input)-1] = 0;

        //Handles the case when the user wants to change directory
        if (strncmp(input,"cd ",3) == 0) {
            part = strtok(input,space);
            part = strtok(NULL,space);
            chdir(part);
        }

        //(W.I.P.) Handles the rest of the cases
        else {
            char* result = commands(input);

            printf("%s\n",result);
        }
        free(input);
    }
    return 0;
}
