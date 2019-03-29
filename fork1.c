#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
int main()
{
	int pid=fork();
	if(pid<0)
	{
	printf("not a process");
    }
	else if(pid==0)
	{
	printf("child process\n");
    }
	else
	{
	printf("parent process\n");
    }
}

