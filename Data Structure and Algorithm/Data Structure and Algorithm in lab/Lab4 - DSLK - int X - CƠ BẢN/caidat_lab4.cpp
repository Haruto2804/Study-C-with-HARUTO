#include "thuvien_lab4.h"
void khoiTao(NodePtr& list) {
	list = NULL;
}
int isEmpty(NodePtr list) {
	return(list == NULL ? 1 : 0);
}
NodePtr tao_Node(TYPEINFO x) {
	NodePtr p;
	p = new Node;
	p->data = x;
	p->link = NULL;
	return p;
}
NodePtr them_Dau(NodePtr& list, TYPEINFO x) {
	NodePtr p;
	p = tao_Node(x);
	p->link = list;
	list = p;
	return p;
}
void nhap_DanhSach_Dau(NodePtr& list) {
	khoiTao(list);
	int x;
	do {
		cout << "\nNhap vao x= (thoat -99): ";
		cin >> x;
		if (x == -99) {
			break;
		}
		them_Dau(list,x);
	} while (1);
}
void xuat_DanhSach(NodePtr list) {
	if (list == NULL) {
		return;
	}
	NodePtr p = list;
	while (p != NULL) {
		cout << p->data << " ";
		p = p->link;
	}
}
void giaiPhong(NodePtr& list) {
	NodePtr p = list;
	while (p != NULL) {
		list = list->link;
		delete p;
		p = list;
	}
}
void them_Cuoi(NodePtr& list, TYPEINFO x) {
	NodePtr temp = list;
	NodePtr newNode = tao_Node(x);
	if (isEmpty(list)) {
		list = newNode;
		return;
	}
	while (temp->link != NULL) {
		temp = temp->link; // duyet toi thang cuoi cung
	}
	temp->link = newNode;
}
void nhap_DanhSach_Cuoi(NodePtr& list) {
	khoiTao(list);
	int x;
	do {
		cout << "\nNhap vao x= (thoat -99): ";
		cin >> x;
		if (x == -99) {
			break;
		}
		them_Cuoi(list, x);
	} while (1);
}
NodePtr tim_Node_x(NodePtr list, TYPEINFO x) {
	NodePtr p = list;
	while (p != NULL) {
		if (p->data == x) {
			return p;
		}
		p = p->link;
	}
	return p;
}
NodePtr chenSau_Q(NodePtr q, TYPEINFO x) {
	NodePtr p = tao_Node(x);
	p->link = q->link;
	q->link = p;
	return q;
}
void xoa_Dau(NodePtr& list) {
	NodePtr p;
	if (list != NULL) {
		p = list;
		list = p->link;
		delete p;
	}
}
void xoa_Cuoi(NodePtr& list) {
	NodePtr q;
	NodePtr p;
	p = list;
	q = list;
	if (p->link == NULL) { // thang dau tien
		delete p;
		list = NULL;
		return;
	}
	else {
		while (p->link != NULL) {
			q = p;
			p = p->link;
		}
		if (p != NULL) {
			delete p;
			q->link = NULL;
		}
	}
}
	
bool del_X(NodePtr& list, TYPEINFO x) {
	if (isEmpty(list)) {
		return false;
	}
	NodePtr p, q;
	p = list;
	q = list;
	if (p->link==NULL && p->data == x) { // neu danh sach la thang dau tien
		xoa_Dau(list);
		return true; // da xoa x
	}
	while (p != NULL) {
		if (p->data == x) {
			q->link = p->link;
			delete p;
			return true; // da xoa x
		}
		q = p;
		p = p->link;
	}
	return false;
}
void daoNguocDSLK(NodePtr &list) {
	NodePtr prev = NULL;
	NodePtr current = list;
	NodePtr next = NULL;
	while (current != NULL) {
		next = current->link;
		current->link = prev;
		prev = current;
		current = next;
	}
	list = prev;
}
void tachDS(NodePtr list, NodePtr& listChan, NodePtr& listLe) {
	NodePtr p = list;
	khoiTao(listChan);
	khoiTao(listLe);
	while (p != NULL) {
		if (p->data % 2 == 0) {
			them_Cuoi(listChan, p->data);
		}
		else {
			them_Cuoi(listLe, p->data);
		}
		p = p->link;
	}
}
void del_All_X(NodePtr& list, TYPEINFO x) {
	NodePtr p = list;
	NodePtr q = NULL;
	NodePtr temp;
	if (isEmpty(list)) {
		return;
	}
	while(p != NULL && p->data == x) {
		temp = p;
		p = p->link;
	}
	p = list;
	while (p != NULL) {
		if (p->data == x) {
			if (q != NULL) { // neu node truoc node p chua gia tri x ko NULL thi 
				q->link = p->link; //cap nhat lien ket cua q voi thang lien sau p;
			}
			temp = p;
			p = p->link;
			delete temp;
		}
		else {
			q = p; // Cập nhật q chỉ khi p không bị xóa
			p = p->link; // Tiến đến nút tiếp theo
		}
	}
}

	
	

