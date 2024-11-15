#pragma once
#include <iostream>
using namespace std;
typedef int TYPEINFO;
struct Node {
	TYPEINFO data;
	Node* next;
	Node* prev;
};
typedef struct Node* Nodeptr;
struct Dlist {
	Nodeptr first;
	Nodeptr last;
};
void khoi_Tao(Dlist& list);
int isEmpty(Dlist list);
Nodeptr tao_Node(TYPEINFO x);
void them_Dau(Dlist& list, TYPEINFO x);
void nhap_Ds_themDau(Dlist& list);
void xuat_Ds_Thuan(Dlist list);
void xuat_Ds_Nguoc(Dlist list);
void them_Cuoi(Dlist& list, TYPEINFO x);
void xoa_Dau(Dlist& list);
void xoa_Cuoi(Dlist& list);
void nhap_Ds_themCuoi(Dlist& list);
int tim_ViTri_X(Dlist list,TYPEINFO x);