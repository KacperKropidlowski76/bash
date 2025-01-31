#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include <sys/wait.h>
#include <pthread.h>
#include <fcntl.h>
#include <signal.h>

int globalna = [1, 2, 3, 4, 5];

// watek pierwszy pierwszego procesu
void *myThread1(void *arg) {
    printf("Siema tu watek o id: %ld\n", pthread_self());
}

void *myThread2(void *arg) {
    printf("Siema tu watek o id: %ld\n", pthread_self());
}

void *myThread3(void *arg) {
    printf("Siema tu watek o id: %ld\n", pthread_self());
}

void *myThread4(void *arg) {
    printf("Siema tu watek o id: %ld\n", pthread_self());
}

int main(){
    int potomny1 = fork();
    if (potomny1 == 0)
    {
        //id potomnego
        //printf("%d\n", getpid()); // getpid - id aktualnego procesu;
        //id narzednego
        //printf("%d\n", getppid()); // getpid - id parent procesu;
        pthread_t threadId1;
        pthread_t threadId2;
        pthread_create(&threadId1, NULL, myThread1, NULL);
        pthread_create(&threadId2, NULL, myThread2, NULL);
        pthread_join(threadId1, NULL);
        pthread_join(threadId2, NULL);
        return 0;
    }
    
    if (potomny1 > 0)
    {
        //sleep(1);
        int potomny2 = fork();
        if (potomny2 == 0)
        {
            //id potomnego
            // printf("%d\n", getpid());
            //id narzednego
            // printf("%d\n", getppid());
            pthread_t threadId1;
            pthread_t threadId2;
            pthread_create(&threadId1, NULL, myThread3, NULL);
            pthread_create(&threadId2, NULL, myThread4, NULL);
            pthread_join(threadId1, NULL);
            pthread_join(threadId2, NULL);
            return 0;
        }
        //sleep(1);
        // proces nadrzedny
        printf("jd%d\n", getpid());
    }
    return 0;
    
}