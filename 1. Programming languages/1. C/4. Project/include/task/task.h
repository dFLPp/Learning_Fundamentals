#ifndef TASK_H
#define TASK_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "id.h"
#include "consts.h"

typedef enum Boolean Boolean;

enum Boolean
{
    FALSE = 0,
    TRUE = 1
};

typedef struct Task Task;

struct Task
{
    char id[ID_LENGTH];
    char title[TITLE_LENGTH];
    char desc[DESC_LENGTH];
    Boolean isDone;
};

Task createTask(char *title, char *desc, Boolean isDone);
Task createTaskFromFile(char *id, char *title, char *desc, Boolean isDone);

Boolean setTitle(Task *task, char *title);
Boolean setDesc(Task *task, char *desc);
Boolean setStatus(Task *task, Boolean status);

#endif
