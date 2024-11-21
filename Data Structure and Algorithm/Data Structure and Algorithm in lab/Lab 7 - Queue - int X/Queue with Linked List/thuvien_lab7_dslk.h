#pragma once
#include <iostream>
using namespace std;
typedef int TYPEINFO;
struct Node {
	int data;
	Node* next;
};
typedef Node* NodePtr;
struct Queue {
	NodePtr front, rear;
};
void khoiTao(Queue& q);
int isEmpty(Queue q);
NodePtr makeNode(TYPEINFO x);
void enQueue(Queue& q, TYPEINFO x);
void print(Queue q);
void setValue(Queue& q);
TYPEINFO deQueue(Queue& q);
TYPEINFO getFront(Queue &q);
