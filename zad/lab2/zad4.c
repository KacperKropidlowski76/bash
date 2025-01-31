#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <sys/wait.h>
#include <signal.h>

int main(){
    
    
    srand(time(NULL));
    int id1 = fork();
    if (id1 == 0){
        while (1)
        //for (size_t i = 0; i < 10; i++)      
        {
            printf("Potomny1 id: %d\n", getpid());
            printf("Nadrzedny1 id: %d\n", getppid());
            sleep(2);
        }
        return 0;
    }

    if (id1 > 0) {
        int id2 = fork();
        if (id2 == 0)
        {
            while (1)
            //for (size_t i = 0; i < 10; i++)    
            {
                printf("Potomny2 id: %d\n", getpid());
                printf("Nadrzedny2 id: %d\n", getppid());
                sleep(2);
            }
            return 0;
        }
    

        while (1)
        {
            int liczba = 0;
            liczba = rand() % 50 + 1;
            printf("%d\n", liczba);
            if (liczba < 10 && id1 > 0)
            {
                printf("Zabijam proces o id: %d\n", id1);
                kill(id1, SIGKILL);
                id1 = -1;
            }

            if (liczba > 40 && id2 > 0)
            {
                printf("Zabijam proces od id: %d\n", id2);
                kill(id2, SIGKILL);
                id2 = -1;
            }

            if (id1 == -1 && id2 == -1){
                printf("Zakończono oba procesy potomne. Proces nadrzędny kończy działanie.\n");
                break;
            }
            sleep(1);        
        }
    }
    return 0;
    
}