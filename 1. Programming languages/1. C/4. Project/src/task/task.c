#include "../../include/task/task.h"

static void copyStringWithLimit(char *destination, const char *source, size_t limit)
{
    strncpy(destination, source, limit - 1);
    destination[limit - 1] = '\0';
}

static Task createTaskCommon(char *title, char *desc, Boolean isDone)
{
    Task task;
    task.isDone = (isDone >= FALSE && isDone <= TRUE) ? isDone : FALSE;

    copyStringWithLimit(task.title, title, sizeof(task.title));
    copyStringWithLimit(task.desc, desc, sizeof(task.desc));

    return task;
}

Task createTask(char *title, char *desc, Boolean isDone)
{
    Task task = createTaskCommon(title, desc, isDone);
    generateUUID(task.id);
    copyStringWithLimit(task.id, task.id, sizeof(task.id)); // só pra garantir q n extrapola o tamanho
    return task;
}

Task createTaskFromFile(char *id, char *title, char *desc, Boolean isDone)
{
    Task task = createTaskCommon(title, desc, isDone);
    copyStringWithLimit(task.id, id, sizeof(task.id));
    return task;
}

Boolean setTitle(Task *task, char *title)
{
    copyStringWithLimit(task->title, title, sizeof(task->title));
    return TRUE;
}

Boolean setDesc(Task *task, char *desc)
{
    copyStringWithLimit(task->desc, desc, sizeof(task->desc));
    return TRUE;
}

Boolean setStatus(Task *task, Boolean status)
{
    if (task->isDone == status)
        return FALSE;
    task->isDone = status;
    return TRUE;
}

void printTask(Task *task)
{
    printf("id: %s\n", task->id);
    printf("titulo: %s\n", task->title);
    printf("descricao: %s\n", task->desc);
    printf("Concluida: %s\n", task->isDone);
}