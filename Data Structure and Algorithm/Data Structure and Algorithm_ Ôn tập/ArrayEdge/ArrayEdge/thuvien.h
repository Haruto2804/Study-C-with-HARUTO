#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stack>
#include <queue>
using namespace std;
// MAX: MAX phần tử trong ma trận kề
// MaxEdge: MAX cạnh
// MaxVertex: MAX đỉnh
const int MAX = 50;
const int MaxEdge = 50;
const int MaxVertex = 50;
// AdjacencyMatrixx: Ma Trận Kề
struct AdjacencyMatrix {
	int n;
	int ArrayList[MAX][MAX];
};
bool Read(AdjacencyMatrix& mt, const char* fileName);
bool Write(AdjacencyMatrix& mt, const char* fileName);
// printAdjacencyMatrixx: In ma trận kề
void printAdjacencyMatrix(AdjacencyMatrix mt);
// VERTEX: Đỉnh
typedef int VERTEX;
// EDGE: Cạnh
struct Edge {
	VERTEX org; // Đỉnh đầu - origin
	VERTEX des; // Đỉnh cuối  destination
	int wei; // Trọng số
};
struct ArrayEdge {
	// count: số phần tử trong danh sách
	int count;
	Edge list[MaxEdge];
};
struct ArrayVertex {
	int count;
	VERTEX list[MaxVertex];
};
ArrayEdge findEdges(AdjacencyMatrix mt);
void printEdges(ArrayEdge e);
bool isConnected(AdjacencyMatrix mt, int x, int y);
ArrayVertex DFS(AdjacencyMatrix mt, VERTEX startV);
void printDFS(ArrayVertex dsDinh);
void printVERTEX(ArrayVertex dsDinh);
