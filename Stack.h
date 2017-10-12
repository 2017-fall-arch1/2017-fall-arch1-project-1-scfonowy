#ifndef STACK_H_
#define STACK_H_

#include "StackNode.h"

typedef struct Stack {
  StackNode* head;
}Stack;

// pops the passed stack
// param stack :: the stack to pop
// returns :: the popped StackNode
StackNode* pop(Stack* stack);

// pushes the passed element onto the
// passed stack.
// param stack :: the stack to push onto
// param n :: the element to push onto the stack
void push(Stack* stack, char n);

// returns the size of the passed stack
// param stack :: the stack to be evaluated
// returns :: the size of the stack
int stackSize(Stack* stack);

//deletes the passed stack
// param stack :: the stack to delete
void deleteStack(Stack* stack);

#endif
