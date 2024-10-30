#pragma once
#include <iostream>
#include <cstdio>
using namespace std;
const int KTM = 50;
struct DaySo {
	int arr[KTM];
	int n;
};
bool docDaySo(DaySo& ds, const char *tenFile);
bool luuDaySo(DaySo& ds, const char *tenFile);
void nhapDaySo(DaySo& ds);
void xuatDaySo(DaySo ds);
int tongDS(DaySo ds);
int tichDS(DaySo ds);
int demPhanTuDuong(DaySo ds);
void xuatSoChan(DaySo ds);
int tongChan(DaySo ds);
int tichChiSoChan(DaySo ds);
int demPTChiaHet3Va5(DaySo ds);