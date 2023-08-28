#ifndef TASKLIST_H
#define TASKLIST_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../task/task.h"

typedef struct Node Node;

struct Node
{
    Task object;
    Node *next;
};

Boolean insertNode(Node **head, Task *task);
Boolean removeNode(Node **head, char *id);
Boolean updateNode(Node **head, char *id);

#endif
