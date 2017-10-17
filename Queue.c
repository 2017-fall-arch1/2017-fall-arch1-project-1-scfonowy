#include "Queue.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

// creates a new queue
Queue* newQueue() {
  Queue* queue = (Queue* )malloc(sizeof(Queue));
  queue->head = NULL;
  queue->size = 0;
  return queue;
}

// polls the passed queue
char pollQueue(Queue* queue) {
  if (queue == NULL) {
    printf("Attempted to poll null queue.\r\n");
    return -1;
  }
  if (queue->head == NULL) {
    printf("Attempted to poll empty queue.\r\n");
    return -1;
  }
  
  QueueNode* oldHead = queue->head;
  queue->head = queue->head->next;
  char data = unwrapDataNode(oldHead);
  queue->size -= 1;
  return data;
}

// peeks the passed queue
char peekQueue(Queue* queue) {
  if (queue == NULL) {
    printf("Attempted to peek null queue.\r\n");
    return -1;
  }
  if (queue->head == NULL) {
    printf("Attempted to peek empty queue.\r\n");
  }
  
  return queue->head->data;
}

// enqueues the passed data onto the queue
void enqueue(Queue* queue, char n) {
  if (queue == NULL) {
    printf("Attempted to enqueue onto null queue.\r\n");
  }
  
  QueueNode* node = newDataNode(n);
  if (queue->head == NULL) { // fringe case
    queue->head = node;
    queue->size += 1;
    return;
  }
  
  QueueNode* insertPoint = queue->head;
  while (insertPoint->next != NULL) {
    insertPoint = insertPoint->next;
  }
  insertPoint->next = node;
  queue->size += 1;
  return;
}

// returns the size of the passed queue
short queueSize(Queue* queue) {
  if (queue == NULL) {
    printf("Attempted to get size of null queue.\r\n");
    return -1;
  }
  return queue->size;
}

// returns true if the passed data is in the queue
bool inQueue(Queue* queue, char data) {
  if (queue == NULL) {
    printf("Attempted to search null queue.\r\n");
    return false;
  }
  if (queue->head == NULL) {
    return false;
  }
  
  QueueNode* current = queue->head;
  while (current != NULL) {
    if (current->data == data) {
      return true;
    }
    current = current->next;
  }
  
  return false;
}

// deletes the passed queue
void deleteQueue(Queue* queue) {
  if (queue == NULL) {
    return;
  }
  
  while (queue->head != NULL) {
    QueueNode* node = queue->head;
    queue->head = queue->head->next;
    deleteDataNode(node);
  }
  free(queue);
  return;
}
