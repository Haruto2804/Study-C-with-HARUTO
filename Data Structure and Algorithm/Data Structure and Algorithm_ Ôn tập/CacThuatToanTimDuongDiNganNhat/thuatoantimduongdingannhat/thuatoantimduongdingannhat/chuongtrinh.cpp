#include "thuvien.h"
int main() {
	MaTranKe mt;
	if (docFile(mt, "dothi.txt")) {
		cout << "Doc file thanh cong!" << endl;
		xuatMaTranKe(mt);
	}
	else {
		cout << "\nDoc file that bai!";
	}

	// THUAT TOAN FLOYDD


	/*cout << "\nMa tran next luu dinh ke den dinh ke tiep" << endl;
	int next[100][100];
	khoiTaoMaTranNextDeTruyVet(mt, next);
	for (int i = 0;i < mt.n;i++) {
		for (int j = 0;j < mt.n;j++) {
			cout << next[i][j] << "\t";
		}
		cout << endl;
	}
	cout << "\nThuat Toan Floydd" << endl;
	mt = Floyd(mt, next);
	xuatMaTranKe(mt);
	for (int i = 0;i < mt.n;i++) {
		for (int j = 0;j < mt.n;j++) {
			if (i == j) {
				continue;
			}
			else {
				cout << "Duong di tu " << i << " den " << j << " la: ";
				getPath(i, j, next);

			}
				
			cout << endl;
		}
	}*/

	// CHUYEN DOI MA TRAN KE SANG DANH SACH CANH
	//DanhSachCanh dsCanh;
	//dsCanh = timTapCanh(mt);
	//xuatTapCap(dsCanh);
	Dijisktra(mt,0, parent);
	Trace(0, 2);
	return 0;
}