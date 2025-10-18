#include "thuvien.h"
NodePtr createNode(int x) {
	Node* newNode = new Node;
	newNode->data = x;
	newNode->next = NULL;
	return newNode;
}
void insertHashTable(HashTable& ht, TYPEINFO x) {
	int viTriBam = funcHash(x, ht);
	pushBack(ht.list[viTriBam], x);
}
void xuatHashTable(HashTable ht) {
	for (int i = 0;i < ht.n;i++)
	{
		cout << i << "> ";
		NodePtr p = ht.list[i];
		while (p != NULL) {
			cout << p->data << "\t";
			p = p->next;
		}
		cout << endl;
	}
}
void pushBack(NodePtr& list, int x)
{
	if (list == NULL) {
		list = createNode(x);
		return;
	}
	NodePtr p = list;
	Node* newNode = createNode(x);
	while (p->next != NULL) {
		p = p->next;
	}
	p->next = newNode;
}
void khoiTaoHT(HashTable& ht)
{
	cout << "\nNhap so luong phan tu cua HashTable: ";
	cin >> ht.n;
	for (int i = 0;i < ht.n;i++) {
		ht.list[i] = NULL;
	}
}
int funcHash(TYPEINFO x, HashTable ht) {
	return x % ht.n;
}