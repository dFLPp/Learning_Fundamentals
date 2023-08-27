#include "workbook.h"

Boolean mapFromFileToList(Node **head, FILE *filePointer)
{
    char line[ID_LENGTH + DESC_LENGTH + TITLE_LENGTH + 11];

    filePointer = fopen("path", "r");

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
            Node *newNode = createNode(&task);
            if (newNode != NULL)
                insertNode(head, newNode);
        }
    }

    fclose(filePointer);

    return TRUE;
}

Boolean mapFromListToFile(Node **head, FILE *filePointer)
{
    Node *curr = *head;
    char line[ID_LENGTH + DESC_LENGTH + TITLE_LENGTH + 11];
    // 3 caractares separadores para 3 separações + 1 carac para o número de isDone + 1 do '\0' = 11;

    filePointer = fopen("path", "w");
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
