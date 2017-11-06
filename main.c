#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "commands.h"

int main() {
    char* input = malloc(200 * sizeof(char));
    char* part;
    const char* space = " ";
    char** parts = malloc(200 * sizeof(char));
    int i = 0;

    printf("Please enter your command:\n");
    while(1) {
        printf(">> ");
        fgets(input,500,stdin);
        char* result = commands(input);
        printf("%s",result);
        if (strcmp(result, "exit") == 0) {
            break;
        }
    }



    // part = strtok(input,space);
    //
    // while (part != NULL) {
    //     parts[i] = part;
    //     i++;
    //     part = strtok(NULL,space);
    // }



    // commands(input);



    free(parts);
    free(input);
    return 0;
}
