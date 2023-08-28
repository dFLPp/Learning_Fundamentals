#ifndef WORKBOOK_H
#define WORKBOOK_H

#include <stdio.h>
#include <stdlib.h>

#include "../task/task.h"
#include "../tasklist/tasklist.h"
#include "../lib/input.h"
#include "../lib/types.h"
#include "../lib/consts.h"

typedef struct WorkBook WorkBook;

struct WorkBook
{
    Node *head;
    FILE *filePointer;
};

bool showTasks(WorkBook *workbook);
bool saveTasks(WorkBook *workbook);
bool loadTasks(WorkBook *workbook);

#endif