#include <sys/types.h>
#include <dirent.h>
#include <stdio.h>

int main(int c, char* arg[])
{
	DIR *d;
	struct dirent *r;
	int i = 0;
	d = opendir(arg[1]);
	printf("\n\t NAME OF ITEM \n");
	while ((r = readdir(d)) != NULL)
	{
		printf("\t %s \n", r->d_name);
		i = i + 1;
	}
	printf("\n TOTAL NUMBER OF ITEMS IN THAT DIRECTORY ARE %d \n", i);
	return 0;
}

