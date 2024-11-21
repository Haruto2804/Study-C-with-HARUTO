#pragma once
#include <iostream>
using namespace std;
const int MAX = 50;
typedef int type;
// khai bao cac hang so
const int STOP = -99;
struct Queue {
	int front, rear;
	int elem[MAX];
};
void khoiTao(Queue& q);
int isEmpty(Queue q);
int isFull(Queue q);
int enQueue(Queue& q, type x);
void setValue(Queue& q);
void print(Queue q);
int deQueue(Queue& q);