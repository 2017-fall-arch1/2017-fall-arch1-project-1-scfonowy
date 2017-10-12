#ifndef STACK_NODE_H
#define STACK_NODE_H

typedef struct StackNode {
  char name; // name of graph node
  struct StackNode* next;
}StackNode;

// unwraps and deletes the passed node
// param node :: the node to unwrap
// returns :: the contents of the stack
char unwrapStackNode(StackNode* node);

// deletes the passed stack node
// param node :: the node to delete
void deleteStackNode(StackNode* node);

#endif
