#pragma once
#include <iostream>
using namespace std;
const int STOP = -99;
typedef int TYPEINFO;
struct Node {
	TYPEINFO data;
	Node* next;
};
typedef Node* NodePtr;
struct Stack {
	NodePtr top;
};
void init_Stack(Stack& s);
int isEmpty(Stack s);
NodePtr makeNode(TYPEINFO x);
void push(Stack& s, TYPEINFO x);
int pop(Stack& s);
int top(Stack s);
void input_Stack(Stack& s);
void output_Stack(Stack s);
