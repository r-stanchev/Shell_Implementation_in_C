#include "commands.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>


int main() {

    printf("\nPlease enter your command:\n");
    while(1) {
        printf(">> ");
        char* input = malloc(2000);

        //Get input and remove the end-of-line character at the end of the string
        fgets(input,200 * sizeof(char),stdin);
        input[strlen(input)-1] = '\0';

        //Handles the case when the user wants to change directory
        if (strncmp(input,"cd ",3) == 0) {
            char* part;
            part = strtok(input," ");
            part = strtok(NULL," ");
            chdir(part);
            free(input);
        }

        //Handles the case when the user wants to run a program
        if (strncmp(input,"ex ",3) == 0) {
            char* part;
            part = strtok(input," ");
            part = strtok(NULL," ");
            pid_t pid = fork();
            printf("SECOND!");
            if (pid < 0){
              printf("Fork has failed!");
              exit(-1);
            }

            if(pid == 0)
            {
              // child
              printf("FIRST!\n");
              printf("IT IS: %d\n", pid);
              execl(part, (char*)NULL);

            }
            else {
              // parent
              wait(NULL);
            }
            free(input);
        }

        //(W.I.P.) Handles the rest of the cases
        else {
            char* result = commands(input);
            free(input);
            printf("%s\n",result);
        }
    }
    return 0;
}
