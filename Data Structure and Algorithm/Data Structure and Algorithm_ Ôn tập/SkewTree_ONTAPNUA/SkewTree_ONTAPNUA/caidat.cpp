#include "thuvien.h"
SkewTree makeNode(int x) {
	Node* p = new Node;
	p->data = x;
	p->left = p->right = NULL;
	return p;
}
SkewTree insert(SkewTree tree, int x) {
	if (tree == NULL) {
		tree = makeNode(x);
		return tree;
	}
	Node* temp = makeNode(x); // h2 va tree se tuong duong voi h1
	tree = merge(tree, temp);
	return tree;
}
SkewTree deleteT(SkewTree tree, int &x) {
	if (tree == NULL) {
		return NULL;
	}
	x = tree->data;
	SkewTree leftRoot = tree->left;
	SkewTree rightRoot = tree->right;
	delete tree;
	SkewTree cayHopNhat = merge(leftRoot, rightRoot);
	return cayHopNhat;
}
SkewTree merge(SkewTree h1, SkewTree h2) {
	if (h1 == NULL) {
		return h2;
	}
	if (h2 == NULL) {
		return h1;
	}
	if (h1->data > h2->data) {
		swap(h1, h2);
	}
	swap(h1->left, h1->right);
	h1->left = merge(h2, h1->left);
	return h1;
}

void preOrder(Node* root)
{
	if (root != NULL) {
		cout << root->data << "\t";
		preOrder(root->left);
		preOrder(root->right);
	}
}
