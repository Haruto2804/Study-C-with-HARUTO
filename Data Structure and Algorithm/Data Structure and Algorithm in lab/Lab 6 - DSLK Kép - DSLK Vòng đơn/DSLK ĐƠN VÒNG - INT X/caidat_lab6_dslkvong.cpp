#include "thuvien_lab6_dslkvong.h"
Nodeptr tao_Node2(TYPEINFO x) {
	Nodeptr newNode = new Node;
	newNode->data = x;
	newNode->next = NULL;
	return newNode;
}
void khoiTao(List& list) {
	list.last = list.first = NULL;
}
int isEmpty(List& list) {
	return(list.first == NULL ? 1 : 0);
}
void them_Dau(List& list, TYPEINFO x) {
	Nodeptr newNode = tao_Node2(x);
	if (isEmpty(list)) {
		list.first = list.last = newNode;
	}
	else {
		newNode->next = list.first;
		list.first = newNode;
	}
	list.last->next = list.first;
}
void them_Cuoi(List& list, TYPEINFO x) {
	Nodeptr newNode = tao_Node2(x);
	if (isEmpty(list)) {
		list.first = list.last = newNode;
	}
	else {
		list.last->next = newNode;
		list.last = newNode;
	}
	list.last->next = list.first;
}
void readList_Dau(List& list) {
	int x;
	do {
		cout << "\nNhap x=(thoat -99): ";
		cin >> x;
		if (x == -99) {
			break;
		}
		them_Dau(list, x);
	} while (1);
}
void readList_Cuoi(List& list) {
	int x;
	do {
		cout << "\nNhap x=(thoat -99): ";
		cin >> x;
		if (x == -99) {
			break;
		}
		them_Cuoi(list, x);
	} while (1);
}
void printList(List list) {
	if (list.first != NULL) {
		Nodeptr p = list.first;
		do {
			cout << p->data << " ";
			p = p->next;
		} while (p != list.first);
	}
	else {
		cout << "\nDS rong";
	}
}
void xoa_Dau(List& list) {
	if (list.first != NULL) {
		if (list.first != list.last) {
			Nodeptr p = list.first;
			list.first = list.first->next;
			list.last->next = list.first;
			delete p;
		}
		else {
			list.first = NULL;
		}
	}
}
void xoa_Cuoi(List& list) {
	if (isEmpty(list)) {
		return;
	}
	if (list.first == list.last) {
		xoa_Dau(list);
		return;
	}
	Nodeptr p = list.first;
	Nodeptr q = nullptr;
	while (p->next != list.first) {
		q = p;
		p = p->next;
	}
	if (p != NULL) {
		delete p;
		q->next = list.first; 
		list.last = q;
	}
}
bool tim_X(List list, TYPEINFO x) {
	if (isEmpty(list)) {
		return false;
	}
	Nodeptr p = list.first;
	do {
		if (p->data == x) {
			return true;
		}
	} while (p != list.first);
	return false;
}
