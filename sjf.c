#include<stdio.h>
#include<stdbool.h>
#include<limits.h>
typedef struct process
{
	int id;
	int at;
	int bt;
	int wt;
	int tat;
	int stt;
	int cot;
	bool ct;
}p;
int main()
{
	int n;
	int current_time=0,completed_time=0,twt=0,ttat=0,time=0;
	p p[100];
	printf("Enter the number of process\n");
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		printf("Enter the arival time\n");
		scanf("%d",&p[i].at);
		printf("Enter burst time\n");
		scanf("%d",&p[i].bt);
		p[i].id=i+1;
		p[i].ct=false;
	}
	while(completed_time<n)
	{
		int minbt=INT_MAX;
		int st=-1;
		for(int i=0;i<n;i++)
		{
			if(!p[i].ct&&p[i].at<=current_time&&p[i].bt<minbt)
			{
				minbt=p[i].bt;
				st=i;
			}
		}
		if(st==-1)
		{
			time++;
		}
		else
		{
			current_time++;
		}
		p[st].stt=time;
		p[st].cot=p[st].stt+p[st].bt;
		p[st].wt=current_time-p[st].at;
		current_time+=p[st].bt;
		p[st].tat=current_time-p[st].at;
		p[st].ct=true;
		completed_time++;
		twt+=p[st].wt;
		ttat+=p[st].tat;
	}
	printf("pid\t\tat\t\tbt\t\tst\t\tct\t\twt\t\ttat\n");
	for(int i=0;i<n;i++)
	{
		printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n",p[i].id,p[i].at,p[i].bt,p[i].stt,p[i].cot,p[i].wt,p[i].tat);
	}
	printf("Average wating time=%f",(float)twt/n);
	printf("\nAverage turn around time=%f",(float)ttat/n);
	}
	
