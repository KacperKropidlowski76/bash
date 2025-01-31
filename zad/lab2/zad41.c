#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <sys/wait.h>
#include <signal.h>

int main() {
    srand(time(NULL));  // Ustawienie ziarna losowości

    // Tworzenie pierwszego procesu potomnego
    pid_t id1 = fork();
    if (id1 == 0) {
        // Kod procesu potomnego 1
        while (1) {
            printf("Potomny1 - ID: %d, Nadrzędny - ID: %d\n", getpid(), getppid());
            sleep(2);
        }
        return 0;
    }

    if (id1 > 0) {
        // Tworzenie drugiego procesu potomnego tylko przez proces nadrzędny
        pid_t id2 = fork();
        if (id2 == 0) {
            // Kod procesu potomnego 2
            while (1) {
                printf("Potomny2 - ID: %d, Nadrzędny - ID: %d\n", getpid(), getppid());
                sleep(2);
            }
            return 0;
        }

        // Kod procesu nadrzędnego
        printf("Proces nadrzędny - ID: %d\n", getpid());

        while (1) {
            int liczba = rand() % 50 + 1;
            printf("Wylosowana liczba: %d\n", liczba);

            if (liczba < 10 && id1 > 0) {
                printf("Zabijam proces potomny 1 - ID: %d\n", id1);
                kill(id1, SIGKILL);
                id1 = -1;  // Ustawiamy, że proces został zakończony
            } else if (liczba > 40 && id2 > 0) {
                printf("Zabijam proces potomny 2 - ID: %d\n", id2);
                kill(id2, SIGKILL);
                id2 = -1;  // Ustawiamy, że proces został zakończony
            }         

        
            if (id1 == -1 && id2 == -1) {
                printf("Zakończono oba procesy potomne. Proces nadrzędny kończy działanie.\n");
                break;
            }

            sleep(1);
        }
    }

    return 0;
}
