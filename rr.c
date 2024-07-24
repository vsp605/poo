#include<stdio.h>
typedef struct process
{
	int id;
	int at;
	int bt;
	int rt;
	int st;
	int wt;
	int tat;
	int ct;
}ps;
int main()
{
	int n;
	printf("Enter the number of process\n");
	scanf("%d",&n);
	ps p[n];
	int qn;
	for(int i=0;i<n;i++)
	{
		printf("Enter the arival time\n");
		scanf("%d",&p[i].at);
		printf("Enter burst time\n");
		scanf("%d",&p[i].bt);
		p[i].id=i+1;
		p[i].rt=p[i].bt;
		p[i].ct=0;
	}
	printf("Enter the time quantum\n");
	scanf("%d",&qn);
	int time=0;
	int ctt=0;
	while(ctt<n)
	{
		for(int i=0;i<n;i++)
		{
			if(p[i].at<=time&&p[i].rt>0)
			{
				if(p[i].rt==p[i].bt)
				{
					p[i].st=time;
				}
				if(p[i].rt>qn)
				{
					time+=qn;
					p[i].rt-=qn;
				}
				else
				{
					time+=p[i].rt;
					p[i].rt=0;
					p[i].ct=1;
					ctt++;
					p[i].tat=time-p[i].at;
					p[i].wt=p[i].tat-p[i].bt;
				}
			}
		}
	}
	int twt=0;
	int ttat=0;
	printf("pid\t\tat\t\tbt\t\tst\t\tct\t\twt\t\ttat\n");
	for(int i=0;i<n;i++)
	{
		printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n",p[i].id,p[i].at,p[i].bt,p[i].st,p[i].ct,p[i].wt,p[i].tat);
	}
	float avr_wt=(float)twt/n;
	float avr_tat=(float)ttat/n;
	printf("Average wating time=%f",avr_wt);
	printf("\nAverage turn around time=%f",avr_tat);
	return 0;
}
	
		
	
