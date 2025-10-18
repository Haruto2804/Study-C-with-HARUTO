#pragma once
#include <iostream>
using namespace std;
struct Node {
	int data;
	Node* left;
	Node* right;
	int height;
};
typedef Node* AVLTREE;
AVLTREE createNode(int x);
void init(AVLTREE& root);
void rotateRight(AVLTREE& tree);
void rotateLeft(AVLTREE& tree);
AVLTREE insertKey(AVLTREE tree, int x);
AVLTREE deleteKey(AVLTREE tree, int x);
int height(AVLTREE tree);
int getBalance(AVLTREE tree);
void preOrder(AVLTREE tree);
int Max(int x, int y);
AVLTREE deleteKey(AVLTREE tree, int x);
AVLTREE findMin(AVLTREE tree);


