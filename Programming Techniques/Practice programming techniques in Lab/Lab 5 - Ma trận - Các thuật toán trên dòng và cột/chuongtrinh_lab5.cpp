#include "thuvien_lab5.h"
int main() {
	MaTran a;
	nhapMaTran(a);
	xuatMaTran(a);
	//BAI TAP 1
	//if (docMaTran(a, "matran.txt")) {
	//	cout << "\nDoc ma tran thanh cong!" << endl;
	//}
	//else {
	//	cout << "\nKhong doc duoc ma tran: " << endl;
	//}
	//cout << "Ma tran vua nhap la: " << endl;

	//xuatMaTran(a);
	//cout << "\nTong cac gia tri trong mang la: " << tong(a) << endl;
	//cout << "Gia tri lon nhat la: " << max(a) << endl;
	//if (luuMaTran(a, "matran.txt")) {
	//	cout << "Luu thanh cong" << endl;
	//}
	//else {
	//	cout << "Luu khong thanh cong" << endl;
	//}
	//cout << "So duong co trong ma tran la: " << demDuong(a);

	//BT VAN DUNG
	cout << "\nTong chan trong ma tran la: " << tongChan(a) << endl;
	cout << "So lan so chinh phuong co trong ma tran la: " << demSoChinhPhuong(a) << endl;
	int max;
	if (maxSoNguyenTo(a, max)) {
		cout << "Da tim thay so nguyen trong ma tran, max cua so nguyen to la " << max << endl;
	}
	else {
		cout << "Khong tim thay so nguyen to nao trong ma tran!" << endl;
	}

	//BT TONG HOP
	tinhTongCacDong(a);
	cout << "\n============================================" << endl;
	DongCoTongMax(a);
	cout << "\nTong cac phan tu max cua moi dong la " << tongCacMaxMoiDong(a);
	cout << "\nTong cua tung cot la: " << endl;
	tongCacCot(a);
	cout << "\nNhap 2 cot can hoan doi: ";
	int k, j;
	cin >> k;
	cin >> j;
	k = k - 1;
	j = j - 1;
	hoanDoiHaiCot(a, k, j);
	cout << "Ma tran sau khi hoan doi cot " << k + 1 << " va " << j + 1 << endl;
	xuatMaTran(a);
	cout << "\nMa tran sau khi sap xep tang dan tung cot la: ";
	sapXepTangDanTungCot(a);
	cout << endl;
	xuatMaTran(a);
	cout << "\nMa tran sau khi sap xep giam dan tung dong la: ";
	sapXepGiamDanTungDong(a);
	cout << endl;
	xuatMaTran(a);
	return 0;
}