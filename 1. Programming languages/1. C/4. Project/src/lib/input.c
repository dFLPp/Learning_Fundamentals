#include "../../include/lib/input.h"

bool getInput(char *destination, char *type)
{
    int size = 0;
    char *p;

    if (strcmp(type, "ID") == 0)
        size = ID_LENGTH;
    else if (strcmp(type, "TITLE") == 0)
        size = TITLE_LENGTH;
    else if (strcmp(type, "DESCRIPTION") == 0)
        size = DESC_LENGTH;
    else if (strcmp(type, "SAVE_ON_EXIT") == 0)
        size = OPT_LENGTH;
    else if (strcmp(type, "LOAD_ON_START") == 0)
        size = OPT_LENGTH;
    else
    {
        printf("[DEGUB LOG]: ERROR\n");
        return FALSE;
    }

    fflush(stdin);

    if (fgets(destination, size, stdin) == NULL)
    {
        printf("[DEGUB LOG]: ERROR\n");
        return FALSE;
    }

    if ((p = strchr(destination, '\n')) != NULL)
        *p = '\0';

    return TRUE;
}