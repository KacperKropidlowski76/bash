#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <signal.h>
#include <unistd.h>
#include <sys/wait.h>

int main(){
    // Tworzymy proces potomny
    int id = fork();
    if (id == 0){
        // Proces potomny
        printf("Proces potomny - id: %d\n", getpid());
        printf("Proces nadrzedny - id: %d\n", getppid());

        // Ustawienie ziarna dla generatora liczb losowych
        srand(time(NULL));
        // Losowanie liczb z zakresu [1; 50]
        int randomowa = 1;
        while (randomowa % 5 != 0){
            randomowa = rand() % 50 + 1;
            printf("Liczba to: %d\n", randomowa);
                }
    } else {
        // Proces nadrzędny
        wait(NULL);  // Czekamy na zakończenie procesu potomnego
        printf("Proces nadrzedny: %d\n", getpid());
    }
    return 0;
    }
    

