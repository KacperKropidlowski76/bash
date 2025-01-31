#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <signal.h>
#include <unistd.h>
#include <sys/wait.h>

int main(){
    int pierwszy = fork();
    wait(NULL);
    int idPotomny;
    int idNadrzedny;
    srand(time(NULL));
    int losowa = 1;

    if (pierwszy == 0){
        idPotomny = getpid(); // potomny id
        idNadrzedny = getppid(); // nadrzedny id
        printf("Potomny Id: %d\nNadrzedny Id: %d\n", idPotomny, idNadrzedny);
        while (losowa % 5 != 0)
        {
        losowa = rand() % 50 + 1;
        printf("Losowa liczba to: %d\n", losowa);
        }
        return 0;
    }
    idNadrzedny = getpid();
    printf("Potomny zakonczyl swoje dzialanie, Nadrzedny id: %d\n", idNadrzedny);
}