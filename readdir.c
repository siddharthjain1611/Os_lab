#include <stdio.h>
#include <dirent.h>
#include <stdlib.h>
int main(int argc, char *argv[])
{
	DIR *dp;
	struct dirent *dirp;
	if(argc<2)
	{
		printf("you have provided only one arg");
		exit(1);
	}
	if((dp=opendir(argv[1]))==NULL)
	{
		printf(" cannot open file %s", argv[1]);
		exit(1);
	}
	while((dirp=readdir(dp))!=NULL)
	printf(" %s\n", dirp->d_name);
	closedir(dp);
}
