#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
    FILE *fp;
    char path[1024];
    char *longestName = NULL;
    char *shortestName = NULL;
    size_t longestLen = 0;
    size_t shortestLen = 1024;  // zakładamy, że nazwa nie przekroczy 1024 znaków

    // Otwieramy potok do komendy "ls -1 $HOME"
    fp = popen("ls -1 \"$HOME\"", "r");
    // if (fp == NULL) {
    //     fprintf(stderr, "Błąd: Nie udało się wywołać polecenia ls.\n");
    //     return 1;
    // }

    // Czytamy wyniki polecenia linia po linii
    while (fgets(path, sizeof(path), fp) != NULL) {
        // Usuwamy znak nowej linii na końcu odczytanej linii
        path[strcspn(path, "\n")] = '\0';

        // Obliczamy długość nazwy pliku/katalogu
        size_t len = strlen(path);

        // Sprawdzamy, czy to jest najdłuższa nazwa
        if (len > longestLen) {
            free(longestName);  // zwalniamy poprzednią pamięć (jeśli była)
            longestName = strdup(path);
            longestLen = len;
        }

        // Sprawdzamy, czy to jest najkrótsza nazwa
        if (len < shortestLen) {
            free(shortestName);  // zwalniamy poprzednią pamięć (jeśli była)
            shortestName = strdup(path);
            shortestLen = len;
        }
    }

    // Zamykamy potok
    pclose(fp);

    // Wyświetlamy wyniki
    // if (longestName == NULL || shortestName == NULL) {
    //     fprintf(stderr, "Błąd: Nie znaleziono plików ani katalogów w $HOME.\n");
    // } else {
    //     printf("Najdłuższa nazwa: %s (długość: %zu)\n", longestName, longestLen);
    //     printf("Najkrótsza nazwa: %s (długość: %zu)\n", shortestName, shortestLen);
    // }
    printf("Najdłuższa nazwa: %s (długość: %zu)\n", longestName, longestLen);
    printf("Najkrótsza nazwa: %s (długość: %zu)\n", shortestName, shortestLen);

    // Zwalniamy zaalokowaną pamięć
    free(longestName);
    free(shortestName);

    return 0;
}
