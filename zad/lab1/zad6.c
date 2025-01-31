#include <stdio.h>

#include <stdlib.h>



int main() {

    int wybor;
    printf("Jezeli chcesz uzyc tar - wybierz [1], jezeli chcesz uzyc zip - wybierz [2]: \n");
    scanf("%d", &wybor);

    if (wybor == 1)
    {
        system("tar -cvf temp.tar temp/");
    } else if (wybor == 2) {
        system("zip -r temp.zip temp/");
    }

    return 0;
}





// #include <stdio.h>

// #include <stdlib.h>



// int main() {

//     int choice;



//     // Zapytanie o wybór formatu archiwum

//     printf("Wybierz format archiwum:\n");

//     printf("1. .tar\n");

//     printf("2. .zip\n");

//     printf("Wybierz (1 lub 2): ");

//     scanf("%d", &choice);



//     // Tworzenie katalogu 'temp' (jeśli nie istnieje)

//     if (system("mkdir -p temp") != 0) {

//         fprintf(stderr, "Błąd przy tworzeniu katalogu temp.\n");

//         return 1;

//     }



//     // Wybór odpowiedniego polecenia w zależności od formatu

//     if (choice == 1) {

//         // Tworzenie archiwum tar

//         if (system("tar -cvf temp.tar temp/") != 0) {

//             fprintf(stderr, "Błąd przy tworzeniu archiwum .tar.\n");

//             return 1;

//         }

//         printf("Archiwum .tar zostało utworzone: temp.tar\n");

//     } else if (choice == 2) {

//         // Tworzenie archiwum zip

//         if (system("zip -r temp.zip temp/") != 0) {

//             fprintf(stderr, "Błąd przy tworzeniu archiwum .zip.\n");

//             return 1;

//         }

//         printf("Archiwum .zip zostało utworzone: temp.zip\n");

//     } else {

//         fprintf(stderr, "Błędny wybór.\n");

//         return 1;

//     }



//     return 0;

// }
