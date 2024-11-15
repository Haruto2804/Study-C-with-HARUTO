#pragma warning (disable: 4996);
#include <iostream>
using namespace std;
const int MAX = 50;
struct MaTran {
	int arr[MAX][MAX];
	int dong;
	int cot;
};
void nhapMaTran(MaTran& a);
void xuatMaTran(MaTran a);
bool docMaTran(MaTran& a, const char* tenFile);
bool luuMaTran(MaTran a, const char* tenFile);
int tong(MaTran a);
int demDuong(MaTran a);
int max(MaTran a);
int tongChan(MaTran a);
bool checkSoChinhPhuong(int n);
int demSoChinhPhuong(MaTran a);
bool checkSNT(int n);
bool maxSoNguyenTo(MaTran a, int& max);
void tinhTongCacDong(MaTran a);
void DongCoTongMax(MaTran a);
int tongCacMaxMoiDong(MaTran a);
void tongCacCot(MaTran a);
void hoanDoiHaiCot(MaTran& a, int k, int j);
void sapXepTangDanTungCot(MaTran& a);
void sapXepGiamDanTungDong(MaTran & a);
