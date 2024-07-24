#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#define BUFFER_SIZE 10  
#define N 20            
int buffer[BUFFER_SIZE];  
int in = 0;               
int out = 0;             
sem_t mutex;   
sem_t full; 
void *producer(void *arg) {
    int item;
    for (int i = 0; i < N; ++i) {
        item = rand() % 100;  
        sem_wait(&full);      
        sem_wait(&mutex);     
        buffer[in] = item;    
        in = (in + 1) % BUFFER_SIZE;  
        sem_post(&mutex);     
        sem_post(&full);    
        printf("Produced item: %d\n", item);
    }
    pthread_exit(NULL);
}

void *consumer(void *arg) {
    int item;
    for (int i = 0; i < N; ++i) {
        sem_wait(&full);      
        sem_wait(&mutex);     
        item = buffer[out];   
        out = (out + 1) % BUFFER_SIZE; 
        sem_post(&mutex);     
        sem_post(&full);      
        printf("Consumed item: %d\n", item);
    }
    pthread_exit(NULL);
}

int main() {
    pthread_t prod_thread, cons_thread;

    sem_init(&mutex, 0, 1);    
    sem_init(&full, 0, BUFFER_SIZE); 

    pthread_create(&prod_thread, NULL, producer, NULL);
    pthread_create(&cons_thread, NULL, consumer, NULL);

    pthread_join(prod_thread, NULL);
    pthread_join(cons_thread, NULL);

    sem_destroy(&mutex);
    sem_destroy(&full);

    return 0;
}
