#include "lab2_thuvien.h"
int main() {
	// BAI TAP 1
	//1
	DaySo x;
	nhapDaySo(x);
	cout << "Day so vua nhap la: " << endl;
	xuatDaySo(x);
	cout << "Tong cac phan tu cua day so la: ";
	cout << tongDS(x) << endl;
	//Luu day so thanh file
	if (luuDaySo(x, "dayso.txt")) {
		cout << "Day so da duoc luu" << endl;
	}
	else {
		cout << "Luu khong thanh cong" << endl;
	}

	//2
	FILE* fp;
	fp = fopen("dayso.txt", "r");
	if (fp == NULL) {
		perror("Loi mo file: ");
		return 1;
	}
	cout << "Day so doc duoc trong file la: ";
	docDaySo(x, "dayso.txt"); // doc day so trong file roi luu vao mang;
	xuatDaySo(x); // duyet mang de lay cac gia tri vua doc duoc

	//3
	cout << "Tich cua cac phan tu trong day so la: " << tichDS(x);

	//4
	cout << "\nCac phan tu duong co trong day so la: " << demPhanTuDuong(x);

	//5
	cout << "\nSo chan co trong day so la: ";
	xuatSoChan(x);


	//BAI TAP VAN DUNG 2

	//1
	 cout << "\nTong cua cac so chan co trong day so la: " << tongChan(x);


	//2
	 cout << "\nTich cua cac chi so chan co trong day so la: " << tichChiSoChan(x);
	 
	//3
	 cout << "\nSo phan tu trong day so chia het cho 3 va 5 la: " << demPTChiaHet3Va5(x);
	 return 1;
}
