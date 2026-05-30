#ifndef ROUND_ROBIN_H
#define ROUND_ROBIN_H

#include "process.h"

void round_robin_schedule(Process processes[],
                          int n,
                          int quantum);

#endif