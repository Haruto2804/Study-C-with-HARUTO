#include "thuvien.h"
bool Read(AdjacencyMatrix& mt, const char* fileName) {
	FILE* f = fopen(fileName, "r");
	if (f == NULL) {
		return false;
	}
	fscanf(f, "%d", &mt.n);
	for (int i = 0;i < mt.n;i++) {
		for (int j = 0;j < mt.n;j++) {
			fscanf(f, "%d", &mt.ArrayList[i][j]);
		}
	}
	fclose(f);
	return true;
}
bool Write(AdjacencyMatrix& mt, const char* fileName) {
	FILE* f = fopen(fileName, "r");
	if (f == NULL) {
		return false;
	}
	fprintf(f, "%d\n", mt.n);
	for (int i = 0;i < mt.n;i++) {
		for (int j = 0;j < mt.n;j++) {
			fprintf(f, "%d ", mt.ArrayList[i][j]);
		}
		fprintf(f, "\n");
	}
	fclose(f);
	return true;
}
void printAdjacencyMatrix(AdjacencyMatrix mt) {
	cout << "==========ADJACENCY MATRIX==========" << endl;
	for (int i = 0;i < mt.n;i++) {
		for (int j = 0;j < mt.n;j++) {
			cout << mt.ArrayList[i][j] << "\t";
		}
		cout << endl;
	}
	cout << "===================================";
}

ArrayEdge findEdges(AdjacencyMatrix mt)
{
	ArrayEdge arrayEdge;
	arrayEdge.count = 0;
	for (int i = 0;i < mt.n;i++) {
		for (int j = 0;j < mt.n;j++) {
			Edge edge;
			edge.org = i;
			edge.des = j;
			edge.wei = mt.ArrayList[i][j];
			arrayEdge.list[arrayEdge.count++] = edge;
		}
	}
	return arrayEdge;
}

void printEdges(ArrayEdge e)
{
	cout << "\n===========EDGE===========";
	for (int i = 0;i < e.count;i++) {
		cout << "\nOrg: " << char(e.list[i].org+65) << "\t";
		cout << "Des: " << char(e.list[i].des + 65) << "\t";
		cout << "Wei: " << e.list[i].wei << "\t";
	}
	cout << "\n==========================";
}

bool isConnected(AdjacencyMatrix mt, int x, int y)
{
	if (mt.ArrayList[x][y] != 0) {
		return true;
	}
	else {
		return false;
	}
}

ArrayVertex DFS(AdjacencyMatrix mt, VERTEX startV)
{
	ArrayVertex dsDinh;
	dsDinh.count = 0;
	VERTEX visited[50];
	for (int i = 0;i < mt.n;i++) {
		visited[i] = 0;
	}
	stack <VERTEX> s;
	s.push(startV);
	visited[startV] = 1;
	dsDinh.list[dsDinh.count++] = startV;
	// them vao stack
	while (!s.empty()) {
		VERTEX k = s.top();
		s.pop();
		for (int i = 0;i < mt.n;i++) {
			if (isConnected(mt, k, i) && !visited[i]) {
				s.push(i);
				visited[i] = 1;
			}
		}
		return dsDinh;
	}
}

void printVERTEX(ArrayVertex dsDinh)
{
	for (int i = 0;i < dsDinh.count;i++) {
		cout << char(dsDinh.list[i] + 65) << "\t";
	}
}

