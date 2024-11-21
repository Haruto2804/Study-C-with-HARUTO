#include "thuvien_lab8_dslk.h"
int main() {
	Stack s;
	init_Stack(s);
	input_Stack(s);
	output_Stack(s);
	TYPEINFO t = pop(s);
	cout << "\nDanh sach sau khi xoa stack (POP) la: ";
	output_Stack(s);
	cout << "\nGia tri sau khi xoa stack (POP): " << t << endl;
	t = top(s);
	cout << "\nDanh sach sau khi lay stack (TOP) la: ";
	output_Stack(s);
	cout << "\nDanh sach sau khi lay STACK de xem: " << t;
	return 0;
}