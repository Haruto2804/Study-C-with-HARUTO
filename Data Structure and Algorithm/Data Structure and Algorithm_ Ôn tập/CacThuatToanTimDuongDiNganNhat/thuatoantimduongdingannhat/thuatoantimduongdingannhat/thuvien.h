#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <vector>
const int INF = 1e9;
#include <iostream>
int parent[100];
using namespace std;
struct MaTranKe {
	int n;
	int mt[100][100];
};
struct Node {
	int dinhKe;
	int trongSo;
};
typedef Node* NodePtr;
bool docFile(MaTranKe& mt, const char* tenFile);
bool ghiFile(MaTranKe &mt, const char* tenFile);
void xuatMaTranKe(MaTranKe mt);
MaTranKe Floyd(MaTranKe& mt, int next[][100]);
bool isConnected(MaTranKe mt, int x, int y);
void getPath(int u, int v, int next[][100]);
void khoiTaoMaTranNextDeTruyVet(MaTranKe mt,int next[][100]);
void Dijisktra(MaTranKe mt, int startV,int parent[]);
// CAC HAM CHUYEN DOI MA TRAN KE QUA CAC DANG KHAC
const int MAXN = 100;
struct Canh {
	int dinhDau;
	int dinhCuoi;
	int trongSo;
};
struct DanhSachCanh {
	int n;
	Canh dsCanh[MAXN];
};
DanhSachCanh timTapCanh(MaTranKe mt);
void xuatTapCap(DanhSachCanh dsCanh);
void Trace(int u, int v);