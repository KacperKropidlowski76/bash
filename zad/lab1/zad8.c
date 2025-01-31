#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define CMD_LEN 256

int main(void) {
    // Nazwy dwóch plików do porównania
    char file1[] = "plik1.txt";
    char file2[] = "plik2.txt";

    // Zmienne do przechowywania liczby słów w plikach
    int wordsFile1 = 0;
    int wordsFile2 = 0;

    // Bufor poleceń
    char command[CMD_LEN];
    FILE *fp;

    // 1) Obliczamy liczbę słów w pierwszym pliku
    //    Używamy polecenia wc -w plik1.txt (wyświetla liczbę słów, a następnie nazwę pliku)
    snprintf(command, sizeof(command), "wc -w %s", file1);
    fp = popen(command, "r");  // otwieramy potok do odczytu wyjścia z wc
    if (fp == NULL) {
        fprintf(stderr, "Błąd przy wywołaniu polecenia: %s\n", command);
        return 1;
    }
    // Odczytujemy wyjście, które ma postać np: "10 plik1.txt\n"
    fscanf(fp, "%d", &wordsFile1); 
    pclose(fp);

    // 2) Obliczamy liczbę słów w drugim pliku
    snprintf(command, sizeof(command), "wc -w %s", file2);
    fp = popen(command, "r");
    if (fp == NULL) {
        fprintf(stderr, "Błąd przy wywołaniu polecenia: %s\n", command);
        return 1;
    }
    fscanf(fp, "%d", &wordsFile2);
    pclose(fp);

    // 3) Porównujemy liczby słów i wyświetlamy wynik
    printf("Liczba słów w %s: %d\n", file1, wordsFile1);
    printf("Liczba słów w %s: %d\n", file2, wordsFile2);

    if (wordsFile1 > wordsFile2) {
        printf("Plik %s ma więcej słów.\n", file1);
    } else if (wordsFile2 > wordsFile1) {
        printf("Plik %s ma więcej słów.\n", file2);
    } else {
        printf("Oba pliki mają tyle samo słów.\n");
    }

    return 0;
}
