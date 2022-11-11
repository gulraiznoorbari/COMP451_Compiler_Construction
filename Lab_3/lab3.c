#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void displayFile();
void addLineNumber();
void removeBlankLines();

void main(int argc, char *argv[])
{
	if (argc != 4)
	{
		printf("Need to have a file name in the arguments of this program\n");
		exit(0);
	}
	addLineNumber(argv[1], argv[2]);
	displayFile(argv[2]);
	printf("\n\n");
	removeBlankLines(argv[2], argv[3]);
	displayFile(argv[3]);
	exit(0);
}

void displayFile(char *file)
{
	FILE *fp;
	fp = fopen(file, "r");
	int c;
	while ((c = fgetc(fp)) != EOF)
	{
		printf("%c", c);
	}
	fclose(fp);
}

void addLineNumber(char *inputfp, char *outputfp)
{
	FILE *inputFile = fopen(inputfp, "r");
	FILE *outputFile = fopen(outputfp, "w");

	int linecount = 1;
	fputc('1', outputFile);
	int c;
	while ((c = fgetc(inputFile)) != EOF)
	{
		fputc(c, outputFile);
		if (c == '\n')
		{
			linecount++;
			fprintf(outputFile, "%d. ", linecount);
		}
	}
	fclose(inputFile);
	fclose(outputFile);
}

void removeBlankLines(char *inputfp, char *outputfp)
{
	FILE *inputFile = fopen(inputfp, "r");
	FILE *outputFile = fopen(outputfp, "w");

	int c;
	while ((c = fgetc(inputFile)) != EOF)
	{
		if (c == '.')
		{
			if ((c = fgetc(inputFile)) == '\n')
			{
				if ((c = fgetc(inputFile)) == '\n')
				{
					fputc(c, outputFile);
					fputc('.', outputFile);
					fputc(' ', outputFile);
				}
			}
			else
			{
				fputc('.', outputFile);
				fputc(c, outputFile);
			}
		}
		else
		{
			fputc(c, outputFile);
		}
	}
	fclose(inputFile);
	fclose(outputFile);
}