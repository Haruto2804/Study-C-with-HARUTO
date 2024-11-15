#include "thuvien.h"
void khoiTao(NodePtr& list) {
	list = NULL;
}
int isEmpty(NodePtr list) {
	return list == NULL ? 1 : 0;
}
void giaiPhong(NodePtr& list) {
	NodePtr p = list;
	while (p != NULL) {
		list = list->link;
		delete p;
		p = list;
	}
}
NodePtr makeNodeSV(SinhVien x) {
	NodePtr p;
	p = new Node;
	p->data = x;
	p->link = NULL;
	return p;
}
NodePtr them_Dau(NodePtr& list, SinhVien x) {
	NodePtr p = makeNodeSV(x);
	p->link = list;
	list = p;
	return p;
}
bool kiemTra_TrungMa(NodePtr list, char* ma) {
	NodePtr p = list;
	while (p != NULL) {
		if (strcmp(p->data.masv, ma) == 0) {
			return true;
		}
		p = p->link;
	}
	return false;
}
void nhap_DSSV(NodePtr& list) {
	//khoiTao(list);
	//char x[10];
	SinhVien sv;
	do {
		cout << "\nNhap MaSV (NHAP 0 DE THOAT): ";
		cin.getline(sv.masv, 10);
		while (kiemTra_TrungMa(list, sv.masv)) {
			cout << "\nMA so sv bi trung" << endl;
			cout << "Nhap lai ma so sv: ";
			cin.getline(sv.masv, 10);
		}
		if (strcmp(sv.masv, "0") == 0) {
			break;
		}
		cout << "\nNhap ten SV: ";
		cin.getline(sv.tensv, 10);
		cout << "\nNhap diem SV: ";
		cin >> sv.diem;
		cin.ignore();
		them_Dau(list, sv);
	} while (1);
}
void xuat_DSSV(NodePtr list) {
	cout << left;
	cout << setw(15) << "MASV"
		 << setw(20) << "TEN SV"
		 << setw(5) << "Diem"
		 << setw(7) << "Toan"
		 << setw(7) << "Ly"
		 << setw(7) << "Hoa"
		 << setw(7) << "DTB" << endl;
	while (list != NULL) {
		list->data.dtb = (list->data.toan + list->data.ly + list->data.hoa) / 3; // tinh diem trung binh
		cout << setw(15) << list->data.masv 
		     << setw(20) << list->data.tensv 
			 << setw(5)  << list->data.diem 
			 << setw(7) << list->data.toan
			 << setw(7)  << list->data.ly
			 << setw(7)  << list->data.hoa
			 << setw(7)  << list->data.dtb << endl;
		list = list->link;
	}
}
void themCuoi(NodePtr& list, SinhVien x) {
	NodePtr p = list;
	NodePtr newNode = makeNodeSV(x);
	if (p == NULL) {
		p = newNode;
		list = p;
		return;
	}
	while (p->link != NULL) {
		p = p->link;
	}
	p->link = newNode;
}
// DUNG HAM NAY KHI MUON CHO CAC DIEM LA SO NGAU NHIEN, TEST CHUONG TRINH CHO NHANH
void themCuoi_DSSV(NodePtr& list) {
	SinhVien sv;
	do {
		random_device rd; // tao mot hat giong moi lan lap 
		mt19937_64 rng(rd()); // cho hat giong seed la mot bo so ngau nhien
		uniform_int_distribution<int> uni(0,10); // cho bo so ngau nhien tu 0 den 10 
		cout << "\nNhap MaSV (NHAP 0 DE THOAT): ";
		cin.getline(sv.masv, 10);
		while (kiemTra_TrungMa(list, sv.masv)) {
			cout << "\nMA so sv bi trung" << endl;
			cout << "Nhap lai ma so sv: ";
			cin.getline(sv.masv, 10);
		}
		if (strcmp(sv.masv, "0") == 0) {
			break;
		}
		cout << "\nNhap ten SV: ";
		cin.getline(sv.tensv, 30);
		// nhap diem, diem toan, ly hoa theo phuong phap chon sinh so ngau nhien
		sv.diem = uni(rng);
		sv.toan = uni(rng);
		sv.ly = uni(rng);
		sv.hoa = uni(rng);
		themCuoi(list, sv);
	} while (1);
}
// DUNG HAM NAY KHI MUON NHAP DU LIEU CAC DIEM TU BAN PHIM
//void themCuoi_DSSV(NodePtr& list) {
//	SinhVien sv;
//	do {
//		cout << "\nNhap MaSV (NHAP 0 DE THOAT): ";
//		cin.getline(sv.masv, 10);
//		while (kiemTra_TrungMa(list, sv.masv)) {
//			cout << "\nMA so sv bi trung" << endl;
//			cout << "Nhap lai ma so sv: ";
//			cin.getline(sv.masv, 10);
//		}
//		if (strcmp(sv.masv, "0") == 0) {
//			break;
//		}
//		cout << "\nNhap ten SV: ";
//		cin.getline(sv.tensv, 30);
//		cout << "\nNhap diem SV: ";
//		cin >> sv.diem;
//		cout << "\nNhap diem toan: ";
//		cin >> sv.toan;
//		cout << "\nNhap diem ly: ";
//		cin >> sv.ly;
//		cout << "\nNhap diem hoa: ";
//		cin >> sv.hoa;
//		cin.ignore();
//		themCuoi(list, sv);
//	} while (1);
//}
NodePtr tim_SV_Masv(NodePtr list, char* ma) {
	NodePtr p = list;
	if (isEmpty(list)) {
		return NULL;
	}
	while (p != NULL) {
		if (strcmp(p->data.masv, ma) == 0) {
			return p;
		}
		p = p->link;
	}
	return NULL;
}
void xoa_Dau(NodePtr& list) {
	NodePtr p;
	if (list == NULL) {
		return;
	}
	if (list != NULL) {
		p = list;
		list = list->link;
		delete p;
	}
}
void xoa_Cuoi(NodePtr& list) {
	NodePtr p = list;
	NodePtr q = NULL;
	if (p == NULL) { // danh sach rong
		return;
	}
	if (p->link == NULL) { // danh sach co mot phan tu duy nhat
		delete p;
		return;
	}
	while (p->link != NULL) {
		q = p;
		p = p->link;
	}
	q->link = NULL;
	delete p;
}
void xoa_SV_MaSV(NodePtr& list, char* maCanXoa) {
	if (isEmpty(list)) { // danh sach rong
		return;
	}
	if (strcmp(maCanXoa, list->data.masv) == 0) { // thang dau tien
		xoa_Dau(list);
		return;
	}
	NodePtr p = list;
	NodePtr q;
	while (p != NULL && strcmp(maCanXoa, list->data.masv) != 0) {
		q = p;
		p = p->link;
		if (p != NULL && strcmp(maCanXoa, list->data.masv) == 0) {
			q->link = p->link;
			delete p;
		}
	}
}
void spilit_SinhVien(NodePtr list, NodePtr& list1, NodePtr& list2) {
	if (list == NULL) {
		return;
	}
	SinhVien x;
	while (list != NULL) {
		if (list->data.diem >= 5) {
			x = list->data;
			themCuoi(list1, x);
		}
		else {
			x = list->data;
			themCuoi(list2, x);
		}
		list = list->link;
	}
}
void daoNguocDSLK(NodePtr& list) {
	// dung phuong phap dao nguoc lien ket cua cac node
	Node* current = list;
	Node* next;
	Node* prev = NULL;
	if (list == NULL) {
		return;
	}
	while (current != NULL) {
		next = current->link; // lua dia chi tiep theo current
		current->link = prev; // dao nguoc lien ket cua current vao node truoc
		prev = current; // cap nhat prev
		current = next; // cho current toi node tiep theo
	}
	list = prev; // cap nhat prev la list
}
void xoaTatCaSinhVienCoDiemDuoi5(NodePtr& list) {
	if (list == NULL) {
		return;
	}
	Node* p = list;
	Node* q = list;
	Node* temp;
	while (p != NULL) { // duyet het vong lap
		if (p->data.diem < 5) { // dieu kien xoa
			temp = p;
			if (p == list) { // trong Truong hop la node dau tien
				list = list->link;
				p = list;
				q = list;
				delete temp;
			}
			else {
				q->link = p->link;
				p = p->link;
				delete temp;
			}
		}
		else { // neu sinh vien co diem >= 5 thi di toi tiep theo
			q = p;
			p = p->link;
		}
	}
}
void sapXepTheoDTB(NodePtr& list) {
	if (list == NULL) {
		return;
	}
	float dtb1, dtb2;
	//HAM SAP XEP TINH THEO DIEM TRUNG BINH
	for (NodePtr p = list; p != NULL; p = p->link) {
		for (NodePtr q = p->link; q != NULL; q = q->link) {
			dtb1 = (p->data.toan + p->data.ly + p->data.hoa) / 3;
			dtb2 = (q->data.toan + q->data.ly + q->data.hoa) / 3;
			if (dtb1 > dtb2) { // sap xep tang dan theo diem trung binh
				swap(p->data, q->data);
			}
		}
	}
}