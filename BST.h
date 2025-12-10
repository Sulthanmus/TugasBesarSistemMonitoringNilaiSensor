#ifndef BST_H_INCLUDED
#define BST_H_INCLUDED
#include <iostream>


using namespace std;

typedef struct Node * adrNode;

struct Node{
    int value;
    adrNode right;
    adrNode left;
};

void createTree(adrNode &root);
adrNode createNode(int x);
void insertNode(adrNode &root, adrNode p);
adrNode searchNode(adrNode root, int x);
void displayTree(adrNode root);
adrNode findMin(adrNode root);
void deleteNode(adrNode &root, int x);
void findPredecessor(adrNode root, adrNode& pre, int val);
void findSuccessor(adrNode root, adrNode& suc, int val);
void printPath(adrNode root, int x);
int heightTree(adrNode root);
int depthNode(adrNode root, int x, int level);
void printRange(adrNode root, int minVal, int maxVal);

#endif // BST_H_INCLUDED

