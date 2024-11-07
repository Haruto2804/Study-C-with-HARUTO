#include "thuvien_lab4.h"
void main() {
	NodePtr list;
	khoiTao(list);
	// cau 1
	//nhap_DanhSach_Dau(list); // chen dau
	//cout << "\nDSLK vua nhap la: ";
	//xuat_DanhSach(list); // cau 1c, khi nhap day so 10 8 7 9 20, thi ket qua la 20 9 7 8 10 vi khi nhapDanhSach thi thuc hien them dau thic cac phan tu nhap sau cung se day len tren dau danh sach
	// cau 2
	nhap_DanhSach_Cuoi(list); // chen dau
	cout << "\nDSLK vua nhap la: ";
	xuat_DanhSach(list);
	// cau 3
	TYPEINFO x;
	NodePtr p;
	cout << "\nNhap x can tim: ";
	cin >> x;
	if (tim_Node_x(list, x) == NULL) {
		cout << "\nKhong tim thay " << x;
	}
	else {
		cout << "Da tim thay " << x;
		p = tim_Node_x(list, x);
	}
	// cau 4
	int pos;
	NodePtr k = list;
	cout << "\nNhap vi tri can chen: ";
	cin >> pos;
	for (int i = 0; i <= pos - 2; i++) {
		k = k->link;
	}
	cout << "\nNhap gia tri can chen: ";
	cin >> x;
	chenSau_Q(k, x);
	cout << "\nDanh sach sau khi chen " << x << " la: ";
	xuat_DanhSach(list);

	// cau 5
	xoa_Dau(list);
	cout << "\nDSLK sau khi xoa phan tu dau la: ";
	xuat_DanhSach(list);
	xoa_Cuoi(list);
	cout << "\nDSLK sau khi xoa cuoi la : ";
	xuat_DanhSach(list);

	// cau 6
	cout << "\nNhap gia tri can xoa: ";
	cin >> x;
	if (del_X(list, x)) {
		cout << "Da xoa x thanh cong!" << endl;
		cout << "Danh sach sau khi xoa " << x << " la: ";
		xuat_DanhSach(list);
	}
	else {
		cout << "\nKhong tim thay " << x << " can xoa: ";
	}
	cout << "\nDanh sach lien ket sau khi dao nguoc la: ";
	daoNguocDSLK(list);
	xuat_DanhSach(list);
	NodePtr listChan, listLe;
	tachDS(list, listChan, listLe);
	cout << "\nDanh sach toan so chan la: ";
	xuat_DanhSach(listChan);
	cout << "\nDanh sach toan so le la: ";
	xuat_DanhSach(listLe);
	cout << "\nNhap phan tu can xoa tat ca: ";
	int y;
	cin >> y;
	del_All_X(list, y);
	cout << "\nDanh sach con lai sau khi xoa tat ca cac phan tu " << y << ": ";
	xuat_DanhSach(list);
	giaiPhong(list); // cau 1b, giai phong vung nho ma cac phan tu trong DSLK ve cho he dieu hanh,
	system("pause");
}

