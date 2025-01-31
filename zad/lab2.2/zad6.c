//pobieranie z pliku, tworzenie n watkow, losowa liczba, id watku
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <time.h>

void *myThread(void *arg) {
    int losowa = 1;
    // int watekID = pthread_self();
    while (losowa % 5 != 0)
    {    
        printf("Moje id: %ld\n", pthread_self());
        losowa = rand()% 50 + 1;
        printf("Losowa: %d\n", losowa);
        sleep(3);
    }
    printf("Koncze watek o id: %ld\n", pthread_self());
    return NULL;
}

int main(){
    int number;
    FILE *pliki = fopen("odczyt.txt", "r");
    fscanf(pliki, "%d", &number);
    printf("%d", number);
    pthread_t threadsID[number];
    srand(time(NULL));

    for (size_t i = 0; i < number; i++)
    {
        pthread_create(&threadsID[i], NULL, myThread, NULL);
    }

    for (size_t i = 0; i < number; i++)
    {
        pthread_join(threadsID[i], NULL);
    }

    
    printf("Koncze proces glowny.");
    
    fclose(pliki);
}