#include "thuvien.h"


AVLTree::AVLTree()
{
	this->head = nullptr;
}

void AVLTree::deleteTree(NodePtr T)
{
	// để xóa ta áp dụng duyệt left right node, vì nếu ta dùng node left right, nếu ta xóa nút cha trước thì sẽ mất địa chị đến các nhánh con,
	// do đó ta cần xóa các nhánh con trước rồi xóa cha ở cuối cùng
	if (T != nullptr) {
		deleteTree(T->left); //left
		deleteTree(T->right); // right;
		delete T;
		T = nullptr; 
	}
}



void AVLTree::insert(SinhVien data)
{
	this->head = insert(this->head, data);
}

NodePtr AVLTree::insert(NodePtr T, SinhVien data)
{	// nếu cây rỗng, tạo node mới cho nó rồi trả cho head là nút mới
	if (T == nullptr) {
		return createNode(data);
	}
	else {
		// nếu không rỗng thì kiểm tra 3 TH:
		// trong hàm này ta sẽ dùng tiêu chí là MSSV để sắp xếp cây
		//lấy MSSV từ nút đang xét
		string maSVCuaNode = T->data.getMaSV();
		string maSVData = data.getMaSV();
		// TH1: nếu maSVCuaNode đang xét > MaSV của sinh viên muốn thêm vào thì đi qua trái của cây, gọi đệ quy
		if (maSVCuaNode > maSVData) {
			T->left = insert(T->left, data);
		}
		// TH2: nếu maSVCuaNode đang xét < MaSV của sinh viên muốn thêm vào thì đi qua phải của cây, gọi đệ quy
		else if (maSVCuaNode < maSVData) {
			T->right = insert(T->right, data);
		}
		// TH3: Nếu = là đã có sinh viên đó rồi nên không cần thêm nữa
		else {
			cout << "\nDa ton tai sinh vien co ma so la " << maSVData<<" trong danh sach!";
			return T;
		}
	}
	// sau khi chèn cập nhật lại chiều cao và chỉ số cân bằng của từng nút
	T->height = 1 + max(height(T->left), height(T->right));
	int balance = getBalance(T);
	// theo lý thuyết: lệch trái khi balance > 1 và lệch phải khi balance < -1, cây có balance nằm trong khoảng [-1,0,1] thì cây cân bằng
	// TH1: Lệch trái trái

	if (balance > 1 && (data.getMaSV() < T->left->data.getMaSV())) {
		return RotateRight(T);
	}
	// lệch phải phải
	else if (balance < -1 && (data.getMaSV() > T->right->data.getMaSV())) {
		return RotateLeft(T);
	}

	// lệch trái phải
	else if (balance > 1 && (data.getMaSV() > T->left->data.getMaSV())) {
		T->left = RotateLeft(T->left);
		return RotateRight(T);
	}
	// lệch phải trái
	else if (balance < -1 && (data.getMaSV() < T->right->data.getMaSV())) {
		T->right = RotateRight(T->right);
		return RotateLeft(T);
	}

	return T;
}

NodePtr AVLTree::createNode(SinhVien data) {
	NodePtr newNode = new Node();
	newNode->data = data;
	newNode->left = nullptr;
	newNode->right = nullptr;
	newNode->height = 1; // chiều cao ban đầu = 1
	return newNode;
}
int AVLTree::height(NodePtr T)
{
	if (T == nullptr) {
		return 0;
	}
	return T->height;
}


int AVLTree::getBalance(NodePtr T)
{
	if (T == nullptr) {
		return 0;
	}
	return height(T->left) - height(T->right);
}

// Các hàm xoay

NodePtr AVLTree::RotateLeft(NodePtr T)
{
	NodePtr x = T->right;
	NodePtr T2 = x->left;

	// xoay
	x->left = T;
	T->right = T2;

	// cập nhật lại chiều cao cho nút x mới và T
	T->height = 1 + max(height(T->left), height(T->right));
	x->height = 1 + max(height(x->left), height(x->right));
	return x;
}

NodePtr AVLTree::RotateRight(NodePtr T)
{
	NodePtr x = T->left;
	NodePtr T2 = x->right;

	// xoay
	x->right = T;
	T->left = T2;

	// cập nhật lại chiều cao cho nút x mới và T
	T->height = 1 + max(height(T->left), height(T->right));
	x->height = 1 + max(height(x->left), height(x->right));

	return x;
}


// hàm để xuất cây
void AVLTree::LNR()
{
	LNR(this->head);
}

void AVLTree::RNL()
{
	RNL(this->head);
}

void AVLTree::NLR()
{
	NLR(this->head);
}


// duyệt giảm dần theo MSSV - LEFT - NODE - RIGHT
void AVLTree::RNL(NodePtr T) {
	if (T != nullptr) {
	
		// data muốn xuất
		cout << "\n========================";
		RNL(T->right);
		T->data.inThongTinSinhVien();
		RNL(T->left);
		cout << "\n========================";
	}
}


// duyệt tăng dần theo MSSV - LEFT - NODE - RIGHT
void AVLTree::LNR(NodePtr T) {
	if (T != nullptr) {
		LNR(T->left);

		// Thăm nút hiện tại (N)
		static int stt_counter = 0; // Biến tĩnh chỉ khởi tạo một lần
		stt_counter++;

		T->data.printDataRow(stt_counter);
		printLine(); // Kẻ dòng sau mỗi sinh viên

		LNR(T->right);

		// Quan trọng: Phải reset counter sau khi duyệt xong toàn bộ cây (chỉ ở nút gốc)
		if (T == this->head) {
			stt_counter = 0;
		}
	}
}

void AVLTree::NLR(NodePtr T)
{
	if (T != nullptr) {
		LNR(T->left);

		// Thăm nút hiện tại (N)
		static int stt_counter = 0; // Biến tĩnh chỉ khởi tạo một lần
		stt_counter++;

		T->data.printDataRow(stt_counter);
		printLine(); // Kẻ dòng sau mỗi sinh viên

		LNR(T->right);

		// Quan trọng: Phải reset counter sau khi duyệt xong toàn bộ cây (chỉ ở nút gốc)
		if (T == this->head) {
			stt_counter = 0;
		}
	}
}












