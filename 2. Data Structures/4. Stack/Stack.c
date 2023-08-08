// Stack com array

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
        stk->items = malloc(size * sizeof(Item));
    }
}

void stack_push(Stack *stk, Item item)
{
    if (stk->nItems >= stk->size)
    {
        return;
    }
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
        stk->nItems -= 1;
        stk->items[stk->nItems].isDeleted = 1; // true
        return stk->items[stk->nItems];
    }
    else
    {
        Item empty_item = {.isDeleted = 0, .value = 0}; // Criando um item vazio para retornar em caso de pilha vazia
        return empty_item;
    }
}

Item stack_peek(Stack *stk)
{
    if (stk->nItems > 0)
    {
        return stk->items[stk->nItems - 1];
    }
    else
    {
        Item empty_item = {.isDeleted = 0, .value = 0};
        return empty_item;
    }
}

Item createItem(int value)
{
    Item i = {.value = value, .isDeleted = 0};
    return i;
}

void addToStack(Stack *stk)
{
    int i = -1;
    printf("Valor: ");
    scanf("%d", &i);
    stack_push(stk, createItem(i)); // Corrigido para passar o ponteiro para a pilha
}

void removeFromStack(Stack *stk)
{
    Item top = stack_pop(stk);
    if (top.isDeleted == 0)
    {
        printf("value: %d\n", top.value);
    }
    else
    {
        printf("A pilha está vazia.\n");
    }
}

void printPeek(Stack *stk)
{
    Item top = stack_peek(stk);
    if (top.isDeleted == 0)
    {
        printf("Top element: %d\n", top.value);
    }
    else
    {
        printf("A pilha está vazia.\n");
    }
}

void printStack(Stack *stk)
{
    if (stk->nItems == 0)
    {
        printf("A pilha está vazia.\n");
    }
    else
    {
        for (int i = 0; i < stk->nItems; i++)
        {
            if (stk->items[i].isDeleted == 0)
            {
                printf("Elem %d: %d\n", i, stk->items[i].value);
            }
        }
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
            addToStack(stk);
            break;

        case 2:
            removeFromStack(stk);
            break;

        case 3:
            printPeek(stk);
            break;

        case 4:
            printStack(stk);
            break;

        case 5:
            return;

        default:
            printf("Opção inválida. Tente novamente.\n");
            break;
        }
    }
}

int main()
{
    int v = -1;
    Stack s1;

    printf("Tamanho da stack: ");
    scanf("%d", &v);
    init_stack(&s1, v);
    eventLoop(&s1);

    free(s1.items);
    return 0;
}
