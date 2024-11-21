#include "thuvien_lab7_dslk.h"
int main() {
	Queue q;
	khoiTao(q);
	setValue(q);
	print(q);
	cout << "\nDanh sach sau khi xoa dau tien!";
	TYPEINFO t =getFront(q);
	cout << endl;
	print(q);
	cout << "\nGia tri sau khi xoa: " << t;
	system("pause");
	return 0;
}