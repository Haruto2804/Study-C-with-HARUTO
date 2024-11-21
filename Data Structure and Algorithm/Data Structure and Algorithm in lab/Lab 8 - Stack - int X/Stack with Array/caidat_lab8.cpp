#include "thuvien_lab8.h"
void init_Stack(Stack& s) {
	s.sp = -1;
}
int isEmpty(Stack s) {
	return s.sp == -1;
}
int isFull(Stack s) {
	return s.sp = MAXSTACK - 1;
}
void push(Stack& s, int x) {
	if (isFull(s)==-1) {
		cout << "\nNgan xep day";
		return;
	}
	s.sp++;
	s.elem[s.sp] = x;
}
int pop(Stack& s) {
	int a;
	if (isEmpty(s)) {
		return -1;
	}
	a = s.elem[s.sp];
	s.sp--;
	return a;
}
void input_Stack(Stack& s) {
	int x;
	while (1) {
		cout << "\nNhap data cho Stack (Nhap -99 de thoat): ";
		cin >> x;
		if (x == -99) {
			break;
		}
		push(s, x);
	}
}
void output_Stack(Stack s) {
	for (int i = 0; i <= s.sp; i++) {
		cout << s.elem[i] << " ";
	}
}
void get_Stack(Stack& s) {
	int t = pop(s);
	cout << "\nSo sau khi xoa stack la: " << t;
}
int top(Stack s) {
	if (isEmpty(s) == -1) {
		return -1;
	}
	int t = s.elem[s.sp];
	return t;
}
