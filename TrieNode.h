#ifndef TRIENODE_H_
#define TRIENODE_H_
#include<stdbool.h>
#include<stdlib.h>

typedef struct TrieNode {
  struct TrieNode* children[NUM_LETTERS]; // 26 characters, not case-sensitive
  bool isLeaf;
} TrieNode;

TrieNode* newTrieNode();

#endif
