#include "SJN.h"
#include <stdlib.h>

void schedule_SJN(const TaskPool *task_pool) {
    // TODO
   


     int tick = 0;

    

     Task ** array = malloc(sizeof(Task *) * (task_pool->size));
     int sizeForArray = 0;
     Task * temp = NULL; 
    while (!allDone(task_pool))
    {

        Task *taskArrive = checkArrivals(task_pool, tick);
        if(taskArrive!=NULL)
        {
        printf("Estas son las tareas que llegan : %s y en el tiempo : %d !!! \n" ,taskArrive->name,tick);
        }

        if(temp != NULL)
        {   
                if (execTask(temp, 1) < 0)
                {
                    printf("%sERROR:%s No Task selected to be executed.\n", COLOR_RED, COLOR_RESET);
                    break;
                }
            
            if(temp->total_ticks == temp->exec_ticks)
            {
              
                temp = NULL;   
            }
        }


        tick++;

        if (taskArrive != NULL)
        {
            //printf()
            array[sizeForArray] = taskArrive;
            
            sizeForArray++;
  
            if(temp == NULL)
            {
                
                Task * iterator = taskArrive;
                
            for(int x = 0 ; x< sizeForArray  ; x++)
            {
                //printf("Esto es sizeofArray : %d \n",sizeForArray);
                if(array[x] != NULL)
                {
                    if(array[x] -> total_ticks != array[x] -> exec_ticks )
                    {
                            if(iterator->total_ticks> array[x]->total_ticks)
                            {
                                iterator = array[x];
                            }
                    }

                }
                
            }

            temp = iterator;

                

            }
        }



        

        
    }

    printf("\n");




}
