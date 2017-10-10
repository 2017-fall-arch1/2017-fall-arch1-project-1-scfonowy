#ifndef GRAPHNODE_H_
#define GRAPHNODE_H_

// definition of graph node
typedef struct GraphNode {
  char name; // the "name" of the graph node (e.g. A, B, etc.)
  struct GraphNode* next; // the next graph node
} GraphNode;

// creates and returns a new graph node
// param name :: the name of the node (e.g. A, B, etc.)
GraphNode* newGraphNode(char name);

// deletes the passed graph node
// param node :: the node to be deleted
void deleteGraphNode(GraphNode* node);

#endif
