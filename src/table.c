#include "../include/table.h"
#include <cassert>
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

  //If the table is empty place it here
  if (table->startParentNode == NULL) {
    table->startParentNode = temppn;
    return;
  }

  //Traverse the table until the end
  pn* tempnode = table->startParentNode;
  while(tempnode->next != NULL) {
    tempnode = tempnode->next;

  }

  //Place the new node at the end
  tempnode->next = temppn;
}

void insertData(tb *table, int rowNum, char* label, void* _data) {
  pn* tempnode = table->startParentNode;

  //Find the node
  int i = 0;
  while (tempnode != NULL && i < rowNum) {
    tempnode = tempnode->next;
  }

  if (tempnode == NULL) {
    assert("Invalid Index, in insertData");
    return;
  }


}





