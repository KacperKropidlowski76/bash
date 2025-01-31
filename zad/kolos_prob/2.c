#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <pthread.h>
#include <semaphore.h>

int globalna = -1; // Zmienna globalna do współdzielenia między wątkami
sem_t sem;         // Semafor

void *myThread(void *arg) {
    int liczba = -1; // Lokalna zmienna wątku
    printf("Watek id: %ld startuje\n", pthread_self());
    sem_wait(&sem);
    while (1) {
         // Czekaj na wejście do sekcji krytycznej (tylko 3 wątki w tym samym czasie)

        // Sekcja krytyczna
        liczba = rand() % 100; // Losowanie liczby
        printf("Watek id: %ld wylosowal: %d\n", pthread_self(), liczba);

        if (liczba == globalna) { // Jeśli liczba pasuje do globalnej
            printf("Watek id: %ld konczy prace (liczba == globalna: %d)\n", pthread_self(), liczba);
            sem_post(&sem); // Zwolnij semafor
            break;          // Wyjdź z pętli i zakończ wątek
        }

        globalna = liczba; // Ustawienie globalnej liczby
           // Zwolnienie semafora

        sleep(3); // Symulacja czasu pracy wątku
    }
    return NULL;
    sem_post(&sem);
}

int main() {
    int number = 10; // Liczba wątków
    pthread_t threadsID[number];
    sem_init(&sem, 0, 3); // Semafor ogranicza do 3 równoczesnych wątków
    srand(time(NULL));    // Inicjalizacja generatora liczb pseudolosowych

    // Tworzenie wątków
    for (int i = 0; i < number; i++) {
        pthread_create(&threadsID[i], NULL, myThread, NULL);
    }

    // Czekanie na zakończenie wątków
    for (int i = 0; i < number; i++) {
        pthread_join(threadsID[i], NULL);
    }

    sem_destroy(&sem); // Usunięcie semafora
    printf("Brak procesow, koncze program!\n");
    return 0;
}
