#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <signal.h>
#include <semaphore.h>
#include <time.h>
int sigusr1value = 0;
int sigusr2value = 0;

int handlesig1(int s){
    printf("Otrzymalem sygnal SIGUSR1\n");
    sigusr1value = 1;
}

int handlesig2(int s){
    printf("Otrzymalem sygnal SIGUSR2\n");
    sigusr2value = 1;
}

void *myThread1(void *arg) { //watek 1.1
    
    int number1 = 1;
    while (1)
    // for (size_t i = 0; i < 5; i++)    
    {
        FILE *plik = fopen("number1.txt", "a");
        number1 = rand() % 100;
        fprintf(plik, "%d\n", number1);
        sleep(2);
        fclose(plik);
    }
    
}
void *myThread2(void *arg) { //watek 1.2
    
    int number2 = 1;
    while (1)
    // for (size_t i = 0; i < 5; i++)    
    {
        FILE *plik = fopen("number2.txt", "a");
        number2 = rand() % 100;
        fprintf(plik, "%d\n", number2);
        sleep(2);
        fclose(plik);
    }
    
}
void *myThread3(void *arg) { //watek 2.1
    sleep(5);
    int scannum1;
    int ileLiczba;
    FILE *plik = fopen("number1.txt", "r");
    while (fscanf(plik, "%d", &scannum1) == 1) 
    {
        printf("Zeskanowana liczba to1: %d\n", scannum1);
        ileLiczba = scannum1;
        if (scannum1 > 9)
        {
            ileLiczba = ileLiczba/10;
        }        

        if (ileLiczba > 5 && scannum1 % 10 > 5)
        {
            printf("Liczba spelnia wymagania1: %d\n", scannum1);
            printf("Wysylam sygnal SIGUSR1\n");
            sigusr1value = 1;
            signal(SIGUSR1, handlesig1);
            break;
        } 
        sleep(2);
}
        
    }
    fclose(plik);
    

void *myThread4(void *arg) { //watek 2.2
    sleep(6);
    FILE *plik = fopen("number2.txt", "r");
    int ileLiczba;
    int scannum2;
    while (fscanf(plik, "%d", &scannum2) == 1)    
    {
        ileLiczba = scannum2;
        if (scannum2 > 9)
        {
            ileLiczba = ileLiczba/10;
        }    
        printf("Zeskanowana liczba to2: %d\n", scannum2);
        if (ileLiczba < 5 && scannum2 % 10 < 5)
        {
            printf("Wysylam sygnal SIGUSR2\n");
            printf("Liczba spelnia wymagania2: %d\n", scannum2);
            sigusr2value = 1;
            signal(SIGUSR2, handlesig2);
            break;
        } 
        sleep(2);
    }
    fclose(plik);
    
}

int main(){
srand(time(NULL));
int number1 = 1;
int dlgLicz;
int potomny1 = fork();
if (potomny1 == 0) //potomny1
{
    pthread_t threadId1;
    pthread_t threadId2;
    pthread_create(&threadId1, NULL, myThread1, NULL);
    pthread_create(&threadId2, NULL, myThread2, NULL);
    pthread_join(threadId1, NULL);
    pthread_join(threadId2, NULL);
}

if (potomny1 > 0)
{
    int potomny2 = fork();
    if (potomny2 == 0) //potomny 2
    {
        pthread_t threadId3;
        pthread_t threadId4;
        pthread_create(&threadId3, NULL, myThread3, NULL);
        pthread_create(&threadId4, NULL, myThread4, NULL);
        pthread_join(threadId3, NULL);
        pthread_join(threadId4, NULL);
    }
    if (sigusr1value == 1 && sigusr2value == 1)
    {
        printf("Koncze program\n");
        kill(potomny1, SIGKILL);
        kill(potomny2, SIGKILL);
        return 0;
    }
return 0;
    
}
return 0;

}