#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

char* commands(char* cmd) {
    char* buf = malloc(200 * sizeof(char));
    char* dir;      //The storage for the current working directory


    cmd[strlen(cmd)-1] = 0;     //The command entered by the user

    dir = getcwd(buf,250);

    if (strcmp(cmd, "info") == 0) {
        char* string = "=====================================\nCOMP2211 Simplified Shell by sc16rbs\n=====================================\n";
        return string;
    }
    else if (strcmp(cmd, "pwd") == 0) {
        dir = getcwd(buf,250);
        printf("=====================================\n");
        printf("CURRENT WD IS: %s\n", dir);
        printf("=====================================\n");
        return 0;
    }
    else  {
        printf("NOTHING\n");
        return 0;
    }


    free(buf);

}
