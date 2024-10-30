#pragma once
#include <iostream>
#include <iomanip>
#define KTM 10
using namespace std;
// THUC HANH TREN LOP
void nhapMang(int b[], int& m);
void xuatMang(int b[], int n);
int timKiem_TuanTu(int a[], int n, int x);
void sapXep(int a[], int n);
bool timKiemNhiPhan(int a[], int m, int& x);
void tinhTongAm(int a[], int n);
bool soNguyenTo(int n);
int demSoNguyenTo(int a[], int m);
bool soHoanThien(int n);
void xuatSoHoanThien(int a[], int m);


// BAI TAP VE NHA
void demX(int a[], int n); // cau 1
void thayXthanhY(int a[], int n);// cau 2
bool kiemTraTangDan(int a[], int n); // cau 3
void chenPhanTu(int a[], int& n); // cau 4




