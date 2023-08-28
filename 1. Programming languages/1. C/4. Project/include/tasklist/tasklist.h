#ifndef TASKLIST_H
#define TASKLIST_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../task/task.h"
#include "../lib/types.h"
#include "../lib/consts.h"
#include "../lib/input.h"

typedef struct Node Node;

struct Node
{
    Task object;
    Node *next;
};

bool createItemFromFile(Node **head, Task *task);
bool createItem(Node **head);
bool deleteItem(Node **head);
bool modifyItem(Node **head);

#endif
