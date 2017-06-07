#include "../Tasks/Task.h"


typedef struct _task_elem
{
	Task* task;
	struct _task_elem *next;
}task_elem;

typedef struct Queue 
{
	task_elem *root;
}Queue;


Queue* queue_new();

task_elem* task_elem_new(Task *task);

void queue_free(Queue *queue);

void offer(Queue *queue, task_elem* newElem);

void sjn_offer(Queue *queue, task_elem* newElem);

Task* queue_peek(Queue *queue);

Task* queue_poll(Queue *queue);



