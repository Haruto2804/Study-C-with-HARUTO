#include "thuvien_lab8.h"
int main() {
	Stack s;
	init_Stack(s);
	input_Stack(s);
	output_Stack(s);
	get_Stack(s);
	cout << "\nDanh sach sau khi xoa stack (POP): ";
	output_Stack(s);
	int t = top(s);
	cout << "\nDanh sach sau khi lay stack (TOP): ";
	output_Stack(s);
	cout << "\nVa gia tri sau khi lay: " << t;
	return 0;
}