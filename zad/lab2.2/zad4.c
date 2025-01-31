// 2 procesy potomne
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <sys/wait.h>
#include <signal.h>

int main(){
    int potomny1 = fork();
    int potomnyID;
    int nadrzednyID;
    int losowa = 1;
    int potom1 = 1;
    int potom2 = 1;
    srand(time(NULL));
    if (potomny1 == 0)
    {
        potomnyID = getpid();
        nadrzednyID = getppid();
        while (potom1 == 1)
        {
            printf("Potomny1 ID: %d\n Nadrzedny1 ID: %d\n", potomnyID, nadrzednyID);
            sleep(2);
        }
        return 0;
    }

    if (potomny1 > 0)
    {
        int potomny2 = fork();
        if (potomny2 == 0)
        {
            potomnyID = getpid();
            nadrzednyID = getppid();
            while (potom2 == 1)
            {
                printf("Potomny2 ID: %d\n Nadrzedny1 ID: %d\n", potomnyID, nadrzednyID);
                sleep(2);
            }
            return 0;
        }
        while (1)
        {
            sleep(2);
            int losowa = rand() % 50 + 1;
            printf("%d\n", losowa);
            if (losowa < 10)
            {
                potom1 = 0;
                printf("Zabijam proces Potomny1\n");
                kill(potomny1, SIGKILL);
            } else if (losowa > 40)
            {
                potom2 = 0;
                printf("Zabijam proces Potomny2\n");
                kill(potomny2, SIGKILL);
            }

            if (potom1 == 0 && potom2 == 0)
            {
                printf("Koncze program\n");
                break;
            }
        }
    return 0;

        
    }

    

    
    
}