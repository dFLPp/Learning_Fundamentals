/*
É possivel fazer de várias maneiras, mas existem 2 em especial:
1. usando uma array com tamanho const (#define) para armazenar os items
2. usando pointers e um tamanho dinâmico dado pelo usar

Como eu quero mostrar virtude (e falhar miseravelmente com um código ruim) vou com a segunda opção
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int isDeleted; // 1 = true, 0 = false
    int value;
} Item;

typedef struct
{
    int nItems, size;
    Item *items;
} Stack;

void init_stack(Stack *stk, int size)
{
    if (size > 0)
    {
        stk->nItems = 0;
        stk->size = size;
        stk->items = calloc(stk->size, sizeof(Item *));
        // Acho q faz mais sentido faz n blocos de tamanho x ao invés de um blocão de n*x
    }
    return;
}

void stack_push(Stack *stk, Item item)
{
    if (stk->nItems >= stk->size)
        return;
    else
    {
        stk->items[stk->nItems] = item;
        stk->nItems += 1;
    }
}

Item stack_pop(Stack *stk)
{
    if (stk->nItems > 0)
    {
        stk->items[stk->nItems].isDeleted = 1; // true
        stk->nItems -= 1;
        return stk->items[stk->nItems];
        // do jeito q eu aloquei acho q não tem como fazer o free(stk->items[stk->nItems])
    }
    else
        return;
}

Item stack_peek(Stack *stk)
{
    return stk->items[stk->nItems];
}

Item createItem(int value)
{
    Item i = (Item){
        .value = value,
        .isDeleted = 0,

    };
    return i;

    // A ideia de criar uma struct e uma função pra Item é que ele pode ser qualquer coisa
}

void addToStack(Stack *stk)
{
    int i = -1;
    printf("Valor: ");
    scanf("%d", &i);
    stack_push(&stk, createItem(i));
}

void removeFromStack(Stack *stk)
{
    Item top = stack_pop(&stk);
    printf("value: %d\n", top.value);
};

void printPeek(Stack *stk)
{
    printf("Top element: %d\n", stk->items[stk->nItems].value);
};

void printStack(Stack *stk)
{
    if (stk->nItems == 0)
        return;
    for (int i = 0; i < stk->nItems; i++)
    {
        if (stk->items[i].isDeleted == 0)
            printf("Elem %d: %d\n", i, stk->items[i]);
    }
}

void eventLoop(Stack *stk)
{
    int i = -1;
    while (1)
    {
        printf("Menu:\n");
        printf("1.\tAdicionar elemento\n");
        printf("2.\tRemover elemento\n");
        printf("3.\tVer elemento no topo\n");
        printf("4.\tVer Stack\n");
        printf("5.\tSair\n\n");

        printf("----\n");
        printf("-> ");
        scanf("%d", &i);

        switch (i)
        {
        case 1:
            addToStack(&stk);
            goto teleport;

        case 2:
            removeFromStack(&stk);
            goto teleport;

        case 3:
            printPeek(&stk);
            goto teleport;

        case 4:
            printStack(&stk);
            goto teleport;

        case 5:
            goto Kawarimi;

        default:
            break;
        }
    teleport:
    }

Kawarimi:
    return;
}

int main()
{
    int v = -1;
    Stack s1;

    printf("Tamanho da stack: ");
    scanf("%d", &v);
    init_stack(&s1, v);
    eventLoop(&s1);

    return 0;
}