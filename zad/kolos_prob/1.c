#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <sys/wait.h>
#include <signal.h>
#include <pthread.h>

void handleSignalUSR1(int s) {
printf("Zabijam proces\n");
}

void handleSignalUSR2(int s) {
printf("Zabijam proces\n");
}

void *myThread1(void *arg) {
    int number;
    for (size_t i = 0; i < 10; i++)
    {
        sleep(2);
        number = rand() % 100;
        FILE *file;
        printf("%d\n", number);

        file = fopen("number1.txt", "a");
        fprintf(file, "%d\n", number);
        fclose(file);
    }
    return NULL;

}

void *myThread2(void *arg) {
 int number;
    for (size_t i = 0; i < 10; i++)
    {
        sleep(2);
        number = rand() % 100;
        FILE *file;
        printf("%d\n", number);

        file = fopen("number2.txt", "a");
        fprintf(file, "%d\n", number);
        fclose(file);
    }
    return NULL;
}

void *myThread3(void *arg) { //Pierwszy watek drugiego procesu
    int number;
    int tab[50] = {};
    for (size_t i = 0; i < 10; i++)
    {
        sleep(2);
        number = rand() % 100;
        FILE *file;
        printf("%d\n", number);

        file = fopen("number1.txt", "r");
        while (fscanf(file, "%d", &number) == 1){
            if (number > 5)
            {
                signal(SIGUSR1, handleSignalUSR1);
            }
            
            sleep(2);
        }
        fclose(file);
        
    }
    return NULL;

}

void *myThread4(void *arg) { //Pierwszy watek drugiego procesu
    int number;
    int tab[50] = {};
    for (size_t i = 0; i < 10; i++)
    {
        sleep(2);
        number = rand() % 100;
        FILE *file;
        printf("%d\n", number);

        file = fopen("number2.txt", "r");
        while (fscanf(file, "%d", &number) == 1){
            if (number < 5)
            {
                signal(SIGUSR2, handleSignalUSR2);
            }
            
            sleep(2);
        }
        fclose(file);
        
    }
    return NULL;

}

int main(){
    srand(time(NULL));
    int id1 = fork();
    if (id1 == 0)
    {
        pthread_t threadId1;
        pthread_t threadId2;
        pthread_create(&threadId1, NULL, myThread1, NULL);
        pthread_create(&threadId2, NULL, myThread2, NULL);
        pthread_join(threadId1, NULL);
        pthread_join(threadId2, NULL);
    }

    if (id1 > 0)
    {
        int id2 = fork();
        if (id2 == 0)
        {
            pthread_t threadId3;
            pthread_t threadId4;
            pthread_create(&threadId3, NULL, myThread1, NULL);
            pthread_create(&threadId4, NULL, myThread2, NULL);
            pthread_join(threadId3, NULL);
            pthread_join(threadId4, NULL);
        }
        
    }
}