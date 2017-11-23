#include <dirent.h>
#include <sys/types.h>
#include <sys/dir.h>
#include <sys/param.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "commands.h"

/*
This file contains the function definition for the list-function.
This function lists all files in the current working directory with the addition of colouring the files in the following way:
.c files are red
.o files are pink
.h files are yellow
all other files are blue
*/

void list() {
  struct dirent **nameList;
  int n;

  /*Scan the directory for all types of files, add them in the array nameList and sort them with the alphasort function*/
  n = scandir(".", &nameList, NULL, alphasort);

  /*Checks if scan was successful*/
  if (n == -1) {
    printf("Error! Scanning the directory for files failed!\n");
    exit(EXIT_FAILURE);
  }

  /*Print out the file names in reverse order by sticking to the colouring convention mentioned above*/
  while (n--) {
    if (strstr(nameList[n]->d_name,".c") != NULL) {       //Print coloured .c files
      colour(nameList[n]->d_name,"red");
      printf("\n");
      free(nameList[n]);
    }
    else if (strstr(nameList[n]->d_name,".o") != NULL) {       //Print coloured .o files
      colour(nameList[n]->d_name,"pink");
      printf("\n");
      free(nameList[n]);
    }
    else if (strstr(nameList[n]->d_name,".h") != NULL) {       //Print coloured .h files
      colour(nameList[n]->d_name,"yellow");
      printf("\n");
      free(nameList[n]);
    }
    else {                                                //Print all other files in blue
      colour(nameList[n]->d_name,"blue");
      printf("\n");
      free(nameList[n]);
    }
  }
  free(nameList);
}
