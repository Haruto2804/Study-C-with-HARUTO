#include "thuvien.h"
Node* makeNode(int x) {
	Node* newNode = new Node();
	newNode->data = x;
	newNode->next = NULL;
	return newNode;
}
void pushBack(Node** head, int x) {
	Node* temp = *head;
	Node* newNode = makeNode(x);
	if (*head == NULL) {
		*head = newNode;
		return;
	}
	while (temp->next != NULL) {
		temp = temp->next;
	}
	temp->next = newNode;
}
void duyetDS(Node* head) {
	while (head != NULL) {
		cout << head->data << " ";
		head = head->next;
	}
	cout << endl;
}
void xoaList(Node** head) {
	if (*head == NULL) {
		cout << "Danh sach rong, khong xoa duoc nua!";
		return;
	}
	Node* temp = *head;
	Node* nextNode;
	while (temp->next != NULL) {
		nextNode = temp->next;
		delete temp;
		temp = nextNode;
	}
	*head = NULL;

}
int tinhTong(Node* head) {
	if (head == NULL) {
		cout << "Danh sach rong!";
		return 0;
	}
	int tong = 0;
	while (head != NULL) {
		tong += head->data;
		head = head->next;
	}
	return tong;
}
int max(Node* head) {
	if (head == NULL) {
		cout << "Danh sach rong!";
		return 0;
	}
	int max = head->data; // gan bien max la thang data node dau tien
	while (head != NULL) {
		if (head->data > max) {
			max = head->data;
		}
		head = head->next;
	}
	return max;

}
int demChan(Node* head) {
	if (head == NULL) {
		cout << "Danh sach rong!";
		return 0;
	}
	int dem = 0;
	while (head != NULL) {
		if (head->data % 2 == 0) {
			dem++;
		}
		head = head->next;
	}
	return dem;
}
bool checkSNT(int n) {
	if (n < 2) {
		return false;
	}
	for (int i = 2; i * i <= n; i++) {
		if (n % i == 0) {
			return false;
		}
	}
	return true;
}
int demSNT(Node* head) {
	if (head == NULL) {
		cout << "Danh sach rong!";
		return 0;
	}
	int dem = 0;
	while (head != NULL) {
		if (checkSNT(head->data)) {
			dem++;
		}
		head = head->next;
	}
	return dem;
}
int tongLe(Node* head) {
	if (head == NULL) {
		cout << "Danh sach rong!";
		return 0;
	}
	int tong = 0;
	while (head != NULL) {
		if (head->data % 2 != 0) {
			tong += head->data;
		}
		head = head->next;
	}
	return tong;
}
void taoDSLK(Node **head,int &n) { // truyen 1 con tro vao ham, **head nghia la truy cap vao vung nho ma con tro head dc truyen vao dang tro toi, head tro toi vung nho(Node dau tien)
	int x;
	do {
		cout << "Nhap so luong node can them vao DSLK: ";
		cin >> n;
	} while (n <= 0);
	for (int i = 0; i < n; i++) {
		cout << "Nhap data cua node " << i + 1 << ": ";
		cin >> x;
		pushBack(head, x); // con tro toi con tro, nhu dieu (1),head la dia chi cua Node dau tien
	}
}
void noiHaiDSLK(Node** head1, Node** head2) {
	if (*head1 == NULL && *head2==NULL) {
		cout << "Hai day deu rong!";
		return;
	}
	else if (*head1==NULL) {
		*head1 = *head2;
		duyetDS(*head2);
		return;
	}
	else if(*head2==NULL) {
		*head2 = *head1;
		duyetDS(*head2);
		return;
	}
	Node* temp = *head1; 
	while (temp->next != NULL) {
		temp = temp->next;
	}
	temp->next = *head2;
}
void sapXep(Node** head) { //tang dan
	if (*head == NULL) {
		cout << "Danh sach rong!";
		return;
	}
	for (Node* p = *head; p != NULL; p = p->next) {
		for (Node* q = p->next; q != NULL; q = q->next) {
			if (p->data > q->data) {
				swap(p->data, q->data);
			}
		}
	}
}
void xoaSoNguyenDauTien(Node** head) {
	if (*head == NULL) {
		cout << "Danh sach rong, sao ma xoa?";
		return;
	}
	int x;
	cout << "Nhap so nguyen can xoa: ";
	cin >> x;
	Node* p = *head;
	Node* q = *head;
	Node* nextNode;
	if (p->data == x) { // delete First
		nextNode = p->next;
		delete p;
		*head = nextNode;
		return;
	}
	while (p != NULL && p->data != x) {
		q = p;
		p = p->next;
	}
	if (p != NULL) { // kiem tra nut da tim thay x co nam trong danh sach hay ko
		q->next = p->next;
		delete p;
	}
}
void chenSoNguyen(Node** head) {
	if (*head == NULL) {
		cout << "Danh sach rong!";
		return;
	}
	int x;
	cout << "Nhap so nguyen can chen cho DSLK: ";
	cin >> x;
	Node* newNode = makeNode(x);
	newNode->next = *head; 
	*head = newNode;
	sapXep(head);
}
bool isEmpty(Node* head) {
	if (head == NULL) {
		cout << "Danh sach rong!";
		return false;
	}
	return true;
}
void tachHaiDanhSachChanLe(Node**head, Node** head1, Node** head2) {
	if (!isEmpty(*head)) {
		return;
	}
	Node* temp = *head;
	while (temp != NULL) {
		if (temp->data % 2 == 0) {
			pushBack(head1, temp->data);
		}
		else {
			pushBack(head2, temp->data);
		}
		temp = temp->next;
		
	}


}
void tronHaiDanhSach(Node** head1, Node** head2) {
	if (*head1 == NULL && *head2 == NULL) {
		cout << "Hai day deu rong!";
		return;
	}
	else if (*head1 == NULL) {
		*head1 = *head2;
		duyetDS(*head2);
		return;
	}
	else if (*head2 == NULL) {
		*head2 = *head1;
		duyetDS(*head2);
		return;
	}
	Node* temp = *head1;
	while (temp->next != NULL) {
		temp = temp->next;
	}
	temp->next = *head2;
	sapXep(head1);
	duyetDS(*head1);
}
