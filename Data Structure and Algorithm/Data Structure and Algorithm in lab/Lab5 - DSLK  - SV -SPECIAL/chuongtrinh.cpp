#include "thuvien.h"
int main() {
	// DUNG SINH SO NGAU NHIEN DE NHAP CAC DIEM, TOAN, LY, HOA.....
	NodePtr dssv;
	cout << "Them danh sach vien: " << endl;
	SinhVien x{};
	khoiTao(dssv);
	themCuoi_DSSV(dssv);
	cout << "\nDanh sach sinh vien la: " << endl;
	xuat_DSSV(dssv);
	sapXepTheoDTB(dssv);
	xuat_DSSV(dssv);
	cout << "\nTim sinh vien theo ma. " << endl;
	cout << "Nhap ma sinh vien can tim: ";
	char maCanTim[10];
	cin.getline(maCanTim, 10);
	NodePtr sv;
	if (sv = tim_SV_Masv(dssv, maCanTim)) {
		cout << "Co sinh vien co ma " << maCanTim << endl;
		cout << "Ten sinh vien: " << sv->data.tensv << endl;
	}
	else {
		cout << "Khong tim sinh vien co ma " << maCanTim << endl;
	}
	cout << "Danh sach sinh vien sau khi xoa dau la: " << endl;
	xoa_Dau(dssv);
	xuat_DSSV(dssv);
	cout << "Danh sach sinh vien sau khi xoa cuoi la: " << endl;
	xoa_Cuoi(dssv);
	xuat_DSSV(dssv);
	cout << "\nNhap ma sinh vien can xoa sv: ";
	char maCanXoa[50];
	cin >> maCanXoa;
	xoa_SV_MaSV(dssv, maCanXoa);
	cout << "\nDanh sach sinh vien sau khi xoa sinh vien co ma " << maCanXoa << " la: " << endl;
	xuat_DSSV(dssv);
	cout << "\n==============================================================" << endl;
	cout << "CHUONG TRINH TACH MOT DANH SACH THANH HAI DANH SACH SINH VIEN VOI:" << endl;
	cout << "Danh sach 1 chua cac sinh vien co diem nho hon 5." << endl;
	cout << "Danh sach 2 chua cac sinh vien co diem nho hon hoac bang 5" << endl;
	NodePtr list1, list2;
	khoiTao(list1);
	khoiTao(list2);
	spilit_SinhVien(dssv, list1, list2);
	cout << "\nDanh sach 1: " << endl;
	xuat_DSSV(list2);
	cout << "\nDanh sach 2: " << endl;
	xuat_DSSV(list1);
	cout << "\n=================================================================" << endl;
	cout << "\nDanh sach hoc sinh sau khi dao nguoc la: ";
	daoNguocDSLK(dssv);
	cout << endl;
	xuat_DSSV(dssv);
	xoaTatCaSinhVienCoDiemDuoi5(dssv);
	cout << "\nDanh sach sinh vien sau khi xoa cac sinh vien co diem duoi 5: " << endl;
	xuat_DSSV(dssv);
	cout << endl;
	sapXepTheoDTB(dssv);
	cout << "\nDanh sach sinh vien sau khi sap xep diem trung binh theo chieu tang dan: " << endl;
	xuat_DSSV(dssv);
	system("pause");
	giaiPhong(dssv);
	return 0;
}