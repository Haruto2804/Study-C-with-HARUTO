#include "LinkedList.h"
#include "MonHoc.h"
// hàm tạo
LinkedList::LinkedList()
{
	this->head = nullptr;
}


// hàm hủy
LinkedList::~LinkedList()
{
	NodePtr1 current = this->head; // Bắt đầu từ head
	NodePtr1 nextNode = NULL;       // Con trỏ để lưu node kế tiếp

	while (current != NULL) {
		nextNode = current->next; // 1. LƯU LẠI node kế tiếp (để không mất dấu danh sách)
		delete current;           // 2. XÓA node hiện tại
		current = nextNode;       // 3. CHUYỂN sang node kế tiếp đã lưu
	}
}
// tạo node DSLK
NodePtr1 LinkedList::makeNodeDSLK(MonHoc data) {
	NodePtr1 newNode = new Node1();
	newNode->data = data;
	newNode->next = NULL;
	return newNode;
}

// thêm đầu DSLK
void LinkedList::themDau(MonHoc data) {
	NodePtr1 newNode = makeNodeDSLK(data);
	if (this->head == NULL) {
		this->head = newNode;
		return;
	}
	newNode->next = this->head;
	this->head = newNode;
}

// xuất DSLK
void LinkedList::xuat() {
	if (this->head == NULL) {
		return;
	}
	printMonHocHeader();
	NodePtr1 p = this->head;
	while (p != NULL) {
		xuatMonHocTheoBang(p->data);
		p = p->next;
	}
	// 3. In dòng kẻ chân bảng (tùy chọn)
	cout << "  +-" << setfill('-') << setw(9) << "-"
		<< "+-" << setw(36) << "-"
		<< "+-" << setw(5) << "-"
		<< "+-" << setw(8) << "-+" << setfill(' ') << endl;
}