#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

int jd = 1;
int pid;

void handleSigInt(int s){
    if (jd)
    {
        printf("Jestem niesmiertelny!\n");
        pid = getpid();
        printf("Moje id: %d\n", pid);
    }      
}

void handleSigHup(int s){
    printf("Ignoruje sygna SIGINT\n");
        jd = 0;
}

void handleSigKill(int s){
        printf("Zabijam proces o id: %d\n", pid);
}
   

int main(){   
    signal(SIGINT, handleSigInt); // SIGINT - ctrl c
    signal(SIGHUP, handleSigHup); // kill -SIGHUP pid
    signal(SIGKILL, handleSigKill); // kill -SIGKILL pid
    while (1)
    {
        pause();
    }
    
}