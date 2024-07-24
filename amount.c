#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
void forkexample()
{
	int p=1000,t=1,r=2;
	if(fork()==0)
	{
		float x=p*(1+(r/100))^t;
		float c=x-p;
		printf("child compound intrest=%f\n",c);
	}
	else
	{
		float d=(p*t*r)/100;
		printf("parent simple intrest=%f\n",d);
	}
}
int main()
{
	forkexample();
	return 0;
}
