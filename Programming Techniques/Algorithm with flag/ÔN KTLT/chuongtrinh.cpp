#include <iostream>
#pragma warning (disable : 4996)
using namespace std;
const int MAX = 100;
struct DSDac {
	int n;
	int a[MAX];
};
void nhapDS(DSDac& ds) {
	cout << "Nhap so phan tu: ";
	cin >> ds.n;
	for (int i = 0; i < ds.n; i++) {
		cout << "Nhap vao phan tu a[" << i << "]= ";
		cin >> ds.a[i];
	}
}
void xuatDS(DSDac ds) {
	for (int i = 0; i < ds.n; i++) {
		cout << ds.a[i] << " ";
	}
}
bool checkSNT(int n) {
	if (n < 2) {
		return false;
	}
	for (int i = 2; i * i <= n; i++) {
		if (n % i == 0) {
			return false;
		}
	}
	return true;
}
void tongSoAm(DSDac ds, int& tong) {
	for (int i = 0; i < ds.n; i++) {
		if (ds.a[i] < 0) {
			tong += ds.a[i];
		}
	}
}
void tongSoDuong(DSDac ds) {
	int tong = 0;
	for (int i = 0; i < ds.n; i++) {
		if (ds.a[i] > 0) {
			tong += ds.a[i];
		}
	}
	cout << "Tong cua cac so Duong trong danh sach la: " << tong;
}
void tongSoChan(DSDac ds) {
	int tong = 0;
	for (int i = 0; i < ds.n; i++) {
		if (ds.a[i] %2==0) {
			tong += ds.a[i];
		}
	}
	cout << "Tong cua cac so chan trong danh sach la: " << tong;
}

void timSoDuong(DSDac ds, DSDac &dsDuong) {
	dsDuong.n = 0;
	int k = 0;
	for (int i = 0; i < ds.n; i++) {
		if (ds.a[i] > 0) {
			dsDuong.a[k++] = ds.a[i];
			dsDuong.n++;
		}
	}
}
bool minAm(DSDac ds, int& min) {
	bool flag = false;
	for (int i = 0; i < ds.n; i++) {
		if (ds.a[i] < 0) {
			if (!flag) {
				min = ds.a[i];
				flag = true;
				cout << "\nVong lap thu " << i + 1;
				cout << "\nMin am hien tai dang la: " << min << endl;
				cout << "==========================================================";
			}
			else if (ds.a[i] < min) {
				min = ds.a[i];
				cout << "\nVong lap thu " << i + 1;
				cout << "\nMin am hien tai dang la: " << min << endl;
				cout << "==========================================================";
			}
		}
	}
	return flag;
}
bool duongMax(DSDac ds, int& max) { //max nhung la so am, tim so hoan thien nhung la nho nhat
	bool flag = false; // CHUA TIM THAY SO DUONG
	for (int i = 0; i < ds.n; i++) {
		if (ds.a[i] > 0) { // -1 -2 5 1 2
			// CO IT NHAT 1 PHAN TU LA DUONG
			if (!flag) { //!flag == true, vong lap tiep thep neu tim thay so duong thu hai, flag = true, !flag = false
				max = ds.a[i]; // max = 5
				flag = true; // da tim thay so duong
			}// nhiem cua cua thang if nay la tim so duong dau tien trong danh sach, sau do gan thang do la max
			else if (ds.a[i] > max) { // kiem tra cac so duong tiep theo coi co lon hon so duong dau tien ko, neu lon hon thi gan max la no luon
				max = ds.a[i];
			}
		}
	}
	return flag; // da tim thay mot so duong
}
bool SNTMAX(DSDac ds, int& max) {
	bool flag = false; // CHUA TIM THAY SO DUONG
	for (int i = 0; i < ds.n; i++) {
		if (checkSNT(ds.a[i])) { // -1 -2 5 1 2
			// CO IT NHAT 1 PHAN TU LA DUONG
			if (!flag) { //!flag == true, vong lap tiep thep neu tim thay so duong thu hai, flag = true, !flag = false
				max = ds.a[i]; // max = 5
				flag = true; // da tim thay so duong
			}// nhiem cua cua thang if nay la tim so duong dau tien trong danh sach, sau do gan thang do la max
			else if (ds.a[i] > max) { // kiem tra cac so duong tiep theo coi co lon hon so duong dau tien ko, neu lon hon thi gan max la no luon
				max = ds.a[i];
			}
		}
	}
	return flag; // da tim thay mot so duong
}
int indexDuongMax(DSDac ds, int& max) {
	max = -1; // chua tim thay max duong
	int firstIndex = -1; // vi max duong chua tim thay nen vi tri cung lam gi co
	for (int i = 0; i < ds.n; i++) {
		if (ds.a[i] > 0 && ds.a[i]>max) {
			max = ds.a[i];
			firstIndex = i; // = 1, ==2
		}
	}
	return firstIndex;
}
void tinhTongIMuHai() {
	int tong = 0;
	int so;
	cout << "Nhap so n: ";
	cin >> so;
	for (int i = 1; i <= so; i++) {
		tong = tong+pow(i, 2);
	}
	cout << "Tong cua bieu thuc 1^2+2^2+3^2...+n^2 la: " << tong;
}
void tinhTongBieuThucS() {
	float tong = 0;
	int so;
	cout << "Nhap so n: ";
	cin >> so;
	for (int i = 1; i <= so; i++) {
		tong += pow(-1, i + 1) / i;
	}
	cout << "Tong cua bieu thuc 1+1/2+1/3+....(-1^n+1)/n la: " << tong;
}
int viTriNhoNhatDauTien(DSDac ds) {
	if (ds.n < 0) {
		return -1;
	}
	int firstIndex = 0;
	int min = ds.a[0];
	for (int i = 1; i < ds.n; i++) {
		if (min > ds.a[i]) {
			min = ds.a[i];
			firstIndex = i;
		}
	}
	return firstIndex;
}
bool soHoanThien(int n) {
	int tong = 0;
	for (int i = 1; i < n; i++) {
		if (n % i == 0) {
			tong += i;
		}
	}
	if (tong == n) {
		return true;
	}
	return false;
}
bool indexDauTienSoHoanThien(DSDac ds, int& max, int &firstIndex) {
	bool flag = false;
	firstIndex = -1;
	for (int i = 0; i < ds.n; i++) {
		if (soHoanThien(ds.a[i])) {
			if (!flag) {
				max = ds.a[i];
				firstIndex = i;
				flag = true;
			}
			else if (ds.a[i] > max) {
				max = ds.a[i];
				firstIndex = i;
			}
		}
	}
	return flag;
}
void main() {
	DSDac ds, dsDuong;
	int min;
	nhapDS(ds);
	
	cout << "\n==========================================================";
	cout << "\nDanh sach la: ";
	xuatDS(ds);
	cout << "\nChuong trinh tim min am trong danh sach!";
	if (minAm(ds, min)) {
		cout << "\nDa tim thay min co gia tri la am, min am la " << min << endl;
	}
	else {
		cout << "\nKhong tim thay min am trong danh sach!" << endl;
	}
	cout << "===========================================================" << endl;
	int tong=0;
	tongSoAm(ds, tong);
	cout << "Tong cac so am co trong day so la: " << tong << endl;
	cout << "=============================================================" << endl;
	timSoDuong(ds, dsDuong);
	cout << "Danh sach gom cac so duong la: " << endl;
	xuatDS(dsDuong);
	cout << "\n=============================================================" << endl;
	int max;
	if (duongMax(ds, max)) {
		cout << "\nDuong max la " << max;
	}
	else {
		cout << "\nkhong tim thay duong max!";
	}
	cout << "\n=============================================================" << endl;
	int max1;
	if (indexDuongMax(ds, max1) == -1) {
		cout << "\nKhong co duong max!" << endl;
	}
	else {
		cout << "\nDuong max la " << max1 << " va vi tri cua no la: " << indexDuongMax(ds, max1);
	}
	cout << "\n=============================================================" << endl;
	tinhTongIMuHai();
	cout << "\n=============================================================" << endl;
	tinhTongBieuThucS();
	cout << "\n=============================================================" << endl;
	tongSoDuong(ds);
	cout << "\n=============================================================" << endl;
	tongSoChan(ds);
	cout << "\n=============================================================" << endl;
	cout << "Vi tri nho nhat duoc tim thay trong danh sach dau tien la: " << viTriNhoNhatDauTien(ds);
	cout << "\n=============================================================" << endl;
	int max2, firstIndex;
	if (indexDauTienSoHoanThien(ds, max2, firstIndex)|| firstIndex!=-1) {
		cout << "Da tim thay so hoan thien lon nhat trong day so la " << max << " va vi tri cua no la " << firstIndex;
	}
	else {
		cout << "Khong tim thay so hoan thien nao trong danh sach";
	}
	cout << "\n=============================================================" << endl;
	int max;
	if (SNTMAX(ds, max)) {
		cout << "\nDa tim thay snt co gia tri max, max am la " << max << endl;
	}
	else {
		cout << "\nKhong tim thay snt trong danh sach!" << endl;
	}
}