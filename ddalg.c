#include <stdio.h>
int main()
{
	int n,m,i,j,k;
	int alloc[20][20],req[20][20],avial[20];
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
	printf("Enter the matrix of request\n");
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			scanf("%d",&req[i][j]);
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
	int y=0;
	for(k=0;k<5;k++)
	{
		for(i=0;i<n;i++)
		{
			if(f[i]==0)
			{
				int flag=0;
				for(j=0;j<m;j++)
				{
					if(req[i][j]>avial[j])
					{
						flag=1;
						break;
					}
				}
				if(flag==0)
				{
					ans[ind++]=i;
					for(y=0;y<m;y++)
					{
						avial[y]+=alloc[i][j];
					}
					f[i]=1;
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
