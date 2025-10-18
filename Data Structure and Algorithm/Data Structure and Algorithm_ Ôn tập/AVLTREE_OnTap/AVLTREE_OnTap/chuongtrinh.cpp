#include "thuvien.h"
int main() {
	AVLTREE tree;
	init(tree);
	tree = insertKey(tree, 3);
	tree = insertKey(tree, 2);
	tree = insertKey(tree, 1);
	tree = insertKey(tree, 5);
	tree = insertKey(tree, 6);
	tree = insertKey(tree, 7);
	cout << "\nCay say khi can bang la: ";
	preOrder(tree);
	cout << "\nCay sau khi xoa la: ";
	deleteKey(tree, 3);
	preOrder(tree);
	return 0;

}