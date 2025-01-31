#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <sys/wait.h>
#include <signal.h>
#include <pthread.h>
#include <semaphore.h>

int globalna;
sem_t sem;  


void *myThread(void *arg) {
    sem_wait(&sem);
    int liczba;
    printf("Rozpoczynam watek o id: %ld\n", pthread_self());

    
    sleep(2);
    while (liczba != globalna)
    {
        liczba = rand()%100;
        globalna = liczba;
        sleep(2);
        printf("Losowanie %d liczba\n", liczba);
    }
    sleep(1);
    printf("Koncze proces o id: %ld\n", pthread_self());
    sem_post(&sem);
    return NULL;
}

int main(){
    int number = 10;
    pthread_t threadsID[number];
    sem_init(&sem, 0, 3); 
    srand(time(NULL));

    for (size_t i = 0; i < number; i++)
    {
        pthread_create(&threadsID[i], NULL, myThread, NULL);
    }

    for (size_t i = 0; i < number; i++)
    {
        pthread_join(threadsID[i], NULL);
    }
    sem_destroy(&sem);
    printf("Brak procesow, koncze program!\n");
    return 0;

}