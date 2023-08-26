#ifndef TASK_H
#define TASK_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "id.h"

typedef enum
{
    False = 0, // 0
    True = 1   // 1
} Boolean;

typedef struct
{
    char id[17];
    char title[33];
    char desc[257];
    Boolean isDone; // status

} Task;

Task createTask(char *title, char *desc, Boolean isDone);
Task createTaskFromFile(char *id, char *title, char *desc, Boolean isDone);

Boolean setTitle(Task *task, char *title);
Boolean setDesc(Task *task, char *desc);
Boolean setStatus(Task *task, Boolean status);

#endif