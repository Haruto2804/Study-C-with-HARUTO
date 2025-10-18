//cho file dothi.txt có nội dung sau:
//5
//0 0 1 2 3
//0 0 5 1 3
//3 2 0 0 1
//4 0 7 0 0
//2 1 0 3 0
#include "thuvien.h"
int main() {
	MaTranKe mt;
	bool ketQua = docFile(mt, "dothi.txt");
	if (ketQua) {
		cout << "\nDoc file thanh cong!!";
		cout << "\nMa Tran Ke la: " << endl;
		xuatMaTranKe(mt);
	}
	else {
		cout << "\nDoc file khong thanh cong!";
	}
	DanhSachCanh arrayEdge;
	arrayEdge = timTapCanh(mt);
	xuatTapCanh(arrayEdge);
	DanhSachDinh ketQuaDFS;
	cout << "\nNhap dinh bat dau de duyet DFS(A - B - C - D - E):  ";
	char dinh;
	cin >> dinh;
	if (dinh >= 65 && dinh <= 69) {
		ketQuaDFS = DFS(mt, int(dinh - 65));
		cout << "\nKet qua khi duyet DFS la: " << endl;
		xuatDanhSachDinh(ketQuaDFS);
	}
	else {
		cout << "Nhap dinh khong hop le!!!";
	}
	cout << "\nDoi huong ma tran....";
	MaTranKe maTranDaoNguoc;
	cout << "\nMa tran truoc khi dao nguoc la: " << endl;
	xuatMaTranKe(mt);
	cout << "\nMa tran sau khi dao nguoc la: " << endl;
	doiHuongMaTran(mt, maTranDaoNguoc);
	xuatMaTranKe(maTranDaoNguoc);
	cout << "\n===================================";
	MaTranKe mt2;
	//bool ketQua2 = docFileDinhVaCanhVoHuong(mt2, "dinhvacanhVoHuong.txt");
	bool ketQua2 = docFileDinhVaCanhCoHuong(mt2,"dinhvacanhCoHuong.txt");
	if (ketQua2) {
		DanhSachDinh dsDinh;
		DanhSachCanh dsCanh;
		cout << "\nDoc file thanh cong!";
		cout << "\nMa Tran Ke 2 co dang: " << endl;
			xuatMaTranKe(mt2);
	}
	else {
		cout << "\nLoi doc file!!!";
	}
	return 0;
}