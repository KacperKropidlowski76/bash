#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <signal.h>
#include <sys/stat.h>

const char *products[] = {"Mleko", "Chleb", "Masło", "Ser", "Jabłka", "Banany", "Czekolada", "Kawa", "Herbata", "Cukier"};

int main() {
    char *fifo = "losowo";

    // Tworzenie pliku FIFO
    mkfifo(fifo, 0666);

    // Tworzenie pierwszego procesu potomnego (dostawca)
    pid_t id1 = fork();
    if (id1 == 0) {
        // Proces dostawcy
        srand(time(NULL));
        int fd = open(fifo, O_WRONLY);
        while (1) {
            // Losowanie produktu
            int index = rand() % 10;
            const char *product = products[index];

            // Wysyłanie produktu do FIFO
            write(fd, product, sizeof(products[index]));
            printf("Dostawca wysłał: %s\n", product);

            sleep(2);
        }
        close(fd);
        return 0;
    }

    // Tworzenie drugiego procesu potomnego (magazynier)
    pid_t id2 = fork();
    if (id2 == 0) {
        // Proces magazyniera
        int fd = open(fifo, O_RDONLY);
        FILE *file = fopen("produkty.txt", "a");
        char buf[100];

        while (1) {
            // Odbieranie produktu z FIFO
            int bytesRead = read(fd, buf, sizeof(buf));
            if (bytesRead == 0) {
                // Koniec pliku FIFO – kończymy działanie
                printf("Magazynier: Koniec danych w FIFO. Kończę działanie.\n");
                break;
            }

            printf("Magazynier odebrał: %s\n", buf);

            // Zapis do pliku
            fprintf(file, "%s\n", buf);
            fflush(file);
        }

        fclose(file);
        close(fd);
        return 0;
    }

    // Proces główny
    for (int i = 0; i < 15; i++) {
        sleep(1);
    }

    // Zamykanie procesów potomnych
    printf("Zabijam procesy potomne: %d i %d\n", id1, id2);
    kill(id1, SIGKILL);
    kill(id2, SIGKILL);

    // Usuwanie pliku FIFO
    unlink(fifo);

    return 0;
}
