// Stack com linked lists

#include <stdio.h>
#include <stdlib.h>

struct Item
{
    int value;
    struct Item *next;
};

struct Stack
{
    int size;
    struct Item *top;
};

void init(struct Stack *stk)
{
    stk->size = 0;
    stk->top = NULL;
}

void push(struct Stack *stk, int value)
{
    struct Item *i = (struct Item *)malloc(sizeof(struct Item));
    i->value = value;
    i->next = stk->top;
    stk->top = i;
    stk->size++;
}

void pop(struct Stack *stk)
{
    if (stk->size == 0)
        return;

    struct Item *temp = stk->top;
    stk->top = stk->top->next;
    free(temp);
    stk->size--;
}

void peek(struct Stack *stk)
{
    if (stk->size > 0)
        printf("Top: %d\n", stk->top->value);
}

void print(struct Stack *stk)
{
    struct Item *current = stk->top;
    while (current != NULL)
    {
        printf("%d\n", current->value);
        current = current->next;
    }
}

int main()
{
    struct Stack s1;
    init(&s1);

    push(&s1, 5);
    push(&s1, -3);

    peek(&s1);
    pop(&s1);

    push(&s1, 0);
    print(&s1);

    return 0;
}
