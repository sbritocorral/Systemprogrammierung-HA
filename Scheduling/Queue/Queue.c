#include "queue.h"

#include <stdio.h>
#include <stdlib.h>




Queue* queue_new()
{
	Queue *newelem = malloc(sizeof(Queue));
	
	newelem->root = NULL;
	
	return newelem;
}

task_elem* task_elem_new(Task *task)
{
	task_elem* new_elem = malloc(sizeof(task_elem));
	
	new_elem->task = task;	
		
	new_elem->next = NULL;
	
	return new_elem;
}

void queue_free(Queue *queue)
{
	task_elem * tmp = NULL;
	
	while(queue->root != NULL){
		
		tmp= queue->root;
		queue->root = queue->root->next;
		
		free(tmp);	
	}

	free(queue);

	

}

void offer(Queue *queue, task_elem* newElem){

	if(queue->root == NULL){
		queue->root = newElem;
	}
	else{
		task_elem* tmp = queue->root;

		while(tmp->next != NULL){
			tmp = tmp->next;
		}

		tmp->next = newElem;
	}
}

void sjn_offer(Queue *queue, task_elem* newElem)
{
	
	if(newElem == NULL){
		
		return ;
	}
	
	if(queue->root == NULL){
		
		queue->root = newElem;
		return ;
	}
	

	
	
	if(queue->root->next == NULL){
		
		if(newElem->task->total_ticks < queue->root->task->total_ticks){
			
			newElem->next = queue->root;
			
			queue->root = newElem;	
		}
		else{
			
			queue->root->next = newElem;	
		}
		
		return ;
	}




		if(newElem->task->total_ticks < queue->root->task->total_ticks){
			newElem->next = queue->root;
			
			queue->root = newElem;
		}
		else if(newElem->task->total_ticks < queue->root->next->task->total_ticks){

			newElem->next = queue->root->next;

			queue->root->next = newElem;
		}
		else{

			task_elem *tmp1 = queue->root;
			task_elem *tmp2 = queue->root->next;

			
			while(tmp2!=NULL){
				
				if(newElem->task->total_ticks < tmp2->task->total_ticks){	
					break;	
				}
				tmp1 = tmp1->next;
				tmp2 = tmp2->next;
			}

				tmp1->next = newElem;
				newElem->next = tmp2;
		}
		
	
	
	return ;
	
}

Task* queue_peek(Queue *queue)
{
	if(queue->root == NULL){
		return NULL;
	}

	return queue->root->task;
	
}

Task* queue_poll(Queue *queue)
{
	
	if(queue->root == NULL){
		return NULL;
	}
	
	task_elem *tmp = queue->root;
	
	queue->root = queue->root->next;
	
	
	Task* pointer = tmp->task;
	
	free(tmp);

	
	return pointer;
	
}


