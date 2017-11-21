#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include "commands.h"

/*
This file contains the function definition for the commands-function.
This function contains the code for separating between the cases for "info","pwd","cd","ex" and "exb", and running those commands.
*/
char* commands(char** strHolder) {

    //See the information messege
    if (strcmp(strHolder[0],"info") == 0) {
      colour("=====================================\nCOMP2211 Simplified Shell by sc16rbs\n=====================================","green");
      free(strHolder);
    }


    //See the current working directory
    else if (strcmp(strHolder[0],"pwd") == 0) {
      char buf[sizeof(char)*200];
      getcwd(buf,sizeof(char)*200);      //The storage buffer for the current working directory
      colour(buf,"pink");
      free(strHolder);
    }


    //Handles the case when the user wants to change directory
    else if (strcmp(strHolder[0],"cd") == 0) {
      chdir(strHolder[1]);    //Call the POSIX function to change working directory
      free(strHolder);
    }


    //Handles the case when the user wants to run a program
    else if (strcmp(strHolder[0],"ex") == 0 || strcmp(strHolder[0],"exb") == 0) {
      pid_t pid = fork();     //Fork the parent process
      if (pid == 0) {     //Execute the program using the child

        //Create a subarray of the main array(strHolder) which holds all but the first token in order to pass those tokens as arguments when running the desired program
        int k = 1;
        char** subArray = calloc(200,sizeof(char**));
        while (strHolder[k] != NULL) {
          subArray[k-1] = strHolder[k];
          k++;
        }
        execv(strHolder[1], subArray);      //Actually execute the program
        free(subArray);
      }
      //In case the child creation failed
      else if (pid < 0) {
        colour("Fork has failed!","red");
        exit(-1);
      }
      //Parent waits for child for child to complete task
      else if (strcmp(strHolder[0],"ex") == 0) {
        wait(NULL);
      }
      free(strHolder);
    }
}
