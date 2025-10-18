#include "thuvien.h"
bool visited[50];
bool docFile(MaTranKe& mt, const char* tenFile) {
	FILE* f = fopen(tenFile, "r");
	if (f == NULL) {
		return false;
	}
	else {
		fscanf(f, "%d", &mt.n);
		for (int i = 0;i < mt.n;i++) {
			for (int j = 0;j < mt.n;j++) {
				fscanf(f, "%d", &mt.mt[i][j]);
			}
		}
	}
	fclose(f);
	return true;
}
bool ghiFile(MaTranKe mt, const char* tenFile) {
	FILE* f = fopen(tenFile, "r");
	if (f == NULL) {
		return false;
	}
	else {
		fprintf(f, "%d", mt.n);
		for (int i = 0;i < mt.n;i++) {
			fprintf(f, "\n");
			for (int j = 0;j < mt.n;j++) {
				fprintf(f, "%d ", mt.mt[i][j]);
			}
		}
	}
	fclose(f);
	return true;
}
void xuatMaTranKe(MaTranKe mt) {
	for (int i = 0;i < mt.n;i++) {
		for (int j = 0;j < mt.n;j++) {
			cout << mt.mt[i][j] << "\t";
		}
		cout << endl;
	}
}
DanhSachCanh timTapCanh(MaTranKe mt) {
	DanhSachCanh dsCanh{};
	dsCanh.n = 0;
	for (int i = 0; i < mt.n; i++) {
		for (int j = 0; j < mt.n; j++) {
			if (mt.mt[i][j] != 0) {
				Canh canh;
				canh.dinhDau = i;
				canh.dinhCuoi = j;
				canh.trongSo = mt.mt[i][j];
				dsCanh.dsCanh[dsCanh.n++] = canh;

			}
				
		}
	}
	return dsCanh;
}
void xuatTapCanh(DanhSachCanh dsCanh) {
	int k = 1;
	for (int i = 1;i < dsCanh.n;i++) {
		cout << endl;
		cout << k++<<"." << " Dinh dau: " << dsCanh.dsCanh[i].dinhDau;
		cout << "\t\tDinh cuoi: " << dsCanh.dsCanh[i].dinhCuoi ;
		cout << "\t\tTrong so: " << dsCanh.dsCanh[i].trongSo;
	}
}

void bacRaVaBacVaoCuaDinhBatKy(MaTranKe mt, char dinh)
{
	int dinh2 = int(dinh - 65);
	int bacRa = 0;
	int bacVao = 0;
	// tinh bac Ra
	for (int j = 0;j < mt.n;j++) {
		if (mt.mt[dinh2][j]!=0) {
			bacRa++;
		}
	}
	for (int j = 0;j < mt.n;j++) {
		if (mt.mt[j][dinh2]!=0) {
			bacVao++;
		}
	}
	cout << "\nBac vao cua dinh " << char(dinh2 + 65) << " la: " << bacRa;
	cout << "\nBac ra cua dinh " << char(dinh2 + 65) << " la: " << bacVao;
}
bool isConnected(MaTranKe mt, int x, int y)
{
	if (mt.mt[x][y] != 0) {
		return true;
	}
	else {
		return false;
	}
}

void xuatDanhSachDinh(DanhSachDinh dsDinh)
{
	for (int i = 0;i < dsDinh.n;i++) {
		cout << char(dsDinh.DanhSachDinh[i] + 65) << "\t";
	}
}
int demThanhPhanLienThong(MaTranKe mt)
{
	DanhSachDinh dsDinh;
	bool visited[50];
	int cnt = 0;
	for (int i = 0;i < mt.n;i++) {
		visited[i] = false;
	}
	cout << "\nThanh phan lien thong va so tplt" << endl;
	int k = 0;
	for (int i = 0;i < mt.n;i++) {
		if (!visited[i]) {
			dsDinh = DFS(mt, i);
			DFS_Component(mt, i, visited);
			cnt++;
			cout << k++ << ". ";
			xuatDanhSachDinh(dsDinh);
			cout << endl;
		}
		
	}
	return cnt++;
}
void DFS_Component(MaTranKe mt, VERTEX startV, bool visited[])
{
	stack <VERTEX> s;
	s.push(startV);
	while (!s.empty()) {
		VERTEX k = s.top();
		s.pop();
		if (!visited[k]) {
			visited[k] = 1;
			for (int i = 0;i < mt.n;i++) {
				if (isConnected(mt, k, i) && !visited[i]) {
					s.push(i);
				}
			}
		}
	}
}
void truyVetDuongDi(MaTranKe mt, int s, int e, bool visited[],VERTEX parent[]) // PATH
{
	memset(visited, false, sizeof(visited));
	memset(parent, -1, sizeof(parent));
	DFS_TruyVet(mt, s,visited,parent);
	if (!visited[e]) {
		cout << "\nKhong co duong di";
	}
	else {
		vector<int> path;
		while (s != e) {
			path.push_back(e);	
			s = parent[e];
		}
		path.push_back(s);
		reverse(path.begin(), path.end());
		for (int x : path) {
			cout << x << " ";
		}
	}
}
void DFS_TruyVet(MaTranKe mt, VERTEX startV, bool visited[], VERTEX parent[]) {
	stack <VERTEX> s;
	s.push(startV);
	while (!s.empty()) {
		VERTEX k = s.top();
		s.pop();
		if (!visited[k]) {
			visited[k] = 1;
			for (int i = 0;i < mt.n;i++) {
				if (isConnected(mt, k, i) && !visited[i]) {
					s.push(i);
					parent[i] = k;
				}
			}
		}
	}
}
	DanhSachDinh DFS(MaTranKe mt, VERTEX startV) {
		DanhSachDinh d;
		d.n = 0;
		bool visited[50];
		for (int i = 0;i < 50;i++) {
			visited[i] = 0;
		}
		stack <VERTEX> s;
		s.push(startV);
		while (!s.empty()) {
			VERTEX k = s.top();
			s.pop();
			if (!visited[k]) {
				visited[k] = 1;
				d.DanhSachDinh[d.n++] = k;
				// kiem tra coi co thang nao ke voi k va chua dc tham ko
				for (int i = 0;i < mt.n;i++) {
					if (isConnected(mt, k, i) && !visited[i]) {
						s.push(i);
					}
				}
			}

		}
		return d;
	}