#ifndef WORKBOOK_H
#define WORKBOOK_H

#include <stdio.h>
#include <stdlib.h>

#include "task.h"
#include "tasklist.h"
#include "consts.h"

typedef struct WorkBook WorkBook;

struct WorkBook
{
    Node *head;
    FILE *filePointer;
} WorkBook;

Boolean mapFromFileToList(Node **head, FILE *filePointer);
Boolean mapFromListToFile(Node **head, FILE *filePointer);

#endif