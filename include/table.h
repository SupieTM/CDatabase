#ifndef table_H
#define table_H


typedef struct pnode pn;

typedef struct table {
  int rows;
  int columns;
  char **labels;
  pn *startParentNode;
} tb;


tb *createTable();

tb *recreateTable();

void insertRow(tb* table);

void insertData(tb* table, int rowNum, char* _label, void* _data);


#endif
