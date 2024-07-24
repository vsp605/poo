#include<stdio.h>
int main()
{
	int i,n,temp[30],bt[30],tat[30],wt[30],at[30];
	float awt=0,atat=0;
	printf("Enter the number of process\n");
	scanf("%d",&n);
	printf("Enter the burst time of the process\n");
	for(i=0;i<n;i++)
	{
		scanf("%d",&bt[i]);
	}
	printf("Enter the arrival time of the process\n");
	for(i=0;i<n;i++)
	{
		scanf("%d",&at[i]);
	}
	 temp[0]=0;
	 printf("process\t burst time\t arrival time\t waitting time\t  turn around time\n");
	 for(i=0;i<n;i++)
	 {
		 wt[i]=0;
		 tat[i]=0;
		 temp[i+1]=temp[i]+bt[i];
		 wt[i]=temp[i]-at[i];
		 tat[i]=wt[i]+bt[i];
		 awt=awt+wt[i];
		 atat=atat+tat[i];
		 printf("%d\t%d\t%d\t%d\t%d\n",i+1,bt[i],at[i],wt[i],tat[i]);
	 }
	 awt=awt/n;
	 atat=atat/n;
	 printf("avg watting time=%f\n",awt);
	 printf("avg term around time=%f\n",atat);
	 return 0;
	 }
	 
	 
	 
		 
		 
	
	
