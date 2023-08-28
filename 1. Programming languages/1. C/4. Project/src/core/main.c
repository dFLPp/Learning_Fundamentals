#include "../../include/core/main.h"

static void printMenu()
{
    printf("Task app\n\n");
    printf("1 - Criar\n");
    printf("2 - Remover\n");
    printf("3 - Editar\n");
    printf("4 - Mostrar\n");
    printf("5 - Sair\n");
    printf("-> ");
}

static void eventLoop(WorkBook *workbook)
{
    char buf[OPT_LENGTH];
    char *p;
    bool isChill = TRUE;

    if (loadTasks(workbook) == TRUE)
        printf("[DEBUG LOG]: SUCESS\n\n");
    else
        printf("[DEBUG LOG]: ERROR\n\n");

    while (TRUE)
    {
        printMenu();
        getInput(buf, "MENU_OPTION");
        system("cls");

        if (strcmp(buf, "1") == 0)
            isChill = createItem(&workbook->head);
        else if (strcmp(buf, "2") == 0)
            isChill = deleteItem(&workbook->head);
        else if (strcmp(buf, "3") == 0)
            isChill = modifyItem(&workbook->head);
        else if (strcmp(buf, "4") == 0)
            isChill = showTasks(workbook);
        else if (strcmp(buf, "5") == 0)
            if (saveTasks(workbook) == TRUE)
                exit(0);
            else
                exit(1);
        else
            isChill = FALSE;

        if (isChill == TRUE)
            printf("[DEBUG LOG]: SUCESS\n\n");
        else
            printf("[DEBUG LOG]: ERROR\n\n");
    }
}

int main()
{
    WorkBook workbook;
    workbook.head = NULL;
    workbook.filePointer = NULL;

    eventLoop(&workbook);
    return 0;
}