#include "thuvien_lab8_dslk.h"
void init_Stack(Stack& s) {
	s.top = NULL;
}
int isEmpty(Stack s) {
	return s.top == NULL;
}
NodePtr makeNode(TYPEINFO x) {
	NodePtr newNode = new Node;
	newNode->data = x;
	newNode->next = NULL;
	return newNode;
}
void push(Stack& s, TYPEINFO x) {
	NodePtr newNode = makeNode(x);
	if (isEmpty(s)) {
		s.top = newNode;
		return;
	}
	newNode->next = s.top;
	s.top = newNode;
}
int pop(Stack& s) {
	// neu DS rong
	if (isEmpty(s)) {
		return -1;
	}
	// neu ds chi co mot phan tu
	if (s.top->next == NULL) {
		TYPEINFO t;
		t = s.top->data;
		return t;
		// TH con lai
	}
	NodePtr p = s.top;
	s.top = s.top->next;
	TYPEINFO t = p->data;
	delete p;
	return t;
}
int top(Stack s) {
	TYPEINFO t;
	// neu DS rong
	if (isEmpty(s)) {
		return -1;
	}
	t = s.top->data;
	return t;
}
void input_Stack(Stack& s) {
	TYPEINFO x;
	while (1) {
		cout << "\nNhap data cho stack: ";
		cin >> x;
		if (x == STOP) {
			break;
		}
		push(s, x);
	}
}
void output_Stack(Stack s) {
	NodePtr p = s.top;
	while (p != NULL) {
		cout << p->data << " ";
		p = p->next;
	}
}