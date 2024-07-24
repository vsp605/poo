#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
int main(int argc,char *argv[])
{
	int fd,n;
	char buf[11];
    fd=open("sjf1.c",O_RDONLY);
	if(fd==-1)
	{
		printf("open error\n"); 
		exit(1);
	}
	else
	while((n=read(fd,buf,10))>0)
		{
			printf("%s",buf);
			write(1,buf,n);
		}
	}
