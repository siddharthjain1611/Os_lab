#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
	//int creat("os lab .txt", O_RDWR);
	int fd, re;
	char *c =(char *)calloc(100, sizeof (char));
	fd=open("osfile.txt", O_RDONLY  | O_CREAT);
	re= read(fd, c, 10);
	printf("%d bytes are read \n", re); 
	printf("%d first unused descriptor \n",fd);
    int fd1=close(fd);
    if(fd1==0)
    printf("file closed successfully\n");
    return 0;
}
