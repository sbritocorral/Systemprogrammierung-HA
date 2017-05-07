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
	PrioQueue *new = malloc(sizeof(PrioQueue));
	return new;
}

q_elem* q_elem_new(int priority, char* name)
{
	q_elem * new_elem = malloc(sizeof(q_elem_s));
	
	new_elem->priority = priority;	
	strcpy(new_elem->name, name);
	
	return new_elem;
}

void pqueue_free(PrioQueue *queue)
{
	q_elem * tmp = null;
	
	while(queue->root != null){
		
		tmp= queue->root;
		queue->root = queue->root->next;
		
		free(tmp);	
	}

}

char* pqueue_offer(PrioQueue *queue, q_elem* newElem)
{
	
	q_elem *tmp1 = queue->root;
	q_elem *tmp2 = queue->root->next;
	
	
	if(queue->root->next != null){
		
		if(newElem->priority)
		
	}
	
	while(tmp2!=null){
		
		if(newElem->priority > tmp2->priority){
			
			tmp1->next = newElem;
			newElem->next = tmp2;	
		}
		else{		
			newElem->next = tmp2->next;
			tmp2->next = newElem;
		}
			
		tmp1 = tmp1->next;
		tmp2 = tmp2->next;
	}
	
	
	
	return NULL;
}

char* pqueue_peek(PrioQueue *queue)
{
	//TODO
	return NULL;
}

char* pqueue_poll(PrioQueue *queue)
{
	//TODO
	return NULL;
}

int pqueue_size(PrioQueue *queue)
{
	//TODO
	return -1;
}

void pqueue_print(PrioQueue *queue)
{
	//TODO
}

