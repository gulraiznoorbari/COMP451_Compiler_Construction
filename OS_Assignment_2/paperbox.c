#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

int paper = 0;
int boxes = 0;

void sig_handler(int sig)
{
    if (sig == SIGUSR1)
    {
        printf("paperbox: received paper\n");
        paper++;
    }
}

int main()
{
    signal(SIGUSR1, sig_handler);

    while (1)
    {
        if (paper > 0)
        {
            printf("paperbox: making one box\n");
            paper--;
            boxes++;
            sleep(0.4);
        }
        else
        {
            printf("paperbox: out of paper, requesting more\n");
            kill(getppid(), SIGUSR1);
            sleep(1);
        }

        if (boxes == 5)
        {
            printf("paperbox: finished making boxes\n");
            boxes = 0;
            printf("paperbox: requesting papermachine to stop making paper\n");
            kill(getppid(), SIGUSR2);
        }
    }

    return 0;
}
