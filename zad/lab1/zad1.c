#include <stdio.h>
#include <stdlib.h>

void find_min_max(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        fprintf(stderr, "Błąd: Nie można otworzyć pliku '%s'.\n", filename);
        return;
    }

    int number;
    int min, max;
    int first = 1;

    while (fscanf(file, "%d", &number) == 1) {
        if (first) {
            min = max = number;
            first = 0;
        } else {
            if (number < min) min = number;
            if (number > max) max = number;
        }
    }

    if (first) {
        fprintf(stderr, "Błąd: Plik '%s' jest pusty lub zawiera nieprawidłowe dane.\n", filename);
    } else {
        printf("Najmniejsza liczba: %d\n", min);
        printf("Największa liczba: %d\n", max);
    }

    fclose(file);
}

int main() {
    const char *filename = "liczby.txt";
    find_min_max(filename);
    return 0;
}
