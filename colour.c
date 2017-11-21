#include <stdio.h>
#include <string.h>

/*
Constants for the colours
*/
#define red   "\x1B[1;31m"
#define green   "\x1B[1;32m"
#define yellow   "\x1B[1;33m"
#define blue   "\x1B[1;34m"
#define pink   "\x1B[1;35m"
#define white   "\x1B[1;37m"
#define black   "\x1B[30m"
#define reset "\x1B[0m"

/*
This file contains the function definition for the colour-function.
This function takes prints out your desired text in one of 7 predefined colours. It takes two arguments - the first one is the text you want to print and the second one is the colour you want to print it in.
*/
void colour(char* text,char* colour) {
  if (strcmp(colour,"red") == 0) {
    printf(red "%s" reset, text);
  }
  else if (strcmp(colour,"green") == 0) {
    printf(green "%s" reset, text);
  }
  else if (strcmp(colour,"yellow") == 0) {
    printf(yellow "%s" reset, text);
  }
  else if (strcmp(colour,"blue") == 0) {
    printf(blue "%s" reset, text);
  }
  else if (strcmp(colour,"pink") == 0) {
    printf(pink "%s" reset, text);
  }
  else if (strcmp(colour,"white") == 0) {
    printf(white "%s" reset, text);
  }
  else if (strcmp(colour,"black") == 0) {
    printf(black "%s" reset, text);
  }
}
