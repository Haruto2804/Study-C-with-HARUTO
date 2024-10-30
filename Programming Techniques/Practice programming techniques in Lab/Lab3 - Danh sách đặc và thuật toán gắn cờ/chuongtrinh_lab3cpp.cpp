#include "thuvien_lab3.h"
void main() {
	struct DaySo ds;
	int x;
	nhapDaySo(ds);
	xuatDaySo(ds);
	// cau 1
	cout << "Tim gia tri can tim trong danh sach: ";
	cin >> x;
	if (tim(ds, x) == -1) { //tim va tra ve vi tri dau tien duoc tim thay
		cout << "Khong tim thay " << x;
	}
	else {
		cout << "Phan tu " << x << " da duoc tim thay o vi tri " << tim(ds, x);
	}
	cout << "\nTim phan tu cuoi cung co trong danh sach!" << endl;
	
	cout << "\nTim gia tri nho nhat trong danh sach!" << endl;
	cout << "Phan tu nho nhat trong danh sach la: " << min(ds);
	
	// cau 2
	if (tim1(ds, x) == -1) {
		cout << "Khong tim thay " << x;
	}
	else {
		cout << "Phan tu " << x << " cuoi cung da duoc tim thay o vi tri " << tim1(ds, x);
	}
	cout << "\nTim gia tri nho nhat nhung phai la gia tri duong " << endl;
	int min;
	if (minDuong(ds, min) == false) {
		cout << "Khong tim thay min duong can tim trong danh sach!";
	}
	else {
		cout << "Phan tu min duong can tim trong danh sach la: " << min;
	}
	cout << "\nTim gia tri lon nhat nhung phai la gia tri am!" << endl;
	int max;
	if (maxAm(ds, max) == false) {
		cout << "Khong tim thay max am can tim trong danh sach!";
	}
	else {
		cout << "Phan tu max am can tim trong danh sach la: " << max;
	}

	// cau 3

	
	
	// cau 2


}