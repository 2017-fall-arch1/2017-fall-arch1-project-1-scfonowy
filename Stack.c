#include "Stack.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

// creates a new stack
Stack* newStack(void)  {
  Stack* stack = (Stack* )malloc(sizeof(Stack));
  stack->size = 0;
  return stack;
}

// pops the passed stack
char pop(Stack* stack) {
  if (stack == NULL) {
    printf("Attempted to pop a null stack.\r\n");
    return -1;
  }
  if (stack->head == NULL) {
    printf("Attempted to pop an empty stack.\r\n");
    return -1;
  }
  
  StackNode* oldHead = stack->head;
  stack->head = oldHead->next;
  stack->size -= 1;
  return unwrapDataNode(oldHead);
}

// peeks the passed stack
char peekStack(Stack* stack) {
  if (stack == NULL) {
    printf("Attempted to peek a null stack.\r\n");
    return -1;
  }
  if (stack->head == NULL) {
    printf("Attempted to peek an empty stack.\r\n");
  }
  
  return stack->head->data;
}

// pushes the passed element onto the passed stack
void push (Stack* stack, char n) {
  if (stack == NULL) {
    printf("Attempted to push onto a null stack.\r\n");
    return;
  }
  
  StackNode* node = newDataNode(n);
  node->next = stack->head;
  stack->head = node;
  stack->size += 1;
  return;
}

// returns the size of the passed stack
int stackSize(Stack* stack) {
  if (stack == NULL) {
    printf("Attempted to get size of null stack.\r\n");
    return -1;
  }
  
  return stack->size;
}

// returns true if passed data is in stack
bool inStack(Stack* stack, char data) {
  if (stack == NULL) {
    printf("Attempted to search null stack.\r\n");
    return false;
  }
  if (stack->head == NULL) {
    return false;
  }
  
  StackNode* current = stack->head;
  while (current != NULL) {
    if (current->data == data) {
      return true;
    }
    current = current->next;
  }
  
  return false;
}

// deletes the passed stack
void deleteStack(Stack* stack) {
  if (stack == NULL) {
    return;
  }
  
  // delete all nodes in stack
  while (stack->head != NULL) {
    StackNode* oldHead = stack->head;
    stack->head = stack->head->next;
    deleteDataNode(oldHead);
  }
  
  // delete stack object
  free(stack);
  return;
}
