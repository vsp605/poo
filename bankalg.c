#include <stdio.h>
#include "work.h"
int main()
{
	int n,m,i,j,k;
	int alloc[20][20],max[20][20],avial[20];
	printf("Enter n and m \n");
	scanf("%d%d",&n,&m);
	printf("Enter the matrix of allocation\n");
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			scanf("%d",&alloc[i][j]);
		}
	}
	printf("Enter the matrix of maximum\n");
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			scanf("%d",&max[i][j]);
		}
	}
	printf("Enter the array of avilable resource\n");
	for(i=0;i<m;i++)
	{
		scanf("%d",&avial[i]);
	}
	int f[n],ans[n],ind=0;
	for(i=0;i<n;i++)
	{
		ans[i]=0;
	}
	for(k=0;k<n;k++)
	{
		f[k]=0;
	}
	int need[n][m];
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			need[i][j]=max[i][j]-alloc[i][j];
		}
	}
	int count=0;
	while(count<n)
	{
		for(i=0;i<n;i++)
		{
			if(f[i]==0)
			{
				if(less(i,m,need,avial))
				{
					for(j=0;j<m;j++)
					{
						avial[j]+=alloc[i][j];
					}
					ans[ind++]=i;
					f[i]=1;
					
					count++;
				}
			}
		}
	}
	printf("following is safe sequeance\n");
	for(i=0;i<n-1;i++)
	{
		printf("p%d->",ans[i]);
	}
	printf("p%d",ans[n-1]);
	return 0;
}
