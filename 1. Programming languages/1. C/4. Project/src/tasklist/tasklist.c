#include "../../include/tasklist/tasklist.h"

Node *createNode(Task *task)
{
    if (task != NULL)
    {
        Node *node = (Node *)malloc(sizeof(Node));
        if (node != NULL)
        {
            node->object = *task;
            node->next = NULL;
        }
        return node;
    }
    return NULL;
}

Boolean insertNode(Node **head, Task *task)
{
    Node *newNode = createNode(task);
    if (newNode != NULL)
    {
        newNode->next = *head;
        *head = newNode;
        return TRUE;
    }
    return FALSE;
}

Boolean removeNode(Node **head, char *id)
{
    Node *curr = *head;
    Node *prev = NULL;

    while (curr != NULL)
    {
        if (strcmp(curr->object.id, id) == 0)
        {
            if (prev == NULL)
            {
                *head = curr->next;
            }
            else
            {
                prev->next = curr->next;
            }
            free(curr);
            return TRUE;
        }

        prev = curr;
        curr = curr->next;
    }

    return FALSE;
}

Boolean updateNode(Node *head, char *id, Boolean status)
{
    Node *curr = head;

    while (curr != NULL)
    {
        if (strcmp(curr->object.id, id) == 0)
        {
            curr->object.isDone = status;
            return TRUE;
        }

        curr = curr->next;
    }
    return FALSE;
}
