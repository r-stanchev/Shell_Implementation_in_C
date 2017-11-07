#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

char* commands(char* cmd) {

    //See the information messege
    if (strcmp(cmd, "info") == 0) {
        char* string = "=====================================\nCOMP2211 Simplified Shell by sc16rbs\n=====================================\n";
        return string;
    }

    //See the current working directory
    else if (strcmp(cmd, "pwd") == 0) {
        char* buf;
        char* dir = getcwd(buf,250);      //The storage for the current working directory
        char* string = ("=====================================\nCURRENT WD IS: %s\n=====================================\n", dir);
        return string;
    }

    //(W.I.P.) Handles exit
    else  {
        free(cmd);
        exit(EXIT_SUCCESS);
    }
}
