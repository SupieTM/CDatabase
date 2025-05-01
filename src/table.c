#include "../include/table.h"
#include <stdlib.h>

typedef struct node {
  void* data;
  struct node* next;
} nd;

typedef struct pnode {
  struct pnode* next;
  int rowNum;
  nd* left;
} pn;

typedef struct table {
  int rows;
  int columns;
  char** labels;
  pn* startParentNode;
} tb;


tb *createTable() {
  tb* temp = (tb*)malloc(sizeof(*temp));
  temp->columns = 0;
  temp->rows = 0;
  temp->labels = NULL;
  temp->startParentNode = NULL;
  
  return temp;
}

tb *recreateTable() {
  return NULL;
}

void insertRow(tb* table) {

}



