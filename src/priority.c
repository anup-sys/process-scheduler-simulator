#include "priority.h"

void priority_schedule(Process processes[], int n)
{
    int completed = 0;
    int current_time = 0;

    int visited[n];

    for (int i = 0; i < n; i++)
    {
        visited[i] = 0;
    }

    while (completed < n)
    {
        int highest = -1;

        for (int i = 0; i < n; i++)
        {
            if (!visited[i] &&
                processes[i].arrival_time <= current_time)
            {
                if (highest == -1 ||
                    processes[i].priority <
                    processes[highest].priority)
                {
                    highest = i;
                }
            }
        }

        if (highest == -1)
        {
            current_time++;
            continue;
        }

        visited[highest] = 1;

        processes[highest].waiting_time =
            current_time -
            processes[highest].arrival_time;

        current_time +=
            processes[highest].burst_time;

        processes[highest].completion_time =
            current_time;

        processes[highest].turnaround_time =
            processes[highest].completion_time -
            processes[highest].arrival_time;

        completed++;
    }
}