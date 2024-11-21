#pragma once
#include <iostream>
using namespace std;
#define MAXSTACK 100
typedef int TYPE;
struct Stack {
	int sp; // stack pointer, theo doi chi so cua STACK
	TYPE elem[MAXSTACK];
};
void init_Stack(Stack& s);
int isEmpty(Stack s);
void push(Stack& s, int x);
int pop(Stack& s);
void input_Stack(Stack& s);
void output_Stack(Stack s);
void get_Stack(Stack& s);
int top(Stack s);
