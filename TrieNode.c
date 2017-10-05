#include "TrieNode.h"

TrieNode* newTrieNode() {
  TrieNode* node = (TrieNode*)malloc(sizeof(TrieNode));
  node->isLeaf = false;
  return node;
}
