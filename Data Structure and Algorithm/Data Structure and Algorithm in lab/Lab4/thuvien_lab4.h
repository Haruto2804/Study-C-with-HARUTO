#pragma once
#include <iostream>
using namespace std;
typedef int TYPEINFO;
struct Node {
	int data;
	Node* link;
};
typedef Node* NodePtr;
void khoiTao(NodePtr& list);
int isEmpty(NodePtr list);
NodePtr tao_Node(TYPEINFO x);
NodePtr them_Dau(NodePtr& list, TYPEINFO x);
void nhap_DanhSach_Dau(NodePtr& list);
void xuat_DanhSach(NodePtr list);
void giaiPhong(NodePtr& list);  // cau 1b, ham giai Phong nham giai phong danh sach lien ket khi ko con su dung nua.
void them_Cuoi(NodePtr& list, TYPEINFO x);
void nhap_DanhSach_Cuoi(NodePtr& list);
NodePtr tim_Node_x(NodePtr list, TYPEINFO x);
NodePtr chenSau_Q(NodePtr q, TYPEINFO x);
void xoa_Dau(NodePtr& list);
void xoa_Cuoi(NodePtr& list);
bool del_X(NodePtr& list, TYPEINFO x);
void daoNguocDSLK(NodePtr &list);
void tachDS(NodePtr list, NodePtr& listChan, NodePtr& listLe);
void del_All_X(NodePtr& list, TYPEINFO x);

