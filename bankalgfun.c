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
	int index;
    for(k=0;k<n;k++)
     {
        index=isSafe(n,m,alloc,max,avial,f);
        if(index!=-1)
         {
            ans[ind++]=index;
            for(j=0;j<m;j++) 
            {
                avial[j]+=alloc[index][j];
            }
            f[index]=1;
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
