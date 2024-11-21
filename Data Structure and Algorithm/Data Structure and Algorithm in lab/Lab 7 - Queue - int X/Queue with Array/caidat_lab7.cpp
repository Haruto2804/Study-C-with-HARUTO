#include "thuvien_lab7.h"
void khoiTao(Queue& q) {
	q.front = q.rear = -1;
}
// ham kiem tra Queue co rong hay khong
int isEmpty(Queue q) {
	if (q.front == -1) {
		return 1;
	}
	return 0;
}
int isFull(Queue q) {
	return(q.rear - q.front == MAX - 1);
}
// Ham them mot phan tu vao hang doi
int enQueue(Queue& q, type x) {
	if (isFull(q)) {
		return 0;
	}
	if (q.front == -1) {
		q.front = 0;
	}
	if (q.rear == MAX - 1) {
		for (int i = q.front; i <= q.rear; i++) {
			q.elem[i - q.front] = q.elem[i];
		}
		q.rear = MAX - 1 - q.front;
		q.front = 0;
	}
	q.rear++;
	q.elem[q.rear] = x;
	return q.rear;
}
// in ham doi
void print(Queue q) {
	if (isEmpty(q) != -1) {
		for (int i = q.front; i <= q.rear; i++) {
			cout << q.elem[i] << " ";
		}
	}
	else {
		cout << "Rong!!!";
	}
}
void setValue(Queue& q) {
	int x;
	while (1) {
		cout << "Nhap du lieu vao Queue (Nhap -99 de thoat): ";
		cin >> x;
		if (x == STOP) {
			break;
		}
		enQueue(q, x);
	}
}
int deQueue(Queue& q) {
	if (isEmpty(q) != -1) {
		if (q.front == q.rear) {
			khoiTao(q);
		}
		else {
			int t = q.elem[q.front];
			q.front++;
			return t;
		}
	}
}-
