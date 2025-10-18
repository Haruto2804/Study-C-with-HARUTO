#include "thuvien.h"
bool docFile(MaTranKe& mt, const char* tenFile) {
	FILE* f = fopen(tenFile, "r");
	if (f == NULL) {
		return false;
	}
	fscanf(f, "%d", &mt.n);
	for (int i = 0;i < mt.n;i++) {
		for (int j = 0;j < mt.n;j++) {
			fscanf(f, "%d", &mt.mt[i][j]);
		}
	}
	fclose(f);
	return true;
}
bool ghiFile(MaTranKe& mt, const char* tenFile) {
	FILE* f = fopen(tenFile, "r");
	if (f == NULL) {
		return false;
	}
	fprintf(f, "%d", mt.n);
	for (int i = 0;i < mt.n;i++) {
		fprintf(f, "\n");
		for (int j = 0;j < mt.n;j++) {
			fprintf(f, "%d ", mt.mt[i][j]);
		}
	}
	fclose(f);
	return true;
}
void xuatMaTranKe(MaTranKe mt) {
	for (int i = 0;i < mt.n;i++) {
		for (int j = 0;j < mt.n;j++) {
			cout << mt.mt[i][j] << " ";
		}
		cout << endl;
	}
}
DanhSachDinh DFS(MaTranKe mt, int startV) {
	DanhSachDinh dsDinh;
	dsDinh.n = 0;
	stack <int> s;
	bool visited[MAX];
	for (int i = 0;i < mt.n;i++) {
		visited[i] = false;
	}
	s.push(startV);
	visited[startV] = true;
	while (!s.empty())
	{
		int u = s.top();
		s.pop();
		dsDinh.ds[dsDinh.n++] = u;
		for (int i = 0;i <mt.n;i++) {
			if (isConnect(u, i, mt) && !visited[i]) {
				s.push(i);
				visited[i] = true;
			}
		}
	}
	return dsDinh;
}
bool isConnect(int x, int y, MaTranKe mt)
{
	if (mt.mt[x][y] != 0) {
		return true;
	}
	else {
		return false;
	}
}
DanhSachDinh BFS(MaTranKe mt, int startV) {
	DanhSachDinh dsDinh;
	dsDinh.n = 0;
	queue<int> q;
	bool visited[50];
	for (int i = 0;i < mt.n;i++) {
		visited[i] = false;
	}
	q.push(startV);
	visited[startV] = true;
	while (!q.empty()) {
		int u = q.front();
		q.pop();
		dsDinh.ds[dsDinh.n++] = u;
		for (int i = 0;i < mt.n;i++) {
			if (isConnect(u, i, mt) && !visited[i]) {
				q.push(i);
				visited[i] = true;
			}
		}
	}
	return dsDinh;
}
void DFS_DeQui(MaTranKe mt, int startV, bool visited[50])
{
	cout << startV << " ";
	visited[startV] = true;
	for (int i = 0;i < mt.n;i++) {
		if ( isConnect(startV, i,mt) && !visited[i]) {
			DFS_DeQui(mt, i, visited);
		}
	}
}
void DFS_DeQui1(MaTranKe mt, int startV, bool visited[50])
{
	visited[startV] = true;
	for (int i = 0;i < mt.n;i++) {
		if (isConnect(startV, i, mt) && !visited[i]) {
			DFS_DeQui1(mt, i, visited);
		}
	}
}
void xuatDanhSachDinh(DanhSachDinh dsDinh) {
	for (int i = 0;i < dsDinh.n;i++) {
		cout << dsDinh.ds[i] << " ";
	}
}
void xuatTapCanh(DanhSachCanh dsCanh) {
	// neu do thi co trọng số
	
		for (int i = 0;i < dsCanh.n;i++) {
			cout << "Dinh dau: " << dsCanh.ds[i].dinhDau << ", Dinh cuoi: " << dsCanh.ds[i].dinhCuoi << ", Trong so: " << dsCanh.ds[i].trongSo;
			cout << endl;
		}

}
int demSoThanhPhanLienThong(MaTranKe mt, bool visited[50])
{
	int count = 0;
	for (int i = 0;i < mt.n;i++) {
		if (!visited[i]) {
			DFS_DeQui1(mt, i, visited);
			count++;
		}
	}
	return count;
}

DanhSachCanh timTapCanh(MaTranKe mt)
{
	DanhSachCanh dsCanh;
	dsCanh.n = 0;
	for (int i = 0;i < mt.n;i++) {
		for (int j = 0;j < mt.n;j++) {
			if (mt.mt[i][j] != 0) {
				Canh canh;
				canh.dinhDau = i;
				canh.dinhCuoi = j;
				canh.trongSo = mt.mt[i][j];
				dsCanh.ds[dsCanh.n++] = canh;
			}
		}
	}
	return dsCanh;
}
DanhSachKe chuyenMaTranKeSangDanhSachKe(MaTranKe mt)
{
	DanhSachKe dsKe;
	dsKe.n = mt.n;
	for (int i = 0;i < mt.n;i++) {
		for (int j = 0;j < mt.n;j++) {
			if (isConnect(i, j, mt)) {
				Node* p = new Node;
				p->dinhKe = j;
				p->trongSo = mt.mt[i][j];
				p->next = dsKe.ds[i];
				dsKe.ds[i] = p;
			}
		}
	}
	return dsKe;
}

void xuatDanhSachKe(DanhSachKe dsKe)
{
	for (int i = 0;i < dsKe.n;i++) {
		Node* p = dsKe.ds[i];
		cout << "[" << i << "]: ";
		while (p != NULL) {
			cout << p->dinhKe << " " << p->trongSo << "\t";
			p = p->next;
		}
		cout << endl;
	}
}
bool docFile(DanhSachKe& dsKe, const char* tenFile) {
	FILE* f = fopen(tenFile, "r");
	if (f == NULL) {
		return false;
	}
	fscanf(f, "%d", &dsKe.n);
	for (int i = 0;i < dsKe.n;i++) {
		int m;
		fscanf(f, "%d", &m);
		dsKe.ds[i] = NULL;
		for (int j = 0;j < m;j++) {
			Node* p = new Node();
			fscanf(f, "%d%d", &p->dinhKe, &p->trongSo);
			p->next = dsKe.ds[i];
			dsKe.ds[i] = p;
		}
	}
	return true;
}

