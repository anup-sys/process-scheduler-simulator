#include <stdio.h>

#include "scheduler.h"

void print_results(Process processes[], int n)
{
    double total_wt = 0;
    double total_tat = 0;

    printf("\nPID\tAT\tBT\tWT\tTAT\tCT\n");

    for (int i = 0; i < n; i++)
    {
        printf("%d\t%d\t%d\t%d\t%d\t%d\n",
               processes[i].pid,
               processes[i].arrival_time,
               processes[i].burst_time,
               processes[i].waiting_time,
               processes[i].turnaround_time,
               processes[i].completion_time);

        total_wt += processes[i].waiting_time;
        total_tat += processes[i].turnaround_time;
    }

    printf("\nAverage Waiting Time: %.2f\n",
           total_wt / n);

    printf("Average Turnaround Time: %.2f\n",
           total_tat / n);
}