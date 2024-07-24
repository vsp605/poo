#include<stdio.h>
#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/shm.h>
#include<stdlib.h>
#include<unistd.h>
#include<stdio.h>
typedef struct
{
	int turn,flag[2],bal;
}shmpacket;
int main()
{
	int shmid,damt,wamt,sleeptime,option,pid;
	shmpacket* ptr;
	shmid=shmget(200,sizeof(shmpacket),IPC_CREAT|0666);
	ptr=(shmpacket*)shmat(shmid,0,0);
	ptr->bal=5000;
	pid=fork();
	if(pid==0)
	{
		do
		{
			ptr->flag[1]=1;
			ptr->turn=0;
			while((ptr->turn==0)&&(ptr->flag[0]==1));
			printf("c:entering cs\n");
			printf("C: enter a amount to withdraw\n");
			wamt=rand()%1000;
			printf("C:withdraw amt=%d\n",wamt);
			if(ptr->bal-wamt>=1000)
			{
				printf("C:withdraw amt=%d\n",wamt);
				ptr->bal=ptr->bal-wamt;
				printf("C:remaning balance=%d\n",ptr->bal);
			}
			else
			{
				printf("C: withdraw not possible mimimum balance problem\n");
				printf("C:current balance=%d\n",ptr->bal);
			}
			ptr->flag[1]=0;
			sleeptime=rand()%5;
			sleep(sleeptime);
			option=rand()%10;
		}
		while(option!=0);
		exit(0);
	} 
	if(pid>0)
	{
		do
		{
			ptr->flag[0]=1;
			ptr->turn=1;
			while((ptr->turn==1)&&(ptr->flag[1]==1));
			printf("p:entering cs\n");
			printf("p: enter a amount to deposit\n");
			damt=rand()%1000;
			printf("p:depositamt=%d\n",damt);
			ptr->bal=ptr->bal+damt;
			printf("p:balance amt=%d\n",ptr->bal);
			ptr->flag[0]=0;
			sleeptime=rand()%5;
			sleep(sleeptime);
			option=rand()%10;
		}
		while(option!=0);
		exit(0);
	}
} 
			
