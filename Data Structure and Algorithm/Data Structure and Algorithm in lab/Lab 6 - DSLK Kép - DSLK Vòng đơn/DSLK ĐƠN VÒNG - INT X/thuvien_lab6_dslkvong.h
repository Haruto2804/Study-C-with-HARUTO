#pragma once
#include <iostream>
using namespace std;
typedef int TYPEINFO;
struct Node {
	TYPEINFO data;
	Node* next;
};
typedef Node* Nodeptr;
struct List {
	Nodeptr first;
	Nodeptr last;
};
Nodeptr tao_Node2(TYPEINFO x);
void khoiTao(List& list);
int isEmpty(List& list);
void them_Dau(List& list, TYPEINFO x);
void them_Cuoi(List& list, TYPEINFO x);
void readList_Dau(List& list);
void readList_Cuoi(List& list);
void printList(List list);
void xoa_Dau(List& list);
void xoa_Cuoi(List& list);
bool tim_X(List list, TYPEINFO x);


