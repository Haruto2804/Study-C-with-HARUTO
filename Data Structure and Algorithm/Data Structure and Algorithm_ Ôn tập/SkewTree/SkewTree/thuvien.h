#pragma once
#include <iostream>
using namespace std;
struct Node {
	int data;
	Node* left;
	Node* right;
};
typedef Node* SkewTree;
SkewTree createNode(int x);
SkewTree Merge(SkewTree h1, SkewTree h2);
SkewTree Insert(SkewTree root, int x);
SkewTree DeleteMax(SkewTree root);
void preOrder(SkewTree root);
void Init(SkewTree& root);
