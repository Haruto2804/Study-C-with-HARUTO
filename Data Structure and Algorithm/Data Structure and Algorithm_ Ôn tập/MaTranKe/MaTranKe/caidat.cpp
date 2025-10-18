#include "thuvien.h"
bool docFile(MaTranKe& a, const char* tenFile) {
	FILE* f = fopen(tenFile, "r");
	if (f == NULL) {
		return false;
	}
	else {
		fscanf(f, "%d", &a.n);
		for (int i = 0;i < a.n;i++) {
			for (int j = 0;j < a.n;j++) {
				fscanf(f, "%d", &a.mt[i][j]);
			}
		}
	}
	fclose(f);
	return true;
}
bool ghiFile(MaTranKe a, const char* tenFile) {
	FILE* f = fopen(tenFile, "w");
	if (f == NULL) {
		return false;
	}
	else {
		fprintf(f, "%d\n", &a.n);
		for (int i = 0;i < a.n;i++) {
			for (int j = 0;j < a.n;j++) {
				fprintf(f, "%d ", a.mt[i][j]);
			}
			fprintf(f, "\n");
		}
	}
	fclose(f);
	return true;
}
void xuatMaTranKe(MaTranKe a) {
	for (int i = 0;i < a.n;i++) {
		for (int j = 0;j < a.n;j++) {
			cout << a.mt[i][j] << "\t";
		}
		cout << endl;
	}
}
DanhSachCanh timTapCanh(MaTranKe a) {
	DanhSachCanh arrayEdge;
	arrayEdge.n = 0;
	for (int i = 0;i < a.n;i++) {
		for (int j = 0;j < a.n;j++) {
			Canh canh;
			canh.dinhDau = i;
			canh.dinhCuoi = j;
			canh.trongSo = a.mt[i][j];
			arrayEdge.dsCanh[arrayEdge.n++] = canh;
		}
	}
	return arrayEdge;
}
void xuatTapCanh(DanhSachCanh arrayEdge) {
	for (int i = 0;i < arrayEdge.n;i++) {
		cout << "\nDinh dau: " << char(arrayEdge.dsCanh[i].dinhDau + 65);
		cout << "\tDinh cuoi: " << char(arrayEdge.dsCanh[i].dinhCuoi + 65);
		cout << "\tTrong so: " << arrayEdge.dsCanh[i].trongSo;
		cout << endl;
		cout << "----------------------------------------------"; // Dấu phân cách trực quan hơn
		}
}
DanhSachDinh DFS(MaTranKe a, VERTEX startV) {
	stack <VERTEX> s;
	DanhSachDinh arrayDFS;
	arrayDFS.n = 0;
	bool visited[MAX_DINH];
	for (int i = 0;i < a.n;i++) {
		visited[i] = 0;
	}
	cout << "\n- Day " << char(startV + 65) << " vo stack!!";
	s.push(startV);
	visited[startV] = 1;
	cout << "\n- Thuat toan DFS bat dau tu dinh " << char(startV + 65) << " bat dau......";
	while (!s.empty())
	{
		VERTEX k = s.top();
		s.pop();
		cout << "\n- Lay " << char(k + 65) << " ra khoi stack" << endl;
		cout << "\n*************************KIEM TRA CAC DINH LIEN KET VOI " << char(k + 65) << "*************************";
		for (int i = 0;i < a.n;i++)
		{
			cout <<"\n- Dang kiem tra dinh " << char(i + 65);
			if (isConnected(a, k, i) && !visited[i]) {
				cout << "\n- Dinh " << char(k + 65) << " co lien ket voi " << " dinh " << char(i + 65);
				cout << "\n- Dang day " << char(i + 65) << " vo stack";
				s.push(i);
				cout << "\n- Danh dau " << char(i + 65) << " da tham!";
				visited[i] = 1;
				cout << "\n====>DA DAY " << char(i + 65) << " VO STACK!!!";
				cout << "\n+++++++++++++++++++++++++++++++++++++++++++++";
			}
			else if (isConnected(a, k, i) && visited[i]) {
				cout << "\n- DA THAM DINH " << char(i + 65) << " ROI!!!!!";
			}
			else {
				cout << "\n- Dinh " << char(k + 65) << " khong lien ket voi dinh " << char(i + 65);
			}
			}
		cout << "\n- Luu dinh " << char(k + 65) << " vao ds duyet DFS";
		arrayDFS.dsDinh[arrayDFS.n++] = k;
		cout << "\n- Ket thuc qua trinh duyet dinh " << char(k + 65);
		cout << "\n------------------------------------------------";
	}
	return arrayDFS;
}
bool isConnected(MaTranKe mt, int x, int y) {
	if (mt.mt[x][y] !=0) {
		return true;
	}
	else {
		return false;
	}
}
void xuatDanhSachDinh(DanhSachDinh dsDinh) {
	for (int i = 0;i < dsDinh.n;i++) {
		cout << char(dsDinh.dsDinh[i] + 65) << "\t";
	}
}
void doiHuongMaTran(MaTranKe mtGoc, MaTranKe& mtDaonguoc) {
	mtDaonguoc.n = mtGoc.n;
	for (int i = 0;i < mtDaonguoc.n;i++) {
		for (int j = 0;j < mtDaonguoc.n;j++) {
			mtDaonguoc.mt[i][j] = mtGoc.mt[j][i];
		}
	}
}

bool docFileDinhVaCanhVoHuong(MaTranKe &mt, const char* tenFile)
{
	FILE* f = fopen(tenFile, "r");
	if (f == NULL) {
		return false;
	}
	else {
		mt = { 0 };
		int u, v;
		fscanf(f, "%d", &mt.n);
		while (fscanf(f, "%d %d", &u, &v) == 2) {
			mt.mt[u][v] = 1;
			mt.mt[v][u] = 1;
		}
	}
	fclose(f);
	return true;
}
bool docFileDinhVaCanhCoHuong(MaTranKe& mt, const char* tenFile) {
	FILE* f = fopen(tenFile, "r");
	if (f == NULL) {
		return false;
	}
	else {
		mt = { 0 };
		int u, v;
		fscanf(f, "%d", &mt.n);
		while (fscanf(f, "%d %d", &u, &v) == 2) {
			mt.mt[u][v] = 1;
		}
	}
	fclose(f);
	return true;
}
