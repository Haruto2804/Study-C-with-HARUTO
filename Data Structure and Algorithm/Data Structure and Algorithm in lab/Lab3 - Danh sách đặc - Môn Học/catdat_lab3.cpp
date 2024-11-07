#include "thuvien_lab3.h"
void nhapMonHoc(MonHoc& mh) {
	cout << "\n Nhap ma mh: ";
	cin >> mh.mamh;
	cout << "nhap ten mon hoc: ";
	cin.ignore();
	cin.getline(mh.tenmh, 30);
	cout << "Nhap so tin chi: ";
	cin >> mh.sotc;
}
void xuatMonHoc(MonHoc mh) {
	cout << "MaMH " << "\t" << "TenMH" << "\t\t" << "So TC" << endl;
	cout << mh.mamh << "\t " << mh.tenmh << "  \t\t" << mh.sotc << endl;
}
void nhapDanhSachMonHoc(DanhSachMonHoc& ds) {
	cout << "\n Nhap so luong mon hoc: ";
	cin >> ds.so;
	cout << "Nhap thong tin tung mon hoc";
	for (int i = 0; i < ds.so; i++) {
		cout << "\n Thong tin mon hoc thu " << i + 1 << endl;
		nhapMonHoc(ds.data[i]);
	}
}
void xuatDanhSachMonHoc(DanhSachMonHoc ds) {
	cout << "\nDanh sach cac mon hoc: " << endl;
	for (int i = 0; i < ds.so; i++) {
		cout << "Thong tin mon hoc thu " << i + 1 << endl;
		xuatMonHoc(ds.data[i]);
		cout << "\n=====================================" << endl;
	}
}
void them_MonHoc_ViTri(DanhSachMonHoc& ds, int vt, MonHoc mh) {
	// Kiểm tra vị trí hợp lệ
	if (vt < 0 || vt > ds.so) {
		cout << "\n Vi tri khong hop le";
		return; // Thoát hàm nếu vị trí không hợp lệ
	}

	// Kiểm tra xem danh sách đã đầy chưa
	if (ds.so >= MAX) { // Giả sử MAX_SIZE là kích thước tối đa của mảng
		cout << "\n Danh sach da day";
		return;
	}

	// Dịch chuyển các phần tử từ vị trí vt về sau sang bên phải
	for (int i = ds.so; i > vt; i--) {
		ds.data[i] = ds.data[i - 1];
	}

	// Thêm môn học vào vị trí vt
	ds.data[vt] = mh;
	ds.so++; // Tăng số lượng môn học
}
void xoa_MonHoc_ViTri(DanhSachMonHoc& ds, int vt) {
	if (vt<0 || vt>ds.so) {
		cout << " \n Vi tri khong hop le";
	}
	else {
		for (int i = vt+1; i <ds.so; i++) {
			ds.data[i -1] = ds.data[i];
		}
		ds.so--;
	}

}
int timKiem_TuanTu(DanhSachMonHoc ds, char* ma) {
	int i = 0;
	while (i < ds.so && strcmp(ds.data[i].mamh, ma) != 0) {
		i++;
	}
	if (i == ds.so) {
		return -1; // Khong tim thay
	}
	return i;
}
void selectionSort(DanhSachMonHoc& ds) {
	MonHoc a;
	int min;
	for (int i = 0; i < ds.so - 1; i++) {
		min = i;
		for (int j = i + 1; j < ds.so; j++) {
			if (ds.data[j].sotc < ds.data[min].sotc) {
				min = j;
			}
		}
		a = ds.data[i];
		ds.data[i] = ds.data[min];
		ds.data[min] = a;
	}
}
bool timKiemNhiPhan(DanhSachMonHoc ds, char* ma) {
	int left = 0;
	int right = ds.so - 1;
	int mid;
	do {
		mid = (left + right) / 2;
		if (strcmp(ds.data[mid].mamh, ma) == 0) {// chuoi 1 ngan hon chuoi hai
			return true;
		}
		
		if (strcmp(ds.data[mid].mamh,ma)<0) {// chuoi 1 ngan hon chuoi hai
			left = mid + 1;
		}
		else {
			right = mid - 1;
		}
	} while (left <= right);
	return false;
}
 //BTVN
int demSoLanMH(DanhSachMonHoc ds ,char *mamh) {
	int dem = 0;
	for (int i = 0; i < ds.so; i++) {
		if (strcmp(mamh, ds.data[i].mamh) == 0) {
			dem++;
		}
	}
	return dem;
}
int thayTheMonHocXThanhY(DanhSachMonHoc& ds, MonHoc MHThayThe) {
	char monHocX[20];
	cout << "\nNhap ma mon hoc X: ";
	cin >> monHocX;
	for (int i = 0; i < ds.so; i++) {
		if (strcmp(ds.data[i].mamh, monHocX) == 0) {
			for (int j = i; j < ds.so; j++) {
				ds.data[i] = MHThayThe;
				return i;
			}
		}
	}
	return -1;
}
void tinChiDanhSachMonHoc(DanhSachMonHoc& ds, DanhSachMonHoc& dstc,int &stc) {
	int l = 0;
	dstc.so = 0;
	cout << "\nNhap so tin chi: ";
	cin >> stc;
	for (int i = 0; i < ds.so; i++) {
		if (ds.data[i].sotc == stc) {
			dstc.data[l++] = ds.data[i];
			dstc.so++;
		}
	}
}
