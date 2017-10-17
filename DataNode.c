#include "DataNode.h"
#include <stdlib.h>
#include <stdio.h>

// creates a new stack node with the passed data
DataNode* newDataNode(char data) {
  DataNode* node = (DataNode* )malloc(sizeof(DataNode));
  node->data = data;
  node->next = NULL;
  return node;
}

// unwraps and deletes the passed node
char unwrapDataNode(DataNode* node) {
  if (node != NULL) {
    char data = node->data;
    deleteDataNode(node);
    return data;
  } else {
    printf("Attempted to unwrap null node.\r\n");
  }
  return -1;
}

// deletes the passed data node
void deleteDataNode(DataNode* node) {
  free(node);
  return;
}
