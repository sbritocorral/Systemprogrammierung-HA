#include "MLF.h"
#include "../Queue/queue.h"
#include <math.h>
#include <stdlib.h>

void schedule_MLF(const TaskPool *task_pool, uint16_t num_levels)
{

    int tick = 0;
    int quantum = 0;

    int numPiscina = 0;

    Queue **piscina = malloc(sizeof(Queue *) * (num_levels + 1));

    for (int i = 0; i < num_levels; i++)
    {
        piscina[i] = queue_new();
    }

    while (!allDone(task_pool))
    {
        Task *taskArrive = checkArrivals(task_pool, tick);

        task_elem *tmp = NULL;

        if (taskArrive != NULL)
        {
            offer(piscina[0], task_elem_new(taskArrive));
        }

        Task *gg = NULL;

        for (int i = 0; i < num_levels; i++)
        {

            if ((gg = queue_poll(piscina[i])) != NULL)
            {

                tmp = task_elem_new(gg);

                numPiscina = i;
                break;
            }
        }

        if (tmp != NULL)
        {
            if (numPiscina == num_levels - 1)
            {
                int remainingTicks = tmp->task->total_ticks - tmp->task->exec_ticks;
                for (int i = 0; i < remainingTicks; i++)
                {
                    if (!isDone(tmp->task))
                    {
                        if (execTask(tmp->task, 1) < 0)
                        {
                            printf("%sERROR:%s No Task selected to be executed.\n", COLOR_RED, COLOR_RESET);
                            break;
                        }
                    }

                    if (i != remainingTicks - 1)
                    {
                        tick++;
                        Task *taskArrive = checkArrivals(task_pool, tick);

                        if (taskArrive != NULL)
                        {
                            offer(piscina[0], task_elem_new(taskArrive));
                        }
                    }
                }

                free(tmp);
            }

           // Aqui me repito para caso de queue y fcfs

            else
            {
                quantum = (int)pow(2.0, (double)numPiscina);

                //printf("Esto es quantum : %d\n", quantum);
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

                    if (i != quantum - 1)
                    {
                        tick++;
                        Task *taskArrive = checkArrivals(task_pool, tick);

                        if (taskArrive != NULL)
                        {
                            offer(piscina[0], task_elem_new(taskArrive));
                        }
                    }
                }

                if (tmp->task->exec_ticks != tmp->task->total_ticks)
                {
                    if (numPiscina != num_levels - 1)
                    {
                        offer(piscina[numPiscina + 1], tmp);
                    }
                }
                else{
                    free(tmp);
                }

                
            }

            
        }

        tick++;
    }

    for (int i = 0; i < num_levels; i++)
    {
        queue_free(piscina[i]);
    }

    free(piscina);

    printf("\n");
}

