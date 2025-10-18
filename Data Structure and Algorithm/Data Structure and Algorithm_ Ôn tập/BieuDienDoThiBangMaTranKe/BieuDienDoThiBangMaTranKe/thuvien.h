#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stack>
#include <queue>
using namespace std;
struct Canh {
	int dinhDau;
	int dinhCuoi;
	int trongSo;
};
struct MaTranKe {
	int n;
	int mt[100][100];
};
struct DanhSachCanh {
	int n;
	Canh dsCanh[100];
};
typedef int VERTEX;
struct DanhSachDinh {
	int n;
	VERTEX DanhSachDinh[100];
};
bool docFile(MaTranKe& mt, const char* tenFile);
bool ghiFile(MaTranKe mt, const char* tenFile);
void xuatMaTranKe(MaTranKe mt);
DanhSachCanh timTapCanh(MaTranKe mt);
void xuatTapCanh(DanhSachCanh dsCanh);
void bacRaVaBacVaoCuaDinhBatKy(MaTranKe mt, char dinh);
DanhSachDinh DFS(MaTranKe mt, VERTEX startV);
bool isConnected(MaTranKe mt, int x, int y);
void xuatDanhSachDinh(DanhSachDinh dsDinh);
void DFSdeQuy(MaTranKe mt,VERTEX startV);
int demThanhPhanLienThong(MaTranKe mt);

void DFS_Component(MaTranKe mt, VERTEX startV, bool visited[]);
void truyVetDuongDi(MaTranKe mt, int s, int e, bool visited[],VERTEX parent[]);
void DFS_TruyVet(MaTranKe mt, VERTEX startV, bool visited[], VERTEX parent[]);