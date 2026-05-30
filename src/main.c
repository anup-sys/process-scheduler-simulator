#include <stdio.h>

#include "process.h"
#include "fcfs.h"
#include "scheduler.h"

int main()
{
    int n;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    Process processes[n];

    printf("\nEnter PID ArrivalTime BurstTime\n");

    for (int i = 0; i < n; i++)
    {
        scanf("%d %d %d",
              &processes[i].pid,
              &processes[i].arrival_time,
              &processes[i].burst_time);
    }

    fcfs_schedule(processes, n);

    print_results(processes, n);

    return 0;
}