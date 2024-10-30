#pragma once
#pragma once
#include <iostream>
#include <string>
#include <iomanip>
#include <windows.h>
using namespace std;
struct MonHoc {
	string ma;
	string ten;
	int tinchi;
};
struct Node {
	MonHoc data;
	Node* next = NULL;
	Node* prev = NULL;
};

struct DList {
	Node* first;
	Node* last;
};
void Init(DList& list);
Node* makeNode(MonHoc mh);
void pushBack(DList& list, MonHoc mh);
void pushFront(DList& list, MonHoc mh);
bool isEmpty(DList list);
void duyet(DList list);
void deleteFirst(DList& list);
void deleteLast(DList& list);
void tinChiMin(DList list, int& min);
Node* timMonHocQuaMa(DList list,string &maCanTin);
void sapXep(DList& list);



