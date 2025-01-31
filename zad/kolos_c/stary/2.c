#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include <sys/wait.h>
#include <pthread.h>
#include <fcntl.h>
#include <signal.h>
#include <semaphore.h>

sem_t sem;

int losowanie(int liczbaUjemnych, int liczba){
    for (size_t i = 0; i < 50; i++)
    {
        liczba = rand()%200 - 100;
        if (liczba < 0)
        {
            liczbaUjemnych = liczbaUjemnych + 1;
        }
        //sleep(1);
    }
    return liczbaUjemnych;
}

void *myThread(void *arg) {
    sem_wait(&sem);
    int liczba;
    int liczbaUjemnych;
    int liczbaSkanowana;
    int liczbaUjemnychSkanowanych;
    printf("Rozpoczynam watek o id: %ld\n", pthread_self());
    FILE *plik = fopen("liczba.txt", "r");
    while (fscanf(plik, "%d", &liczbaSkanowana) == 1)
    {
        if (liczbaSkanowana < 0)
        {
            liczbaUjemnychSkanowanych = liczbaUjemnychSkanowanych + 1;
        }
        //printf("liczba zeskanowanych %d\n", liczbaUjemnychSkanowanych);
    }
    fclose(plik);
    FILE *plik2 = fopen("liczba.txt", "a");

    sleep(2);
    losowanie(liczbaUjemnych, liczba);
    for (size_t i = 0; i < 50; i++)
    {
        liczba = rand()%200 - 100;
        if (liczba < 0)
        {
            liczbaUjemnych = liczbaUjemnych + 1;
        }
        //sleep(1);
        //printf("%d\n", liczba);
    }

    if (liczbaUjemnych < liczbaUjemnychSkanowanych)
        {
            fprintf(plik2, "%d\n", liczba);
        } else if (liczbaUjemnych == liczbaUjemnychSkanowanych)
        {
            printf("Błąd\n");
            losowanie(liczbaUjemnych, liczba);
        }


    printf("Koncze proces o id: %ld\n", pthread_self());
    fclose(plik2);
    sem_post(&sem);
    return NULL;
}

int main(){
    int number = 10;
    pthread_t threadsID[number];
    sem_init(&sem, 0, 2);
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