#include <iostream>
using namespace std;
#include <iomanip>
#include "MonHoc.h"
// xây dựng danh sách liên kết lưu trữ thông tin của 1 môn học

struct Node1 { // Nut == Node
	MonHoc data;
	Node1* next;
};
typedef Node1* NodePtr1;
class LinkedList {
private:
	NodePtr1 head;
public:
	LinkedList();
	~LinkedList();


	void themDau( MonHoc data);
	NodePtr1 makeNodeDSLK(MonHoc data);
	void taoDanhSachMonHoc();
	void xuat();
};