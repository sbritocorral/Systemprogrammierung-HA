#include "PrioQueue.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct q_elem_s
{
	char* name;
	int priority;
	struct q_elem_s *next;
};

struct PrioQueue
{
	int size;
	q_elem *root;
};

PrioQueue* pqueue_new()
{
	PrioQueue *newelem = malloc(sizeof(PrioQueue));
	
	newelem->root = NULL;
	newelem->size = 0;
	
	return newelem;
}

q_elem* q_elem_new(int priority, char* name)
{
	q_elem* new_elem = malloc(sizeof(q_elem));
	
	new_elem->priority = priority;	
	
	new_elem->name = name;
	
	new_elem->next = NULL;
	
	return new_elem;
}

void pqueue_free(PrioQueue *queue)
{
	q_elem * tmp = NULL;
	
	while(queue->root != NULL){
		
		tmp= queue->root;
		queue->root = queue->root->next;
		
		free(tmp);	
	}

	free(queue);

	

}

char* pqueue_offer(PrioQueue *queue, q_elem* newElem)
{
	
	if(newElem == NULL){
		
		return NULL;
	}
	
	if(queue->root == NULL){
		
		queue->root = newElem;
		queue->size++;
		return newElem->name;
	}
	
	queue->size++;
	
	
	
	
	if(queue->root->next == NULL){
		
		if(newElem->priority > queue->root->priority){
			
			newElem->next = queue->root;
			
			queue->root = newElem;	
		}
		else{
			
			queue->root->next = newElem;	
		}
		
		return newElem->name;
	}
	
	q_elem *tmp1 = queue->root;
	q_elem *tmp2 = queue->root->next;
	
	while(tmp2!=NULL){
		
		if(newElem->priority > tmp2->priority){	
			break;	
		}
		tmp1 = tmp1->next;
		tmp2 = tmp2->next;
	}

		tmp1->next = newElem;
			newElem->next = tmp2;
	
	return newElem->name;
	
}

char* pqueue_peek(PrioQueue *queue)
{
	if(queue->root == NULL){
		return NULL;
	}
	
	
	return queue->root->name;
	
}

char* pqueue_poll(PrioQueue *queue)
{
	
	if(queue->root == NULL){
		return NULL;
	}
	
	q_elem *tmp = queue->root;
	
	queue->root = queue->root->next;
	
	
	char*pointer = tmp->name;
	

	free(tmp);
	
	queue->size--;
	
	return pointer;
	
}

int pqueue_size(PrioQueue *queue)
{
	
	return queue->size;
}

void pqueue_print(PrioQueue *queue)
{
	q_elem *tmp = queue->root;
	
	while(tmp!=NULL){
		
		printf("(%d,%s)", tmp->priority, tmp->name);
		
		tmp = tmp->next;	
	}
	printf("\n");
	
	
}

