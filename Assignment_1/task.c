#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void removeBlankLines();
void removeComments();
void macroExpansion();

void main(int argc, char *argv[])
{
    if (argc != 5)
    {
        printf("Invalid Arguments.\n");
        exit(0);
    }

    FILE *fp = fopen(argv[1], "r");
    char line[128] = "";
    while (fgets(line, sizeof(line), fp) != NULL)
    {
        fputs(line, stdout);
    }
    fclose(fp);

    removeBlankLines(argv[1], argv[2]);
    removeComments(argv[2], argv[3]);
    removeBlankLines(argv[3], argv[4]);
    macroExpansion(argv[4]);

    exit(0);
}

void removeBlankLines(char *inputFile, char *outputFile)
{
    FILE *fp = fopen(inputFile, "r");
    FILE *fp1 = fopen(outputFile, "w");
    char line[128] = "";
    while (fgets(line, sizeof(line), fp) != NULL)
    {
        if (line[0] == '\n')
        {
            continue;
        }
        fputs(line, fp1);
        // fputs(line, stdout);
    }
    fclose(fp);
    fclose(fp1);
}

void removeComments(char *inputFile, char *outputFile)
{
    FILE *fp = fopen(inputFile, "r");
    FILE *fp1 = fopen(outputFile, "w");
    char *c;
    char line[128] = "";
    while ((c = fgets(line, sizeof(line), fp)) != NULL)
    {
        for (int i = 0; i < strlen(line); i++)
        {
            if (c[i] == '/' && c[i + 1] == '/')
            {
                while (c[i] != '\n' && c[i] != '\0')
                {
                    i++;
                }
            }
            if (c[i] == '/' && c[i + 1] == '*')
            {
                while (c[i] != '\n' && c[i + 1] != '\0')
                {
                    i++;
                }
            }
            if (c[i] == '*' && c[i + 1] == '/')
            {
                while (c[i] != '\n' && c[i + 1] != '\0')
                {
                    i++;
                }
            }
            while (c[i] == '*')
            {
                i++;
            }
            fputc(c[i], fp1);
            // fputc(c[i], stdout);
        }
    }
    fclose(fp);
    fclose(fp1);
}

void macroExpansion(char *inputFile)
{
    FILE *fp = fopen(inputFile, "r");
    FILE *outfp = fopen("output.c", "w");
}
