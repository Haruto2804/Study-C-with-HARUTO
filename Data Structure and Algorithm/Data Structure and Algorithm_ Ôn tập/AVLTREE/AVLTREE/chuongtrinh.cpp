#include "thuvien.h"
int main() {
	AVLTREE T;
	Init(T);
	T = insert(T, 10);
	T = insert(T, 20);
	T = insert(T, 30);
	T = insert(T, 40);
	T = insert(T, 50);
	T = insert(T, 25);
	preOrder(T); //30 20 10 25 40 50
	return 0;
}