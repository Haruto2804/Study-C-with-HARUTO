#include "thuvien.h"
int main() {
	// khoi tao
	SkewTree h1, h2;
	h1 = h2 = NULL;
	h1 = insert(h1, 2);
	h1 = insert(h1, 3);
	h1 = insert(h1, 5);
	h1 = insert(h1, 66);
	h1 = insert(h1, 10);
	cout << "\nCay nghieng 1 xuat theo quy tac LNR la: ";
	preOrder(h1);
	h2 = insert(h2, 9);
	h2 = insert(h2, 77);
	h2 = insert(h2, 88);
	h2 = insert(h2, 35);
	h2 = insert(h2, 24);
	
	cout << "\nCay nghieng 2 xuat theo quy tac LNR la: ";
	preOrder(h2);
	Node* temp = merge(h1, h2);
	cout << "\nCay nghieng xuat theo quy tac LNR la: ";
	preOrder(temp);
	int x;
	temp = deleteT(temp, x);
	cout << "\nCay sau khi xoa " << x << " la: ";
	preOrder(temp);
	return 0;
}