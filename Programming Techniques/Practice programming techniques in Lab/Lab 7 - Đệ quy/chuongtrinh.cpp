#include "thuvien.h"
int main() {
	//int a[MAX];
	//int n, x;
	//// nhap n nguyen duong, in ra n giai thua, in ra phan tu thu n cua day Fibonacci
	//do {
	//	cout << "Nhap so phan tu: ";
	//	cin >> n;
	//} while (n <= 0);
	//for (int i = 0; i < n; i++) {
	//	cout << "Nhap a[" << i << "]: ";
	//	cin >> a[i];
	//}
	//cout << n << "!= " << giaiThua(n) << " la: " << endl;
	//cout << "So finonacci thu " << n << " la: " << fibonacci(n) << endl; // 1 1 2 3 5
	//cout << "Ban muon tim so may?: ";
	//cin >> x;
	//// tim kiem nhi phan
	//int kq = binarySearch(a, 0, 5, x);
	//if (kq >= 0) {
	//	cout << "Tim thay tai vi tri " << kq << endl;
	//}
	//else {
	//	cout << "Khong tim thay " << endl;
	//}
	//// QuickSort sap xep tang dan
	//quickSort(a, 0, n - 1);
	//cout << "Day so sau khi sap xep la: ";
	//xuatMang(a, n);
	// YEU CAU SINH VIEN (2D)
	//a.
	//b. khi n =5,x=8, ket qua chuong trinh xuat hien day so voi n = 5, giai thua cua 5! = 120, day so fibonacci thu 5 la 5
	//   khi n = 7, x = 10, ket qua chuong trinh xuat hien day so voi n = 7, giai thua cua 7!= 5040, day so fibonacci thu 7 la 13/
	//c. Chay tung buoc ham giaiThua voi n =5
	// B1: n = 5, kiem tra dieu kien->false, 
	// khi chay ve 1 thi se return 1
	// n = 5*24=120 (5)
	//n=4*6=24 (4)
	//n=3*2=6 (3)
	//n=2*1=2 (2)
	//n=1-->return 1 (1)
	// ====================================================================================================================
	// B1: n = 7, kiem tra dieu kien->false, 
	// khi chay ve 1 thi se return 1
	// n=7*720=5040
	// n=6*120=720
	// n=5*24= 120
	//n=4*6=24
	//n=3*2=6
	//n=2*1=2
	//n=1-->return

	// cau 2
	/*char* ten = new char[50];
	strcpy_s(ten, 50, "dssv.txt");
	DanhSachSV ds=taoDuLieu();
	luuDanhSachSV(ds,ten);
	ds = loadDuLieu(ten);
	inDanhSachSV(ds);*/
	//BT LAM THEM
	int c;
	do {
		cout << "\nNhap so nguyen duong n: ";
		cin >> c;
	} while (c <= 0);
	cout << "Chu so lon nhat cua " << c << " la: " << maxChuSo(c);
	cout << "\nChu so nho nhat cua " << c << " la: " << minChuSo(c) << endl;
	if (checkChuSoToanChan(c)) {
		cout << c << " la so toan chan!" << endl;
	}
	else {
		cout << c << " khong phai la so toan chan!" << endl;
	}
	if (checkChuSoToanLe(c)) {
		cout << c << " la so toan le!" << endl;
	}
	else {
		cout << c << " khong phai la so toan le!" << endl;
	}
	cout << "So " << c << " sau khi dao nguoc la: ";
	daoNguocSo(c);
	cout << "\nSo chu so co trong " << c << " la: " << demChuSo(c);
	cout << "\nCac so le co trong " << c << " la: ";
	xuatCacChuSoLe(c);
	cout << "\nCac so chan co trong " << c << " la: ";
	xuatCacChuSoChan(c);
	cout << "\nCac so nguyen to co trong " << c << " la: ";
	xuatCacChuSoNguyenTo(c);
}