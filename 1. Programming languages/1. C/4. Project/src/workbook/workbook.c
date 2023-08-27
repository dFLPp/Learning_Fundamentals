#include "../../include/workbook/workbook.h"

Boolean mapFromFileToList(Node **head, FILE *filePointer)
{
    char line[ID_LENGTH + DESC_LENGTH + TITLE_LENGTH + 11];

    // vc coloca o path de onde o arquivo está nom seu PC
    filePointer = fopen("C:\\Users\\Outros\\Downloads\\Arch\\C\\1. Fundamentals\\1. Programming languages\\1. C\\4. Project\\data.txt", "r");

    if (filePointer == NULL)
        return FALSE;

    while (fgets(line, sizeof(line), filePointer) != NULL)
    {
        char id[ID_LENGTH];
        char title[TITLE_LENGTH];
        char desc[DESC_LENGTH];
        Boolean isDone;

        if (sscanf(line, "%[^;-;];-;%[^;-;];-;%[^;-;];-;%d\n", id, title, desc, &isDone) == 4)
        {
            Task task = createTask(title, desc, isDone);
            insertNode(head, &task);
        }
    }

    fclose(filePointer);

    if (head != NULL)
        return TRUE;
    else
        return FALSE;
}

Boolean mapFromListToFile(Node **head, FILE *filePointer)
{
    if (head == NULL)
        return FALSE;
    Node *curr = *head;
    char line[ID_LENGTH + DESC_LENGTH + TITLE_LENGTH + 11];
    // 3 caractares separadores para 3 separações + 1 carac para o número de isDone + 1 do '\0' = 11;

    filePointer = fopen("C:\\Users\\Outros\\Downloads\\Arch\\C\\1. Fundamentals\\1. Programming languages\\1. C\\4. Project\\data.txt", "w");
    if (filePointer == NULL)
        return FALSE;

    while (curr != NULL)
    {
        snprintf(line, sizeof(line), "%s;-;%s;-;%s;-;%d\n", curr->object.id, curr->object.title, curr->object.desc, curr->object.isDone);
        fprintf(filePointer, "%s\n", line);
        curr = curr->next;
    }

    fclose(filePointer);

    return TRUE;
}
