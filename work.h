#include<stdio.h>
int j;
int less(int i,int m,int need[][20],int avail[])
{
	for(j=0;j<m;j++)
	{
		if(need[i][j]>avail[j])
		{
			return 0;
		}
	}
	return 1;
}
