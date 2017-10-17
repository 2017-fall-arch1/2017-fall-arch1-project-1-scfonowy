#ifndef STACK_H_
#define STACK_H_

#include "DataNode.h"
#include <stdbool.h>

typedef struct Stack {
  StackNode* head;
  short size;
} Stack;

// creates a new stack
// returns :: an empty stack
Stack* newStack(void);

// pops the passed stack
// param stack :: the stack to pop
// returns :: the data in the popped stack node
char pop(Stack* stack);

// peeks the passed stack
// param stack :: the stack to peek
// returns :: the data in the peeked stack node
char peekStack(Stack* stack);

// pushes the passed element onto the stack
// param stack :: the stack to push onto
// param n :: the element to push onto the stack
void push(Stack* stack, char n);

// returns the size of the passed stack
// param stack :: the stack to be evaluated
// returns :: the size of the stack
int stackSize(Stack* stack);

// returns true if passed data is in stack
// param stack :: the stack to search
// param data :: the data to search for
// returns :: true if data in stack, false otherwise
bool inStack(Stack* stack, char data);

// deletes the passed stack
// param stack :: the stack to delete
void deleteStack(Stack* stack);

#endif
