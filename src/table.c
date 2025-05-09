#include "../include/table.h"

#include "../include/readline.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
  void *data;
  char *label;
  struct node *next;
} nd;

typedef struct pnode {
  struct pnode *next;
  int rowNum;
  nd *left;
} pn;

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

// Initalize an empty table.
tb *createTable() {
  tb *temp = (tb *)malloc(sizeof(*temp));
  temp->columns = 0;
  temp->rows = 0;
  temp->startParentNode = NULL;

  return temp;
}

// This function takes the first line of the database file, splits it by ','
// then inserts each item into the table->labels attributes
void insertLabels(tb *table, char *filename) {

  // Get the file
  FILE *file = fopen(filename, "r");
  char *buffer;
  table->labels = (char **)malloc(sizeof(char *));
  int i = 0;

  while (readline(&buffer, file, ',')) {
    // This is just here so it dosen't realloc after the first malloc
    if (i) {
      table->labels = (char **)realloc(table->labels, sizeof(char *) * (i + 1));
    }
    table->labels[i] = (char *)malloc(sizeof(buffer));
    table->labels[i] = buffer;
    i++;
  }

  // Set the table's columns
  table->columns = i + 1;

  fclose(file);
}

tb *recreateTable(char *file) {
  tb *temp = (tb *)malloc(sizeof(*temp));
  temp->columns = 0;
  temp->rows = 0;
  temp->startParentNode = NULL;

  insertLabels(temp, file);

  return temp;
}

void insertRow(tb *table) {

  // Inlialize a new parent node
  pn *temppn = (pn *)malloc(sizeof(*temppn));
  temppn->rowNum = -1;
  temppn->left = NULL;
  temppn->next = NULL;

  // Loop through and add empty data
  nd *tempNode = temppn->left;
  for (int i = 0; i < table->columns; i++) {
    nd *cNode = (nd *)malloc(sizeof(*cNode));
    cNode->label = table->labels[i];
    cNode->data = NULL;
    cNode->next = NULL;

    if (tempNode == temppn->left) {
      temppn->left = cNode;
    } else {
      tempNode->next = cNode;
    }
    tempNode = cNode;
  }

  // If the table is empty place it here
  if (table->startParentNode == NULL) {
    table->startParentNode = temppn;
    return;
  }

  // Traverse the table until the end
  pn *tempnode = table->startParentNode;
  while (tempnode->next != NULL) {
    tempnode = tempnode->next;
  }

  // Place the new node at the end
  tempnode->next = temppn;
}

void insertData(tb *table, int rowNum, char *_label, void *_data) {
  pn *tempnode = table->startParentNode;

  // Find the node
  int i = 0;
  while (tempnode != NULL && i < rowNum) {
    tempnode = tempnode->next;
  }

  if (tempnode == NULL) {
    printf("Invalid index in insertData\n");
    return;
  }

  nd *tempnd = tempnode->left;

  while (tempnd != NULL && !strcmp(tempnd->label, _label)) {
    tempnd = tempnd->next;
  }

  if (tempnd == NULL) {
    printf("Couldn't find label\n");
    return;
  }

  tempnd->data = _data;
}
