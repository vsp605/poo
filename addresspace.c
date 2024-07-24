#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
void forkexample()
{
	int x=4;
	if(fork()==0)
	{
		printf("child has x=%d\n",++x);
	}
	else
	{
		printf("parent has x=%d\n",--x);
	}
}
int main()
{
	forkexample();
	return 0;
}
