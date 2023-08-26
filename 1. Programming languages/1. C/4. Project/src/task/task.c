#include "task.h"

Task createTask(char *title, char *desc, Boolean isDone)
{
    Task task;

    if (isDone != True && isDone != False)
        return task;
    else
    {

        task.isDone = isDone;

        strncpy(task.title, title, sizeof(task.title) - 1);
        task.title[sizeof(task.title) - 1] = '\0'; // surprise motherfucker

        strncpy(task.desc, desc, sizeof(task.desc) - 1);
        task.desc[sizeof(task.desc) - 1] = '\0'; // surprise motherfucker

        generateUUID(task.id);
        task.id[sizeof(task.id) - 1] = '\0';

        return task;
    }
}

Task createTaskFromFile(char *id, char *title, char *desc, Boolean isDone)
{
    Task task;

    if (isDone != True && isDone != False)
        return task;
    else
    {

        task.isDone = isDone;

        strncpy(task.title, title, sizeof(task.title) - 1);
        task.title[sizeof(task.title) - 1] = '\0'; // surprise motherfucker

        strncpy(task.desc, desc, sizeof(task.desc) - 1);
        task.desc[sizeof(task.desc) - 1] = '\0'; // surprise motherfucker

        strncpy(task.id, id, sizeof(task.id) - 1);
        task.id[sizeof(task.id) - 1] = '\0'; // surprise motherfucker

        return task;
    }
}

Boolean setTitle(Task *task, char *title)
{
    strncpy(task->title, title, sizeof(task->title) - 1);
    task->title[sizeof(task->title) - 1] = '\0'; // surprise motherfucker
    return True;
}
Boolean setDesc(Task *task, char *desc)
{
    strncpy(task->desc, desc, sizeof(task->desc) - 1);
    task->desc[sizeof(task->desc) - 1] = '\0'; // surprise motherfucker
    return True;
}
Boolean setStatus(Task *task, Boolean status)
{
    if (task->isDone == status)
        return False;
    else
    {
        task->isDone = status;
        return True;
    }
}