#include <stdio.h>
#include <string.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <unistd.h>
int main()
{
	key_t key=ftok("Consumer |.c",165);
	int shmid=shmget(key,10*sizeof(int),IPC_CREAT|0660);
	if(shmid>0)
	printf("It is okshm id=%d\n",shmid);
	int *ptr=(int*)(shmat(shmid,0,0));
	printf("Write Data:");
	for(int i=0;i<10;i++)
	{
		scanf("%d",ptr+i);
	}
	printf("Data written in memory intially\n");
	for(int i=0;i<10;i++)
	{
		printf("%d",*(ptr+i));
	}
	int pid=fork();
	if(pid==0)
	{
		printf("Child data read from shared memory:\n");
		for(int i=0;i<10;i++)
		{
			printf("child:%d\n",*(ptr+i));
		}
		printf("child:I am going to update\n");
		for(int i=0;i<10;i++)
		{
			*(ptr+i)+=i;
			printf("child %d\n",*(ptr+i));
		}
		sleep(60);
		printf("child:I am going to display updated copy by parent\n");
		for(int i=0;i<10;i++)
		{
			printf("child:%d\n",*(ptr+i));
		}
	}
		else
		{
			sleep(10);
			printf("p:I am reading shared memory\n");
			for(int i=0;i<10;i++)
			{
				printf("parent:%d\n",*(ptr+i));
			}
			sleep(10);
			printf("parent:I am going to update\n");
			for(int i=0;i<10;i++)
			{
				*(ptr+i)+=20;
				printf("parent:%d\n",*(ptr+i));
			}
			sleep(5);
		}
		shmdt(ptr);
		return 0;
	}
		
