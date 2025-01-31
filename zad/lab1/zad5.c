#include <stdio.h>

#include <stdlib.h>



int main() {

    // 1. Utworzenie pliku o nazwie dane.txt

    system("touch dane.txt");
    printf("Plik dane.txt został utworzony.\n");

    system("mkdir inne");
    printf("Utworzono folder o nazwie inne\n");

    system("cp dane.txt inne");
    printf("Skopiowano dane.txt do folderu inne\n");

    system("mv dane.txt inne");
    printf("Przeniesionoi dane.txt do folderu inne\n");



    // // 2. Utworzenie katalogu o nazwie inne

    // if (system("mkdir inne") == -1) {

    //     fprintf(stderr, "Błąd przy tworzeniu katalogu inne.\n");

    //     return 1;

    // }

    // printf("Katalog 'inne' został utworzony.\n");



    // // 3. Usunięcie pliku o nazwie dane.txt

    // if (remove("dane.txt") != 0) {

    //     fprintf(stderr, "Błąd przy usuwaniu pliku dane.txt.\n");

    //     return 1;

    // }

    // printf("Plik dane.txt został usunięty.\n");



    // // 4. Usunięcie katalogu o nazwie inne

    // if (rmdir("inne") != 0) {

    //     fprintf(stderr, "Błąd przy usuwaniu katalogu inne.\n");

    //     return 1;

    // }

    // printf("Katalog 'inne' został usunięty.\n");



    // // 5. Skopiowanie pliku dane.txt do folderu inne

    // if (system("cp dane.txt inne/") == -1) {

    //     fprintf(stderr, "Błąd przy kopiowaniu pliku dane.txt.\n");

    //     return 1;

    // }

    // printf("Plik dane.txt został skopiowany do katalogu 'inne'.\n");



    // // 6. Przeniesienie pliku dane.txt do folderu inne

    // if (system("mv dane.txt inne/") == -1) {

    //     fprintf(stderr, "Błąd przy przenoszeniu pliku dane.txt.\n");

    //     return 1;

    // }

    // printf("Plik dane.txt został przeniesiony do katalogu 'inne'.\n");



    return 0;

}
