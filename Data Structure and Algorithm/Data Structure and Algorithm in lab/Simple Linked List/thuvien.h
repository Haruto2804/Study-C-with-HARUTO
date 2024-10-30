#pragma once
#include <iostream>
using namespace std;
struct Node {
	int data;
	Node* next;
};
void taoDSLK(Node** head, int& n);
Node* makeNode(int x);
void pushBack(Node** head, int x);
void duyetDS(Node* head);
void xoaList(Node** head);
int tinhTong(Node* head);
int max(Node* head);
int demChan(Node* head);
bool checkSNT(int n);
int demSNT(Node* head);
int tongLe(Node* head);
void noiHaiDSLK(Node* head1, Node* head2);
void sapXep(Node** head);
void xoaSoNguyenDauTien(Node** head);
void chenSoNguyen(Node** head);
void tachHaiDanhSachChanLe(Node*, Node** head1, Node** head2);
void tronHaiDanhSach(Node** head1, Node** head2);
