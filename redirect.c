#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <sys/types.h>
#include "commands.h"

/*
This file contains the function definition for the red-function.
This function contains the code for redirecting the output to a file and storing it there.
*/
char* red(char** strHolder) {
  /*Create a file or append to it if necessary and return a file descriptor*/
  int fp = open(strHolder[3], O_WRONLY|O_CREAT|O_APPEND, 0666);
  pid_t pid = fork();       //Create a child process
  if (pid == 0) {
    dup2(fp,STDOUT_FILENO);       //Duplicate the file descriptor on to stdout
    execv(strHolder[1], NULL);        //Execute the program
  }
  else if (pid < 0) {       //Child creation failed
    printf("Fork has failed!");
    exit(-1);
  }
  /*Parent waits for child for the child to complete task*/
  else if (pid > 0) {
    close(fp);
    wait(NULL);
  }
  free(strHolder);
}
