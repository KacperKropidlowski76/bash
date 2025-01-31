#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <signal.h>
#include <semaphore.h>
#include <time.h>

int main(){
    int liczba = 85;
    int ileLiczba = liczba;
        if (liczba > 9)
        {
            ileLiczba = ileLiczba/10;
        }        

        if (ileLiczba > 5 && liczba % 10 > 5)
        {
            printf("Wszystkie cyfry sa wieksze od 5");
        } else if (ileLiczba < 5 && liczba % 10 < 5)
        {
            printf("Wszystkie liczby sa mniejsze od 5");
        } else {
            printf("Jedna z liczb nie jest");
        }    
}