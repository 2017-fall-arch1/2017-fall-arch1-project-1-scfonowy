#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include <errno.h>
#include "Graph.h"

///////// BEGIN CODE CITED FROM K&R C PROGRAMMING LANGUAGE 2e
#define BUFSIZE 100
char buf[BUFSIZE];
FILE *fp;
int bufp = 0;

int getchar() {
  return (bufp > 0) ? buf[--bufp] : fgetc(fp);
}

void ungetchar(int c) {
  if (bufp >= BUFSIZE) {
    printf("too many characters\r\n");
  } else {
    buf[bufp++] = c;
  }
}

int getword(char *word, int lim) {
  int c;
  char *w = word;
  
  while(isspace(c = getchar()));
  if (c != EOF) {
    *w++ = c;
  }
  if (!isalnum(c)) {
    *w = '\0';
    return c;
  }
  for ( ; --lim > 0; w++) {
    if (!isalnum(*w = getchar())) {
      ungetchar(*w);
      break;
    }
  }
  *w = '\0';
  return word[0];
}
///////// END CODE CITED FROM K&R C PROGRAMMING LANGUAGE 2e

// loads graph from passed file
Graph* loadGraphFromFile(char* filepath) {
  printf("Loading graph from file %s\r\n", filepath);
  fp = fopen(filepath, "r");
  if (fp == NULL) { // unable to open file
    printf("Error opening file: %s", strerror(errno));
    fclose(fp);
    return NULL;
  }
  
  Graph* graph = newGraph(); // graph to be returned
  char currentNode = 'A'; // node having outgoing edges added
  char edge[2]; // string used to read edges from file
  
  while(getword(edge, 2) != EOF && (currentNode - NODE_INDEX_OFFSET) < GRAPH_SIZE_LIMIT) {
    if (*edge == '!') { // reached end of line, increment node
      currentNode++;
    } else { // add edge into the graph
      addEdge(graph, currentNode, *edge);
    }
  }
  
  // return the graph
  fclose(fp);
  return graph;
}

// prints all the menu options
void printOptions() {
  printf("MAIN MENU\r\n");
  printf("1 - DEPTH-TRAVERSE GRAPH\r\n");
  printf("2 - BREADTH-TRAVERSE GRAPH\r\n");
  printf("3 - ADD EDGE\r\n");
  printf("4 - REMOVE EDGE\r\n");
  printf("5 - SAVE GRAPH\r\n");
  printf("6 - PRINT GRAPH\r\n");
  printf("0 - QUIT\r\n");
  printf("ENTER OPTION >> ");
}

// prompts user for input node and traverses graph
// param graph :: the graph to traverse
void traverseGraph(Graph* graph, bool isBreadth) {
  char node;
  printf("Enter node to begin from, e.g. A, B, C... >>");
  scanf(" %c", &node);
  if (isBreadth == true) {
    breadthTraversal(graph, node);
  } else {
    depthTraversal(graph, node);
  }
}

// prompts user for edges to add and adds them to the graph
// param graph :: the graph to modify
void addInputEdge(Graph* graph) {
  char from;
  char to;
  do {
    printf("Adding new edge:\r\n");
    printf("Enter origin node, 0 to quit >>");
    scanf(" %c", &from);
    if (from < 'A' || from > 'Z') { // check validity
      return;
    }
    
    printf("Enter destination node, 0 to quit >>");
    scanf(" %c", &to);
    if (to < 'A' || to > 'Z') { // check validity
      return;
    }
    
    addEdge(graph, from, to); // add the edge
  } while (from >= 'A' && from <= 'Z' && to >= 'A' && to <= 'Z');
  
  return;
}

// prompts user for edges to delete and removes them from the graph
// param graph :: the graph to remove edges from
void removeInputEdge(Graph* graph) {
  char from;
  char to;
  do {
    printf("Removing edge:\r\n");
    printf("Enter origin node, 0 to quit >>");
    scanf(" %c", &from);
    if (from < 'A' || from > 'Z') { // check validity
      return;
    }
    
    printf("Enter destination node, 0 to quit >>");
    scanf(" %c", &to);
    if (to < 'A' || to > 'Z') { // check validity
      return;
    }
    
    removeEdge(graph, from, to);
  } while (from >= 'A' && from <= 'Z' && to >= 'A' && to <= 'Z');
  
  return;
}

// saves the passed graph to a file
// param graph :: the graph to save
void saveGraph(Graph* graph) {
  fp = fopen("edges.txt", "w+");
  int i;
  for (i = 0; i < GRAPH_SIZE_LIMIT; i++) {
    if (graph->edge_list[i] != NULL) {
      GraphNode* edge = graph->edge_list[i];
      while(edge != NULL) {
	fprintf(fp, "%c ", edge->name);
	edge = edge->next;
      }
      fprintf(fp, "!\r\n");
    }
  }
  fclose(fp);
  return;
}

int main() {
  // initialize graph from file
  Graph* graph = loadGraphFromFile("edges.txt");
  int option;
  do {
    printOptions();
    scanf(" %d", &option); // get option
    switch (option) {
      case 1: traverseGraph(graph, false); break;
      case 2: traverseGraph(graph, true); break;
      case 3: addInputEdge(graph); break;
      case 4: removeInputEdge(graph); break;
      case 5: saveGraph(graph); break;
      case 6: printGraph(graph); break;
      case 0: break;
      default: printf("Invalid option.\r\n"); break;
    }
  } while (option != 0);
  printf("Terminating...\r\n");
  return 0;
}
