#ifndef GRAPH_H_
#define GRAPH_H_

#include "GraphNode.h"

extern const short GRAPH_SIZE_LIMIT;
extern const short NODE_INDEX_OFFSET;

// definition of the graph
typedef struct Graph {
  GraphNode *edge_list[26];
} Graph;

// creates and returns a new, empty graph
Graph* newGraph(void);

// adds a unidirectional edge between the two nodes
// param graph :: the graph to update
// param from :: the origin node
// param to :: the destination node
void addEdge(Graph* graph, char from, char to);

// removes an edge from the graph
// param graph :: the graph to update
// param from :: the origin node
// param to :: the destination node
void removeEdge(Graph* graph, char from, char to);

// performs a breadth-first traversal on the graph
// param graph :: the graph being searched
// param from :: the name of the node to start from
void breadthTraversal(Graph* graph, char from);

//performs a depth-first traversal on the graph
// param graph :: the graph being searched
// param from :: the name of the node to start from
void depthTraversal(Graph* graph, char from);

// deletes the passed graph
// param graph :: the graph to delete
void deleteGraph(Graph* graph);

// prints all edges in the graph
// param graph :: graph to print
void printGraph(Graph* graph);

#endif
