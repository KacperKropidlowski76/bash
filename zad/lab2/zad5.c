#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <signal.h>

int main() {
    srand(time(NULL));
    const char *products[] = {"Mleko", "Chleb", "Masło", "Ser", "Jabłka", "Banany", "Czekolada", "Kawa", "Herbata", "Cukier"};
    char *fifo = "losowo";
    int fd;
    char buf[50];
    mkfifo(fifo, 0666);

    int id1 = fork();
    if (id1 == 0) {  // Dostawca
        fd = open(fifo, O_WRONLY);
        while (1) {
            const char *product = products[rand() % 10];
            write(fd, product, strlen(product));
            printf("Dostawca wyslal: %s\n", product);
            sleep(1);
        }
        close(fd);
        return 0;
    }

    if (id1 > 0) {
        int id2 = fork();
        if (id2 == 0) {  // Magazynier
            fd = open(fifo, O_RDONLY);
            while (1) {
                memset(buf, 0, sizeof(buf));
                int bytesRead = read(fd, buf, sizeof(buf) - 1);
                if (bytesRead > 0) {
                    buf[bytesRead] = '\0';
                    printf("Magazynier odebral: %s\n", buf);
                }
            }
            close(fd);
            return 0;
        }

        // Proces główny
        for (size_t i = 0; i < 5; i++) {
            sleep(2);
        }

        printf("Zabijam proces o id: %d i %d\n", id1, id2);
        kill(id1, SIGKILL);
        kill(id2, SIGKILL);
        unlink(fifo);
    }

    return 0;
}
