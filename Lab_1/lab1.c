#include <stdio.h>
#include <stdlib.h>

int main(int argc, char * argv[]) {
	if(argc != 2) {
		printf("Invalid Arguments.\n");
	}
	FILE *fp;
	int linecount = 1;
	int charscount = 0;
	fp = fopen(argv[1],"r");
	printf("1. ");
	int c;
	while((c = fgetc(fp)) != EOF)
	{
		if(c != '\n' || c != ' ') {
			charscount++;
		}
		fputc(c, stdout);
		if (c == '\n') {
			linecount++;
			printf("%d. ", linecount);
		}
	}
	printf("Total Number of Characters %d \n", charscount);
	exit(0);
}

