#include <stdio.h>
#include <stdlib.h>
#define WINDOWS
#ifdef WINDOWS
#include <direct.h>
#define GetCurrentDir _getcwd
#else
#include <unistd.h>
#define GetCurrentDir getcwd
#endif

int main()
{
    char buf[FILENAME_MAX];
    char dirname[100];
    GetCurrentDir(buf, FILENAME_MAX);
    printf("\nCurrent Working Directory: %s\n", buf);
    printf("Enter directory name: ");
    scanf("%s", dirname);
    if (mkdir(dirname))
    {
        printf("Directory exists!");
    }

    return 0;
}
