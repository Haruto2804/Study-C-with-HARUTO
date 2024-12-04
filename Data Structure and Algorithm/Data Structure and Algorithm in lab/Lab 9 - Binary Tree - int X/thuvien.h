#pragma once
#include <iostream>
using namespace std;
#include "windows.h"
typedef int TYPEINFO;
struct Node {
	TYPEINFO data;
	Node* right;
	Node* left;
};
typedef Node* Nodeptr;
typedef Nodeptr BST;
Nodeptr makeNode(int x);
void init_Tree(BST& root);
void gotoxy(short x, short y);
void insertTree(BST& root, int x);
void nhapCay(BST& root);
void NLR(BST T, int x, int y, int d);
void NLR(BST root);
void LNR(BST root);
void LRN(BST root);
int tongSoNut(BST t);
int tongNutLa(BST t);
int chieuCao(BST tree);
int muc_Cay(BST root, TYPEINFO x);
bool tim_Node(BST tree, TYPEINFO a);
bool delNode(BST &t, TYPEINFO x);
Nodeptr findMax(BST tree);
Nodeptr findKey(BST t, TYPEINFO x);