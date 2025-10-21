#include "thuvien.h"
int main() {
	AVLTree DSSV;
	for (int i = 0; i < 10000; ++i) {
		SinhVien sv;
		sv.taoNgauNhienDuLieuSinhVien(); // Hàm này chứa taoMaSV()
		sv.taoMaSV();
		DSSV.insertSV(sv);
	}

	cout << "Da khoi tao 5 sinh vien ngau nhien." << endl;
	switchCaseForChoice(DSSV);
	return 0;
}