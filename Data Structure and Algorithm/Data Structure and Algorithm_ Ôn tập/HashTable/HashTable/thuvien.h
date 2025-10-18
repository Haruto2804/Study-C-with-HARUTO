#pragma once
#include <iostream>
const int MAX = 100;
using namespace std;
struct Node {
	int data;
	Node* next;
};
typedef Node* NodePtr;
typedef int TYPEINFO;
struct HashTable {
	int n;
	NodePtr list[MAX];
};
NodePtr createNode(int x);
void insertHashTable(HashTable& ht, TYPEINFO x);
void xuatHashTable(HashTable ht);
int funcHash(TYPEINFO x, HashTable ht);
void pushBack(NodePtr& list, int x);
void khoiTaoHT(HashTable& ht);
