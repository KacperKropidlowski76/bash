#include <stdio.h>
#include <stdlib.h>

void segregate_numbers(int n) {
    FILE *negative_file = fopen("ujemne.txt", "w");
    FILE *positive_file = fopen("dodatnie.txt", "w");

    for (int i = 0; i < n; i++) {
        int number;
        printf("Podaj liczbę #%d: ", i + 1);
        scanf("%d", &number);
        // if (scanf("%d", &number) != 1) { //Sprawdzanie czy zostaly podane liczby
        //     fprintf(stderr, "Błąd: Nieprawidłowe dane wejściowe.\n");
        //     fclose(negative_file);
        //     fclose(positive_file);
        //     return;
        // }

        if (number < 0) { // Sprawdzanie czy ujemna, dodatnia, czy równa 0
            fprintf(negative_file, "%d\n", number);
        } else if (number > 0) {
            fprintf(positive_file, "%d\n", number);
        } else if (number == 0) {
            fprintf(stderr, "Liczba 0 nie jest zapisywana do plików.\n");
        } else {
            fprintf(stderr, "Błąd: Nieprawidłowe dane wejściowe.\n");
            return;
        }
    }

    fclose(negative_file);
    fclose(positive_file);
}

int main() {
    int n;
    printf("Podaj liczbę n: ");
    scanf("%d", &n);

    segregate_numbers(n);
    return 0;
}
