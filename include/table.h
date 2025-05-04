#ifndef table_H
#define table_H

typedef struct table tb;

tb *createTable();

tb *recreateTable();

void insertRow(tb* table);

void insertData(tb* table, int rowNum, char* _label, void* _data);


#endif
