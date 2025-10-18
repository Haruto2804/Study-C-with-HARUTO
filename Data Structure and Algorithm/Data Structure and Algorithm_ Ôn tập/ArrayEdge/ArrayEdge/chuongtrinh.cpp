#include "thuvien.h"
int main() {
	AdjacencyMatrix mt;
	bool result = Read(mt, "dothi.txt");
	if (result) {
		cout << "\nRead File is Succesful!!" << endl;
		printAdjacencyMatrix(mt);
	}
	else {
		cout << "\nRead File is Failure!!!";
	}
	ArrayEdge arrayEdge;
	arrayEdge = findEdges(mt);
	printEdges(arrayEdge);
	return 0;
	ArrayVertex dsDinh;
	// đỉnh: VERTEX
	VERTEX dinh = 0;
	dsDinh = DFS(mt, dinh);
	cout << "\ArrayVERTEX WITH START " << char(dinh + 65) << " by DFS IS: ";
	printVERTEX(dsDinh);
}
