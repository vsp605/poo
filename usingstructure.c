#include<stdio.h>
typedef struct 
{
	int bt;
	int at;
	int wt;
	int tat;
	int st;
	int ct;
}p;
int main()
{
	int i,n;
	int temp[30];
	float twt=0,ttat=0;
	p p[30];
	printf("Enter the number of process\n");
	scanf("%d",&n);
	printf("Enter the burst time of the process\n");
	for(i=0;i<n;i++)
	{
		printf("process %d:",i+1);
		scanf("%d",&p[i].bt);
	}
	printf("Enter the arrival time of the process\n");
	for(i=0;i<n;i++)
	{
		printf("process %d:",i+1);
		scanf("%d",&p[i].at);
	}
	 temp[0]=0;
	 printf("process\tarrival time\tburst time\tstarting time\tcompication time\tturn around time\twatting time\n");
	 for(i=0;i<n;i++)
	 {
		 p[i].wt=0;
		 p[i].tat=0;
		 temp[i+1]=temp[i]+p[i].bt;
		 p[i].st=(p[i-1].ct>p[i].at)?p[i-1].ct:p[i].at;
		 p[i].ct=p[i].bt+p[i].st;
		 p[i].tat=p[i].ct-p[i].at;
		 p[i].wt=p[i].st-p[i].at;
		 twt+=p[i].wt;
		 ttat+=p[i].tat;
		 printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n",i+1, p[i].at,p[i].bt,p[i].st,p[i].ct,p[i].tat,p[i].wt);
	 }
	 printf("avg watting time=%f\n",twt/n);
	 printf("avg term around time=%f\n",ttat/n);
	 return 0;
	 }
	 
