#include "thuvien.h"
int main() {
	maTran mt;
	phatSinhMaTran(mt);
	xuatMaTran(mt);
	cout << "Tong cua tam giac tren phai la: " << tongMaTranTamGiacTrenPhai(mt);
	cout << "\nMax cua tam giam giac duoi trai la: " << maxTamGiacDuoiTrai(mt);
	cout << "\nSo lan so duong xuat hien trong tam giac tren phai la: " << demSoDuongMaTranTamGiacTrenPhai(mt);
	int max;
	if (maxAmMaTranTamGiacDuoiTrai(mt, max)) {
		cout << "\nDa tim thay max am tren tam giac duoi trai, max am la: " << max << endl;
	}
	else {
		cout << "\nKhong tim thay max am tren tam giac duoi trai!" << endl;
	}
	xuatTamGiacDuoiTrai(mt);
	return 0;
}