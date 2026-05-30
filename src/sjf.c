#include "sjf.h"

void sjf_schedule(Process processes[], int n)
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
        int shortest = -1;

        for (int i = 0; i < n; i++)
        {
            if (!visited[i] &&
                processes[i].arrival_time <= current_time)
            {
                if (shortest == -1 ||
                    processes[i].burst_time <
                    processes[shortest].burst_time)
                {
                    shortest = i;
                }
            }
        }

        if (shortest == -1)
        {
            current_time++;
            continue;
        }

        visited[shortest] = 1;

        processes[shortest].waiting_time =
            current_time -
            processes[shortest].arrival_time;

        current_time +=
            processes[shortest].burst_time;

        processes[shortest].completion_time =
            current_time;

        processes[shortest].turnaround_time =
            processes[shortest].completion_time -
            processes[shortest].arrival_time;

        completed++;
    }
}