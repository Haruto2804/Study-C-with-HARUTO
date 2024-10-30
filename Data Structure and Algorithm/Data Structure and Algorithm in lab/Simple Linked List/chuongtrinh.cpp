#include "thuvien.h"
void main() {
	Node* head = nullptr;
	Node* head1 = nullptr;
	Node* head2 = nullptr;
	int n1, n2, n;
	taoDSLK(&head, n);
	//xoa List
	//xoaList(&head);
	//cout << "Mang vua xoa: ";
	//duyetDS(head);
	cout << "Tong cua DSLK: " << tinhTong(head);
	cout << "\nMAX cua DSLK: " << max(head);
	cout << "\nDem so chan cua DSLK: " << demChan(head);
	cout << "\nSo nguyen to co trong DSLK: " << demSNT(head);
	cout << "\nTong le cua DSLK: " << tongLe(head);
	cout << "\nNhap danh sach 1: " << endl;
	taoDSLK(&head1, n1);
	cout << "\nNhap danh sach 2: " << endl;
	taoDSLK(&head2, n2);
	duyetDS(head1);
	duyetDS(head2);
	//cout << "\nDanh sach sau khi sap xep: ";
	//sapXep(&head);
	//duyetDS(head);
	cout << "\n";
	//xoaSoNguyenDauTien(&head);
	//duyetDS(head);
	//chenSoNguyen(&head);
	//sapXep(&head);
	//duyetDS(head);
	cout << "\nMang sau khi tron va da sap xep: ";
	tronHaiDanhSach(&head1, &head2);


	
}