#include <stdio.h>
#include <stdlib.h>

#include "timestables.h"

void generateTable(int num, int *table);
void printTable(int num, int *table);

int main(int argc, char *argv[])
{
    int *tables[MAX_TIMES_TABLE + 1];

    for (int i = 0; i <= MAX_TIMES_TABLE; i++) {
        tables[i] = (int *) malloc(sizeof(int) * MAX_TABLE_SIZE);
        generateTable(i, tables[i]);
    }

    printTables(tables);

    for (int i = 0; i <= MAX_TIMES_TABLE; i++) {
        free(tables[i]);
    }

    return 0;
}
