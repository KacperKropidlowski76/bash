#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include <sys/wait.h>
#include <pthread.h>
#include <fcntl.h>
#include <signal.h>

int sigusr1 = 0;
int sigusr2 = 0;

const char *tablica[] = {0, 0, 0, 0, 0};

int handlesig1(int s){
    printf("Otrzymalem sygnal SIGUSR1\n");
    sigusr1 = 1;
}

int handlesig2(int s){
    printf("Otrzymalem sygnal SIGUSR2\n");
    sigusr1 = 2;
}

void *myThread1(void *arg) { //watek 1.1

    int number1 = 1;
    int number2 = 1;
    int number3 = 1;
    int number4 = 1;
    int number5 = 1;
    while (1)
    {
        number1 = rand()%1000;
        number2 = rand()%1000;
        number3 = rand()%1000;
        number4 = rand()%1000;
        number5 = rand()%1000;
        tablica[0] = number1;
        tablica[1] = number2;
        tablica[2] = number3;
        tablica[3] = number4;
        tablica[4] = number5;
        sleep(10);
    }

}
void *myThread2(void *arg) { //watek 1.2
    int licz;
    int liczpom;
    while (1)
    {
        for (size_t i = 0; i < 5; i++)
        {
            licz = tablica[i];
            liczpom = licz / 10;
            if ((licz < 100 && licz > 9) && liczpom == 7)
            {
                signal(SIGUSR1, handlesig1);
            }
            sleep(5);
        }
    }

}
void *myThread3(void *arg) { //watek 2.1

    int number1 = 1;
    int number2 = 1;
    int number3 = 1;
    int number4 = 1;
    int number5 = 1;
    while (1)
    {
        number1 = rand()%1000;
        number2 = rand()%1000;
        number3 = rand()%1000;
        number4 = rand()%1000;
        number5 = rand()%1000;
        tablica[0] = number1;
        tablica[1] = number2;
        tablica[2] = number3;
        tablica[3] = number4;
        tablica[4] = number5;
        sleep(5);
    }

}
void *myThread4(void *arg) { //watek 1.2
    int licz;
    int liczpom;
    while (1)
    {
    for (size_t i = 0; i < 5; i++)
    {
        licz = tablica[i];
        if ((licz < 100 && licz > 9) && liczpom == 7)
        {
            signal(SIGUSR2, handlesig2);
        }
        sleep(5);
    }
    }

}

int main(){
    int potomny1 = fork();
    srand(time(NULL));
    if (potomny1 == 0)
    {
    pthread_t threadId1;
    pthread_t threadId2;
    pthread_create(&threadId1, NULL, myThread1, NULL);
    pthread_create(&threadId2, NULL, myThread2, NULL);
    pthread_join(threadId1, NULL);
    pthread_join(threadId2, NULL);
}
        //id potomnego
        printf("%d\n", getpid()); // getpid - id aktualnego procesu;
        //id narzednego
        printf("%d\n", getppid()); // getpid - id parent procesu;
        /* code */
        return 0;

    if (potomny1 > 0)
    {
        sleep(1);
        int potomny2 = fork();
        if (potomny2 == 0)
        {
            pthread_t threadId3;
            pthread_t threadId4;
            pthread_create(&threadId3, NULL, myThread3, NULL);
            pthread_create(&threadId4, NULL, myThread4, NULL);
            pthread_join(threadId3, NULL);
            pthread_join(threadId4, NULL);
            //id potomnego
            printf("%d\n", getpid());
            //id narzednego
            printf("%d\n", getppid());
            /* code */
            return 0;
        }
        sleep(1);
        // proces nadrzedny
        handlesig1;
        handlesig2;

    if (sigusr1 == 1 && sigusr2 == 1)
    {
        printf("Koncze program\n");
        kill(potomny1, SIGKILL);
        kill(potomny2, SIGKILL);
        return 0;
        exit;
    }


    }
}