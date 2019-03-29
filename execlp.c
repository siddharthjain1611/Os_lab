#include <stdio.h>
#include<stdlib.h>
#include <unistd.h>

int main(void) {
	int pid;
	pid=fork();
	if(pid<0)
	{
		printf("fork failed");
		exit(1);
	}
  else if(pid==0)
  {
  	execlp("ls" , "ls" , NULL);
  	exit(0);
  }
  else
  {
  	printf("process id is %d", getpid());
  	wait(NULL);
  	exit(0);
  }
	return 0;
}
