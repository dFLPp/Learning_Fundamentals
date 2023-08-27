#ifndef WORKBOOK_H
#define WORKBOOK_H

#include <stdio.h>
#include <stdlib.h>

#include "../task/task.h"
#include "../tasklist/tasklist.h"
#include "../core/consts.h"

typedef struct WorkBook WorkBook;

struct WorkBook
{
    Node *head;
    FILE *filePointer;
};

Boolean mapFromFileToList(Node **head, FILE *filePointer);
Boolean mapFromListToFile(Node **head, FILE *filePointer);

#endif