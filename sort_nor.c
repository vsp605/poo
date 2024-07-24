#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
int main()
{
	int fd[100];
	pid_t pid;
	if(pipe(fd)==-1)
	{
		perror("pipe");
		exit(EXIT_FAILURE);
	}
	pid=fork();
	if(pid<0)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}
	if(pid==0)
	{
		int num[10]={10,5,8,6,8,6,8,7,2,3};
		close(fd[0]);
		write(fd[10],&num,sizeof(num));
		close(fd[10]);
		exit(EXIT_SUCCESS);
	}
	else
	{
		int num[10];
		int temp;
		close(fd[10]);
		read(fd[0],&num,sizeof(num));
		close(fd[0]);
		for(int i=0;i<10;i++)
		{
				if(num[i]>num[i+1])
				{
					temp=num[i+1];
					num[i+1]=num[i];
					num[i]=temp;
				}
		}
		printf("sorted number\n");
		for(int i=0;i<10;i++)
		{
			printf("%d\n",num[i]);
		}
	}
	return 0;
}
