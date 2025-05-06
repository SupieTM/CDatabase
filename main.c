#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

#include "include/readline.h"
#include "include/table.h"

int main(int argc, char *argv[])
{

  tb* table = createTable();


  insertLabels(table, "test.txt"); 

  for (int i = 0; i < 5; i++) {
    printf("%s\n", table->labels[i]);
  }




  return EXIT_SUCCESS;
}
