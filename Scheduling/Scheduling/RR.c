#include "RR.h"
#include "../Queue/queue.h"
#include <stdlib.h>

void schedule_RR(const TaskPool *task_pool, uint16_t quantum_max)
{

    int tick = 0;
    int quantum = quantum_max;

    Queue *queue = queue_new();

    task_elem *tmp = NULL;

    while (!allDone(task_pool))
    {
        Task *taskArrive = checkArrivals(task_pool, tick);

        if (taskArrive != NULL)
        {
            offer(queue, task_elem_new(taskArrive));
        }

         if (tmp != NULL)
        {
            if (tmp->task->exec_ticks != tmp->task->total_ticks)
            {
                offer(queue, tmp);
            }
            else
            {
                free(tmp);
            }
        }
        tmp = NULL;
        tmp = task_elem_new(queue_poll(queue));

        if (tmp != NULL)
        {

            for (int i = 0; i < quantum; i++)
            {

                if (!isDone(tmp->task))
                {
                    if (execTask(tmp->task, 1) < 0)
                    {
                        printf("%sERROR:%s No Task selected to be executed.\n", COLOR_RED, COLOR_RESET);
                        break;
                    }
                }

                if (i != quantum - 1 && !isDone(tmp->task))
                {
                    tick++;
                    Task *taskArrive = checkArrivals(task_pool, tick);

                    if (taskArrive != NULL)
                    {
                        offer(queue, task_elem_new(taskArrive));
                    }
                }
            }
        }

        tick++;
    }

    queue_free(queue);

    printf("\n");
}
