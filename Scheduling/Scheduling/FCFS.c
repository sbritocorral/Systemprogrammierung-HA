#include "FCFS.h"

void schedule_FCFS(const TaskPool *task_pool)
{
    // TODO

    int tick = 0;
    while (!allDone(task_pool))
    {

        Task *taskArrive = checkArrivals(task_pool, tick);

        if (taskArrive != NULL)
        {

            if (execTask(taskArrive, taskArrive->total_ticks) < 0)
            {
                printf("%sERROR:%s No Task selected to be executed.\n", COLOR_RED, COLOR_RESET);
                break;
            }
        }

        tick++;
    }

    printf("\n");
}
