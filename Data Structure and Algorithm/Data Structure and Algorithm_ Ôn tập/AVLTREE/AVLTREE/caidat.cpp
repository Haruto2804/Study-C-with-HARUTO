#include "thuvien.h"
Node* createNode(int x) {
	Node* newNode = new Node;
	newNode->data = x;
	newNode->left = newNode->right = NULL;
	newNode-> height = 1;
	return newNode;
}

AVLTREE insert(AVLTREE T, int x) {
	if (T == NULL) {
		T = createNode(x);
		return T;
	}
	else if (x < T->data) {
		T->left = insert(T->left, x);
	}
	else if (x > T->data) {
		T->right = insert(T->right, x);
	}
	else {
		cout << "\nDa ton tai " << x << " trong cay!";
		return T;
	}
	//cap nhat lai chieu cao cua T sau khi them vao
	T->height = 1 + max(height(T->left), height(T->right));
	int balance = getBalance(T);
	// lech trai trai
	if (balance > 1 && x < T->left->data) {
		return RotateRight(T);
	}
	// lech trai phai
	if (balance > 1 && x > T->left->data) {
		T->left = RotateLeft(T->left);
		return RotateRight(T);
	}
	// lech phai phai
	if (balance <-1 && x >T->right->data) {
		return RotateLeft(T);
	}
	// lech phai trai
	if (balance < -1 && x < T->right->data) {
		T->right = RotateRight(T->right);
		return RotateLeft(T);
	}
	return T;
}
void Init(AVLTREE& T) {
	T = NULL;
}
int height(AVLTREE T) {
	if(T==NULL) {
		return 0;
	}
	return 1 + max(height(T->left), height(T->right));
}
int getBalance(AVLTREE T) {
	if (T == NULL) {
		return 0;
	}
	return height(T->left) - height(T->right);
}
int max(int a, int b) {
	return (a > b) ? a : b;
}
void preOrder(AVLTREE T) {
	if (T != NULL) {
		cout << T->data << "\t";
		preOrder(T->left);
		preOrder(T->right);
	}
}
AVLTREE RotateRight(AVLTREE T) {
	Node* x = T->left;
	Node* T2 = x->right;
	// phep xoay
	x->right = T;
	T->left = T2;
	T->height = max(height(T->left), height(T->right)) + 1;
	x->height = max(height(x->left), height(x->right)) + 1;
	return x;
}
AVLTREE RotateLeft(AVLTREE T) {
	Node* x = T->right;
	Node* T2 = x->left;
	// phep xoay
	x->left = T;
	T->right = T2;
	T->height = max(height(T->left), height(T->right)) + 1;
	x->height = max(height(x->left), height(x->right)) + 1;
	return x;
}