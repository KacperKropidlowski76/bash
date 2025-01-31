//FIFO, zapisywanie w pliku, tablica, 2 potomne
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <signal.h>

int main(){
    int potomny1 = fork();
    srand(time(NULL));
    mkfifo("fifo", 0666);
    const char *products[] = {"Mleko", "Chleb", "Masło", "Ser", "Jabłka", "Banany", "Czekolada", "Kawa", "Herbata", "Cukier"};
    int dlgTab = sizeof(products) / sizeof(products[0]); // Dlugosc tablicy
    int dlgProd;
    int losowa = 1;
    char buf[20];
    int fd;
    if (potomny1 == 0) //dostawca
    {
        fd = open("fifo", O_WRONLY);
        while (1)
        {
            losowa = rand() % dlgTab;
            const char *produkt = products[losowa];
            dlgProd = strlen(produkt);
            write(fd, produkt, dlgProd+1);
            printf("Dostawca wysyla: %s\n", produkt);
            sleep(3);
        }
        close(fd);
        exit(0);
    }

    if (potomny1 > 0) // magazynier
    {
        int potomny2 = fork();
        if (potomny2 == 0)
        {
            sleep(1);
            fd = open("fifo", O_RDONLY);
            char buffer[100];
            
            FILE *pliki = fopen("zapis.txt", "a"); //
            while (1) {
                int bytes_read = read(fd, buffer, sizeof(buffer) - 1); // Odczyt danych z FIFO
                if (bytes_read > 0) {
                    buffer[bytes_read] = '\0'; // Dodanie znaku końca stringa
                    printf("Magazynier odbiera: %s\n", buffer);
                    fprintf(pliki, "%s\n", buffer);
                    fflush(pliki);// Wazne do zapisu w pliku z bufora
                }
                sleep(3);
            }
            fclose(pliki);
            close(fd);
            exit(0);
        }
        
        sleep(30);
        printf("Minelo 30 sekun, przerywam program!");
        kill(potomny1, SIGKILL);
        kill(potomny2, SIGKILL);
        return 0;
    }
        return 0;
}