#include "../../include/task/task.h"

static void copyStringWithLimit(char *destination, const char *source, size_t limit)
{
    strncpy(destination, source, limit - 1);
    destination[limit - 1] = '\0';
}

static Task createTaskCommon(char *title, char *desc, bool isDone)
{
    Task task;
    task.isDone = (isDone >= FALSE && isDone <= TRUE) ? isDone : FALSE;

    copyStringWithLimit(task.title, title, TITLE_LENGTH);
    copyStringWithLimit(task.desc, desc, DESC_LENGTH);

    return task;
}

Task createTask(char *title, char *desc, bool isDone)
{
    Task task = createTaskCommon(title, desc, isDone);
    generateUUID(task.id);
    copyStringWithLimit(task.id, task.id, ID_LENGTH);
    return task;
}

Task createTaskFromFile(char *id, char *title, char *desc, bool isDone)
{
    Task task = createTaskCommon(title, desc, isDone);
    copyStringWithLimit(task.id, id, ID_LENGTH);
    return task;
}

void printTask(Task *task)
{
    printf("id: %s\n", task->id);
    printf("titulo: %s\n", task->title);
    printf("descricao: %s\n", task->desc);
    printf("Concluida: %d\n", task->isDone);
}