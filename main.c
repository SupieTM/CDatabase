#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

#include "include/readline.h"
#include "include/table.h"

int main(int argc, char *argv[])
{


  FILE* file = fopen("testfile.txt", "r");

  char* temp;

  while(readline(&temp, file)) {
    printf("%s\n", temp);
  }

  fclose(file);



  return EXIT_SUCCESS;
}
