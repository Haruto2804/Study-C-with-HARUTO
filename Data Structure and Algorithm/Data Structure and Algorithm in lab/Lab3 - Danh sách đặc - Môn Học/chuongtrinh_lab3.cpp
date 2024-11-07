#include "thuvien_lab3.h"
void main() {
	// cau 1
	MonHoc mh, MHthayThe;
	DanhSachMonHoc ds;
	//nhapMonHoc(mh);
	//cout << "\n Mon hoc ban vua nhap la: " << endl;
	//xuatMonHoc(mh);

	//// cau 2
	nhapDanhSachMonHoc(ds);
	xuatDanhSachMonHoc(ds);

	// cau 3
	/*cout << "Nhap mon hoc can them vao danh sach" << endl;
	cout << "Nhap vi tri can them vao danh sach: ";
	int vt;
	cin >>vt;
	nhapMonHoc(mh);*/
	//them_MonHoc_ViTri(ds, vt, mh);
	//xuatDanhSachMonHoc(ds);

	// cau 4
	//cout << "Nhap vi tri can xoa vao danh sach: ";
	//int vtxoa;
	//cin >> vtxoa;
	////xoa_MonHoc_ViTri(ds, vtxoa);
	//xuatDanhSachMonHoc(ds);

	//// cau 5
	char mamh[10];
	//cout << "\n Nhap ma MH muon tim: ";
	//cin >> mh.mamh;
	//int k = timKiem_TuanTu(ds, mh.mamh);
	//if (k == -1) {
	//	cout << "\nKhong co ma mh trong DS";
	//}
	//else {
	//	cout << "\nCo mon hoc ban can tim:" << endl;
	//	xuatMonHoc(ds.data[k]);
	//}
	//// cau 6
	//selectionSort(ds);
	//xuatDanhSachMonHoc(ds);
	/*cout << "\nNhap ma mon hoc can tim: ";
	cin >> mamh;
	if (timKiemNhiPhan(ds, mamh)) {
		cout << "Da tim thay!";
	}
	else {
		cout << "Khong tim thay!";
	}
	*/
	//BTVN
	//cau 1
	//cout << "\n Nhap ma MH muon dem: ";
	//cin >> mh.mamh;
	//cout<<"So lan ma "<<mh.mamh<< " xuat hien trong danh sach la "<<demSoLanMH(ds, mh.mamh);
	
	// cau 2
	/*nhapMonHoc(MHthayThe);
	cout << "\nVi tri tim thay cua mon hoc X la: " << thayTheMonHocXThanhY(ds, MHthayThe);
	xuatDanhSachMonHoc(ds);*/

	//cau 3
	DanhSachMonHoc dsTinChi;
	int stc;
	tinChiDanhSachMonHoc(ds, dsTinChi, stc);
	cout << "Danh sach co chua so tin chi la " << stc << " ma ban can la: " << endl;
	xuatDanhSachMonHoc(dsTinChi);



}