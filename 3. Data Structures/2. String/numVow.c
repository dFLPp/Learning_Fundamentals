// Conta o número de vogais em uma string

#include <stdio.h>
#include <string.h>
#include <ctype.h>

int count_vowels(const char *str)
{
    int count = 0;
    int len = strlen(str);

    for (int i = 0; i < len; i++)
    {
        char c = tolower(str[i]);
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
        {
            count++;
        }
    }

    return count;
}

int main()
{
    const char *string = "Hello, how are you?";
    int vowel_count = count_vowels(string);
    printf("O número de vogais na string é: %d\n", vowel_count);

    return 0;
}