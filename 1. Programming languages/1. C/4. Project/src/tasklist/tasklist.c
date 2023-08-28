#include "../../include/tasklist/tasklist.h"

static Node *createNode(Task *task)
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

static bool insertNode(Node **head, Task *task)
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

static bool removeNode(Node **head, char *id)
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

static bool updateNode(Node **head, char *id)
{
    Node *curr = *head;

    while (curr != NULL)
    {
        if (strcmp(curr->object.id, id) == 0)
        {
            if (curr->object.isDone == TRUE)
                curr->object.isDone = FALSE;
            else
                curr->object.isDone = TRUE;
            return TRUE;
        }

        curr = curr->next;
    }
    return FALSE;
}

bool deleteItem(Node **head)
{
    char id[ID_LENGTH];
    printf("ID: ");
    getInput(id, "ID");
    getchar();

    if (head == NULL)
        return FALSE;
    if (id == NULL)
        return FALSE;

    return removeNode(head, id);
}

bool createItem(Node **head)
{
    char title[TITLE_LENGTH];
    char desc[DESC_LENGTH];
    char isDone[STATUS_LENGTH];
    bool status = FALSE;

    printf("VALUES:\n");

    printf("- TITLE: ");
    getInput(title, "TITLE");

    printf("- DESCRIPTION: ");
    getInput(desc, "DESCRIPTION");

    printf("- STATUS: ");
    scanf(" %c", &isDone);

    if (strcmp(isDone, "1") == 0)
        status = TRUE;
    else
        status = FALSE;

    Task task = createTask(title, desc, status);
    return insertNode(head, &task);
}

bool createItemFromFile(Node **head, Task *task)
{
    return insertNode(head, task);
}

bool modifyItem(Node **head)
{
    char id[ID_LENGTH];
    printf("ID: ");
    getInput(id, "ID");
    getchar();

    if (head == NULL || *head == NULL)
        return FALSE;

    return updateNode(head, id);
}