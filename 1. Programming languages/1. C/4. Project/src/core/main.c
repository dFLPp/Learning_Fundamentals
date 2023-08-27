#include "../../include/core/main.h"

static Boolean createItem(Node **head)
{
    char title[TITLE_LENGTH];
    char desc[DESC_LENGTH];
    Boolean isDone;

    printf("Diga os valores da task:\n");

    printf("Titulo: ");
    fflush(stdin);
    scanf("%s", title);

    printf("Descricao: ");
    fflush(stdin);
    scanf("%s", desc);

    printf("concluida: ");
    fflush(stdin);
    scanf("%d", &isDone);

    Task task = createTask(title, desc, isDone);
    return insertNode(head, &task);
}

static Boolean deleteItem(Node **head, char *id)
{
    if (head == NULL)
        return FALSE;
    if (id == NULL)
        return FALSE;

    return removeNode(head, id);
}

static Boolean modifyItem(Node **head, char *id, Boolean newStatus)
{
    if (head == NULL)
        return FALSE;
    if (head == NULL)
        return FALSE;
    if (newStatus <= 0 && newStatus >= 1)
        return FALSE;

    return updateNode(*head, id, newStatus);
}

static Boolean saveTasks(WorkBook *workbook)
{
    if (workbook->head == NULL)
        return FALSE;
    else
        return mapFromListToFile(&workbook->head, workbook->filePointer);
}

static Boolean showTasks(WorkBook *workbook)
{
    if (workbook->head == NULL)
        return FALSE;
    Node *curr = workbook->head;
    int i = 1;
    while (curr->next != NULL)
    {
        printf("TASK %d\n", i);
        printTask(&curr->object);
        printf("\n");
        curr = curr->next;
    }
    printf("TASK %d\n", i);
    printTask(&curr->object);
    printf("\n");

    return TRUE;
}

static Boolean loadTaks(WorkBook *workbook)
{
    return mapFromFileToList(&workbook->head, workbook->filePointer);
}

Boolean setup(WorkBook *workbook)
{
    if (!loadTaks(workbook))
    {
        workbook->head = NULL;
        workbook->filePointer = NULL;
        return FALSE;
    }
    return TRUE;
}

void eventLoop(WorkBook *workbook)
{
    char opt;
    char newId[ID_LENGTH];
    Boolean newIsDone;

    while (TRUE)
    {
        printf("Task app\n");
        printf("1 - Criar\n");
        printf("2 - Remover\n");
        printf("3 - Editar\n");
        printf("4 - Mostrar\n");
        printf("5 - Sair\n");
        printf("-> ");

        fflush(stdin);

        scanf(" %c", &opt);

        switch (opt)
        {
        case '1':
            if (!createItem(&workbook->head))
                exit(1);
            break;

        case '2':
            printf("Diga qual o id da task: ");
            fflush(stdin);
            scanf("%s", newId);
            if (!deleteItem(&workbook->head, newId))
                exit(1);
            break;

        case '3':
            printf("Diga qual o id da task: ");
            fflush(stdin);
            scanf("%s", newId);

            printf("Diga qual o novo status da task: ");
            fflush(stdin);
            scanf("%d", newIsDone);
            if (!modifyItem(&workbook->head, newId, newIsDone))
                exit(1);
            break;

        case '4':
            if (!showTasks(workbook))
                exit(1);
            break;

        case '5':
            if (saveTasks(workbook))
                exit(0);
            else
                exit(1);

            break;

        default:
            exit(1);
            break;
        }
    }
}

int main()
{
    WorkBook workbook;
    if (!setup(&workbook))
    {
        printf("Erro ao configurar o WorkBook.\n");
        return 1;
    }
    eventLoop(&workbook);
    return 0;
}