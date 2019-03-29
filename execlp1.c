#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
void main()
{
	int pid;
	pid=fork();
	if(pid<0)
	{
		printf("fork failed");
		exit(1);
	}
	else if(pid==0)
	{
		execlp("ls","ls",NULL);
		exit(0);
		execlp("ping", "ping", "192.168.1.107",NULL);
	}
	else
	{
		printf("process id is %d", getpid());
		wait(NULL);
		exit(0);
	}
}
