// #include <cstddef>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include <sys/wait.h>
#include <pthread.h>
#include <fcntl.h>
#include <signal.h>

static int tablica[5];

int zmienna1=0;
int zmienna2=0;

void handleSigUsr1(int s){
    zmienna1 = 1;
}

void handleSigUsr2(int s){
    zmienna2 = 1;    
}


void *myThread1(void *arg) {
    while (1) {
        for (size_t i = 0; i < 5; i++)
        {
            tablica[i] = rand() % 100;
            printf("Losowa z potom1: %d\n", tablica[i]);
        }
        sleep(5);
    }
}

void *myThread2(void *arg) {
    sleep(1);
    int nadrzednyID = getppid();
    printf("Nadrzedny id: %d\n", nadrzednyID);
    while (1) {
        for (size_t i = 0; i < 5; i++)
        {
            printf("sprawdzenie tablicy1: %d\n", tablica[i]);
            if (tablica[i] >= 70 && tablica[i] <= 79)
            {
                kill(nadrzednyID, SIGUSR1);
            }
        }
        sleep(5);
    }
}

void *myThread3(void *arg) {
    while (1) {
        for (size_t i = 0; i < 5; i++)
        {
            tablica[i] = rand() % 100;
            printf("Losowa z potom2: %d\n", tablica[i]);
        }
        sleep(5);
    }
}

void *myThread4(void *arg) {
    sleep(1);
    int nadrzednyID = getppid();
    printf("Nadrzedny id: %d\n", nadrzednyID);
    while (1) {
        for (size_t i = 0; i < 5; i++)
        {
            printf("sprawdzenie tablicy2: %d\n", tablica[i]);
            if (tablica[i] >= 70 && tablica[i] <= 79)
            {
                kill(nadrzednyID, SIGUSR2);
            }
        }
        sleep(5);
    }
}



int main(){
    int potomny1 = fork();
    srand(time(NULL));
    if (potomny1 == 0)
    {
        pthread_t threadsID1;
        pthread_t threadsID2;
        pthread_create(&threadsID1, NULL, myThread1, NULL);
        pthread_create(&threadsID2, NULL, myThread2, NULL);
        pthread_join(threadsID1, NULL);
        pthread_join(threadsID2, NULL);
    }
    if (potomny1 > 0)
    {
        int potomny2 = fork();
        if (potomny2 == 0)
        {
            pthread_t threadsID3;
            pthread_t threadsID4;
            pthread_create(&threadsID3, NULL, myThread3, NULL);
            pthread_create(&threadsID4, NULL, myThread4, NULL);
            pthread_join(threadsID3, NULL);
            pthread_join(threadsID4, NULL);
        }
        //nadrzedny
        signal(SIGUSR1, handleSigUsr1);
        signal(SIGUSR2, handleSigUsr2);
        while (zmienna1 == 0 || zmienna2 == 0) {
            pause();  // czekaj na sygnał
            printf("Koncze proces potomny 1\n");
            kill (potomny1, SIGKILL);
            printf("Koncze proces potomny 2\n");
            kill (potomny2, SIGKILL);
            printf("Koncze proces glowny\n");
            kill (potomny1, SIGKILL);
        }
    }
}