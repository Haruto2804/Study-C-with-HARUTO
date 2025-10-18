#include "thuvien.h"
void init(SPLAYTREE& tree)
{
	tree = NULL;
}
SPLAYTREE createNode(int x) {
	Node* newNode = new Node;
	newNode->data = x;
	newNode->left = newNode->right = NULL;
	return newNode;
}
void rotateLeft(SPLAYTREE& tree) {
	Node* x = tree->right;
	Node* T2 = x->left;
	x->left = tree;
	tree->right = T2;
	tree = x;
}
void rotateRight(SPLAYTREE& tree) {
	Node* x = tree->left;
	Node* T2 = x->right;
	x->right = tree;
	tree->left = T2;
	tree = x;
}
SPLAYTREE find(SPLAYTREE& tree, int x) {
	if (tree != NULL) {
		if (tree->data == x) {
			return tree;
		}
		else if (x < tree->data) {
			return find(tree->left, x);
		}
		else if (x > tree->data) {
			return find(tree->right, x);
		}
	}
	return NULL;
}
SPLAYTREE insert(SPLAYTREE tree, int x) {
	if (tree == NULL) {
		tree = createNode(x);
		return tree;
	}
	else {
		if (x < tree->data) {
			tree->left = insert(tree->left, x);
		}
		else if (x > tree->data) {
			tree->right = insert(tree->right, x);
		}
		else {
			cout << "\nDa ton tai phan tu " << x << " trong cay, khong the them!";
		}
	}
	return tree;
}
SPLAYTREE insertAndSplay(SPLAYTREE tree, int x) {
	tree = insert(tree, x);
	Node* nutCanXoay = find(tree, x);
	splayToRoot(tree, nutCanXoay);
	return nutCanXoay;
}
SPLAYTREE splay(SPLAYTREE &tree, SPLAYTREE nutCanXoay) {
	if (tree == NULL) {
		return NULL;
	}

	else
	{
		if (tree->left == nutCanXoay)
		{
			//zig
			rotateRight(tree);
			return tree;
		}

		else if (tree->right == nutCanXoay)
		{
			rotateLeft(tree);
			return tree;
		}
		else
		{
			if (nutCanXoay->data < tree->data)
			{
			       Node* p = tree->left;
				if (p == NULL)
				{
					return NULL;
				}
				else if (p->left == nutCanXoay)
				{
					rotateRight(tree);
					rotateRight(tree);
					return tree;
				}
				else if(p->right == nutCanXoay)
				{
					rotateLeft(tree->left);
					rotateRight(tree);
					return tree;
				}
				else {
					return splay(tree->left, nutCanXoay);
				}
			}

			else if (nutCanXoay->data > tree->data)
			{
				Node* p = tree->right;
				if (p == NULL) {
					return NULL;
				}
				if (p->right == nutCanXoay)
				{
					rotateLeft(tree);
					rotateLeft(tree);
					return tree;
				}
				else if (p->left == nutCanXoay)
				{
					rotateRight(tree->right);
					rotateLeft(tree);
					return tree;
				}
				else {
					return splay(tree->right, nutCanXoay);
				}
			}
			else {
				return NULL;
			}
		}
	}
}
void splayToRoot(SPLAYTREE& tree, SPLAYTREE nutCanXoay) {
	if (nutCanXoay == NULL || tree==NULL) {
		return;
	}

	while (nutCanXoay != NULL)
	{
		nutCanXoay = splay(tree, nutCanXoay);
	}
}
SPLAYTREE findMax(SPLAYTREE tree)
{
	if (tree->right == NULL) {
		return tree;
	}
	return findMax(tree->right);
}
void preOrder(SPLAYTREE tree)
{
	if (tree != NULL) {
		cout << tree->data << "\t";
		preOrder(tree->left);
		preOrder(tree->right);
	}
}
SPLAYTREE deleteKey(SPLAYTREE tree, int x)
{
 	Node* nutCanXoa = find(tree, x);
	if (nutCanXoa != NULL) {
		splayToRoot(tree, nutCanXoa);
		Node* leftParent = nutCanXoa->left;
		Node* rightParent = nutCanXoa->right;
		Node* xoayMax = NULL;
		if (rightParent == NULL) {
			delete nutCanXoa;
			nutCanXoa = NULL;
			xoayMax = findMax(leftParent);
			splayToRoot(leftParent, xoayMax);
		}
		else if (leftParent == NULL) {
			delete nutCanXoa;
			nutCanXoa = NULL;
			xoayMax = findMax(rightParent);
			splayToRoot(rightParent, xoayMax);
		}
		else if (leftParent != NULL && rightParent != NULL) {
			delete nutCanXoa;
			xoayMax = findMax(leftParent);
			splayToRoot(leftParent, xoayMax);
			xoayMax->right = rightParent;
		}
		return xoayMax;
	}
	return tree;
}
