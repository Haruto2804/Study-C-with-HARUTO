//Cho ma trận vuông có các phần tử là những số nguyên
//• Tính tổng các phần tử trong Tam giác trên bên phải.
//• Tìm giá trị lớn nhất trong Tam giác dưới bên trái.
//• Cho biết số các số dương trong tam giác trên bên phải.
//• Tìm số âm lớn nhất trong tam giác dưới bên trái
#pragma once
#include <iostream>
#include <cstdlib>
#include <time.h>
#include <random>
#include <iomanip>
using namespace std;
struct MaTranVuong {
	int matrix[100][100];
	int n;
};
typedef MaTranVuong maTran;
void nhapMaTran(maTran &mt);
void xuatMaTran(maTran mt);
int tongMaTranTamGiacTrenPhai(maTran mt);
int maxTamGiacDuoiTrai(maTran mt);
int demSoDuongMaTranTamGiacTrenPhai(maTran mt);
bool maxAmMaTranTamGiacDuoiTrai(maTran mt, int &max);
void phatSinhMaTran(maTran& mt);
void xuatTamGiacDuoiTrai(maTran mt);
void xuatTamGiacDuoiPhai(maTran mt);

