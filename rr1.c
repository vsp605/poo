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
	ps p[20];
	int tq,r[20];
	float sumtat=0,sumwt=0,avgtat=0,avgwt=0;
	for(int i=0;i<n;i++)
	{
		printf("Enter the arival time\n");
		scanf("%d",&p[i].at);
		printf("Enter burst time\n");
		scanf("%d",&p[i].bt);
		p[i].tat=0;
		p[i].wt=0;
		p[i].ct=0;
		r[i]=p[i].bt;
		p[i].pid=i+1;
	}
	printf("Enter time quantum\n");
	scanf("%d",&tq);
	int time=0;
	int ctt=0;
	while(ctt<n)
	{
		for(int i=0;i<n;i++)
		{
			if(r[i]>0)
			{
				if(r[i]>tq)
				{
					time+=tq;
					r[i]-=tq;
				}
				else
				{
					time+=r[i];
					p[i].ct=time;
					r[i]=0;
					ctt++;
					p[i].tat=p[i].ct-p[i].at;
					p[i].wt=p[i].tat-p[i].bt;
					sumtat+=p[i].tat;
					sumwt+=p[i].wt;
				}
			}
		}
	}
	avgtat=sumtat/n;
	avgwt=sumwt/n;
	printf("pid\t\tat\t\tbt\t\tst\t\tct\t\twt\t\ttat\n");
	for(int i=0;i<n;i++)
	{
		printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n",p[i].pid,p[i].at,p[i].bt,p[i].st,p[i].ct,p[i].wt,p[i].tat);
	}
	printf("Average wating time=%f",avgwt);
	printf("\nAverage turn around time=%f",avgtat);
	return 0;
}
