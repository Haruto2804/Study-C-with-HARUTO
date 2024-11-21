#include "thuvien_lab7_dslk.h"
void khoiTao(Queue& q) {
	q.front = q.rear = NULL;
}
int isEmpty(Queue q) {
	if (q.front == NULL) {
		return 1;
	}
	return 0;
}
NodePtr makeNode(TYPEINFO x) {
	NodePtr newNode = new Node;
	newNode->data = x;
	newNode->next = NULL;
	return newNode;
}
void enQueue(Queue& q, TYPEINFO x) {
	NodePtr newNode = makeNode(x);
	if (isEmpty(q)) {
		q.rear = q.front = newNode;
		return;
	}
	q.rear->next = newNode;
	q.rear = newNode;
}
void print(Queue q) {
	NodePtr p = q.front;
	while (p != NULL) {
		cout << p->data << " ";
		p = p->next;
	}
}
void setValue(Queue& q) {
	int x;
	while (1) {
		cout << "\n Nhap gia tri cho Queue (Nhap -99 de thoat): ";
		cin >> x;
		if (x == -99) {
			break;
		}
		enQueue(q, x);
	}
}
TYPEINFO deQueue(Queue& q) {
	if (isEmpty(q)) {
		return -1;
	}else {
		NodePtr p = q.front;
		q.front = q.front->next;
		TYPEINFO t = p->data;
		delete p;
		return t;
	}
}
TYPEINFO getFront(Queue &q) {
	TYPEINFO t = deQueue(q);
	return t;
}