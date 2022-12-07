#include <stdio.h>
#include <stdlib.h>

void displayFile();

void main(int argc, char *argv[])
{
	if (argc != 2)
	{
		printf("Invalid Arguments.");
		exit(0);
	}
	displayFile(argv[1]);

	FILE *fp = fopen(argv[1], "r");
	int c;
	printf("State Transitions are shown below: \n");
	while ((c = fgetc(fp)) != EOF)
	{
		if (c == 'a')
		{
			printf("Received a on state q0 --- Moving to state q1\n");
			goto q1;
		}
		else if (c == 'b')
		{
			printf("Received b on state q0 --- Moving to state q3\n");
			goto q3;
		}
		else if (c == '$')
		{
			printf("End of String.\n");
			printf("String Rejected\n");
			exit(0);
		}
		else
		{
			printf("Received unknown character %c on state q0.\n", c);
			printf("Terminating the process...");
			exit(0);
		}
	q1:
		c = fgetc(fp);
		if (c == 'a')
		{
			printf("Received a on state q1 --- Moving to state q2\n");
			goto q2;
		}
		else if (c == 'b')
		{
			printf("Received b on state q1 --- Moving to state q3\n");
			goto q3;
		}
		else if (c == '$')
		{
			printf("End of String.\n");
			printf("String Rejected\n");
			exit(0);
		}
		else
		{
			printf("Received unknown character %c on state q1.\n", c);
			printf("Terminating the process...");
			exit(0);
		}
	q2:
		c = fgetc(fp);
		if (c == 'a')
		{
			printf("Received a on state q2 --- Moving to state q2\n");
			goto q2;
		}
		if (c == 'b')
		{
			printf("Received b on state q2 --- Moving to state q3\n");
			goto q3;
		}
		else if (c == '$')
		{
			printf("End of String.\n");
			printf("String Accepted\n");
			exit(0);
		}
		else
		{
			printf("Received unknown character %c on state q2.\n", c);
			printf("Terminating the process...");
			exit(0);
		}
	q3:
		c = fgetc(fp);
		if (c == 'a')
		{
			printf("Received a on state q3 --- Moving to state q1\n");
			goto q1;
		}
		if (c == 'b')
		{
			printf("Received b on state q3 --- Moving to state q4\n");
			goto q4;
		}
		else if (c == '$')
		{
			printf("End of String.\n");
			printf("String Rejected\n");
			exit(0);
		}
		else
		{
			printf("Received unknown character %c on state q3.\n", c);
			printf("Terminating the process...");
			exit(0);
		}
	q4:
		c = fgetc(fp);
		if (c == 'a')
		{
			printf("Received a on state q4 --- Moving to state q1\n");
			goto q1;
		}
		if (c == 'b')
		{
			printf("Received b on state  --- Moving to state q4\n");
			goto q4;
		}
		else if (c == '$')
		{
			printf("End of String.\n");
			printf("String Accepted\n");
			exit(0);
		}
		else
		{
			printf("Received unknown character %c on state q4.\n", c);
			printf("Terminating the process...");
			exit(0);
		}
	}
	fclose(fp);
}

void displayFile(char *filename)
{
	FILE *fp = fopen(filename, "r");
	char buf[50] = "";
	while ((fgets(buf, 50, fp)) != NULL)
	{
		printf("Input String is: %s\n", buf);
	}
	fclose(fp);
}