# Project 1 - Graph Manager - CS3432 Fall 2017
--
*Steven Brooks, last updated October 17th, 2017*

**NOTE:** This project was done in place of the Binary Search Tree Personnel Manager, as I had completed that project when taking the course a year prior. This project was discussed with and approved by the CS3432 lab TA as skill-equivalent.
## Introduction
This project contains a relatively simple implementation of a directed graph in C, along with a driver that allows users to perform depth-first traversals, breadth-first traversals, add and remove edges, print the graph, and save the graph to a file.

The graph is represented internally by an adjacency list, with size limit 26 (each node is denoted by a capital letter in the English alphabet). As one might expect, there are also simple implementations of Stack and Queue data structures in order to perform depth-first and breadth-first traversals. Both Stack and Queue use the DataNode structure, aliased accordingly (e.g. a DataNode for a Stack is a StackNode).

Because the graph is represented as a fixed-size adjacency list, there is no need to add or remove nodes. If a node has an incoming or outgoing edge, it "exists." If it does not, the program does not print or acknowledge it, effectively making it nonexistant.

## Setup & Running
In order to run this program:

1. Clone or download this repository.
2. Navigate to the root folder of the repository.
3. Run `$ make`.
4. Start the program with `$ ./main`.

If you wish to clean up the object files created during compilation, simply run `$ make clean` in the root folder of the repository.

## Program Overview
Users will be presented with six options upon running the program. To select one, simply enter the number of the option you wish to run. A table with the options and a brief description is below.

| Option  | Description  |
|---|---|
| 1 - DEPTH-TRAVERSE GRAPH | Traverses the graph depth-first. |
| 2 - BREADTH-TRAVERSE GRAPH | Traverses the graph breadth-first. |
| 3 - ADD EDGE | Starts a prompt in which the user can add edges to the graph. |
| 4 - REMOVE EDGE | Starts a prompt in which the user can remove edges from the graph. |
| 5 - SAVE GRAPH | Saves the current state of the graph to disk. |
| 6 - PRINT GRAPH | For every node with outgoing edges, prints the node and its outgoing edges. |
| 0 - QUIT | Exits the program. |

The program comes pre-loaded with some edges as demonstration. The graph is saved and loaded from `edges.txt` in the root directory of the repository.

## Edge File Format
Outgoing edges are read in from the file line-by-line, each line representing the node from which the edge originates (e.g. line 1 is node A, line 2 is node B, etc.) Lines are terminated with a `!` character, so nodes with no outgoing edges should still have at least the `!`. As an example, the below edge file snippet defines node A with outgoing edges to B and C, node B with outgoing edge to A, and node C with no outgoing edges.

```
B C !
A !
!
```

## BFS and DFS
Breadth-first traversal and depth-first traversal are well-known algorithms for walking a graph, either directed or undirected. Pseudocode for both is provided below. The algorithms are identical, only breadth-first search uses a queue and depth-first uses a stack. While it is possible to use recursion for depth-first (removing the need for a stack fringe), this project's goal was to write data structures in C, so the approach that made use of stacks was chosen.

### BFS
```
bfs(origin):
	fringe = queue()
	fringe.enqueue(origin)
	
	while fringe.size > 0:
		current_node = fringe.poll()
		print(current_node)
		for adjacent_node in current_node.adjacent_nodes:
			if adjacent_node not in fringe AND not visited:
				fringe.enqueue(adjacent_node)
```

### DFS
```
dfs(origin):
	fringe = stack()
	fringe.push(origin)
	
	while fringe.size > 0:
		current_node = fringe.pop()
		print(current_node)
		for adjacent_node in current_node.adjacent_nodes:
			if adjacent_node not in fringe AND not visited:
				fringe.push(adjacent_node)
```

## Attributions
Several sources were used in the completion of this lab.

1. Dr. Eric Freudenthal's provided Linked List code, which is in the folder Linked List Demo Code (in particular, the Makefile was very helpful.)
2. Kernighan & Ritchie's *The C Programming Language, 2e*, Chapters 4 and 6 for `getword()` and associated methods.
