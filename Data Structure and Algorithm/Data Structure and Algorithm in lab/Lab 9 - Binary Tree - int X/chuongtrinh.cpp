#include "thuvien.h"
int main() {
	BST tree;
	init_Tree(tree);
	nhapCay(tree);
	system("cls"); 
	NLR(tree, 40, 1, 40);
	cout << "\nDuyet cay NLR: ";
	NLR(tree);
	cout << "\nDuyet cay LNR: ";
	LNR(tree);
	cout << "\nDuyet cay LRN: ";
	LRN(tree);
	cout << "\nTong so nut co trong node la: " << tongSoNut(tree);
	cout << "\nTong so nut la co trong node la: " << tongNutLa(tree);
	cout << "\nChieu cao cua cay nhi phan la: " << chieuCao(tree);
	cout << "\nNhap node can tim: ";
	int x;
	cin >> x;
	if (tim_Node(tree, x)) {
		cout << "\nCo tim thay " << x;
	}
	else {
		cout << "\nKhong tim thay " << x;
	}
	int c;
	cout << "\nNhap gia tri can xoa: ";
	cin >> c;
	if (delNode(tree, c)) {
		cout << "Xoa thanh cong " << c;
	}
	else {
		cout << "Xoa khong thanh cong " << c;
	}
	cout << "\nCay sau khi xoa " << c << " la: " << endl;
	NLR(tree);
	
	return 0;
}