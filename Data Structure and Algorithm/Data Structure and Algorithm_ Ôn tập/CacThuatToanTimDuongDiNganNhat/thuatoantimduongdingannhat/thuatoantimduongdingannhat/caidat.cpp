#include "thuvien.h"
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
bool ghiFile(MaTranKe &mt, const char* tenFile) {
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

void xuatMaTranKe (MaTranKe mt)
{
	for (int i = 0;i < mt.n;i++) {
		for (int j = 0;j < mt.n;j++) {
			if (mt.mt[i][j] == 9999) {
				cout << "INF" << "\t";
			}
			else {
				cout << mt.mt[i][j] << "\t";
			}
		}
		cout << endl;
	}
}
MaTranKe Floyd(MaTranKe& mt, int next[][100]) {
	for (int k = 0;k < mt.n;k++) {
		for (int i = 0;i < mt.n;i++) {
			for (int j = 0;j < mt.n;j++) {
				if (mt.mt[i][j] > mt.mt[i][k] + mt.mt[k][j]) {
					mt.mt[i][j] = mt.mt[i][k] + mt.mt[k][j];
					next[i][j] = next[i][k];
				}
			}
		}
	}
	return mt;
}
bool isConnected (MaTranKe mt, int x, int y) {
	if (mt.mt[x][y] != 0 && mt.mt[x][y] != 9999) {
		return true;
	}
	else {
		return false;
	}
}
void getPath(int u, int v, int next[][100]) {
	if (next[u][v] == -1) {
		cout << "\nKhong co duong di tu dinh u toi dinh v" << endl;
		return;
	}
	vector <int> path;
	// u = 3, v = 1
	while (u!=v) {
		path.push_back(u);
		u = next[u][v];	
	}
	path.push_back(u);
	for (int x : path) {
		cout << x << "->" << " ";
	}
}

void khoiTaoMaTranNextDeTruyVet(MaTranKe mt,int next[][100])
{
	for (int i = 0;i < mt.n;i++) {
		for (int j = 0;j < mt.n;j++) {
			if (i == j) {
				next[i][j] = i;
			}
			else if (isConnected(mt, i, j)) {
				next[i][j] = j;
			}
			else {
				next[i][j] = -1;
			}
		}
	}
}
DanhSachCanh timTapCanh(MaTranKe mt) {
	DanhSachCanh dsCanh;
	dsCanh.n = 0;
	for (int i = 0;i < mt.n;i++) {
		for (int j = 0;j < mt.n;j++) {
			if (i != j) {
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
void xuatTapCap(DanhSachCanh dsCanh) {
	cout << "\nCAC TAP CANH LA: " << endl;
	for (int i = 0;i < dsCanh.n;i++) {
		if (dsCanh.dsCanh[i].trongSo != 9999) {
			cout << "\nDinh dau: " << dsCanh.dsCanh[i].dinhDau;
			cout << "\tDinh cuoi: " << dsCanh.dsCanh[i].dinhCuoi;
			cout << "\tTrong so: " << dsCanh.dsCanh[i].trongSo;
			cout << endl;
		}
	}
}
void Dijisktra(MaTranKe mt, int startV,int parent[]) {
	bool visited[100];
	for (int i = 0;i < mt.n;i++) {
		visited[i] = false;
	}
	int dist[100];
	for (int i = 0;i < mt.n;i++) {
		dist[i] = INF;
	}
	dist[startV] = 0;
	for (int i = 0;i < mt.n;i++) { // dinh hien tai dang xet 
		//tim dist nho nhat va chua duoc tham
		int u = -1;
		int MIN = INT_MAX;
		for (int k = 0;k < mt.n;k++) {
			if (!visited[k] && dist[k] < MIN) {
				MIN = dist[k];
				u = k;
			}
		}
		if (u == -1) {
			break;
		}
		visited[u] = true;
		for (int j = 0;j < mt.n;j++) {
			if (mt.mt[i][j] != 9999 && !visited[j])
			{
				if (dist[j] > dist[i] + mt.mt[i][j])
				{
					dist[j] = dist[i] + mt.mt[i][j];
					parent[j] = i;
				}
			}
		}
	}
}
void Trace(int u,int v) {
	vector <int> path;
	while (u != v) {
		path.push_back(u);
		u = parent[u];
	}
	path.push_back(v);
	for (int x : path) {
		cout << v << " ";
	}
}
