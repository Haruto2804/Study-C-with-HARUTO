#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>
#include <stack>
using namespace std;
const int MAX = 100;
struct MaTranKe {
	int n;
	int mt[MAX][MAX];
};
struct Canh {
	int dinhDau;
	int dinhCuoi;
	int trongSo;
};
struct DanhSachCanh {
	int n;
	Canh ds[MAX];
};
typedef int VERTEX;
struct DanhSachDinh {
	int n;
	VERTEX ds[MAX];
};
struct Node {
	int dinhKe;
	int trongSo;
	Node* next;
};
struct DanhSachKe {
	int n;
	Node* ds[MAX];
};
bool docFile(MaTranKe& mt, const char* tenFile);
bool docFile(DanhSachKe& dsKe, const char* tenFile);
bool ghiFile(MaTranKe& mt, const char* tenFile);
void xuatMaTranKe(MaTranKe mt);
void xuatDanhSachDinh(DanhSachDinh dsDinh);
void xuatTapCanh(DanhSachCanh dsCanh);
DanhSachDinh DFS(MaTranKe mt, int startV);
DanhSachDinh BFS(MaTranKe mt, int startV);
void DFS_DeQui(MaTranKe mt, int startV, bool visited[50]);
void DFS_DeQui(MaTranKe mt, int startV, bool visited[50]);
bool isConnect(int x, int y, MaTranKe mt);
int demSoThanhPhanLienThong(MaTranKe mt, bool visited[50]);
DanhSachCanh timTapCanh(MaTranKe mt);
DanhSachKe chuyenMaTranKeSangDanhSachKe(MaTranKe mt);
void xuatDanhSachKe(DanhSachKe dsKe);
