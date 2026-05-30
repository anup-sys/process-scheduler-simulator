#include <stdio.h>

#include "gantt_chart.h"

void print_gantt_chart(int pids[],
                       int times[],
                       int count)
{
    printf("\nGantt Chart:\n\n");

    for (int i = 0; i < count; i++)
    {
        printf("| P%d ", pids[i]);
    }

    printf("|\n");

    for (int i = 0; i <= count; i++)
    {
        printf("%-5d", times[i]);
    }

    printf("\n");
}