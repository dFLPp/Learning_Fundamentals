#include "main.h"

void eventLoop()
{
    char opt;
    while (TRUE)
    {
        printf("Task app\n");
        printf("\t1- Criar\n");
        printf("\t2- Remover\n");
        printf("\t3- Editar\n");
        printf("\t4- Salvar\n");
        printf("\t5- Sair\n");
        printf("-> ");
        scanf("%c", &opt);

        if (strcmp(opt, '5') == 0)
            exit(1);
    }
}

int main()
{
    eventLoop();
    return 0;
}