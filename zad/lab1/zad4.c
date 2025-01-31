#include <stdio.h>

#include <stdlib.h>

#include <string.h>

#include <ctype.h>



#define MAX_LEN 100



// Funkcja sprawdzająca, czy tekst zawiera tylko litery

int is_alpha(char *str) {

    for (int i = 0; i < strlen(str); i++) {

        if (!isalpha(str[i])) {

            return 0; // Zawiera znaki inne niż litery

        }

    }

    return 1; // Zawiera tylko litery

}



int main() {

    char firstName[MAX_LEN], lastName[MAX_LEN];

    FILE *file;

    char line[MAX_LEN];

    int found = 0;



    // Pobranie imienia i nazwiska od użytkownika

    printf("Podaj imię: ");

    scanf("%s", &firstName);

    // fgets(firstName, MAX_LEN, stdin);

    // firstName[strcspn(firstName, "\n")] = '\0'; // Usuwamy znak nowej linii



    printf("Podaj nazwisko: ");

    scanf("%s", &lastName);

    // fgets(lastName, MAX_LEN, stdin);

    // lastName[strcspn(lastName, "\n")] = '\0'; // Usuwamy znak nowej linii



    // Sprawdzanie, czy imię i nazwisko zawierają tylko litery

    if (!is_alpha(firstName) || !is_alpha(lastName)) {

        fprintf(stderr, "Błąd: Imię i nazwisko mogą zawierać tylko litery.\n");

        return 1;

    }



    // Otwarcie pliku baza.txt

    file = fopen("baza.txt", "r");

    if (file == NULL) {

        fprintf(stderr, "Błąd: Nie można otworzyć pliku.\n");

        return 1;

    }



    // Sprawdzanie, czy w pliku znajduje się podana osoba

    while (fgets(line, MAX_LEN, file) != NULL) {

        char storedFirstName[MAX_LEN], storedLastName[MAX_LEN];



        // Rozdzielanie imienia i nazwiska z linii w pliku

        sscanf(line, "%s %s", storedFirstName, storedLastName);



        // Sprawdzanie, czy znaleziono osobę

        if (strcmp(firstName, storedFirstName) == 0 && strcmp(lastName, storedLastName) == 0) {

            found = 1;

            break;

        }

    }



    // Zamknięcie pliku

    fclose(file);



    // Wypisanie odpowiedniego komunikatu

    if (found) {

        printf("Znaleziono osobę: %s %s\n", firstName, lastName);

    } else {

        printf("Nie znaleziono osoby: %s %s\n", firstName, lastName);

    }



    return 0;

}
