#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	FILE *fptr;
	fptr = fopen("Lab4.txt", "w");
	char data[100];
	if (fptr == NULL)
	{
		printf("Error!");
		exit(1);
	}
	fprintf(fptr, "This is Lab4 of Operating Systems Course.", data);
	fclose(fptr);

	fptr = fopen("Lab4.txt", "r");
	fscanf(fptr, "%[^\n]", data);
	int length = strlen(data);
	for (int i = 0; i < length / 2; i++)
	{
		char temp = data[i];
		data[i] = data[length - 1 - i];
		data[length - 1 - i] = temp;
	}

	fptr = fopen("Lab4.txt", "w");
	fprintf(fptr, "%s", data);
	printf("The reversed string is: %s", data);
	fclose(fptr);
	return 0;
}
