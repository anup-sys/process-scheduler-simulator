# Process Scheduler Simulator 🚀

A CPU Scheduling Simulator implemented in C that demonstrates fundamental Operating System scheduling algorithms and performance analysis techniques. The simulator models how an operating system allocates CPU time among multiple processes.

## Features

### First Come First Serve (FCFS)

Processes are executed in the order they arrive.

```text
P1 → P2 → P3
```

### Shortest Job First (SJF)

Process with the shortest burst time is selected first.

```text
P1 → P3 → P2
```

### Round Robin (RR)

Processes are scheduled using a configurable time quantum.

```text
P1 → P2 → P3 → P1 → P2
```

### Priority Scheduling

Processes are selected based on priority.

```text
Priority 1 > Priority 2 > Priority 3
```

### Gantt Chart Visualization

Visual representation of CPU execution order.

```text
| P1 | P2 | P3 | P1 |
0    2    4    6    8
```

---

## Implemented Algorithms

* FCFS (First Come First Serve)
* SJF (Shortest Job First)
* Round Robin
* Priority Scheduling

---

## Metrics Calculated

* Waiting Time (WT)
* Turnaround Time (TAT)
* Completion Time (CT)
* Average Waiting Time
* Average Turnaround Time

---

## Project Structure

```text
process-scheduler-simulator/
│
├── README.md
├── LICENSE
├── Makefile
│
├── src/
│   ├── main.c
│   ├── scheduler.c
│   ├── fcfs.c
│   ├── sjf.c
│   ├── round_robin.c
│   ├── priority.c
│   └── gantt_chart.c
│
├── include/
│   ├── process.h
│   ├── scheduler.h
│   ├── fcfs.h
│   ├── sjf.h
│   ├── round_robin.h
│   ├── priority.h
│   └── gantt_chart.h
│
├── docs/
│   └── architecture.md
│
└── examples/
    └── input.txt
```

---

## Technologies Used

* C Programming Language
* Linux
* GCC
* Make
* Git & GitHub
* Operating System Concepts

---

## Build

Using Makefile:

```bash
make
```

Or manually:

```bash
gcc src/*.c -Iinclude -o scheduler
```

---

## Run

```bash
./scheduler
```

---

## Example Input

```text
4

1 0 5 3
2 1 3 1
3 2 8 4
4 3 6 2
```

Format:

```text
PID ArrivalTime BurstTime Priority
```

---

## Example Output

```text
PID    AT    BT    WT    TAT    CT

1      0     5     0      5      5
2      1     3     4      7      8
3      2     8     6      14     16

Average Waiting Time: 3.33
Average Turnaround Time: 8.67
```

---

## Scheduling Concepts Demonstrated

* CPU Scheduling
* Process Management
* Queue Management
* Operating System Internals
* Systems Programming
* Performance Analysis

---

## Learning Outcomes

This project demonstrates:

* Operating System Fundamentals
* Scheduling Algorithms
* Process Lifecycle Management
* Systems Programming in C
* Algorithm Analysis
* Performance Metrics Calculation

---

## Future Improvements

* Preemptive SJF (SRTF)
* Preemptive Priority Scheduling
* Multi-Level Queue Scheduling
* Multi-Level Feedback Queue
* CPU Utilization Metrics
* Throughput Analysis
* Context Switching Cost Simulation
* Multi-Core Scheduling

---

## Author

**Anup**

Built to explore CPU Scheduling Algorithms, Operating Systems, Process Management, and Systems Programming using C.
