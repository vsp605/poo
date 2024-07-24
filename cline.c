#include <stdio.h>
int main(int argc,char *arvg[])
{
	printf("number of arguments=%d\n",argc);
	printf("program name=%s\n",arvg[0]);
	for(int i=0;i<argc;i++)
	{
		printf("Argument %d :%s\n",i,arvg[i]);
	}
	return 0;
}
