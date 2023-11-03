// Fazendo uma "database" com hash tables

#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

// truque para conseguir limpar o terminal em "qualquer" sistema
#ifdef _WIN32
#include <windows.h>
#define CLEAR_SCREEN "cls"
#else
#define CLEAR_SCREEN "clear"
#endif

#define DB_SIZE 100

typedef struct Entry Entry;

struct Entry
{
    char key[20];
    char value[200];
};

static unsigned int hashFunction(char *key)
{
    unsigned int hash = 0;
    while (*key)
    {
        hash = (hash << 5) + *key++;
        // (hash << 5) = hash * (2^5)
    }
    return hash % DB_SIZE;
}

void getInput(char *buffer, size_t bufferSize, const char *prompt)
{
    printf("%s", prompt);
    if (fgets(buffer, bufferSize, stdin))
    {
        size_t len = strlen(buffer);
        if (len > 0 && buffer[len - 1] == '\n')
            buffer[len - 1] = '\0';
    }
    else
        printf("Não foi possível receber a entrada.\n");
}

void addElement(Entry *database)
{
    char keyBuff[20];
    char valueBuff[200];

    getInput(keyBuff, sizeof(keyBuff), "Chave: ");
    unsigned int validIndex = hashFunction(keyBuff);

    if (strlen(database[validIndex].key) > 0)
    {
        printf("Chave já existe.\n");
        return;
    }

    getInput(valueBuff, sizeof(valueBuff), "Valor: ");
    strcpy(database[validIndex].key, keyBuff);
    strcpy(database[validIndex].value, valueBuff);
}

void removeElement(Entry *database)
{
    char keyBuff[20];

    getInput(keyBuff, sizeof(keyBuff), "Chave: ");
    unsigned int indexToRemove = hashFunction(keyBuff);

    if (strlen(database[indexToRemove].key) == 0)
    {
        printf("Chave não encontrada.\n");
        return;
    }

    memset(&database[indexToRemove], 0, sizeof(Entry));
}

void printElement(Entry *database)
{
    char keyBuff[20];

    getInput(keyBuff, sizeof(keyBuff), "Chave: ");
    unsigned int indexToSearch = hashFunction(keyBuff);

    if (strlen(database[indexToSearch].key) == 0)
    {
        printf("Chave não encontrada.\n");
        return;
    }

    printf("Valor: %s\n", database[indexToSearch].value);
}

void printDatabase(Entry *database)
{
    system(CLEAR_SCREEN);

    for (int i = 0; i < DB_SIZE; i++)
    {
        if (strlen(database[i].key) > 0)
        {
            printf("Chave: %s, Valor: %s\n", database[i].key, database[i].value);
        }
    }
}

static void eventLoop(Entry *database)
{
    memset(database, 0, DB_SIZE * sizeof(Entry));
    int option;
    int flag = 1;

    while (flag)
    {
        printf("Simulador de Banco de Dados\n\n");
        printf("1 - Adicionar elemento\n");
        printf("2 - Remover elemento\n");
        printf("3 - Ver elemento\n");
        printf("4 - Ver tabela hash\n");
        printf("5 - Sair\n");
        printf("-> ");

        if (scanf("%d", &option) != 1)
        {
            printf("Entrada inválida.\n");
            return;
        }
        while (getchar() != '\n')
            ; // Limpar o buffer de entrada

        switch (option)
        {
        case 1:
            addElement(database);
            break;
        case 2:
            removeElement(database);
            break;
        case 3:
            printElement(database);
            break;
        case 4:
            printDatabase(database);
            break;
        case 5:
            flag = 0;
            break;
        default:
            printf("Opção inválida.\n");
            break;
        }

        printf("\nPressione Enter para continuar...");
        while (getchar() != '\n')
            ; // Limpar o buffer de entrada
        system(CLEAR_SCREEN);
    }
}

int main()
{
    Entry database[DB_SIZE];
    eventLoop(database);

    return 0;
}
