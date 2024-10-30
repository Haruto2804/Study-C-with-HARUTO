#include <iostream>
using namespace std;
#define MAX 100
struct DaySo {
	int soPhanTu;
	int arr[MAX];
};
void nhapDaySo(DaySo& ds);
void xuatDaySo(DaySo ds);
int tim(DaySo ds, int x);
int tim1(DaySo ds, int x);
int min(DaySo ds);
bool minDuong(DaySo ds, int& min);
bool maxAm(DaySo ds, int& max);
