#include "thuvien.h"
int main()
{
	SPLAYTREE tree;
	init(tree);
	tree = insertAndSplay(tree, 5);
	tree = insertAndSplay(tree, 2);
	tree = insertAndSplay(tree, 10);
	tree = insertAndSplay(tree, 3);
	tree = insertAndSplay(tree, 7);
	cout << "\nCay sau khi xoay la: ";
	preOrder(tree);
	tree = deleteKey(tree, 1);
	tree = deleteKey(tree, 1);
	tree = deleteKey(tree, 3);
	cout << "\nCay say khi xoa la: ";
	preOrder(tree);
	return 0;
}