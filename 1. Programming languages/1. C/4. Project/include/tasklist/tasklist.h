#ifndef TASKLIST_H
#define TASKLIST_H

#include <stdio.h>
#include <stdlib.h>
#include "task.h"
#include "id.h"

typedef struct
{
    Task head;
    Node *next;
} Node;

Node createNode(Task task);

Boolean insertNode(Node **head, Node *task);
Boolean removeNode(char *id);
Boolean updateNode(char *id);

#endif