#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

int flaga = 1;

void handleSignalSIGINT(int s) { //Przec ctrl c
 if (flaga == 1)
 {
 int ida = getpid();
 write(STDOUT_FILENO, "Jestem niesmiertelny!\n", 20); //Wypisuje sie po wcisnieciu ctrl+c
 printf("Moje PID: %d\n", ida);
}
 }
  
void handleSignalSIGHUP(int s) {
flaga = 0;
printf("Ignoruje SIGINT\n");
}

void handleSignalKill(int s) {
printf("Zabijam proces\n");
}

int main() {
signal(SIGINT, handleSignalSIGINT);
signal(SIGHUP, handleSignalSIGHUP);
signal(SIGKILL, handleSignalKill);

 while (1)
 {
    pause();
 }
 
 return 0;
}