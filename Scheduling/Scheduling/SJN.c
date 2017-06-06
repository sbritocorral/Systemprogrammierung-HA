#include "SJN.h"
#include "../Queue/queue.h"
#include <stdlib.h>


void schedule_SJN(const TaskPool *task_pool) {
    // TODO
   
   
int tick = 0;

Task * temp = NULL;

Queue * queue =  queue_new();

   

   

while(!allDone(task_pool))
{

    Task * arrive = checkArrivals(task_pool,tick);

     if(arrive != NULL)
    {
        task_elem * element = task_elem_new(arrive);
        sjn_offer(queue,element);
        temp = queue_poll(queue);
    }

    

    if(temp != NULL && !isDone(temp))
    {
        while(!isDone(temp))
        {
            if (execTask(temp, 1) < 0) {
            printf("%sERROR:%s No Task selected to be executed.\n", COLOR_RED, COLOR_RESET);
            break;
            }
        tick++;
        Task * arrivedWhileIsDone = checkArrivals(task_pool,tick);
        if(arrivedWhileIsDone != NULL)
        {
          task_elem * elementen = task_elem_new(arrivedWhileIsDone);
          sjn_offer(queue,elementen);
        }

        }
        temp = queue_poll(queue);
        continue;
    }

    tick++;
}

queue_free(queue);

}
