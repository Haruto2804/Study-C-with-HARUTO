#include "thuvien.h"
Nodeptr makeNode(int x) {
	Nodeptr newNode = new Node;
	newNode->data = x;
	newNode->left = NULL;
	newNode->right = NULL;
	return newNode;
}
void init_Tree(BST& root) {
	root = NULL;
}
void gotoxy(short x, short y) {
	HANDLE hCon = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD pos;
	pos.X = x - 1;
	pos.Y = y - 1;
	SetConsoleCursorPosition(hCon, pos);
}
void insertTree(BST& root, int x) {
	if (root == NULL) {
		root = makeNode(x);
	}
	else {
		if (x == root->data) {
			cout << "\nCo node roi";
			return;
		}
		else {
			if (x < root->data) {
				insertTree(root->left, x);
			}
			else {
				insertTree(root->right, x);
			}
		}
	}
}
void nhapCay(BST& root) {
	int x;
	while (1) {
		cout << "\nNhap DL cho cay (Thoat nhan -99): ";
		cin >> x;
		if (x == -99) {
			break;
		}
		insertTree(root, x);
	}
}
void NLR(BST T, int x, int y, int d) {
	if (T != NULL) {
		gotoxy(x, y);
		cout << "(" << T->data << ")";
		if (T->left != NULL) {
			gotoxy(x + 1, y + 1);
			cout << '|';
			for (int i = x - d / 2 + 2; i <= x + 2; i++) {
				gotoxy(i, y + 2);
				cout << '-';
			}
			NLR(T->left, x - d / 2, y + 3, d / 2);
		}
		if (T->right != NULL) {
			gotoxy(x + 1, y + 1);
			cout << '|';
			for (int i = x + 2; i <= x + d / 2 + 2; i++) {
				gotoxy(i, y + 2);
				cout << '|';
			}
			NLR(T->right, x + d / 2, y + 3, d / 2);
		}

	}
}
void NLR(BST root) {
	if (root != NULL) {
		cout << root->data << " ";
		NLR(root->left);
		NLR(root->right);
	}
}
void LNR(BST root) {
	if (root != NULL) {
		LNR(root->left);
		cout << root->data << " ";
		LNR(root->right);
	}
}
void LRN(BST root) {
	if (root != NULL) {
		LNR(root->left);
		LNR(root->right);
		cout << root->data << " ";
	}
}
int tongSoNut(BST t) {
	if (t == NULL) {
		return 0;
	}
	return 1 + tongSoNut(t->left) + tongSoNut(t->right);
}
int tongNutLa(BST t) {
	if (t == NULL) {
		return 0;
	}
	if (t->left == NULL && t->right == NULL) {
		return 1; // dem len 1
	}
	return tongNutLa(t->left) + tongNutLa(t->right);
}
int chieuCao(BST tree) {
	if (tree == NULL) {
		return 0;
	}
	int heightLeftTree = chieuCao(tree->left);
	int heightRightTree = chieuCao(tree->right);
	return 1 + max(heightLeftTree, heightRightTree);
}
bool tim_Node(BST tree, TYPEINFO a) {
	Nodeptr p = tree;
	if (p) {
		if (p->data == a) {
			return true;
		}
		if (p->data > a) {
			return tim_Node(p->left, a);
		}
		else {
			return tim_Node(p->right, a);
		}
	}
	return false;
}
bool delNode(BST& t, TYPEINFO x) {
	// neu cay khong rong thi moi tim phan tu can xoa
	if (t == NULL) {
		return false;
	}

	if (t->data > x) {
			return delNode(t->left,x);
	}
	else if (t->data < x) {
		return delNode(t->right, x);
	}
	//tim dc nut can xoa
	else {
		//TH1: Cay chi co 1 con, va ko co con nao
		if (t->right == NULL) {
			Nodeptr temp = t;
			t = t->left;
			delete temp;

		}
		else if (t->left == NULL) {
			Nodeptr temp = t;
			t = t->right;
			delete temp;
		}
			//TH co 2 con
		else {
			//CACH 1 tim max ben nhanh trai cua node can xoa
			//tao node theMang tro den node max nhanh trai cua node can xoa
			Nodeptr theMang = findMax(t->left); // tim MAX bang cach de quy sang ben phai cung cua nhanh trai
			t->data = theMang->data;
			delNode(t->left, theMang->data);
		}
	}
		return true;
}
Nodeptr findMax(BST tree) {
	if (tree == NULL) {
		return NULL;
	}
	// neu ko co nhanh phai thi chinh no la MAX
	if (tree->right == NULL) {
		return tree;
	}
	return findMax(tree->right);
}

