# CPU Scheduling Simulator Architecture

## Overview

CPU Scheduling Simulator is a systems programming project written in C that simulates common CPU scheduling algorithms used by operating systems.

The simulator calculates scheduling metrics such as:

* Waiting Time
* Turnaround Time
* Completion Time
* Average Waiting Time
* Average Turnaround Time

Supported Scheduling Algorithms:

* FCFS (First Come First Serve)
* SJF (Shortest Job First)
* Round Robin
* Priority Scheduling

---

## High Level Architecture

```text
                +------------------+
                |      User        |
                +--------+---------+
                         |
                         v
                +------------------+
                |     main.c       |
                +--------+---------+
                         |
                         v
                +------------------+
                | Scheduler Menu   |
                +--------+---------+
                         |
        +----------------+----------------+
        |                |                |
        v                v                v
   +---------+      +---------+     +-----------+
   | FCFS    |      |  SJF    |     | RoundRobin|
   +---------+      +---------+     +-----------+
                         |
                         v
                 +--------------+
                 |  Priority    |
                 +--------------+

                         |
                         v

                +------------------+
                | scheduler.c      |
                | Metrics Output   |
                +--------+---------+
                         |
                         v
                    Console
```

---

## Directory Structure

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
│   └── priority.c
│
├── include/
│   ├── process.h
│   ├── scheduler.h
│   ├── fcfs.h
│   ├── sjf.h
│   ├── round_robin.h
│   └── priority.h
│
├── docs/
│   └── architecture.md
│
└── examples/
    └── input.txt
```

---

## Module Responsibilities

### process.h

Defines Process structure.

```c
typedef struct
{
    int pid;
    int arrival_time;
    int burst_time;
    int priority;

    int waiting_time;
    int turnaround_time;
    int completion_time;

} Process;
```

Stores process information and scheduling metrics.

---

### main.c

Responsibilities:

* Display scheduling menu
* Read process information
* Select scheduling algorithm
* Invoke scheduler
* Display results

Acts as the entry point of the simulator.

---

### scheduler.c

Responsibilities:

* Print scheduling metrics
* Calculate average values
* Display results in tabular format

Output:

```text
PID   AT   BT   WT   TAT   CT
```

---

### fcfs.c

Implements:

First Come First Serve Scheduling

Characteristics:

* Non-preemptive
* Processes execute in arrival order

Time Complexity:

```text
O(n)
```

---

### sjf.c

Implements:

Shortest Job First Scheduling

Characteristics:

* Non-preemptive
* Selects shortest burst time first

Time Complexity:

```text
O(n²)
```

---

### round_robin.c

Implements:

Round Robin Scheduling

Characteristics:

* Time Quantum Based
* Fair CPU Sharing
* Context Switching Simulation

Example:

```text
P1 P2 P3 P1 P2
```

---

### priority.c

Implements:

Priority Scheduling

Characteristics:

* Non-preemptive
* Lower value = Higher Priority

Example:

```text
Priority 1 > Priority 2 > Priority 3
```

---

## Scheduling Metrics

### Waiting Time

```text
Waiting Time =
Turnaround Time - Burst Time
```

---

### Turnaround Time

```text
Turnaround Time =
Completion Time - Arrival Time
```

---

### Completion Time

```text
Time at which process finishes execution
```

---

## Execution Flow

```text
Start
  |
  v
Read Input
  |
  v
Select Algorithm
  |
  v
Run Scheduler
  |
  v
Calculate Metrics
  |
  v
Print Results
  |
  v
End
```

---

## Future Enhancements

* Preemptive SJF (SRTF)
* Preemptive Priority Scheduling
* Multi-Level Queue Scheduling
* Multi-Level Feedback Queue
* Gantt Chart Visualization
* CPU Utilization Metrics
* Throughput Calculation
* Context Switching Cost Simulation
* Multi-Core Scheduling

---

## Learning Outcomes

This project demonstrates:

* Operating System Fundamentals
* CPU Scheduling Algorithms
* Process Management
* Systems Programming in C
* Performance Analysis
* Algorithm Design and Evaluation

---

## Conclusion

The CPU Scheduling Simulator provides a practical implementation of core operating system scheduling techniques and serves as a foundation for understanding modern process management in operating systems.
