#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

void main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Invalid Arguments\n");
        exit(0);
    }
    char *str = argv[1];
    int j = 0;
    int length = strlen(str);
    char *newStr = (char *)malloc(MAX);
    for (int i = 0; i < length; i++)
    {
        while (str[i] != '\0')
        {
            if (str[i] == ' ')
            {
                newStr[j] = ' ';
                j++;

                while (str[i] == ' ')
                {
                    i++;
                }
            }
            // deals w/ space before semi-colon:
            if (str[i] == ';' && str[i + 1] == '\0' && str[i - 1] == ' ')
            {
                newStr[j - 1] = ';';
                j++;
            }
            newStr[j] = str[i];
            i++;
            j++;
        }
    }
    newStr[j] = '\0';
    // deals w/ space at 0 index:
    for (int i = 0; i < strlen(newStr); i++)
    {
        if (i == 0 && newStr[i] == ' ')
        {
            while (newStr[i] != '\0')
            {
                newStr[i] = newStr[i + 1];
                i++;
            }
        }
    }
    printf("%s", newStr);
    exit(0);
}
