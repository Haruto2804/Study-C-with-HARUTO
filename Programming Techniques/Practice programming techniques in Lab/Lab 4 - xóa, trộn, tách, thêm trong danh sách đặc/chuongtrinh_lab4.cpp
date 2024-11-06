#include "thuvien_lab4.h"
int main() {
	// cau 1
	DaySo x;
	nhapDaySo(x);
	cout << "Day so vua nhap la: " << endl;
	xuatDaySo(x);
	int so, viTri;
	cout << "\nCac phan tu khong trung nhau trong danh sach la: ";
	del_All_Trung(x);
	cout << endl;
	xuatDaySo(x);
	cout << "\nNhap so can them: ";
	cin >> so;
	cout << "\nNhap vi tri can them: ";
	cin >> viTri;
	if (chenXVaoViTri(x, viTri, so)) {
		cout << "Chen vao thanh cong" << endl;
		cout << "Day so sau khi chen la: ";
		xuatDaySo(x);
	}
	else {
		cout << "Chen khong duoc" << endl;
	}
	cout << "\nNhap vi tri can xoa: ";
	cin >> viTri;
	if (xoaPhanTu(x, viTri)) {
		cout << "Xoa thanh cong" << endl;
		cout << "Day so sau khi xoa la: ";
		xuatDaySo(x);
	}
	else {
		cout << "Xoa khong duoc" << endl;
	}
	bubbleSort_TangDan(x);
	cout << "\nDay so sau khi sap xep tang dan la: ";
	xuatDaySo(x);

	// BT van dung
	//cau 2
	bubbleSort_GiamDan(x);
	cout << "\nDay so sau khi sap xep giam dan la: ";
	xuatDaySo(x);
	// cau 3
	DaySo day, day1, day2;
	cout << "\nNhap day 1: " << endl;
	nhapDaySo(day1);
	cout << "\nNhap day 2: " << endl;
	nhapDaySo(day2);
	cout << "\nDanh sach sau khi tron: ";
	tronHaiDaySo(day, day1, day2);
	xuatDaySo(day);
	// cau 4
	cout << "\nNhap vi tri can tach: ";
	int k;
	cin >> k;
	tachDayTheoViTri(day, day1, day2, k);
	cout << "\nDay 1 sau khi tach o vi tri " << k << ": ";
	xuatDaySo(day1);
	cout << "\nDay 2 sau khi tach o vi tri " << k << ": ";
	xuatDaySo(day2);
	cout << "\nNhap phan tu can tim: ";
	int soCanTim;
	cin >> soCanTim;
	if (timPhanTu(x, soCanTim) == -1) {
		cout << "Khong tim thay " << soCanTim;
	}
	else {
		cout << "Tim thay " << soCanTim << " va vi tri cua no la: " << timPhanTu(x, soCanTim);
	}
	if (checkTangDan(x)) {
		cout << "\nDanh sach tang dan!";
	}
	else {
		cout << "\nDanh sach khong tang dan!";
	}
	cout << "\nDay so sau khi dao nguoc la: ";
	daoNguocDaySo(x);
	cout << "\nNhap gia tri can xoa: ";
	int soCanXoa;
	cin >> soCanXoa;
	del_All_X(x, soCanXoa);
	cout << "\nDanh sach sau khi xoa " << soCanXoa << endl;
	xuatDaySo(x);
	//BT lam them
	// cau 1
	del_All_Max(x);
	cout << "\nDay so sau khi xoa max la: ";
	xuatDaySo(x);
	tachChanLe(x, day1, day2);
	cout << "\nDay chan la: ";
	xuatDaySo(day1);
	cout << "\nDay le la: ";
	xuatDaySo(day2);
	cout << "\nDay so sau khi ghep lai la: ";
	ghepDay(x,day1, day2);
	xuatDaySo(x);
	return 0;
}
