#include<stdio.h>
void mycat(FILE*,FILE*);
int main(int argc,char** argv)
{
	FILE *fp1,*fp2;
	fp1=fopen(argv[1],"r");
	fp2=fopen(argv[2],"r");
	mycat(fp1,fp2);
	return 0;
}
void mycat(FILE* fp3,FILE* fp4)
{
	char str1[100];
	printf("After containg are\n");
	while(fscanf(fp3,"%s\n",str1)==1)
	{
		printf("%s",str1);
	}
	while(fscanf(fp4,"%s\n",str1)==1)
	{
		printf("%s",str1);
	}
}
