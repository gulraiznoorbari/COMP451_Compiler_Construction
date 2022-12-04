/*
    Name: Gulraiz Noor Bari
    Roll No: 231-525536
    COMP-451 (Compiler Construction)
    Section: A
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void removeBlankLines();
void removeComments();
void macroExpansion();

void main(int argc, char *argv[])
{
    if (argc != 2)
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
    fputs("\n", stdout);
    fputs("\n", stdout);
    fclose(fp);

    removeBlankLines(argv[1], "removeBlankLines1.txt");
    removeComments("removeBlankLines1.txt", "removeComments.txt");
    removeBlankLines("removeComments.txt", "removeBlankLines2.txt");
    macroExpansion("removeBlankLines2.txt");

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
        }
    }
    fclose(fp);
    fclose(fp1);
}

void macroExpansion(char *inputFile)
{
    FILE *fp = fopen(inputFile, "r");
    FILE *outfp = fopen("output.c", "w");
    char line[128] = "";
    char macroLine[500] = "";
    char *c;
    while ((c = fgets(line, sizeof(line), fp)) != NULL)
    {
        for (int i = 0; i < strlen(line); i++)
        {
            if (c[i] == '#')
            {
                while (c[i + 1] == ' ')
                {
                    i++;
                }
                if (c[i + 1] == 'd' && c[i + 2] == 'e' && c[i + 3] == 'f')
                {
                    char *token = strtok(c, " ");
                    token = strtok(NULL, " ");
                    char *macroName = token;
                    token = strtok(NULL, " ");
                    char *macroValue = token;
                    macroValue[strlen(macroValue) - 1] = '\0';
                    // printf("Macro Name: %s\n", macroName);
                    // printf("Macro Value: %s", macroValue);

                    while ((fgets(macroLine, sizeof(macroLine), fp)) != NULL)
                    {
                        if (strstr(macroLine, macroName) != NULL)
                        {
                            char *token = strtok(macroLine, " ");
                            while (token != NULL)
                            {
                                if (strcmp(token, macroName) == 0)
                                {
                                    fputs(macroValue, outfp);
                                    fputs(macroValue, stdout);
                                }
                                else
                                {
                                    fputs(token, outfp);
                                    fputs(token, stdout);
                                }
                                token = strtok(NULL, " ");
                            }
                        }
                        else
                        {
                            fputs(macroLine, outfp);
                            fputs(macroLine, stdout);
                        }
                    }
                }
                else
                {
                    fputs(c, outfp);
                    fputs(c, stdout);
                }
            }
        }
    }
    fclose(fp);
    fclose(outfp);
}