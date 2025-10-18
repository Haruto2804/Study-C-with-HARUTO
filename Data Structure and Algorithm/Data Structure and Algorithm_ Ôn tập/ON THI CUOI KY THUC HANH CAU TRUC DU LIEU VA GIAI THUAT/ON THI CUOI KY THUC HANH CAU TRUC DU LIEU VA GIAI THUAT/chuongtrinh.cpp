#include "thuvien.h"
int main() {
	MaTranKe mt;
	///////////////////////////////////////////////
	if (docFile(mt, "dothi1.txt")) {
		cout << "Doc file thanh cong!" << endl;
		cout << "Ket qua cua ma tran 1 la: " << endl;
		xuatMaTranKe(mt);
	}
	else {
		cout << "Loi doc file!";
	}
	bool visited[50];
	for (int i = 0;i < mt.n;i++) {
		visited[i] = false;
	}
	DanhSachDinh dsDinh;
	dsDinh = DFS(mt, 0);
	cout << "\nKet qua duyet DFS la: ";
	DFS_DeQui(mt, 0, visited);
	cout << "\nKet qua duyet BFS la: ";
	xuatDanhSachDinh(dsDinh);
	//////////////////////////////////////////////
	MaTranKe mt2;
	if (docFile(mt2, "dothidemtplt.txt")) {
		cout << "\nDoc file thanh cong!" << endl;
		cout << "Ket qua cua ma tran 2 la: " << endl;
		xuatMaTranKe(mt2);
		cout << "==============================" << endl;
	}
	else {
		cout << "\nLoi doc file!";
	}
	// reset mảng visited lại
	for (int i = 0; i < mt2.n; i++) {
		visited[i] = false;
	}
	cout << "\nSo thanh phan lien thong cua ma tran 2 la: " << demSoThanhPhanLienThong(mt2, visited) << endl;
	DanhSachCanh dsCanh1;
	cout << "\nTap canh cua ma tran 1: " << endl;
	dsCanh1 = timTapCanh(mt);
	xuatTapCanh(dsCanh1);
	DanhSachCanh dsCanh2;
	cout << "\nTap canh cua ma tran 2: " << endl;
	dsCanh2 = timTapCanh(mt2);
	xuatTapCanh(dsCanh2);
	//////////////////////////////////////////////////////////////////////////
	DanhSachKe dsKe1;
	if (docFile(dsKe1, "dsKe.txt")) {
		cout << "Doc file thanh cong!" << endl;
		xuatDanhSachKe(dsKe1);
	}
	else {
		cout << "Loi doc file!";

		return 0;
	}
}