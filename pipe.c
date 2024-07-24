#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
int main()
{
	int fd[2];
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
		int numbers[2]={40,20};
		close(fd[0]);
		write(fd[1],&numbers,sizeof(numbers));
		close(fd[1]);
		exit(EXIT_SUCCESS);
	}
	else
	{
		int numbers[2];
		int sum;
		close(fd[1]);
		read(fd[0],&numbers,sizeof(numbers));
		close(fd[0]);
		sum=numbers[0]+numbers[1];
		printf("sum of the number :%d\n",sum);
	}
	return 0;
}
		
	
