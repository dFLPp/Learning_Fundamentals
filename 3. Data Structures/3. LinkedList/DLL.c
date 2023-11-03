// Doubly linked list

#include <stdio.h>
#include <stdlib.h>

// representação de um tipo genérico
struct dataE
{
    int v;
};

struct Node
{
    struct dataE data;
    struct Node *next;
    struct Node *prev;
};

struct DDL
{
    int nNodes;
    struct Node *head;
    struct Node *tail;
};

void startDDL(struct DDL *list)
{
    list->head = NULL;
    list->tail = NULL;
    list->nNodes = 0;
    return;
}

struct Node *createNode(int x)
{
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));

    temp->data.v = x;
    temp->prev = NULL;
    temp->next = NULL;
    return temp;
}

void insertAtS(struct DDL *list, int x)
{
    // insert at start O(1)
    struct Node *n = createNode(x);

    if (list->head == NULL)
    {
        list->head = n;
        list->tail = n;
        list->nNodes += 1;
        return;
    }

    list->head->prev = n;
    n->next = list->head;
    list->head = n;
    list->nNodes += 1;
}

void insertAtE(struct DDL *list, int x)
{
    // insert at end
    //  O(n) sem tail | O(1) com tail
    struct Node *n = createNode(x);

    if (list->tail == NULL)
    {
        list->tail = n;
        list->head = n;
        list->nNodes += 1;
        return;
    }

    list->tail->next = n;
    n->prev = list->tail;
    list->tail = n;
    list->nNodes += 1;
}

void print(struct DDL *list)
{
    struct Node *t = list->head;

    while (t->next != NULL)
    {
        printf("%d->", t->data.v);
        t = t->next;
    }
    printf("%d\n", t->data.v);
}

void printR(struct DDL *list)
{
    struct Node *t = list->tail;

    printf("%d", t->data.v);
    t = t->prev;

    while (t->prev != NULL)
    {
        printf("<-%d", t->data.v);
        t = t->prev;
    }
    printf("<-%d\n", t->data.v);
}

void deleteAt(struct DDL *list, int n)
{
    if (list->nNodes < n || n <= 0)
    {
        printf("Não existem elementos nessa posição\n");
        return;
    }

    struct Node *t = NULL;
    int x = list->nNodes / 2;
    if (n >= x)
    {
        // usar prev
        t = list->tail;
        for (int i = list->nNodes; i > n; i--)
        {
            t = t->prev;
        }

        if (t->next == NULL)
        {
            t->prev->next = t->next;
            list->tail = t->prev;
        }
        else
        {
            t->next->prev = t->prev;
            t->prev->next = t->next;
        }

        free(t);
        list->nNodes -= 1;
        return;
    }
    else
    {
        // usar next
        // 1- 2- 3- 4
        // 1
        t = list->head;
        for (int i = 1; i < n; i++)
        {
            t = t->next;
        }

        if (t->prev == NULL)
        {
            t->next->prev = t->prev;
            list->head = t->next;
        }
        else
        {
            t->prev->next = t->next;
            t->next->prev = t->prev;
        }

        free(t);
        list->nNodes -= 1;
        return;
    }
}

void testFeedback(struct DDL *list)
{
    // propositalmente estou fazendo essas DS's antes de estudar software testing
    // pra n ter o trabalho de fazer eles. Por agora estou feliz com meus printf's
    print(list);
    printR(list);
    printf("Tamanho: %d\n", list->nNodes);
}

int main(void)
{
    struct DDL myList;
    startDDL(&myList);

    insertAtE(&myList, 5);
    insertAtE(&myList, -3);
    testFeedback(&myList);

    insertAtS(&myList, 2);
    insertAtS(&myList, 8);
    testFeedback(&myList);

    deleteAt(&myList, -3);
    deleteAt(&myList, 500);
    deleteAt(&myList, 1);
    deleteAt(&myList, 3);
    testFeedback(&myList);

    return 0;
}