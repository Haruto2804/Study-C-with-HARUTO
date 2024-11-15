#include "thuvien_lab6_doituong.h"
void init(Dlist& list) {
	list.first = list.last = NULL;
}
int isEmpty1(Dlist list) {
	return(list.first == NULL ? 1 : 0);
}
Nodeptr createNode(Student x) {
	Nodeptr newNode = new Node;
	newNode->data = x;
	newNode->prev = NULL;
	newNode->next = NULL;
	return newNode;
}
void printStudentInfo(Student x) {
	cout << left;
	cout << setw(20) << x.fullName << setw(15) << x.id << setw(7) << x.score << endl;
}
void addFirst(Dlist& list, Student x) {
	Nodeptr newNode = createNode(x);
	if (isEmpty1(list)) {
		list.first = list.last = newNode;
	}
	else {
		newNode->next = list.first;
		list.first->prev = newNode;
		list.first = newNode;
	}
}
void createList(Dlist& list) {
	Student x;
	do {
		cout << "\nEnter Id (enter 0 to exit): ";
		cin.getline(x.id, 10);
		while (isDuplicate(list, x.id)) {
			cout << "\n Id is duplicate";
			cout << "\nEnter again, please: ";
			cin.getline(x.id, 10);
		}
		if (strcmp(x.id, "0") == 0) {
			break;
		}
		cout << "\nEnter full name: ";
		cin.getline(x.fullName, 30);
		cout << "\nEnter score: ";
		cin >> x.score;
		cin.ignore();
		addFirst(list, x);
	} while (1);
}
void createList_Last(Dlist& list) {
	Student x;
	do {
		cout << "\nEnter Id (enter 0 to exit): ";
		cin.getline(x.id, 10);
		while (isDuplicate(list, x.id)) {
			cout << "\n Id is duplicate";
			cout << "\nEnter again, please: ";
			cin.getline(x.id, 10);
		}
		if (strcmp(x.id, "0") == 0) {
			break;
		}
		cout << "\nEnter full name: ";
		cin.getline(x.fullName, 30);
		cout << "\nEnter score: ";
		cin >> x.score;
		cin.ignore();
		addLast(list, x);
	} while (1);
}

void printList(Dlist list) {
	Nodeptr p = list.first;
	cout << left;
	cout << setw(20) << "FullName" << setw(15) << "ID" << setw(7) << "Score" << endl;
	while (p != NULL) {
		printStudentInfo(p->data);
		p = p->next;
	}
}
bool isDuplicate(Dlist list, char *ma) {
	while (list.first != NULL) {
		if (strcmp(ma, list.first->data.id) == 0) {
			return true;
		}
		list.first = list.first->next;
	}
	return false;
}
void printListReserve(Dlist list) {
	if (isEmpty1(list)) {
		return;
	}
	Nodeptr p = list.last;
	cout << setw(20) << "FullName" << setw(15) << "ID" << setw(7) << "Score" << endl;
	while (p != NULL) {
		printStudentInfo(p->data);
		p = p->prev;
	}
}
void addLast(Dlist& list, Student x) {
	Nodeptr newNode = createNode(x);
	if (isEmpty1(list)) {
		list.first = list.last = newNode;
	}
	else {
		list.last->next = newNode;
		newNode->prev = list.last;
		list.last = newNode;
	}
}
void deleteFirst(Dlist& list) {
	if (isEmpty1(list)) {
		return;
	}
	Nodeptr p = list.first;
	list.first = list.first->next;
	list.first->prev = NULL;
	delete p;
}
void deleteLast(Dlist& list) {
	if (isEmpty1(list)) {
		return;
	}
	Nodeptr q = list.last->prev;
	delete list.last;
	list.last = q;
	list.last->next = NULL;
}