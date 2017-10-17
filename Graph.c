#include "Graph.h"
#include "Stack.h"
#include "Queue.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

const short GRAPH_SIZE_LIMIT = 26;
const short NODE_INDEX_OFFSET = 65;

// creates and returns a new, empty graph
Graph* newGraph(void) {
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
      GraphNode* del = current->next;
      current->next = current->next->next;
      del->next = 0;
      deleteGraphNode(del);
      return;
    }
  }
  
  return;
}

// performs BFS on the graph, printing steps
void breadthTraversal(Graph* graph, char from) {
  if (graph == NULL) {
    printf("Attempted to perform BFT on null graph.\r\n");
  }
  printf("Performing a breadth-first traversal from %c\r\n", from);
  
  Queue* fringe = newQueue(); // fringe of nodes to search
  Queue* visited = newQueue(); // list of nodes visited
  
  // initialize fringe with initial node
  enqueue(fringe, from);
  
  char currentNode;
  char currentIndex;
  GraphNode* edge;
  while (queueSize(fringe) > 0) {
    // get current node & index
    currentNode = pollQueue(fringe);
    currentIndex = currentNode - NODE_INDEX_OFFSET;
    enqueue(visited, currentNode);
    printf("Visiting %c...\r\n", currentNode);
    
    // insert adjacent nodes into fringe
    edge = graph->edge_list[currentIndex];
    while (edge != NULL) {
      if (inQueue(fringe, edge->name) == false && inQueue(visited, edge->name) == false) {
        // only insert if not in queues already
        enqueue(fringe, edge->name);
      }
      edge = edge->next;
    }
    
  }
  
  printf("Traversal completed.\r\n");
  return;
}

// performs DFS on the graph, printing steps
void depthTraversal(Graph* graph, char from) {
  if (graph == NULL) {
    printf("Attempted to perform DFT on null graph.\r\n");
  }
  printf("Performing a depth-first traversal from %c\r\n", from);
  
  Stack* fringe = newStack(); // fringe of nodes to search
  Stack* visited = newStack(); // list of nodes visited
  
  // initialize fringe with initial node
  push(fringe, from);
  
  char currentNode;
  char currentIndex;
  GraphNode* edge;
  while (stackSize(fringe) > 0) {
    // get current node & index
    currentNode = pop(fringe);
    currentIndex = currentNode - NODE_INDEX_OFFSET;
    push(visited, currentNode);
    printf("Visiting %c...\r\n", currentNode);
    
    // insert adjacent nodes into fringe
    edge = graph->edge_list[currentIndex];
    while (edge != NULL) {
      if (inStack(fringe, edge->name) == false && inStack(visited, edge->name) == false) {
        // only insert if not in stacks already
        push(fringe, edge->name);
      }
      edge = edge->next;
    }
    
  }
  
  printf("Traversal completed.\r\n");
  return;
}

// deletes the passed graph
void deleteGraph(Graph* graph) {
  int i;
  for (i = 0; i < GRAPH_SIZE_LIMIT; i++) {
    deleteGraphNode(graph->edge_list[i]);
  }
  free(graph);
  return;
}

// prints all edges in the graph
void printGraph(Graph* graph) {
  char i;
  for (i = 0; i < GRAPH_SIZE_LIMIT; i++) {
    printf("Edges leaving %c:\r\n", i+NODE_INDEX_OFFSET);
    GraphNode* edge = graph->edge_list[i];
    while (edge != NULL) {
      printf("- %c\r\n", edge->name);
      edge = edge->next;
    }
  }
  return;
}
