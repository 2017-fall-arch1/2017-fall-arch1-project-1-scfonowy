#include "GraphNode.h"
#include <stdlib.h>

// creates and returns a new graph node
// param name :: the name of the node
GraphNode* newGraphNode(char name) {
  GraphNode* node = (GraphNode *)malloc(sizeof(GraphNode));
  node->name = name;
  return node;
}

// deletes the passed graph node
// param node :: the node to be deleted
void deleteGraphNode(GraphNode* node) {
  if (node == 0) {
    return;
  }
  deleteGraphNode(node->next);
  free(node);
}
