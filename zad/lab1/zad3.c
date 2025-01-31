#include <stdio.h>

#include <string.h>



void compare_strings(const char *str1, const char *str2) {

    FILE *lexicographic_file = fopen("predzej.txt", "w");

    FILE *longer_file = fopen("dluzszy.txt", "w");



    // if (lexicographic_file == NULL || longer_file == NULL) {

    //     fprintf(stderr, "Błąd: Nie można utworzyć plików wyjściowych.\n");

    //     if (lexicographic_file) fclose(lexicographic_file);

    //     if (longer_file) fclose(longer_file);

    //     return;

    // }



    // Porównanie leksykograficzne

    if (strcmp(str1, str2) < 0) {

        fprintf(lexicographic_file, "%s\n", str1);

    } else {

        fprintf(lexicographic_file, "%s\n", str2);

    }



    // Porównanie długości

    int len1 = strlen(str1);

    int len2 = strlen(str2);



    if (len1 > len2) {

        fprintf(longer_file, "%s\n", str1);

    } else if (len1 < len2) {

        fprintf(longer_file, "%s\n", str2);

    } else {

        fprintf(stderr, "Błąd: Oba napisy mają tę samą długość.\n");

    }



    fclose(lexicographic_file);

    fclose(longer_file);

}



int main() {

    char str1[256], str2[256];



    printf("Podaj pierwszy napis: ");

    // if (fgets(str1, sizeof(str1), stdin) == NULL) {

    //     fprintf(stderr, "Błąd: Nie udało się odczytać pierwszego napisu.\n");

    //     return 1;

    // }

    scanf("%s", &str1);



    printf("Podaj drugi napis: ");

    // if (fgets(str2, sizeof(str2), stdin) == NULL) {

    //     fprintf(stderr, "Błąd: Nie udało się odczytać drugiego napisu.\n");

    //     return 1;

    // }

    scanf("%s", &str2);



    // // Usunięcie znaków nowej linii, jeśli występują

    // str1[strcspn(str1, "\n")] = '\0';

    // str2[strcspn(str2, "\n")] = '\0';



    compare_strings(str1, str2);

    return 0;

}
