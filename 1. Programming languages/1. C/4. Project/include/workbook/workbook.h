#ifndef WORKBOOK_H
#define WORKBOOK_H

#include <stdio.h>
#include <stdlib.h>
#include "tasklist.h"

typedef struct
{
    Node *head;
    FILE *filePointer;
} WorkBook;

Boolean mapFromFileToList(Node **head, FILE *filePointer);
Boolean mapFromListToFile(Node **head, FILE *filePointer);

#endif