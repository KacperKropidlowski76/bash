#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <signal.h>
#include <semaphore.h>
#include <time.h>

#define SIZE 50

// Globalne zmienne
int distance[SIZE] = {0};   // Tablica odległości pojazdów
int green_light = 0;        // 1 = zielone, 0 = czerwone
sem_t semaphore;            // Semafor do synchronizacji

// Funkcja wątku zmieniającego światła
void *change_light(void *arg) {
    while (1) {
        sleep(5);  // Zmiana świateł co 5 sekund
        sem_wait(&semaphore);  // Synchronizacja
        green_light = !green_light;  // Zmiana świateł
        printf("Światło zmienione na: %s\n", green_light ? "Zielone" : "Czerwone");
        sem_post(&semaphore);
    }
    return NULL;
}

// Funkcja wątku symulującego ruch pojazdów
void *move_vehicles(void *arg) {
    while (1) {
        sem_wait(&semaphore);
        if (green_light) {
            for (int i = 0; i < SIZE; i++) {
                if (distance[i] > 0) {
                    distance[i]--;
                    printf("Pojazd na pozycji %d, odległość: %d\n", i, distance[i]);
                }
            }
        }
        sem_post(&semaphore);
        sleep(1);
    }
    return NULL;
}

// Obsługa sygnału SIGUSR1
void handle_signal(int sig) {
    sem_wait(&semaphore);
    if (distance[0] == 50) {
        printf("Wypadek! Pojazd już znajduje się na pozycji 50.\n");
        exit(1);
    } else {
        distance[0] = 50;
        printf("Pojazd dodany na pozycji 50.\n");
    }
    sem_post(&semaphore);
}

int main() {
    // Inicjalizacja semafora
    sem_init(&semaphore, 0, 1);

    // Tworzenie procesów potomnych
    pid_t pid1 = fork();
    if (pid1 == 0) {
        // Proces potomny 1
        signal(SIGUSR1, handle_signal);

        pthread_t light_thread, vehicle_thread;
        pthread_create(&light_thread, NULL, change_light, NULL);
        pthread_create(&vehicle_thread, NULL, move_vehicles, NULL);

        pthread_join(light_thread, NULL);
        pthread_join(vehicle_thread, NULL);
        exit(0);
    }

    pid_t pid2 = fork();
    if (pid2 == 0) {
        // Proces potomny 2
        signal(SIGUSR1, handle_signal);

        pthread_t light_thread, vehicle_thread;
        pthread_create(&light_thread, NULL, change_light, NULL);
        pthread_create(&vehicle_thread, NULL, move_vehicles, NULL);

        pthread_join(light_thread, NULL);
        pthread_join(vehicle_thread, NULL);
        exit(0);
    }

    // Proces nadrzędny
    srand(time(NULL));
    while (1) {
        sleep(10);
        int random_pid = rand() % 2 == 0 ? pid1 : pid2;
        printf("Wysyłanie sygnału SIGUSR1 do procesu %d\n", random_pid);
        kill(random_pid, SIGUSR1);
    }

    return 0;
}
