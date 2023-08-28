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

static Boolean modifyItem(Node **head, char *id)
{
    if (head == NULL || *head == NULL)
        return FALSE;

    return updateNode(head, id);
}

static Boolean showTasks(WorkBook *workbook)
{
    if (workbook->head == NULL)
        return FALSE;

    Node *curr = workbook->head;
    int i = 1;
    while (curr != NULL)
    {
        printf("TASK %d\n", i);
        printTask(&curr->object);
        printf("\n");
        curr = curr->next;
        i++;
    }
    return TRUE;
}

static Boolean saveTasks(WorkBook *workbook)
{
    if (workbook->head == NULL)
        return FALSE;
    else
        return mapFromListToFile(&workbook->head, workbook->filePointer);
}

Boolean setup(WorkBook *workbook)
{
    return mapFromFileToList(&workbook->head, workbook->filePointer);
}

void eventLoop(WorkBook *workbook)
{
    char opt;
    char newId[ID_LENGTH];

    while (TRUE)
    {
        printf("Task app\n\n");
        printf("1 - Criar\n");
        printf("2 - Remover\n");
        printf("3 - Editar\n");
        printf("4 - Mostrar\n");
        printf("5 - Sair\n");
        printf("-> ");

        fflush(stdin);

        scanf(" %c", &opt);

        if (opt == '1')
        {
            system("cls");
            if (createItem(&workbook->head) == FALSE)
            {
                system("cls");
                printf("[DEBUG LOG]: Nao foi possivel inserir\n\n");
            }
            else
                system("cls");
            printf("[DEBUG LOG]: Insercao ocorreu com sucesso\n\n");
        }

        else if (opt == '2')
        {
            printf("ID: ");
            fflush(stdin);
            scanf("%s", newId);

            system("cls");
            if (deleteItem(&workbook->head, newId) == FALSE)
            {
                system("cls");
                printf("[DEBUG LOG]: Nao foi possivel remover\n\n");
            }
            else
                system("cls");
            printf("[DEBUG LOG]: Remocao ocorreu com sucesso\n\n");
        }

        else if (opt == '3')
        {
            printf("ID: ");
            fflush(stdin);
            scanf("%s", newId);

            system("cls");
            if (modifyItem(&workbook->head, newId) == FALSE)
            {
                system("cls");
                printf("[DEBUG LOG]: Nao foi possivel modificar\n\n");
            }
            else
                system("cls");
            printf("[DEBUG LOG]: Modificacao ocorreu com sucesso\n\n");
        }
        else if (opt == '4')
        {
            system("cls");
            if (showTasks(workbook) == FALSE)
            {
                system("cls");
                printf("[DEBUG LOG]: Nao foi possivel mostrar\n\n");
            }
        }
        else if (opt == '5')
        {
            printf("Salvar alteracoes?\n");
            printf("-> ");
            fflush(stdin);
            scanf(" %s", &opt);
            if (opt == 's')
            {
                if (saveTasks(workbook))
                    exit(0);
                else
                    exit(1);
            }
            else
                exit(0);
        }
        else
        {
            printf("[DEBUG LOG]: Opcao nao existe\n\n");
        }
    }
}

int main()
{
    WorkBook workbook;
    workbook.head = NULL;
    workbook.filePointer = NULL;

    setup(&workbook);
    eventLoop(&workbook);
    return 0;
}