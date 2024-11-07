#pragma once
#pragma once
#include <iostream>
#include <random>
using namespace std;
#pragma warning (disable: 4996);
#include <iomanip>
#include "string.h"
typedef struct Node* NodePtr;
struct SinhVien {
	char masv[10];
	char tensv[30];
	float diem;
	float toan, ly, hoa;
	float dtb;
};
struct Node {
	SinhVien data;
	NodePtr link;
};
void khoiTao(NodePtr& list);
int isEmpty(NodePtr list);
void giaiPhong(NodePtr& list);
NodePtr makeNodeSV(SinhVien x);
NodePtr them_Dau(NodePtr& list, SinhVien x);
bool kiemTra_TrungMa(NodePtr list, char* ma);
void nhap_DSSV(NodePtr& list);
void xuat_DSSV(NodePtr list);
void themCuoi(NodePtr& list, SinhVien x);
void themCuoi_DSSV(NodePtr& list);
NodePtr tim_SV_Masv(NodePtr list, char* ma);
void xoa_Dau(NodePtr& list);
void xoa_Cuoi(NodePtr& list);
void xoa_SV_MaSV(NodePtr& list, char* maCanXoa);
void spilit_SinhVien(NodePtr list, NodePtr& list1, NodePtr& list2);
void daoNguocDSLK(NodePtr& list);
void xoaTatCaSinhVienCoDiemDuoi5(NodePtr& list);
void sapXepTheoDTB(NodePtr& list);