#include "thuvien.h"
AVLTREE createNode(int x) {
	Node* newNode = new Node;
	newNode->data = x;
	newNode->left = newNode->right = NULL;
	newNode->height = 1;
	return newNode;
}
void init(AVLTREE& root) {
	root = NULL;
}
void rotateRight(AVLTREE& tree)
{
	Node* x = tree->left;
	Node* T2 = x->right;
	x->right = tree;
	tree->left = T2;
	x->height = Max(height(x->left), height(x->right));
	tree->height = Max(height(tree->left), height(tree->right));
	tree = x;
}
void rotateLeft(AVLTREE& tree) {
	Node* x = tree->right;
	Node* T2 = x->left;
	x->left = tree;
	tree->right = T2;
	x->height = Max(height(x->left), height(x->right));
	tree->height = Max(height(tree->left), height(tree->right));
	tree = x;
}
AVLTREE insertKey(AVLTREE tree, int x) {
	if (tree == NULL) {
		return createNode(x);
	}

	else
	{
		if (tree->data == x) {
			cout << "\nDa ton tai " << x << " trong cay nen khong the them!";
		}
		else if (x < tree->data)
		{
			tree->left = insertKey(tree->left,x);
		}
		else if (x > tree->data)
		{
			tree->right = insertKey(tree->right, x);
		}
	}
	tree->height = 1+ Max(height(tree->left), height(tree->right));
	int balance = getBalance(tree);
	// lech trai trai
	if (balance > 1 && x < tree->left->data)
	{
		rotateRight(tree);
		return tree;
	}
	// lech trai phai
	else if (balance > 1 && x > tree->left->data)
	{
		rotateLeft(tree->left);
		rotateRight(tree);
		return tree;
	}
	else if (balance <-1 && x > tree->right->data)
	{
		// lech phai phai
		rotateLeft(tree);
		return tree;
	}
	else if (balance < -1 && x < tree->right->data)
	{
		// lech phai trai
		rotateRight(tree->right);
		rotateLeft(tree);
		return tree;
	}
	return tree;
}
int Max(int a, int b) {
	return (a > b) ? a : b;
}
AVLTREE deleteKey(AVLTREE tree, int x)
{
	if (tree == NULL) {
		return NULL;
	}

	if (x < tree->data) {
		tree->left =deleteKey(tree->left, x);
	}

	if (x > tree->data) {
		tree->right = deleteKey(tree->right, x);
	}
	// TH tim thay nut can xoa
	if (tree->data == x)
	{
		Node* temp = tree;
		if (tree->left == NULL)
		{
			tree = tree->right;
			delete temp;
		}
		else if (tree->right == NULL)
		{
			tree = tree->left;
			delete temp;
		}

		else if (tree->left != NULL && tree->right != NULL)
		{
			Node* theMang = findMin(tree->left);
			tree->data = theMang->data;
			tree->left = deleteKey(tree->left, theMang->data);
		}
	}
	if (tree == NULL) {
		return NULL;
	}

	tree->height = 1 + Max(height(tree->left), height(tree->right));
	int balance = getBalance(tree);

	if (balance > 1 && getBalance(tree->left) >= 0) {
		 rotateRight(tree);
	}
	else if (balance > 1 && getBalance(tree->left) < 0) {
		 rotateLeft(tree->left);
		 rotateRight(tree);
	}
	else if (balance < -1 && getBalance(tree->right) <= 0) {
		 rotateLeft(tree);
	}
	else if (balance < -1 && getBalance(tree->right) > 0) {
		 rotateRight(tree->right);
		 rotateLeft(tree);
	}

	return tree;
	
}
AVLTREE findMin(AVLTREE tree)
{
	if (tree->right == NULL) {
		return tree;
	}
	return findMin(tree->right);
}
int height(AVLTREE tree) {
	if (tree == NULL) {
		return 0;
	}
	return max(height(tree->left), height(tree->right)) + 1;
}
int getBalance(AVLTREE tree) {
	if (tree != NULL) {
		return height(tree->left) - height(tree->right);
	}
	return 0;
}
void preOrder(AVLTREE tree)
{
	if (tree != NULL) {
		cout << tree->data << "\t";
		preOrder(tree->left);
		preOrder(tree->right);
	}
}

