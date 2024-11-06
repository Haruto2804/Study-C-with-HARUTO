#pragma once
#pragma warning (disable: 4996)
#include <iostream>
using namespace std;
const int KTM = 100;
struct DaySo {
	int n;
	int arr[KTM];
};
void nhapDaySo(DaySo& ds);
void xuatDaySo(DaySo ds);
bool docDaySo(DaySo& ds, char* tenFile);
bool luuDaySo(DaySo& ds, char* tenFile);
bool chenXVaoViTri(DaySo& a, int viTri, int x);
bool xoaPhanTu(DaySo& a, int viTri);
void bubbleSort_TangDan(DaySo& a);
void bubbleSort_GiamDan(DaySo& a);
void tronHaiDaySo(DaySo& day, DaySo day1, DaySo day2);
void tachDayTheoViTri(DaySo day, DaySo& day1, DaySo& day2, int viTri);
int timPhanTu(DaySo a, int x);
bool checkTangDan(DaySo ds);
bool checkTrung(DaySo ds);
void daoNguocDaySo(DaySo ds);
void del_All_X(DaySo& ds, int x);
void del_All_Max(DaySo& ds);
void del_All_Trung(DaySo& ds);
void tachChanLe(DaySo day, DaySo& dayChan, DaySo& dayLe);
void ghepDay(DaySo& day, DaySo day1, DaySo day2);
