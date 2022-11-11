#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		printf("Invalid Arguments.\n");
	}
	FILE *fp;
	int linecount = 0;
	int charscount = 0;
	fp = fopen(argv[1], "r");
	char *c;
	char buf[100] = "";
	while ((c = fgets(buf, 100, fp)) != NULL)
	{
		charscount = 0;
		for (int i = 0; i < strlen(buf); i++)
		{
			if (c[i] == '\t')
			{
				printf("%c ", c[i]);
				continue;
			}
			if (c[i] != '\n')
			{
				fputc(c[i], stdout);
				charscount++;
			}
			if (c[i] == '\n')
			{
				linecount++;
				printf("[%d]\n", charscount);
			}
		}
	}
	printf("Total Number of lines in file are: %d \n", linecount);
	exit(0);
}
