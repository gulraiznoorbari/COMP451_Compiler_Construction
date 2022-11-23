#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void main(int argc, char *argv[])
{
	if (argc != 2)
	{
		printf("Invalid Arguments.\n");
		exit(0);
	}
	FILE *fp = fopen(argv[1], "r");
	int linecount = 1;
	int macroCount = 0;
	char *c;
	char buf[128] = "";
	char macrosLine[1000] = "";
	int z = 0;
	while ((c = fgets(buf, sizeof(buf), fp)) != NULL)
	{
		printf("%d. ", linecount);
		for (int i = 0; i < strlen(buf); i++)
		{
			if (c[i] == '#')
			{
				while (c[i + 1] == ' ')
				{
					i++;
				}
				if (c[i + 1] == 'd')
				{
					macroCount++;
					for (int k = 0; k < strlen(buf); k++)
					{
						macrosLine[z++] = buf[k];
					}
				}
			}
			if (c[i] == '\n')
			{
				linecount++;
			}
			fputc(c[i], stdout);
		}
	}
	printf("\nTotal Macros found in the file are: %d\n", macroCount);
	fputs(macrosLine, stdout);
	fclose(fp);
	exit(0);
}