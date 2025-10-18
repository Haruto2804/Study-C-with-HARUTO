#include "thuvien.h"
SkewTree createNode(int x) {
	Node* newNode = new Node;
	newNode->data = x;
	newNode->left = newNode->right = NULL;
	return newNode;
}
SkewTree Merge(SkewTree h1, SkewTree h2)
{
	Node* temp = NULL;
	if (h1 == NULL) {
		return h2;
	}
	else if (h2 == NULL) {
		return h1;
	}

	else
	{
		if (h1->data < h2->data)
		{
		
			temp = h1;
			h1 = h2;
			h2 = temp;
		}
		
	}
	if (h1->right == NULL)
	{
		h1->right = h2;
	}
	else {
		h1->right = Merge(h1->right, h2);
	}
	temp = h1->left;
	h1->left = h1->right;
	h1->right = temp;
	h1->left = Merge(h1->left, h2);
	return h1;
}
void Init(SkewTree& root)
{
	root = NULL;
}
SkewTree Insert(SkewTree root, int x) {
	if (root == NULL) {
		root = createNode(x);
		return root;
	}
	Node* temp = createNode(x);
	root = Merge(root, temp);
	return root;
}
SkewTree DeleteMax(SkewTree root);
void preOrder(SkewTree root)
{
	if (root != NULL) {
		cout << root->data << "\t";
		preOrder(root->left);
		preOrder(root->right);
	}
}
