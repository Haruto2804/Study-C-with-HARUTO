#include "thuvien.h"
void main() {
	DList list;
	MonHoc mh;
	int n, choose;
	system("color 7"); // Đen nền, chữ xanh lá
	do {

		cout << setw(60) << left << "\tMENU LAM VIEC VOI DANH SACH LIEN KET KEP" << endl;
		cout << setfill('-') << setw(60) << "" << endl;
		cout << setfill(' ');
		cout << setw(10) << left << "=" << setw(40) << left << "[1]. Khoi tao danh sach lien ket" << setw(10) << right << "=" << endl;
		cout << setw(10) << left << "=" << setw(40) << left << "[2]. Them vao dau danh sach lien ket" << setw(10) << right << "=" << endl;
		cout << setw(10) << left << "=" << setw(40) << left << "[3]. Them vao cuoi sach lien ket" << setw(10) << right << "=" << endl;
		cout << setw(10) << left << "=" << setw(40) << left << "[4]. Xoa dau danh sach lien ket" << setw(10) << right << "=" << endl;
		cout << setw(10) << left << "=" << setw(40) << left << "[5]. Xoa cuoi danh sach lien ket" << setw(10) << right << "=" << endl;
		cout << setw(10) << left << "=" << setw(40) << left << "[6]. Duyet danh sach lien ket" << setw(10) << right << "=" << endl;
		cout << setw(10) << left << "=" << setw(40) << left << "[7]. Tim so tin chi nho nhat" << setw(10) << right << "=" << endl;
		cout << setw(10) << left << "=" << setw(40) << left << "[8]. Tim mon hoc theo ma so mon hoc" << setw(10) << right << "=" << endl;
		cout << setw(10) << left << "=" << setw(40) << left << "[9]. Sap xep theo so tin chi tang dan" << setw(10) << right << "=" << endl;
		cout << setw(10) << left << "=" << setw(40) << left << "[0]. Thoat chuong trinh" << setw(10) << right << "=" << endl;
		cout << setfill('-') << setw(60) << "" << endl;
		cout << setfill(' ');
		cout << "Moi ban chon chuc nang, ban muon chon chuc nang gi: ";
		cin >> choose;
		switch (choose) {
		case 1:
			cout << "\n- Ban da chon chuc nang " << choose << endl;
			Init(list);
			cout << "- Ban da khoi tao danh sach thanh cong" << endl;
			cout << setfill('=') << setw(60) << "" << endl;
			cout << setfill(' ');
			system("pause");
			break;
		case 2:
			cout << "\n- Ban da chon chuc nang " << choose << endl;
			pushFront(list, mh);
			cout << "\nThem thanh cong" << endl;

			system("pause");
			break;
		case 3:
			cout << "\n- Ban da chon chuc nang " << choose << endl;
			pushBack(list, mh);
			cout << "\nThem thanh cong" << endl;
			system("pause");
			break;
		case 4:
			cout << "\n- Ban da chon chuc nang " << choose << endl;
			deleteFirst(list);
			cout << "\nXoa thanh cong" << endl;
			system("pause");
			break;
		case 5:
			cout << "\n- Ban da chon chuc nang " << choose << endl;
			deleteLast(list);
			cout << "\nXoa thanh cong" << endl;
			system("pause");
			break;
		case 6:
			cout << "\n- Ban da chon chuc nang " << choose << endl;
			duyet(list);
			system("pause");
			break;
		case 7:
			cout << "\n- Ban da chon chuc nang " << choose << endl;
			int min;
			tinChiMin(list, min);
			cout << "So tin chi nho nhat co trong danh sach la: " << min << endl;
			system("pause");
			break;
		case 8:
		{


			cout << "\n- Ban da chon chuc nang " << choose << endl;
			string maCanTim;
			Node* p = timMonHocQuaMa(list, maCanTim);
			if (p == NULL) {
				cout << "Khong tim thay mon hoc chua ma " << maCanTim;
			}
			else {
				cout << setw(20) << left << "Ten mon hoc"
					<< setw(15) << left << "Ma mon hoc"
					<< setw(11) << left << "So tin chi" << endl;
				// Duyệt qua danh sách
				cout << setw(20) << left << p->data.ten
					<< setw(15) << left << p->data.ma
					<< setw(11) << left << p->data.tinchi << endl;
			}
			system("pause");
			break;
		}
		case 9:
			cout << "\n- Ban da chon chuc nang " << choose << endl;
			sapXep(list);
			cout << "Danh sach da duoc sap xep theo so tin chi tang dan." << endl;
			system("pause");
			break;
		}
	} while (choose != 0);
	cout << "Cam on ban da su dung chuong trinh";
}
