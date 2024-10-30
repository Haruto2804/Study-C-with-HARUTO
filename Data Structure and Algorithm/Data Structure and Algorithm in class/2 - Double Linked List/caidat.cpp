#include "thuvien.h"
void Init(DList& list) {
	list.first = list.last = NULL;
}
Node* makeNode(MonHoc mh) {
	Node* newNode = new Node();
	cout << "Nhap ten mon hoc: ";
	cin.ignore();
	getline(cin, mh.ten);
	newNode->data.ten = mh.ten;
	cout << "Nhap ma mon " << mh.ten << ": ";
	cin >> mh.ma;
	newNode->data.ma = mh.ma;
	cout << "Nhap so tin chi mon " << mh.ten << ": ";
	cin >> mh.tinchi;
	newNode->data.tinchi = mh.tinchi;
	newNode->next = NULL;
	newNode->prev = NULL;
	return newNode;
}
void pushBack(DList& list, MonHoc mh) {
	Node* newNode = makeNode(mh);
	if (isEmpty(list)) {
		list.first = list.last = newNode;
		return;
	}
	list.last->next = newNode;
	newNode->prev = list.last;
	list.last = newNode;
}
void pushFront(DList& list, MonHoc mh) {
	Node* newNode = makeNode(mh);
	if (isEmpty(list)) {
		list.first = list.last = newNode;
		return;
	}
	newNode->next = list.first;
	list.first->prev = newNode;
	list.first = newNode;
}
bool isEmpty(DList list) {
	if (list.first == NULL) {
		return true;
	}
	return false;
}
void duyet(DList list) {
	if (isEmpty(list)) {
		return;
	}
	int i = 1;
	cout << setw(7) << left << "STT"
	    << setw(20) << left << "Ten mon hoc"
		<< setw(15) << left << "Ma mon hoc"
		<< setw(11) << left << "So tin chi" << endl;

	// Duyệt qua danh sách

	while (list.first != NULL) {
		cout << setw(7) << left << i
			 << setw(20) << left << list.first->data.ten
			 << setw(15) << left << list.first->data.ma
			 << setw(11) << left << list.first->data.tinchi << endl;
		i++;
		list.first = list.first->next;
	}
	cout << endl;
}
void deleteFirst(DList& list) {
	if (isEmpty(list)) {
		cout << "\nDanh sach rong!";
		return;
	}
	if (list.first == list.last) { // danh sach co 1 node
		delete list.first;
		list.first = NULL;
		list.last = NULL;
		return;
	}
	//TH co nhieu node
	Node* p = list.first;
	list.first = list.first->next;
	delete p;
	list.first->prev = NULL;
}
void deleteLast(DList& list) {
	if (isEmpty(list)) {
		cout << "\nDanh sach rong!";
		return;
	}
	if (list.first == list.last) { // danh sach co 1 node
		deleteFirst(list);
		return;
	}
	Node* p = list.last->prev;
	delete list.last;
	list.last = p;
	p->next = NULL;
}
void tinChiMin(DList list, int &min) {
	if (isEmpty(list)) {
		cout << "\nDanh sach rong!";
		return;
	}
	min = list.first->data.tinchi;
	list.first = list.first->next;
	while (list.first != NULL) {
		if (list.first->data.tinchi < min) {
			min = list.first->data.tinchi;
		}
		list.first = list.first->next;
	}
}
Node* timMonHocQuaMa(DList list, string& maCanTim) {
	cout << "Nhap ma can tim: ";
	cin >> maCanTim;
	Node* p = list.first;
	while (p != NULL) {
		if (maCanTim == p->data.ma) {
			return p;
		}
		p = p->next;
	}
	return NULL;
}
void sapXep(DList& list) {
	if (isEmpty(list)) {
		cout << "\nDanh sach rong!";
		return;
	}
	for (Node* p = list.first; p != NULL; p = p->next) {
		for (Node* q = p->next; q != NULL; q = q->next) {
			if (p->data.tinchi > q->data.tinchi) {
				swap(p->data, q->data);
			}
		}
	}
}
