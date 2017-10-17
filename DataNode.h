#ifndef DATA_NODE_H
#define DATA_NODE_H

typedef struct DataNode {
  char data; // data in the node
  struct DataNode* next;
}DataNode;

typedef DataNode StackNode;
typedef DataNode QueueNode;

// creates a new datanode with the passed data
// param data :: the data to initialize the data node with
// returns :: a pointer to the new node
DataNode* newDataNode(char data);

// unwraps and deletes the passed node
// param node :: the node to unwrap
// returns :: the contents of the node
char unwrapDataNode(DataNode* node);

// deletes the passed stack node
// param node :: the node to delete
void deleteDataNode(DataNode* node);

#endif
