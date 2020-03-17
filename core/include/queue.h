#ifndef QUEUE_H
#define QUEUE_H
#include <malloc.h>
#include <stddef.h>

#include <limits.h>

// Defines a circular buffer which acts as a FIFIO
typedef struct queue_t
{
	unsigned size;
	int next;
	unsigned capacity;
	void** data;
} queue_t;


// Create a new queue with the gien capacity
queue_t* queue_init(size_t capacity);

// Release the queue
void queue_dispose(queue_t* queue);

// Adds an item to the queue, will return 0 if success, -1 if
// failed.
int queue_add(queue_t* queue, void* value);

// Dequeues an item from the head of the queue. Will return 
// NULL if the queue is empty.
void* queue_remove(queue_t* queue);

// Returns but does not remove head of queue. Will return NULL
// if the queue is empty.
void* queue_peek(queue_t* queue);

#endif
