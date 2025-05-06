#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

#include "include/readline.h"
#include "include/table.h"

int main(int argc, char *argv[])
{

  FILE* file = fopen("test.txt", "r");

  char* buffer;
  while (readline(&buffer, file, ',')) {
    printf("%s\n", buffer);
  }

  fclose(file);



  return EXIT_SUCCESS;
}
