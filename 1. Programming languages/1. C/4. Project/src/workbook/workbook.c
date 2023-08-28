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
    filePointer = fopen("path para o arquivo no seu computador");

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

static bool mapFromListToFile(Node **head, FILE *filePointer)
{
    if (head == NULL)
        return FALSE;

    Node *curr = *head;
    int gambiarra = 0;
    char line[ID_LENGTH + DESC_LENGTH + TITLE_LENGTH + 20];

    filePointer = fopen("path para o arquivo no seu computador");

    if (filePointer == NULL)
        return FALSE;

    rewind(filePointer);

    while (curr != NULL)
    {
        gambiarra = (int)curr->object.isDone;
        snprintf(line, sizeof(line), "%s;%s;%s;%d\0", curr->object.id, curr->object.title, curr->object.desc, gambiarra);
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
        char resp[2];
        printf("SAVE TASKS: ");
        getInput(resp, "SAVE_ON_EXIT");
        getchar();
        if (strcmp(resp, "s") == 0)
            return mapFromListToFile(&workbook->head, workbook->filePointer);
        else
            return FALSE;
    }
}

bool loadTasks(WorkBook *workbook)
{
    char resp[2];
    printf("LOAD TASKS: ");
    getInput(resp, "LOAD_ON_START");
    getchar();
    if (strcmp(resp, "s") == 0)
        return mapFromFileToList(&workbook->head, workbook->filePointer);
    else
        return FALSE;
}
