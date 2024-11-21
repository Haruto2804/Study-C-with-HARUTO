#include "thuvien_lab7.h"
int main() {
	Queue q;
	khoiTao(q);
	setValue(q);
	print(q);
	int t = deQueue(q);
	cout << endl;
	print(q);
	cout << "\nPhan tu sau khi lay: " << t;
	return 0;
}