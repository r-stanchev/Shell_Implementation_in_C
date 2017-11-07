#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

char* commands(char* cmd) {

    //See the information messege
    if (strcmp(cmd, "info") == 0) {
        char* string = "=====================================\nCOMP2211 Simplified Shell by sc16rbs\n=====================================";
        return string;
    }

    //See the current working directory
    else if (strcmp(cmd, "pwd") == 0) {
        char* buf = (char*) malloc(2000);
        char* dir = getcwd(buf,2000);      //The storage for the current working directory
        free(buf);
        return dir;
    }

    //(W.I.P.) Handles exit
    else  {
        free(cmd);
        exit(EXIT_SUCCESS);
    }
}
