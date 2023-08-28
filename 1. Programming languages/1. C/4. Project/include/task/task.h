#ifndef TASK_H
#define TASK_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../id/id.h"
#include "../lib/consts.h"
#include "../lib/types.h"

typedef struct Task Task;

struct Task
{
    char id[ID_LENGTH];
    char title[TITLE_LENGTH];
    char desc[DESC_LENGTH];
    bool isDone;
};

Task createTask(char *title, char *desc, bool isDone);
Task createTaskFromFile(char *id, char *title, char *desc, bool isDone);
void printTask(Task *task);

#endif
