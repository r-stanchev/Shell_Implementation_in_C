#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>


char* commands(char** strHolder) {

    //See the information messege
    if (strcmp(strHolder[0],"info") == 0) {
      printf("=====================================\nCOMP2211 Simplified Shell by sc16rbs\n=====================================\n");
      free(strHolder);
    }

    //See the current working directory
    else if (strcmp(strHolder[0],"pwd") == 0) {
      char buf[200];
      getcwd(buf,200);      //The storage for the current working directory
      printf("%s\n", buf);
      free(strHolder);
    }

    //Handles the case when the user wants to change directory
    else if (strcmp(strHolder[0],"cd") == 0) {
      chdir(strHolder[1]);
      free(strHolder);
    }

    //Handles the case when the user wants to run a program
    else if (strcmp(strHolder[2],"ex") == 0 && (strcmp(strHolder[0],"ex") == 0 || strcmp(strHolder[0],"exb") == 0)) {
      //Fork the parent process
      pid_t pid = fork();
      //Execute the program using the child
      if (pid == 0) {
        int k = 1;
        char** subArray = malloc(2000);
        //New array holds the argumets to be passed to the execv() function
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
      else if (strcmp(strHolder[0],"ex") == 0) {
        wait(NULL);
      }
      free(strHolder);
    }

    if (strcmp(strHolder[2],"|") == 0 && strcmp(strHolder[0],"ex") == 0) {
      int buffSize = sizeof(char)*2000;
      char buffer[100];
      char msg[] = "H E L L O,   R A D O\n";
      int fd[2];
      pid_t pid;

      if (pipe(fd) == -1) {
        printf("Pipe failed!\n");
      }

      pid = fork();
      if (pid < 0) {
        fprintf(stderr, "Fork failed");
      }
      else if (pid == 0) {
        dup2(fd[1],1);
        close(fd[1]);
        close(fd[0]);
        execv(strHolder[1], NULL);
      }
      else {
        dup2(fd[0],0);
        close(fd[0]);
        close(fd[1]);
        execv(strHolder[4], NULL);
      }
      free(strHolder);
    }
}
