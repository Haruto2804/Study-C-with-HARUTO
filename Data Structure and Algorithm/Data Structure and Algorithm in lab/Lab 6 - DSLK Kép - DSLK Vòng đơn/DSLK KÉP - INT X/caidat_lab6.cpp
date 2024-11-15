#include "thuvien_lab6.h"
void khoi_Tao(Dlist& list) {
	list.first = list.last = NULL;
}
int isEmpty(Dlist list) {
	return(list.first == NULL ? 1 : 0);
}
Nodeptr tao_Node(TYPEINFO x) {
	Nodeptr newNode = new Node;
	newNode->data = x;
	newNode->prev = NULL;
	newNode->next = NULL;
	return newNode;
}
void them_Dau(Dlist& list, TYPEINFO x) {
	Nodeptr newNode = tao_Node(x);
	if (isEmpty(list)) {
		list.first = list.last = newNode;
	}
	else {
		newNode->next = list.first;
		list.first->prev = newNode;
		list.first = newNode;
	}
}
void nhap_Ds_themDau(Dlist& list) {
	int x;
	do {
		cout << "\nNhap x= (-99 de thoat): ";
		cin >> x;
		if (x == -99) {
			break;
		}
		them_Dau(list, x);
	} while (1);
}
void xuat_Ds_Thuan(Dlist list) {
	Nodeptr p = list.first; 
	while (p != NULL) {
		cout << p->data << " ";
		p = p->next;
	}
}
void xuat_Ds_Nguoc(Dlist list) {
	Nodeptr p = list.last;
	while (p != NULL) {
		cout << p->data << " ";
		p = p->prev;
	}
}
// cau 2
void them_Cuoi(Dlist& list, TYPEINFO x) {
	Nodeptr newNode = tao_Node(x);
	if (isEmpty(list)) {
		list.first = list.last = newNode;
	}
	else {
		list.last->next = newNode;
		newNode->prev = list.last;
		list.last = newNode;
	}
}
void nhap_Ds_themCuoi(Dlist& list) {
	int x;
	do {
		cout << "\nNhap x= (-99 de thoat): ";
		cin >> x;
		if (x == -99) {
			break;
		}
		them_Cuoi(list, x);
	} while (1);
}
void xoa_Dau(Dlist& list) {
	if (isEmpty(list)) {
		return;
	}
	Nodeptr p = list.first;
	list.first = list.first->next;
	list.first->prev = NULL;
	delete p;
}
void xoa_Cuoi(Dlist& list) {
	if (isEmpty(list)) {
		return;
	}
	Nodeptr q = list.last->prev;
	delete list.last;
	list.last = q;
	list.last->next = NULL;
}
int tim_ViTri_X(Dlist list, TYPEINFO x) {
	int i = 1;
	while (list.first != NULL) {
		if (list.first->data == x) {
			return i;
		}
		i++;
		list.first = list.first->next;
	}
	return -1;
}