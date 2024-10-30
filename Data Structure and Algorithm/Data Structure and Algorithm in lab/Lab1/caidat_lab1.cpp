#include "thuvien_lab1.h"
//cau 1
void nhapMang (int b[], int &m) {
	do {
		cout << "\nNhap so phan tu mang: ";
		cin >> m; 
	} while (m <= 0 || m > KTM);
	cout << "\nNhap gia tri cho mang: ";
	for (int i = 0; i < m; i++) {
		cout << "\nNhap phan tu thu " << i << ": ";
		cin >> b[i];
	}
}
//void xuatMang(int b[], int n) {
//	cout << "\nMang la: ";
//	for (int i = 0; i < n; i++) {
//		cout << b[i] << setw(3);
//	}
//}
// cau 2
//void nhapMang (int b[], int &m) {
//	cout << "\nNhap gia tri cho mang: ";
//	for (int i = 0; i < m; i++) {
//		cout << "\nNhap phan tu thu " << i << ": ";
//		cin >> b[i];
//	}
//}
void xuatMang(int b[], int n) {
	cout << "\nMang la: ";
	for (int i = 0; i < n; i++) {
		cout << b[i] << " ";
	}
}

int timKiem_TuanTu(int a[], int n, int x) {
	int i = 0;
	while (i < n && a[i] != x) {
		i++;
	}
	if (i == n) {
		return -1; 
	}
	return i;
}
void sapXep(int a[], int n) {
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			if (a[j] < a[i]) {
				int tam = a[i];
				a[i] = a[j];
				a[j] = tam;
			}
		}
	}
}
bool timKiemNhiPhan(int a[], int m, int&x) {
	cout << "\nNhap gia tri can tim: ";
	cin >> x;
	int left = 0;
	int right = m-1;
	int mid;
	do {
		mid = (left + right) / 2;
		if (a[mid] == x) {
			return 1;
		}
		else if (x < a[mid]) {
			right = mid - 1;
		}
		else {
			left = mid + 1;
		}
	} while (left <= right);
	return false;
}
int demSoNguyenTo(int a[], int m) {
	int dem = 0;
	for (int i = 0; i < m; i++) {
		if (soNguyenTo(a[i])) {
			dem++;
		}
	}
	return dem;
}
bool soNguyenTo(int n) {
	for (int i = 0; i <= sqrt(n); i++) {
		if (n % i == 0) {
			return false;
		}
	}
	return true;
}

bool soHoanThien(int n) {
	int tongUocSo = 0;
	for (int i = 1; i < n;i++) {
		if (n % i == 0) {
			tongUocSo += i;
		}
	}
	if (tongUocSo == n) {
		return true;
	}
	return false;
}
void xuatSoHoanThien(int a[], int m) {
	cout << "\nCac so hoan thien co trong mang la: "; 
	for (int i = 0; i < m; i++) {
		if (soHoanThien(a[i])) {
			cout << a[i] << " ";
		}
	}
}

void demX(int a[], int n) {
	int x;
	int dem = 0;
	cout << "\nNhap gia tri can tim trong mang: ";
	cin >> x;
	for (int i = 0; i < n; i++) {
		if (a[i] == x) {
			dem++;
		}
	}
	cout << "So lan " << x << " xuat hien trong mang la: " << dem;
}
void thayXthanhY(int a[], int n) {
	int x, y, vitri;
	cout << "\nNhap gia tri cua x: ";
	cin >> x;
	cout << "Nhap gia tri cua y: ";
	cin >> y;
	for (int i = 0; i < n; i++) {
		if(a[i]==x) {
			a[i] = y;

		}
	}
}
bool kiemTraTangDan(int a[], int n) {
	for (int i = 0; i < n-1; i++) {
		if (a[i] > a[i + 1]) {
			return false;
		}
	}
	return true;
}
void chenPhanTu(int a[], int& n) {
	int x, vitri;
	n++;
	cout << "\nNhap vi tri can chen: ";
	cin >> vitri;
	cout << "\nNhap gia tri can chen: ";
	cin >> x;
	for (int i = n - 1; i > vitri; i--) {
		a[i] = a[i - 1];
	}
	a[vitri] = x;
}
void tinhTongAm(int a[], int n) {
	int tong = 0;
	for (int i = 0; i < n; i++) {
		if (a[i] < 0) {
			tong += a[i];
		}
	}
	cout << "\nTong cac phan tu am la: " << tong;
}