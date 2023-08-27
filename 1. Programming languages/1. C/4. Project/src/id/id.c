#include "id.h"

// Função para obter o valor atual do relógio
unsigned long long getClockValue()
{
    struct timespec currentTime;
    clock_gettime(CLOCK_REALTIME, &currentTime);
    return currentTime.tv_nsec + currentTime.tv_sec * 1000000000ULL;
}

// Função para gerar um UUID do paraguai
void generateUUID(char *uuidStr)
{
    unsigned long long timestamp = (unsigned long long)time(NULL);
    unsigned long long clockValue = getClockValue();
    static unsigned int counter = 0;

    // Combinar timestamp, valor do relógio e contador
    unsigned long long combinedValue = timestamp ^ clockValue ^ counter++;

    // Formatar o valor combinado como UUID
    snprintf(uuidStr, 33, "%016llx", combinedValue);
}