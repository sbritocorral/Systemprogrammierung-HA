#include "PrioQueue.h"
#include <stdio.h>

int main()
{

	PrioQueue *queue = pqueue_new();

	pqueue_offer(queue, q_elem_new(3, "1"));
	pqueue_offer(queue, q_elem_new(5, "2"));
	pqueue_peek(queue);
	pqueue_offer(queue,q_elem_new(2, "3"));
	pqueue_offer(queue, q_elem_new(4, "4"));
	pqueue_peek(queue);
	pqueue_offer(queue, q_elem_new(2, "3"));
	pqueue_offer(queue, q_elem_new(4, "4"));
	pqueue_offer(queue, q_elem_new(2, "3"));
	pqueue_peek(queue);
	pqueue_offer(queue, q_elem_new(4, "4"));

	pqueue_print(queue);
	// should print: (5,2)(4,4)(4,4)(4,4)(3,1)(2,3)(2,3)(2,3)

	pqueue_free(queue);
	// use: valgrind ./PrioQueue
	// to check if your free function works correctly 
	
	return 0;
}