#include <stdio.h>
int main(int argc,char *argv[])
{
	FILE *fp1,*fp2;
	fp1=fopen(argv[1],"r");
	fp2=fopen(argv[2],"r");
	char str[100];
	while(fscanf(fp1,"%s",str)==1)
	{
		fprintf(fp2,"%s\t",str);
	}
	return 0;
}
