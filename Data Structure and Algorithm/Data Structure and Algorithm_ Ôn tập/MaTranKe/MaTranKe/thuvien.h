#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stack>
#include <queue>
using namespace std;
const int MAX_CANH = 50;
const int MAX_DINH = 50;
struct Canh {
	int dinhDau;
	int dinhCuoi;
	int trongSo;
};
typedef int VERTEX;
struct MaTranKe {
	int n;
	int mt[20][20];
};
struct DanhSachCanh {
	int n;
	Canh dsCanh[MAX_CANH];
};
struct DanhSachDinh {
	int n;
	VERTEX dsDinh[MAX_DINH];
	
};
bool docFile(MaTranKe& a, const char* tenFile);
bool ghiFile(MaTranKe a, const char* tenFile);
void xuatMaTranKe(MaTranKe a);
DanhSachCanh timTapCanh(MaTranKe a);
void xuatTapCanh(DanhSachCanh arrayEdge);
DanhSachDinh DFS(MaTranKe a, VERTEX startV);
bool isConnected(MaTranKe mt, int x, int y);
void xuatDanhSachDinh(DanhSachDinh dsDinh);
void doiHuongMaTran(MaTranKe mtGoc, MaTranKe& mtDaonguoc);
//cho file dinhvacanhVoHuong.txt co noi dung:
/*     4
       0 1
       0 2
       1 0
       1 2
       2 0
       2 1
       3 2       */
bool docFileDinhVaCanhVoHuong(MaTranKe& mt, const char* tenFile);
//cho file dinhvacanhCoHuong.txt co noi dung:
/*     5
       0 1
       0 2
       1 3
       2 1
       3 4      */
bool docFileDinhVaCanhCoHuong(MaTranKe& mt, const char* tenFile);
DanhSachCanh timTapCanh(MaTranKe a);