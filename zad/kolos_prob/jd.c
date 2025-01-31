#include <stdio.h>

int main() {
    int array[10];  // Tablica o stałym rozmiarze 10
    int size = 0;   // Aktualna liczba elementów w tablicy

    // Dodajemy nowe wartości do tablicy
    // array[size++] = 5;
    // array[size++] = 10;
    // array[size++] = 15;
    array = 1;
    array = 2;

    // Wyświetlamy elementy tablicy
    printf("Tablica: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");

    return 0;
}
