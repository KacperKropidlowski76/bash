#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <signal.h>
#include <semaphore.h>
#include <time.h>
#include <sys/wait.h>
#include <fcntl.h>

void pom(){
srand(time(NULL));
int losowa = rand() % 50 + 1;
mkfifo("fifo", 0666);
fd = open("fifo", O_WRONLY);
write(fd, produkt, dlgProd+1);
close(fd);
FILE *pliki = fopen("zapis.txt", "a");
fprintf(pliki, "%d\n", zapis.txt);
while (fscanf(pliki, "%d", &zmienna) == 1);
fflush(pliki);
fclose(pliki);
kill(potomny1, SIGKILL);
sem_wait(&sem);
sem_post(&sem);
sem_init(&sem, 0, 3); 
sem_destroy(&sem);
}


int main(){
    int potomny1 = fork();
    if (potomny1 == 0)
    {
        //id potomnego
        printf("%d\n", getpid()); // getpid - id aktualnego procesu;
        //id narzednego
        printf("%d\n", getppid()); // getpid - id parent procesu;
        /* code */
        return 0;
    }
    
    if (potomny1 > 0)
    {
        //sleep(1);
        int potomny2 = fork();
        if (potomny2 == 0)
        {
            //id potomnego
            printf("%d\n", getpid());
            //id narzednego
            printf("%d\n", getppid());
            /* code */
            return 0;
        }
        //sleep(1);
        // proces nadrzedny
        printf("jd%d\n", getpid());
    }
    return 0;
    
}