#include "thuvien_lab6_doituong_dslkvong.h"
void init(Dlist& list) {
	list.last = list.first = NULL;
}
int isEmpty3(Dlist list) {
	return(list.first == NULL ? 1 : 0);
}
Nodeptr createNode(Student x) {
	Nodeptr newNode = new Node;
	newNode->data = x;
	newNode->next = NULL;
	return newNode;
}
void printStudentInfo(Student x) {
	cout << left;
	cout << setw(20) << x.fullName << setw(15) << x.id << setw(7) << x.score << endl;
}
void addFirst(Dlist& list, Student x) {
	Nodeptr newNode = createNode(x);
	if(list.first==NULL) {
		list.first = newNode;
		list.last = newNode;
		list.last->next = list.first;
		return;
	}
	newNode->next = list.first;
	list.first = newNode;
	list.last->next = list.first;
}
void createList(Dlist& list) {
	Student x;
	do {
		cout << "\nEnter Id (enter 0 to exit): ";
		cin.getline(x.id, 10);
		while (isDuplicate(list, x.id)) {
			cout << "\nId is duplicate";
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
	if (list.first == NULL) {
		return;
	}
	Nodeptr p = list.first;
	cout << left;
	cout << setw(20) << "FullName" << setw(15) << "ID" << setw(7) << "Score" << endl;
	do {
		printStudentInfo(p->data);
		p = p->next;
	} while (p != list.first);
}
bool isDuplicate(Dlist list, char* ma) {
	Nodeptr p = list.first;
	if (list.first == NULL)
	{
		return false;
	}
	do {
		if (p == NULL) {
			break;
		}
		if (strcmp(ma, p->data.id) == 0) {
			return true; 
		}
		p = p->next;
	} while (p != list.first); 
	return false;
}
void printListReserve(Dlist list) {
	if (isEmpty3(list)) {
		return;  // Nếu danh sách rỗng, không làm gì
	}

	// Đảo ngược danh sách liên kết vòng
	Nodeptr current = list.first;
	Nodeptr prev = NULL;
	Nodeptr next = NULL;
	do {
		next = current->next; 
		current->next = prev;
		prev = current; 
		current = next;
	} while (current != list.first);
	list.last = list.first; 
	list.first = prev;     
	list.last->next = list.first;
	Nodeptr p = list.first;
	cout << setw(20) << "FullName" << setw(15) << "ID" << setw(7) << "Score" << endl;
	do {
		printStudentInfo(p->data);
		p = p->next;
	} while (p != list.first);
}

void addLast(Dlist& list, Student x) {
	Nodeptr newNode = createNode(x);
	if (isEmpty3(list)) {
		list.first = list.last = newNode;
	}
	else {
		list.last->next = newNode;
		list.last = newNode;
	}
	list.last->next = list.first;
}
void deleteFirst(Dlist& list) {
	if (list.first == NULL) {
		return;
	}
	if (list.first == list.last) {
		delete list.first;
		list.first = list.last = NULL;
		return;
	}
	Nodeptr p = list.first;
	list.first = list.first->next;
	list.last->next = list.first;
	delete p;
}
void deleteLast(Dlist& list) {
	if (isEmpty3(list)) {
		return;
	}
	if (list.first == list.last) {
		deleteFirst(list);
		return;
	}
	Nodeptr p = list.first;
	Nodeptr q = NULL;
	while (p->next!= list.first) {
		q = p;
		p = p->next;
	}
	delete p;
	q->next = list.first;
	list.last = q;
}