#pragma once
#include <iostream>
#include <iomanip>
using namespace std;
const int MAX = 50;
struct DaySo {
	int mang[MAX];
	int soPhanTu;
};
long giaiThua(int n);
int fibonacci(int n);
int binarySearch(int a[], int l, int r, int x);
void quickSort(int a[], int l, int h);
int partition(int a[], int low, int high);
void xuatMang(int a[], int n);
struct SinhVien {
	char maSV[5];
	char hoLot[30];
	char ten[10];
	float diemTrungBinh;
};
struct DanhSachSV {
	int siSo;
	SinhVien mang[MAX];
};
DanhSachSV taoDuLieu();
DanhSachSV loadDuLieu(const char* tenFile);
bool luuDanhSachSV(DanhSachSV ds, const char* tenFile);
void inSinhVien(SinhVien sv);
void inDanhSachSV(DanhSachSV dssv);
//cac ham ben duoi chua co dinh nghia ham. SV xay dung cac dinh nghia ham theo yeu cau trong bai tap tong hop
void quickSort(SinhVien a[], int l, int h);
int partition(SinhVien a[], int low, int high);
int binarySearch(SinhVien a[], int l,int r,char* maSV);
// BAI TAP LAM THEM
int maxChuSo(int n);
int minChuSo(int n);
bool checkChuSoToanChan(int n);
bool checkChuSoToanLe(int n);
void daoNguocSo(int n);
void xuatCacChuSoChan(int n);
void xuatCacChuSoLe(int n);
int demChuSo(int n);
void xuatCacChuSoNguyenTo(int n);
bool checkSNT(int n);
