#include "thuvien_lab4.h"
void nhapDaySo(DaySo& ds) {
	cout << "Nhap phan tu can su dung cho danh sach: ";
	cin >> ds.n;
	for (int i = 0; i < ds.n; i++) {
		cout << "a[" << i << "]= ";
		cin >> ds.arr[i];
	}
}
void xuatDaySo(DaySo ds) {
	for (int i = 0; i < ds.n; i++) {
		cout << ds.arr[i] << " ";
	}
}
bool docDaySo(DaySo& ds, char* tenFile) {
	FILE* f;
	f = fopen(tenFile, "rb");
	if (f == NULL) {
		return false;
	}
	if (&ds, sizeof(DaySo), 1, f);
	fclose(f);
	return true;
}
bool luuDaySo(DaySo& ds, char* tenFile) {
	FILE* f;
	f = fopen(tenFile, "wb");
	if (f == NULL) {
		return true;
	}
	fwrite(&ds, sizeof(DaySo), 1, f);
	fclose(f);
	return true;
}
bool chenXVaoViTri(DaySo& a, int viTri, int x) {
	if (a.n == KTM || viTri < 0 || viTri > a.n) {
		return false;
	}
	for (int i = a.n; i >viTri; i--) {
		a.arr[i] = a.arr[i - 1];
	}
	a.arr[viTri] = x;
	a.n++;
	return true;
}
bool xoaPhanTu(DaySo& a, int viTri) {
	if (viTri < 0 || viTri >= a.n) {
		return false;
	}
	for (int i = viTri; i < a.n - 1; i++) {
		a.arr[i] = a.arr[i + 1];
	}
	a.n--;
	return true;
}
void bubbleSort_TangDan(DaySo& a) {
	for (int i = 0; i < a.n; i++) {
		for (int j = a.n - 1; j > i; j--) {
			if (a.arr[j] < a.arr[j - 1]) {
				swap(a.arr[j], a.arr[j - 1]);
			}
		}
	}
}
void bubbleSort_GiamDan(DaySo& a) {
	for (int i = 0; i < a.n; i++) {
		for (int j = a.n - 1; j > i; j--) {
			if (a.arr[j] > a.arr[j - 1]) {
				swap(a.arr[j], a.arr[j - 1]);
			}
		}
	}
}
void tronHaiDaySo(DaySo& day, DaySo day1, DaySo day2) {
	int k = 0; // theo doi chi so day 
	day.n = 0;
	for (int i = 0; i < day1.n; i++) { // sao chep phan tu day 1 sang day
		day.arr[k++] = day1.arr[i];
		day.n++;
	}
	for (int i = 0; i < day2.n; i++) { // sao chep phan tu day 2 sang day
		day.arr[k++] = day2.arr[i];
		day.n++;
	}
}
void tachDayTheoViTri(DaySo day, DaySo& day1, DaySo& day2, int viTri) {
	int k = 0; // theo doi chi so day 1
	int l = 0; // theo doi chi so day 2
	day1.n = 0;
	day2.n = 0;
	for (int i = 0; i < viTri; i++) { // day : 0 1 2 3 vi tri 4 5 6, day 1: 0 1 2 3
		day1.arr[k++] = day.arr[i];
		day1.n++;
	}
	for (int i = viTri; i <day.n ; i++) {
		day2.arr[l++] = day.arr[i];
		day2.n++;
	}
}
int timPhanTu(DaySo a, int x) {
	for (int i = 0; i < a.n; i++) {
		if (a.arr[i] == x) {
			return i;
			break;
		}
	}
	return -1;
}
bool checkTangDan(DaySo ds) {
	for (int i = 0; i < ds.n-1; i++) {
		for (int j = i + 1; j < ds.n; j++) {
			if (ds.arr[i] > ds.arr[j]) {
				return false;
			}
		}
	}
	return true;
}
bool checkTrung(DaySo ds) {
	for (int i = 0; i < ds.n-1; i++) {
			for (int j = i + 1; j < ds.n; j++) {
				if (ds.arr[i] == ds.arr[j]) {
					return true; // co trung
				}
		}
	}
	return false;
}
void daoNguocDaySo(DaySo ds) {
	for (int i = ds.n - 1; i >= 0; i--) {
		cout << ds.arr[i] << " ";
	}
}
void del_All_X(DaySo& ds, int x) {
	for (int i = 0; i < ds.n; i++) {
		if (ds.arr[i] == x) {
			for (int j = i; j < ds.n; j++) {
				ds.arr[j] = ds.arr[j + 1];
			}
			ds.n--;
			i--;
		}
	}
}
void del_All_Max(DaySo& ds) {
	int max = ds.arr[0];
	for (int i = 1; i < ds.n; i++) {
		if (ds.arr[i] > max) {
			max = ds.arr[i];
		}
	}// thoat khoi vong lap ta tim duoc max
	del_All_X(ds, max);
}
void del_All_Trung(DaySo& ds) {
	for (int i = 0; i < ds.n-1; i++) {
		for (int j = i + 1; j < ds.n; j++) {
			if (ds.arr[i] == ds.arr[j]) {
				xoaPhanTu(ds, j);
				j--;
			}
			
		}
	}
}
void tachChanLe(DaySo day, DaySo& dayChan, DaySo& dayLe) {
	int k = 0;// theo doi chi so cua day Chan
	int l = 0; // theo doi chi so cua day Le
	dayChan.n = 0;
	dayLe.n = 0;
	for (int i = 0; i < day.n; i++) {
		if (day.arr[i] % 2 == 0) {
			dayChan.arr[k++] = day.arr[i];
			dayChan.n++;
		}
		else {
			dayLe.arr[l++] = day.arr[i];
			dayLe.n++;
		}
	}
}
void ghepDay(DaySo& day, DaySo day1, DaySo day2) {
	int k = 0;
	day.n = 0;
	for (int i = 0; i < day1.n; i++) {
		day.arr[k++] = day1.arr[i];
		day.n++;
	}
	for (int i = 0; i < day2.n; i++) {
		day.arr[k++] = day2.arr[i];
		day.n++;
	}
}
void tangDauGiamCuoi(DaySo& day, DaySo day1, DaySo day2) {
	bubbleSort_TangDan(day1);
	bubbleSort_GiamDan(day2);
	ghepDay(day, day1, day2);
}

