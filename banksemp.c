#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <semaphore.h>
#include <fcntl.h>
typedef struct
{
    int turn,bal;
} shmpacket;
int main() 
{
    int shmid,damt,wamt,sleeptime,option,pid;
    shmpacket* ptr;
    sem_t *mutex;
    shmid=shmget(200,sizeof(shmpacket),IPC_CREAT|0666);
    if (shmid<0) 
    {
        perror("shmget");
        exit(1);
    }
    ptr=(shmpacket*)shmat(shmid,0,0);
    if (ptr == (void*)-1)
     {
        perror("shmat");
        exit(1);
    }
    ptr->bal=5000;
    ptr->turn=0;
    mutex=sem_open("/mutex",O_CREAT|O_EXCL,0644,1);
    if(mutex==SEM_FAILED)
     {
        perror("sem_open");
        exit(1);
    }
    pid=fork();
    if(pid==0) 
    {
        do 
        {
            sem_wait(mutex);
            ptr->turn =0;
            sem_post(mutex);
            printf("c: entering cs\n");
            printf("C: enter an amount to withdraw\n");
            wamt = rand()%1000;
            printf("C: withdraw amt=%d\n",wamt);
            sem_wait(mutex);
            if (ptr->bal-wamt>=1000)
             {
                ptr->bal=ptr->bal-wamt;
                printf("C: remaining balance=%d\n",ptr->bal);
            } else 
            {
                printf("C: withdraw not possible minimum balance problem\n");
                printf("C: current balance=%d\n",ptr->bal);
            }
            sem_post(mutex);
            sleeptime=rand()%5;
            sleep(sleeptime);
            option = rand()%10;
        } while (option!=0);

        exit(0);
    } else if (pid>0) 
    {
        do 
        {
            sem_wait(mutex);
            ptr->turn=1;
            sem_post(mutex);
            
            printf("p: entering cs\n");
            printf("p: enter an amount to deposit\n");
            damt = rand()%1000;
            printf("p: deposit amt=%d\n",damt);
            sem_wait(mutex);
            ptr->bal=ptr->bal+damt;
            printf("p: balance amt=%d\n",ptr->bal);
            sem_post(mutex);
            sleeptime=rand()%5;
            sleep(sleeptime);
            option = rand()%10;
        } while (option!=0);

        exit(0);
    } else 
    {
        perror("fork");
        exit(0);
    }
    shmdt(ptr);
    shmctl(shmid, IPC_RMID, NULL);
    sem_unlink("/mutex");
    return 0;
}
