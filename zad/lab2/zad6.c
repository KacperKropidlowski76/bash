#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <time.h>

int odczLicz(){
FILE *file;
    int number;

    // Otwieramy plik do odczytu
    file = fopen("plik", "r");
    if (file == NULL) {
        printf("Nie można otworzyć pliku!\n");
        return 1;
    }

    // Odczytujemy liczbę z pliku
    fscanf(file, "%d", &number);
    //printf("Odczytana liczba: %d\n", number);
    fclose(file);
    return number;
    // Zamykamy plik
}

void *myThread(void *arg) {
    int number = 1;
    while (number % 5 != 0)
    {
        printf("Watek id: %ld\n", pthread_self());
        number = rand() % 50 + 1;
        printf("%d\n", number);
        sleep(2);
    }
    
    printf("Wątek kończy działanie. ID wątku: %ld\n", pthread_self());
    return NULL;
}


int main() {
    srand(time(NULL));
    pthread_t threads[odczLicz()];

    for (size_t i = 0; i < odczLicz(); i++) {
        pthread_create(&threads[i], NULL, myThread, NULL);
    }

    for (size_t i = 0; i < odczLicz(); i++) {
        pthread_join(threads[i], NULL);
    }
    return 0;
} 
