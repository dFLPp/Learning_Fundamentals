#include "../../include/workbook/workbook.h"

Boolean mapFromFileToList(Node **head, FILE *filePointer)
{
    char line[ID_LENGTH + DESC_LENGTH + TITLE_LENGTH + 20];
    char id[ID_LENGTH];
    char title[TITLE_LENGTH];
    char desc[DESC_LENGTH];
    Boolean isDone;

    if (filePointer == NULL)
        return FALSE;

    rewind(filePointer);

    while (fgets(line, sizeof(line), filePointer) != NULL)
    {
        if (sscanf(line, "%[^;-;];-;%[^;-;];-;%[^;-;];-;%d", id, title, desc, &isDone) == 4)
        {
            Task task = createTaskFromFile(id, title, desc, isDone);
            insertNode(head, &task);
        }
    }

    return (*head != NULL); // Retornar TRUE se a lista não estiver vazia
}

Boolean mapFromListToFile(Node **head, FILE *filePointer)
{
    if (head == NULL)
        return FALSE;

    Node *curr = *head;
    int gambiarra;
    char line[ID_LENGTH + DESC_LENGTH + TITLE_LENGTH + 20];
    // 3 caractares separadores para 3 separações + 1 carac para o número de isDone + 1 do '\0' = 11;

    filePointer = fopen("C:\\Users\\Outros\\Downloads\\Arch\\C\\1. Fundamentals\\1. Programming languages\\1. C\\4. Project\\data.txt", "w");

    if (filePointer == NULL)
        return FALSE;

    rewind(filePointer);

    while (curr != NULL)
    {
        gambiarra = (int)curr->object.isDone;
        snprintf(line, sizeof(line), "%s;-;%s;-;%s;-;%d", curr->object.id, curr->object.title, gambiarra);
        fprintf(filePointer, "%s\n", line);
        curr = curr->next;
    }

    fclose(filePointer);

    return TRUE;
}
