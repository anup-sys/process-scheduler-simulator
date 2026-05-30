#include <stdio.h>

#include "process.h"
#include "fcfs.h"
#include "sjf.h"
#include "round_robin.h"
#include "scheduler.h"

int main()
{
    int n;
    int choice;
    int quantum;

    printf("CPU Scheduling Simulator\n");

    printf("\n1. FCFS\n");
    printf("2. SJF\n");
    printf("3. Round Robin\n");

    printf("\nEnter choice: ");
    scanf("%d", &choice);

    printf("\nEnter number of processes: ");
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

    switch (choice)
    {
        case 1:
            fcfs_schedule(processes, n);
            break;

        case 2:
            sjf_schedule(processes, n);
            break;

        case 3:
            printf("\nEnter Time Quantum: ");
            scanf("%d", &quantum);

            round_robin_schedule(
                processes,
                n,
                quantum
            );
            break;

        default:
            printf("Invalid Choice\n");
            return 1;
    }

    print_results(processes, n);

    return 0;
}