#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

#include "include/readline.h"
#include "include/table.h"

int main(int argc, char *argv[])
{


  tb* table = createTable();

  table->labels = (char**)malloc(sizeof(char*) * 10);
  char* selector = "123456789";

  for (int i = 0; i < 10; i++) {
    table->labels[i] = (char*)malloc(sizeof(char*));
    table->labels[i] = "Hello";
  }

  for (int i = 0; i < 10; i++) {
    printf("%s\n", table->labels[i]);
  }



  return EXIT_SUCCESS;
}
