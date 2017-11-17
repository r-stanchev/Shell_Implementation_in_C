#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <sys/types.h>
#include "commands.h"

char* red(char** strHolder) {
  int fp = open(strHolder[3], O_WRONLY|O_CREAT|O_APPEND, 0666);


  //Fork the parent process
  pid_t pid = fork();
  //Execute the program using the child
  if (pid == 0) {
    close(1);
    dup2(fp,1);
    execv(strHolder[1], NULL);
  }
  //Fork failed
  else if (pid < 0) {
    printf("Fork has failed!");
    exit(-1);
  }
  //Parent waits for child for child to complete task
  else if (pid > 0) {
    close(fp);
    wait(NULL);
  }
  free(strHolder);
}
