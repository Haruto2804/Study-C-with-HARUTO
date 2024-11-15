#pragma once
#include <iostream>
#include <iomanip>
using namespace std;
struct Student {
	char id[10];
	char fullName[30];
	float score;
};
struct Node {
	Student data;
	Node* next;
};
typedef struct Node* Nodeptr;
struct Dlist {
	Nodeptr first;
	Nodeptr last;
};
void init(Dlist& list);
int isEmpty3(Dlist list);
Nodeptr createNode(Student x);
void printStudentInfo(Student x);
void addFirst(Dlist& list, Student x);
void printListReserve(Dlist list);
void createList(Dlist& list);
void printList(Dlist list);
bool isDuplicate(Dlist list, char* ma);
void addLast(Dlist& list, Student x);
void deleteFirst(Dlist& list);
void deleteLast(Dlist& list);
void createList_Last(Dlist& list);