#ifndef QUEUE_H_
#define QUEUE_H_

#include "DataNode.h"
#include <stdbool.h>

typedef struct Queue {
  QueueNode* head;
  short size;
} Queue;

// creates a new queue
// returns :: the new queue
Queue* newQueue(void);

// polls the passed queue
// param queue :: the queue to poll
// returns :: the data polled
char pollQueue(Queue* queue);

// peeks the passed queue
// param queue :: the queue to peek
// returns :: the data peeked
char peekQueue(Queue* queue);

// enqueues the passed data onto the queue
// param queue :: the queue to enqueue onto
// param data :: the data to enqueue
void enqueue(Queue* queue, char data);

// returns the size of the passed queue
// param queue :: the queue to get the size of
// returns :: the size of the queue
short queueSize(Queue* queue);

// returns true if the passed data is in the queue
// param queue :: the queue to search
// param data :: the data to search for
// returns :: true if data in queue, false otherwise
bool inQueue(Queue* queue, char data);

// deletes the passed queue
// param queue :: the queue to delete
void deleteQueue(Queue* queue);

#endif
