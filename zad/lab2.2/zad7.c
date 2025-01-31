#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <signal.h>
#include <semaphore.h>
#include <time.h>

char *swiatlo;

void *myThread(void *arg) {
 printf("Siema tu watek o id: %ld\n", pthread_self());
}

void handlesignalSigUSR1(int s){

}

void *myThread3(void *arg) {
while (1)
{
    swiatlo = "Zielone";
    printf("Swiatlo to %s\n", swiatlo);
    sleep(5);
    swiatlo = "Czerwone";
    printf("Swiatlo to %s\n", swiatlo);
    sleep(5);
}
}

void *myThread4(void *arg) {
 printf("Nadzoruje ruch");
}

int main(){
    int potomny1 = fork();
    if (potomny1 == 0) //pas 1
    {
        pthread_t threadId1;
        pthread_t threadId2;
        pthread_create(&threadId1, NULL, myThread, NULL);
        pthread_create(&threadId2, NULL, myThread, NULL);
        pthread_join(threadId1, NULL);
        pthread_join(threadId2, NULL);
        
        
    }

    if (potomny1 > 0)
    {
        int potomny2 = fork();
        if (potomny2 == 0) //pas 2
        {
            pthread_t threadId3;
            pthread_t threadId4;
            pthread_create(&threadId3, NULL, myThread3, NULL);
            pthread_create(&threadId4, NULL, myThread4, NULL);
            pthread_join(threadId3, NULL);
            pthread_join(threadId4, NULL);
        }
        
        while (1)
        {
            signal(SIGUSR1, handlesignalSigUSR1)
        }
        
        printf("Tu proces glowny, ktory nadzoruje ruch");
    }
    
}