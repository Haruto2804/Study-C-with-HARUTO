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
Node* createNode(int x);
AVLTREE insert(AVLTREE T, int x);
void Init(AVLTREE& T);
int height(AVLTREE T);
int getBalance(AVLTREE T);
int max(int a, int b);
void preOrder(AVLTREE T);
AVLTREE RotateRight(AVLTREE T);
AVLTREE RotateLeft(AVLTREE T);


