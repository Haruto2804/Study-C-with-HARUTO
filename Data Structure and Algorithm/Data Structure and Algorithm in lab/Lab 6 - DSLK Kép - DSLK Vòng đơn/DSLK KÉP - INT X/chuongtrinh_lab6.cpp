//#include "thuvien_lab6.h"
//int main() {
//	// cau 1
//	Dlist list;
//	khoi_Tao(list);
//	nhap_Ds_themDau(list);
//	cout << "\nXuat danh sach theo chieu thuan: ";
//	xuat_Ds_Thuan(list);
//	cout << "\nXuat danh sach theo chieu nghich: ";
//	xuat_Ds_Nguoc(list);
//	// cau 2
//	cout << "\nNhap them cuoi " << endl;
//	nhap_Ds_themCuoi(list);
//	cout << "\Xuat danh sach sau khi them cuoi: ";
//	xuat_Ds_Thuan(list);
//	// cau 3
//	xoa_Dau(list);
//	cout << "\nDanh sach sau khi xoa dau la: ";
//	xuat_Ds_Thuan(list);
//	// cau 4
//	cout << "\nDanh sach sau khi xoa cuoi la: ";
//	xoa_Cuoi(list);
//	xuat_Ds_Thuan(list);
//	// cau 5
//	TYPEINFO x;
//	cout << "\nNhap x can tim: ";
//	cin >> x;
//	int vitri;
//	vitri = tim_ViTri_X(list, x);
//		if (vitri == -1) {
//		cout << "\nKhong co phan tu " << x << " can tim!" << endl;
//	}
//	else {
//			cout << "Vi tri cua " << x << " la: " << vitri;
//	}
//	return 0;
//}