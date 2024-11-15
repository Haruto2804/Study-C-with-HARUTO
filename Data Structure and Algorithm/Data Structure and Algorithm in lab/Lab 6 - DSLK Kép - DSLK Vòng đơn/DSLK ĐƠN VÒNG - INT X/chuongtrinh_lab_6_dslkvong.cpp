#include "thuvien_lab6_dslkvong.h"
int main() {
	// cau 6
	List k;
	khoiTao(k);
	readList_Dau(k);
	cout << "\nDanh sach lien ket vong sau khi them dau la: ";
	printList(k);
	readList_Cuoi(k);
	cout << "\nDanh sach lien ket vong sau khi them cuoi la: ";
	printList(k);
	// cau 7
	cout << "\nDanh sach lien ket vong sau khi xoa dau la: ";
	xoa_Dau(k);
	printList(k);
	cout << "\nDanh sach lien ket vong sau khi xoa cuoi la: ";
	xoa_Cuoi(k);
	printList(k);
	// cau 8
	TYPEINFO x;
	cout << "\nNhap gia tri de tim node: ";
	cin >> x;
	if (tim_X(k, x)) {
		cout << "Co tim thay node chua phan tu " << x;
	}
	else {
		cout << "Khong tim thay node chua phan tu " << x;
	}
	cout << endl;
	system("pause");

	return 0;
}