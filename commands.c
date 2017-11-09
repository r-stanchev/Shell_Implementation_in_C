#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

char* commands(char** strHolder) {

    //See the information messege
    if (strcmp(strHolder[0],"info") == 0) {
      char* string = "=====================================\nCOMP2211 Simplified Shell by sc16rbs\n=====================================";
      printf("%s\n", string);
    }

    //See the current working directory
    else if (strcmp(strHolder[0],"pwd") == 0) {
      char buf[200];
      getcwd(buf,200);      //The storage for the current working directory
      printf("%s\n", buf);
    }

    //Handles the case when the user wants to run a program
    else if (strcmp(strHolder[0],"ex") == 0) {
      pid_t pid = fork();
      //Execute the program using the child
      if (pid == 0) {
        int k = 1;
        char** subArray = malloc(2000);
        while (strHolder[k] != NULL) {
          subArray[k-1] = strHolder[k];
          k++;
        }
        execv(strHolder[1], subArray);
        free(subArray);
      }
      //Fork failed
      else if (pid < 0) {
        printf("Fork has failed!");
        exit(-1);
      }
      //Parent waits for child for child to complete task
      else {
        wait(NULL);
      }
      free(strHolder);
    }

    //(W.I.P.) Handles exit
    else if (strcmp(strHolder[0],"exit") == 0) {
        free(strHolder);
        exit(EXIT_SUCCESS);
    }
}
