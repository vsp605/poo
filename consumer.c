#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>  
#define BUFFER_SIZE 5
int buffer[BUFFER_SIZE];
sem_t mutex,full,empty;
int in=0,out=0;
void *producer(void *arg)
 {
	 
    while (1) 
    {
        int item=rand()%100+1;  
        sleep(rand()%2+1);       
        sem_wait(&empty);
        sem_wait(&mutex);
        buffer[in]=item;
        printf("Produced: %d\n",item);
        in=(in+1)%BUFFER_SIZE;     
        sem_post(&mutex);
        sem_post(&full);
    }
    return NULL;
}
void *consumer(void *arg) 
{
    while (1)
     {
        sleep(rand()%2+1);       
        sem_wait(&full);
        sem_wait(&mutex);
        int item=buffer[out];
        printf("Consumed: %d\n",item);
        out=(out+1)%BUFFER_SIZE;
        sem_post(&mutex);
        sem_post(&empty);
    }
    return NULL;
}
int main() {
    pthread_t prod_thread,cons_thread;
    sem_init(&mutex,0,1);
    sem_init(&full,0,0);
    sem_init(&empty,0,BUFFER_SIZE);
    pthread_create(&prod_thread, NULL,producer,NULL);
    while (1) {
    }
    pthread_join(prod_thread,NULL);
    pthread_join(cons_thread,NULL);
    sem_destroy(&mutex);
    sem_destroy(&full);
    sem_destroy(&empty);
    return 0;
}
