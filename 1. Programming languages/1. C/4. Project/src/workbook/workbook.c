#include "../../include/workbook/workbook.h"

static bool mapFromFileToList(Node **head, FILE *filePointer)
{
    char id[ID_LENGTH];
    char title[TITLE_LENGTH];
    char desc[DESC_LENGTH];
    bool isDone;

    char ch;
    int charCount = 0;

    // coloque o path para o arquivo no seu PC
    filePointer = fopen("C:\\Users\\Outros\\Downloads\\Arch\\C\\1. Fundamentals\\1. Programming languages\\1. C\\4. Project\\data.txt", "r");

    if (filePointer == NULL)
        return FALSE;

    rewind(filePointer);

    while ((ch = fgetc(filePointer)) != EOF)
    {
        if (ch == ';')
        {

            id[charCount] = '\0';

            charCount = 0;
            while ((ch = fgetc(filePointer)) != ';')
                title[charCount++] = ch;

            title[charCount] = '\0';

            charCount = 0;
            while ((ch = fgetc(filePointer)) != ';')
                desc[charCount++] = ch;

            desc[charCount] = '\0';

            fscanf(filePointer, "%d\n", &isDone);

            Task task = createTaskFromFile(id, title, desc, isDone);
            createItemFromFile(head, &task);
        }
        else
        {
            // Adicionar o caractere ao campo atual
            id[charCount++] = ch;
        }
    }

    return (*head != NULL); // Retornar TRUE se a lista não estiver vazia
}

// refazer
static bool mapFromListToFile(Node **head, FILE *filePointer)
{
    if (head == NULL)
        return FALSE;

    Node *curr = *head;
    int gambiarra;
    char line[ID_LENGTH + DESC_LENGTH + TITLE_LENGTH + 20];

    filePointer = fopen("C:\\Users\\Outros\\Downloads\\Arch\\C\\1. Fundamentals\\1. Programming languages\\1. C\\4. Project\\data.txt", "w");

    if (filePointer == NULL)
        return FALSE;

    rewind(filePointer);

    while (curr != NULL)
    {
        gambiarra = (int)curr->object.isDone;
        snprintf(line, sizeof(line), "%s;-;%s;-;%s;-;%d\0", curr->object.id, curr->object.title, gambiarra);
        fprintf(filePointer, "%s\n", line);
        curr = curr->next;
    }

    fclose(filePointer);

    return TRUE;
}

bool showTasks(WorkBook *workbook)
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

bool saveTasks(WorkBook *workbook)
{
    if (workbook->head == NULL)
        return FALSE;
    else
    {
        char resp[1];
        printf("SAVE TASKS: ");
        getInput(resp, "SAVE_ON_EXIT");
        if (strcmp(resp, "s") == 0)
            return mapFromListToFile(&workbook->head, workbook->filePointer);
        else
            return FALSE;
    }
}

bool loadTasks(WorkBook *workbook)
{
    char resp[1];
    printf("LOAD TASKS: ");
    getInput(resp, "LOAD_ON_START");
    if (strcmp(resp, "s") == 0)
        return mapFromFileToList(&workbook->head, workbook->filePointer);
    else
        return FALSE;
}
