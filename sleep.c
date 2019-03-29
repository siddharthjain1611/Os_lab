#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
main()
{
	int pid=fork();
	if(pid<0)
	{
	printf("not a process\n");
    }
	else if(pid==0)
	{
	sleep(5);	
	printf("child process\n");
    }
	else
	{
	printf("parent process\n");
    }
}

