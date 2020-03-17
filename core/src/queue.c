#include "queue.h"

static int queue_at_capacity(queue_t* queue)
{
	return queue->size >= queue->capacity;
}

queue_t* queue_init(size_t capacity)
{
	if(capacity > INT_MAX / sizeof(void*))
	{
		return NULL;
	}

	queue_t* queue = (queue_t*)malloc(sizeof(queue_t));
	void** data = (void**)malloc(capacity * sizeof(void*));
	if(!queue||!data)
	{
		free(queue);
		free(data);
		return NULL;
	}

	queue->size = 0;
	queue->next = 0;
	queue->capacity = capacity;
	queue->data = data;
	return queue;
}

void queue_dispose(queue_t* queue)
{
	free(queue->data);
	free(queue);
}

int queue_add(queue_t* queue, void* value)
{
	if(queue_at_capacity(queue))
	{
		return -1;
	}
	int pos = queue->next + queue->size;
	if(pos >= queue->capacity)
	{
		pos -= queue->capacity;
	}

	queue->data[pos] = value;
	queue->size++;
	return 0;
}

void* queue_remove(queue_t* queue)
{
	void* value = NULL;
	if(queue->size > 0)
	{
		value = queue->data[queue->next];
		queue->next++;
		queue->size--;
		if(queue->next >= queue->capacity)
		{
			queue->next -= queue->capacity;
		}
	}
	return value;
}

void* queue_peek(queue_t* queue)
{
	return queue->size ? queue->data[queue->next] : NULL;
}
