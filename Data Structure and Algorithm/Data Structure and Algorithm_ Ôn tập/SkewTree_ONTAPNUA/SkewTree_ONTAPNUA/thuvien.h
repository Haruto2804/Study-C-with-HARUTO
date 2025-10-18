#pragma once
#include <iostream>
using namespace std;
struct Node {
	int data;
	Node* right;
	Node* left;
};
typedef struct Node* SkewTree;
SkewTree makeNode(int x);
SkewTree insert(SkewTree tree, int x);
SkewTree deleteT(SkewTree tree, int &x);
SkewTree merge(SkewTree h1, SkewTree h2);
void preOrder(Node* root);
