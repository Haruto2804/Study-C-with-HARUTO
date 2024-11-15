#include "thuvien_lab6_doituong.h"
int main() {
	Dlist list;
	Student x{};
	init(list);
	createList(list);
	printList(list);
	cout << "\nList Reserve: " << endl;
	printListReserve(list);
	cout << "\nAdd first!" << endl;
	createList(list);
	cout << "\nThe list after add first: " << endl;
	printList(list);
	cout << "\nAdd last!" << endl;
	createList_Last(list);
	cout << "\nThe list after add last: " << endl;
	printList(list);
	deleteFirst(list);
	cout << "\nThe list after delete first: " << endl;
	printList(list);
	deleteLast(list);
	cout << "\nThe list after delete last: " << endl;
	printList(list);
	return 0;
}