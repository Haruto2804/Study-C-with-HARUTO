#include "thuvien.h"

int main() {
	MaTranKe mt;
	DanhSachCanh dsCanh;
	if (docFile(mt, "dothi2.txt")) {
		cout << "\nDoc file thanh cong!!!" << endl;
		xuatMaTranKe(mt);
		cout << "\nDanh sach canh cua ma tran tren la: " << endl;
		dsCanh = timTapCanh(mt);
		xuatTapCanh(dsCanh);
	}
	else {
		cout << "\nLoi doc file!!!";
	}
	bacRaVaBacVaoCuaDinhBatKy(mt, 'A');
	bacRaVaBacVaoCuaDinhBatKy(mt, 'D');
	bacRaVaBacVaoCuaDinhBatKy(mt, 'F');
	DanhSachDinh ketQuaDuyet;
	ketQuaDuyet = DFS(mt, 0);
	cout << endl;
	cout << "\nket qua duyet dfs bang stack: ";
	xuatDanhSachDinh(ketQuaDuyet);
	cout << "\nSo thanh phan lien thong la: " << demThanhPhanLienThong(mt);
	cout << "\n====================Chuong trinh truy vet duong di: ";
	cout << "\nNhap dinh dau: ";
	int a, b;
	cin >> a;
	cout << "Nhap dinh cuoi: ";
	cin >> b;
	VERTEX parent[1001];
	bool visited[1001];
	for (int i = 0;i < mt.n;i++) {
		visited[i] = 0;
	}
	for (int i = 0;i < mt.n;i++) {
		parent[i] = -1;
	}
	DFS_TruyVet(mt, 0, visited, parent);
	cout << "\nVISITED: ";
	for (int i = 0;i < mt.n;i++) {
		cout << visited[i] << "\t";
	}
	cout << "\nPARENT: ";
	for (int i = 0;i < mt.n;i++) {
		cout << parent[i] << "\t";
	}
	return 0;
}