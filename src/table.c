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
  char*** labels; // A list of strings. 
  pn* startParentNode;
} tb;


/*
*            (rows)   (data) <- stored in void
*   table -> pnode -> left
*              v
*            pnode -> left
*
*
*
*
*/


//Initalize an empty table.
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

  //Inlialize a new parent node
  pn* temppn = (pn*)malloc(sizeof(*temppn));
  temppn->rowNum = -1;
  temppn->next = NULL;
  temppn->left = NULL;

  

  if (table->startParentNode == NULL) {
    table->startParentNode = temppn;
    insertData(temppn, table);
  }

}


void insertData(pn pNode, tb* table) {
}

