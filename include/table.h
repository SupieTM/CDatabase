#ifndef table_H
#define table_H


typedef struct pnode pn;

typedef struct table {
  char **labels;
  pn *startParentNode;
  int rows;
  int columns;
} tb;


tb *createTable();

tb *recreateTable(char* file);

void insertLabels(tb* table, char* filename);

void insertRow(tb* table);

void insertData(tb* table, int rowNum, char* _label, void* _data);


#endif
