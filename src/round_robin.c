#include <stdio.h>

#include "round_robin.h"

#include "gantt_chart.h"
void round_robin_schedule(Process processes[],
                          int n,
                          int quantum)
{
    int remaining[n];

    int current_time = 0;
    int completed = 0;

    for (int i = 0; i < n; i++)
    {
        remaining[i] = processes[i].burst_time;
    }

    printf("\nGantt Chart:\n| ");

    while (completed < n)
    {
        int executed = 0;

        for (int i = 0; i < n; i++)
        {
            if (remaining[i] > 0)
            {
                executed = 1;

                printf("P%d | ",
                       processes[i].pid);

                if (remaining[i] > quantum)
                {
                    current_time += quantum;

                    remaining[i] -= quantum;
                }
                else
                {
                    current_time += remaining[i];

                    remaining[i] = 0;

                    completed++;

                    processes[i].completion_time =
                        current_time;

                    processes[i].turnaround_time =
                        processes[i].completion_time -
                        processes[i].arrival_time;

                    processes[i].waiting_time =
                        processes[i].turnaround_time -
                        processes[i].burst_time;
                }
            }
        }

        if (!executed)
            break;
    }

    printf("\n");
}