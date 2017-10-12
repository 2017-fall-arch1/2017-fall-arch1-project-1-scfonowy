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
Graph* newGraph();

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

// performs BFS on the graph,
// printing steps of path if it exists,
// or printing that it does not exist.
// param graph :: the graph being searched
// param from :: the name of the node to start from
// param to :: the name of the destination node
void bfs(Graph* graph, char from, char to);

// performs DFS on the graph,
// printing steps of the path if it exists,
// or printing that it does not exist.
// param graph :: the graph being searched
// param from :: the name of the node to start from
// param to :: the name of the destination node
void dfs(Graph* graph, char from, char to);

#endif
