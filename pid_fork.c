#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
 child();
  parent();
child()
{
printf("child_process id is %d \n",getpid());
}
parent()
{
printf("parent_process id is %d   \n",getpid());
}
main()
{
	int pid=fork();
	if(pid<0)
	{
	printf("not a process\n");
    }
	else if(pid==0)
	{
	child();
    }
	else
	{
	parent();
    }
}
