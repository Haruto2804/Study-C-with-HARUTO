#include "thuvien_lab3.h";
void nhapDaySo(DaySo& ds) {
	do {
		cout << "Nhap so phan tu cho mang: ";
		cin >> ds.soPhanTu;
	} while (ds.soPhanTu <= 0 || ds.soPhanTu > MAX);
	for (int i = 0; i < ds.soPhanTu; i++) {
		cout << "Nhap vap phan tu a[" << i << "]= ";
		cin >> ds.arr[i];
	}
}
void xuatDaySo(DaySo ds) {
	cout << "\nDay so: ";
	for (int i = 0; i< ds.soPhanTu; i++) {
		cout << ds.arr[i] << " ";
	}
	cout << endl;
}
int tim(DaySo ds, int x) {
	for (int i = 0; i < ds.soPhanTu; i++) {
		if (ds.arr[i] == x) {
			return i; // co tim thay va tra ve vi tri phan tu da tim duoc
		}
	}
	return -1; // ko tim thay
}
int min(DaySo ds) {
	int x = ds.arr[0]; // gan min la phan tu dau tien trong danh sach
	for (int i = 0; i < ds.soPhanTu; i++) {
		if (ds.arr[i] <x) { // neu phan tu trong mang co gia tri nho hon x(phan tu o vi tri dau tien)
			x = ds.arr[i]; // gan min la gia tri cua phan tu do
		}
	}
	return x; // tra ve gia tri min da tim duoc
}
bool minDuong(DaySo ds, int& min) {
	bool flag = false; // chua tim thay min duong thoa dieu kien
	for (int i = 0; i < ds.soPhanTu; i++) {
		if (ds.arr[i] > 0) { // neu phan tu trong danh sach co gia tri duong
			if (!flag) { // da tim thay phan tu min duong thi lam (!flag == true) lam dong nay
				min = ds.arr[i]; // khi da tim thay min duong thoa man thi gan phan tu tai vi tri i la min
				flag = true; // khi da tim thay min duong thoa man thi doi flag thanh true
			}
			else if (min > ds.arr[i]) {  // neu da tim thay min duong thi di kiem tra min duong do voi cac phan tu khac trong danh sach, de tim min 
				min = ds.arr[i];
			}
		
		}
	}
	return flag; // tra ve min duong co tim thay hay ko
}
bool maxAm(DaySo ds, int& max) {
	bool flag = false; // chua tim thay min duong thoa dieu kien
	for (int i = 0; i < ds.soPhanTu; i++) {
		if (ds.arr[i] < 0 ) { // neu phan tu trong danh sach co gia tri duong
			if (!flag) { // da tim thay phan tu am thi lam (!flag == true) lam dong nay
				max = ds.arr[i]; // khi da tim thay max am thoa man thi gan phan tu tai vi tri i la max
				flag = true; // khi da tim thay max am thoa man thi doi flag thanh true
			}
			else if (max < ds.arr[i]) {  // neu da tim thay max thi di kiem tra min duong do voi cac phan tu khac trong danh sach, de tim max 
				max = ds.arr[i];
			}
		}
	}
	return flag; // tra ve min duong co tim thay hay ko
}
int tim1(DaySo ds, int x) {
	for (int i = ds.soPhanTu - 1; i >=0; i--) {
		if (ds.arr[i] == x) {
			return i; // co tim thay va tra ve vi tri phan tu da tim duoc
		}
	}
	return -1; // ko tim thay
}

