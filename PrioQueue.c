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
	//TODO
	return NULL;
}

q_elem* q_elem_new(int priority, char* name)
{
	//TODO
	return NULL;
}

void pqueue_free(PrioQueue *queue)
{
	//TODO
}

char* pqueue_offer(PrioQueue *queue, q_elem* newElem)
{
	//TODO
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

