#include<stdio.h>
#include<stdbool.h>
typedef struct process
{
	int pid;
	int at;
	int bt;
	int wt;
	int tat;
	int st;
	int ct;
}ps;
int main()
{
	int n;
	printf("Enter the number of process\n");
	scanf("%d",&n);
	ps p[n];
	float stat=0,stwt=0,atat=0,awt=0;
	for(int i=0;i<n;i++)
	{
		p[i].tat=0;
		p[i].wt=0;
		p[i].ct=0;
	}
	for(int i=0;i<n;i++)
	{
		printf("Enter the arival time\n");
		scanf("%d",&p[i].at);
		printf("Enter burst time\n");
		scanf("%d",&p[i].bt);
		p[i].pid=i+1;
	}
	int completed=0,time=0,minbt,minbtindex;
	while(completed<n)
	{
		minbt=10000000;
		minbtindex=-1;
		for(int i=0;i<n;i++)
		{
			if(p[i].at<=time&&p[i].ct==0&&p[i].bt<minbt)
			{
				minbt=p[i].bt;
				minbtindex=i;
			}
		}
		if(minbtindex==-1)
		{
			time++;
			continue;
		}
		p[minbtindex].st=time;
		p[minbtindex].ct=p[minbtindex].st+p[minbtindex].bt;
		p[minbtindex].tat=p[minbtindex].ct-p[minbtindex].at;
		p[minbtindex].wt=p[minbtindex].tat-p[minbtindex].bt;
		stat+=p[minbtindex].tat;
		stwt+=p[minbtindex].wt;
		time=p[minbtindex].ct;
		completed++;
	}
	atat=stat/n;
	awt=stwt/n;
	printf("pid\t\tat\t\tbt\t\tst\t\tct\t\twt\t\ttat\n");
	for(int i=0;i<n;i++)
	{
		printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n",p[i].pid,p[i].at,p[i].bt,p[i].st,p[i].ct,p[i].wt,p[i].tat);
	}
	printf("Average wating time=%f",awt);
	printf("\nAverage turn around time=%f",atat);
	return 0;
}
	
