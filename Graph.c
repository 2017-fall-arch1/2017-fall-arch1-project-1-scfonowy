#include "Graph.h"
#include <stdlib.h>

const short GRAPH_SIZE_LIMIT = 26;
const short NODE_INDEX_OFFSET = 65;

// creates and returns a new, empty graph
Graph* newGraph() {
  Graph* graph = (Graph* )malloc(sizeof(Graph));
  //graph->edge_list = (GraphNode* )[GRAPH_SIZE_LIMIT];
  int i;
  for (i = 0; i < GRAPH_SIZE_LIMIT; i++) {
    graph->edge_list[i] = 0;
  }
  return graph;
}

// adds unidirectional edge between 
void addEdge(Graph* graph, char from, char to) {
  int i = from - NODE_INDEX_OFFSET;
  GraphNode* oldFirstEdge = graph->edge_list[i];
  GraphNode* newFirstEdge = newGraphNode(to);
  newFirstEdge->next = oldFirstEdge;
  graph->edge_list[i] = newFirstEdge;
  return;
}

// deletes the passed edge from the graph
void removeEdge(Graph* graph, char from, char to) {
  int i = from - NODE_INDEX_OFFSET;
  GraphNode* current = graph->edge_list[i];

  if (current == 0) { // nothing to delete
    return;
  }

  if (current->name == to) { // fringe case
    graph->edge_list[i] = current->next;
    deleteGraphNode(current);
    return;
  }
  
  while (current->next != 0) {
    if (current->next->name == to) {
      current->next = current->next->next;
      deleteGraphNode(current->next);
      return;
    }
  }
  
  return;
}
