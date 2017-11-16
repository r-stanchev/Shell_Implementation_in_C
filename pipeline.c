#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include "commands.h"

char* pipeline(char** strHolder) {
  int buffSize = sizeof(char)*2000;
  char buffer[100];
  int fd[2];
  pid_t pid,pid2;

  if (pipe(fd) == -1) {
    printf("Pipe failed!\n");
  }

  pid = fork();
  if (pid < 0) {
  fprintf(stderr, "Fork failed");
  }

  /* CHILD 1*/
 if (pid == 0) {
    dup2(fd[1],STDOUT_FILENO);
    close(fd[0]);
    close(fd[1]);
    execv(strHolder[1], NULL);
  }
  /* PARENT */
  else {
    pid2 = fork();
    //Child 2 - to execute the second pipe command
    if (pid2 == 0) {
      dup2(fd[0],STDIN_FILENO);
      close(fd[1]);
      close(fd[0]);
      execv(strHolder[4], NULL);
    }
    else {
      waitpid(pid, &pid, 0);
      waitpid(pid2, &pid2, 0);
    }
  }
  free(strHolder);
}
