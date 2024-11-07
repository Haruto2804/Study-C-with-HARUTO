#pragma once
#include <iostream>
using namespace std;
#include <string.h>
const int MAX = 50;
struct MonHoc {
	char mamh[10];
	char tenmh[30];
	int sotc;
};
struct DanhSachMonHoc {
	int so;
	MonHoc data[MAX];
};
void nhapMonHoc(MonHoc& mh);
void xuatMonHoc(MonHoc mh);
void nhapDanhSachMonHoc(DanhSachMonHoc& ds);
void xuatDanhSachMonHoc(DanhSachMonHoc ds);
void them_MonHoc_ViTri(DanhSachMonHoc& ds, int vt, MonHoc mh);
void xoa_MonHoc_ViTri(DanhSachMonHoc& ds, int vt);
int timKiem_TuanTu(DanhSachMonHoc ds, char* ma);
void selectionSort(DanhSachMonHoc& ds);
bool timKiemNhiPhan(DanhSachMonHoc ds,char *ma);

// BAI TAP VE NHA
int demSoLanMH(DanhSachMonHoc ds, char* mamh);
int thayTheMonHocXThanhY(DanhSachMonHoc& ds, MonHoc MHThayThe);
void tinChiDanhSachMonHoc(DanhSachMonHoc &ds1, DanhSachMonHoc &dstc, int &stc);