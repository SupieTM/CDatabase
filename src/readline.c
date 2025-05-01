#include <stdio.h>
#include <stdlib.h>

#include "../include/readline.h"

int readline(char **buffer, FILE *file) {


  // Initazlie a variable to hold the bufsize, and the index, and the return str
  int buffsize = 2;
  int index = 0;
  char *retStr = malloc(buffsize);

  if (retStr == 0) {
    printf("Error in first retStr allocation\n");
    return 0;
  }

  // Initalize a temporary char
  char c = 0;

  while ((c = getc(file)), c != EOF && c != '\0' && c != '\n') {
    if (index >= buffsize) {
      buffsize *= 2;

      char *tempStr = realloc(retStr, buffsize);
      if (tempStr == NULL) {
        printf("Error in the tempStr allocation\n");
        free(retStr);
        return 0;
      }

      retStr = tempStr;
    }

    retStr[index++] = c;
  }


  if (index == 0 || c == EOF) {
    free(retStr);
    *buffer = NULL;
    return 0;
  }


  // Return index should be the size;
  if (buffsize != index + 1) {
    buffsize = index + 1;
    retStr = realloc(retStr, buffsize);
    if (retStr == NULL) {
      return 0;
    }
  }


  retStr[index] = '\0';

  *buffer = retStr;
  return 1;
}
