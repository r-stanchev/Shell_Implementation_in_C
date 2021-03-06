#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include "commands.h"

/*
This is the function definition for the pipeling-function.
This function is responsible for creating a pipe between two programs and executing those programs.
*/

char* pipeline(char** strHolder) {
  int fd[2];      //File descriptor array
  pid_t pid,pid2;     //Variables for the two children

  if (pipe(fd) == -1) {       //In case the pipe creation failed
    colour("Pipe failed!\n","red");
    exit(EXIT_FAILURE);
  }
  else {
    pid = fork();     //Create first child

    if (pid < 0) {        //Check if fork() has executed successfully
      colour("Fork has failed!\n","red");
      exit(EXIT_FAILURE);
    }

    /*First child - duplicate write-end of pipe on to stdout, close both end of pipe and execute first program, the one writing to pipe*/
    if (pid == 0) {

      if (dup2(fd[1],STDOUT_FILENO) == -1) {          //Check if file descriptor was duplicated successfully
        colour("Error! Duplication of file descriptor failed!\n","red");
        exit(EXIT_FAILURE);
      }
      else {
        close(fd[0]);
        close(fd[1]);
        execv(strHolder[1], NULL);
      }
    }

    /*Parent in regards to child 1*/
    else {
      pid2 = fork();     //Create second child

      if (pid < 0) {        //Check if fork() has executed successfully
        colour("Fork has failed!\n","red");
        exit(EXIT_FAILURE);
      }

      /*Second child - duplicate read-end of pipe on to stdin, close both end of pipe and execute second program - the one reading from pipe*/
      if (pid2 == 0) {
        if (dup2(fd[0],STDIN_FILENO) == -1) {          //Check if file descriptor was duplicated successfully
          colour("Error! Duplication of file descriptor failed!\n","red");
          exit(EXIT_FAILURE);
        }
        else {
          close(fd[1]);
          close(fd[0]);
          execv(strHolder[4], NULL);
        }
      }

      /*Parent in regards to both child 1 and child 2 - waits for both children to change state, i.e. execute their respective programs*/
      else {
        waitpid(pid, &pid, 0);
        waitpid(pid2, &pid2, 0);
      }
    }
  free(strHolder);
  }
}
