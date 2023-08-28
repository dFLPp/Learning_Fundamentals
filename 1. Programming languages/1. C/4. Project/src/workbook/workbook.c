#include "../../include/workbook/workbook.h"

/*
Problemas:
- Não consigue ler apos o programa iniciar (mapFromFileToList falho)
- Não consegue salvar nem em memória nem em arquivo inputs com espaço
- Não consegue salvar todos os campos corretamente
*/

Boolean mapFromFileToList(Node **head, FILE *filePointer)
{
    char id[ID_LENGTH];
    char title[TITLE_LENGTH];
    char desc[DESC_LENGTH];
    Boolean isDone;

    char ch;           // Variável para ler caracteres do arquivo
    int charCount = 0; // Contador de caracteres

    filePointer = fopen("C:\\Users\\Outros\\Downloads\\Arch\\C\\1. Fundamentals\\1. Programming languages\\1. C\\4. Project\\data.txt", "r");

    // Verificar se o ponteiro para o arquivo é válido
    if (filePointer == NULL)
        return FALSE;

    // Voltar ao início do arquivo para começar a leitura
    rewind(filePointer);

    while ((ch = fgetc(filePointer)) != EOF)
    {
        if (ch == ';')
        {
            // Terminou de ler um campo, colocar o caractere nulo para finalizar a string
            id[charCount] = '\0';

            // Reiniciar o contador de caracteres para o próximo campo
            charCount = 0;

            // Ler o próximo campo (título)
            while ((ch = fgetc(filePointer)) != ';')
            {
                title[charCount++] = ch;
            }
            title[charCount] = '\0';

            // Reiniciar o contador de caracteres para o próximo campo
            charCount = 0;

            // Ler o próximo campo (descrição)
            while ((ch = fgetc(filePointer)) != ';')
            {
                desc[charCount++] = ch;
            }
            desc[charCount] = '\0';

            // Ler o campo final (isDone)
            fscanf(filePointer, "%d\n", &isDone);

            // Criar a Task e inserir no nó
            Task task = createTaskFromFile(id, title, desc, isDone);
            insertNode(head, &task);
        }
        else
        {
            // Adicionar o caractere ao campo atual
            id[charCount++] = ch;
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
        snprintf(line, sizeof(line), "%s;-;%s;-;%s;-;%d\0", curr->object.id, curr->object.title, gambiarra);
        fprintf(filePointer, "%s\n", line);
        curr = curr->next;
    }

    fclose(filePointer);

    return TRUE;
}
