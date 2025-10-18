#pragma once
#include <iostream>
using namespace std;
struct Node {
	int data;
	Node* left;
	Node* right;
};
typedef Node* SPLAYTREE;
void init(SPLAYTREE& tree);
SPLAYTREE createNode(int x);
void rotateLeft(SPLAYTREE& tree);
void rotateRight(SPLAYTREE& tree);
SPLAYTREE find(SPLAYTREE& tree, int x);
SPLAYTREE insert(SPLAYTREE tree, int x);
SPLAYTREE insertAndSplay(SPLAYTREE tree, int x);
void preOrder(SPLAYTREE tree);
SPLAYTREE deleteKey (SPLAYTREE tree, int x);
SPLAYTREE splay(SPLAYTREE &tree, SPLAYTREE nutCanXoay);
void splayToRoot(SPLAYTREE& tree, SPLAYTREE nutCanXoay);
SPLAYTREE findMax(SPLAYTREE tree);



