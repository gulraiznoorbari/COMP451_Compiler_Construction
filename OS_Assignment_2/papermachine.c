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
        printf("papermachine: received signal to make paper\n");
        while (paper < 10)
        {
            printf("papermachine: making one yard of paper\n");
            paper++;
            sleep(0.3);
        }
        printf("papermachine: finished making paper\n");
        paper = 0;
    }
    else if (sig == SIGUSR2)
    {
        printf("papermachine: received signal that boxes are being made\n");
        while (boxes > 0)
        {
            printf("papermachine: waiting for boxes to be made\n");
            sleep(1);
            boxes--;
        }
    }
}

int main()
{
    signal(SIGUSR1, sig_handler);
    signal(SIGUSR2, sig_handler);

    while (1)
    {
        sleep(1);
    }

    return 0;
}
