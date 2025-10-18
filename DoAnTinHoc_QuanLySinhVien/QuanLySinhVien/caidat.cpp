#include "thuvien.h"

// CÁC HÀM LÀM VIỆC VỚI CẤU TRÚC DỮ LIỆU CÂY AVL - SINH VIÊN
AVLTree::AVLTree()
{
	this->head = nullptr;
}

//HÀM XÓA HẾT CÂY
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


// HÀM BỌC THÊM SINH VIÊN
void AVLTree::insertSV(SinhVien data)
{
	this->head = insertSV(this->head, data);
}

// HÀM THÊM SINH VIÊN
NodePtr AVLTree::insertSV(NodePtr T, SinhVien data)
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
			T->left = insertSV(T->left, data);
		}
		// TH2: nếu maSVCuaNode đang xét < MaSV của sinh viên muốn thêm vào thì đi qua phải của cây, gọi đệ quy
		else if (maSVCuaNode < maSVData) {
			T->right = insertSV(T->right, data);
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


// HÀM BỌC XÓA SINH VIÊN+

void AVLTree::deleteSV(string maSVCanXoa) {
	this->head = deleteSV(this->head, maSVCanXoa);
}

// HÀM XÓA SINH VIÊN
NodePtr AVLTree::deleteSV(NodePtr T, string maSVCanXoa)
{
	// TÌM SINH VIÊN CẦN XÓA TRONG CÂY ÁP DỤNG TÌM KIẾM THEO QUY TẮC CÂY NHỊ PHÂN
	if (T == nullptr) {
		return T;
	}
	else {
		string maSVCuaNut = T->data.getMaSV();
		// qua trái
		if (maSVCuaNut > maSVCanXoa) {
			T->left = deleteSV(T->left, maSVCanXoa);
		}
		//qua phải
		else if (maSVCuaNut < maSVCanXoa) {
			T->right = deleteSV(T->right, maSVCanXoa);
		}
		// tìm thấy nút cần xóa
		else if (maSVCuaNut == maSVCanXoa) {
			//Xử lí xóa:
			NodePtr temp = T;
			// TH1: cây 1 con:
			// 1. Cây con trái null
			if (T->left == nullptr) {
				T = T->right; //T đi qua phải
				delete temp; // xóa nút 
			}
			else if (T->right == nullptr) {
				T = T->left;
				delete temp;
			}
			else if (T->left != nullptr && T->right != nullptr) {
				// tìm nút thế mạng
				NodePtr theMang = findMAX(T->left);
				T->data = theMang->data;
				T->data = theMang->data;
				delete temp;
			}
			cout << "\n Da xoa thanh cong" << endl;
		}
	}
	if (T == nullptr) {
		return T;
	}
	T->height = 1 + max(height(T->left), height(T->right));
	int balance = getBalance(T);
	// theo lý thuyết: lệch trái khi balance > 1 và lệch phải khi balance < -1, cây có balance nằm trong khoảng [-1,0,1] thì cây cân bằng
	// TH1: Lệch trái trái

	if (balance > 1 && (maSVCanXoa < T->left->data.getMaSV())) {
		return RotateRight(T);
	}
	// lệch phải phải
	else if (balance < -1 && (maSVCanXoa > T->right->data.getMaSV())) {
		return RotateLeft(T);
	}

	// lệch trái phải
	else if (balance > 1 && (maSVCanXoa > T->left->data.getMaSV())) {
		T->left = RotateLeft(T->left);
		return RotateRight(T);
	}
	// lệch phải trái
	else if (balance < -1 && (maSVCanXoa < T->right->data.getMaSV())) {
		T->right = RotateRight(T->right);
		return RotateLeft(T);
	}

	return T;
}

// HÀM tìm nút thế mạng, ở đây em chọn hàm tìm nút lớn nhất cây con bên trái
NodePtr findMAX(NodePtr T) {
	if (T->right == nullptr) {
		return T;
	}
	return findMAX(T->right);
}
// HÀM XÓA SINH VIÊN
//HÀM TẠO 1 NÚT SINH VIÊN
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

// HÀM LẤY CHỈ SỐ CÂN BẰNG CỦA 1 NÚT
int AVLTree::getBalance(NodePtr T)
{
	if (T == nullptr) {
		return 0;
	}
	return height(T->left) - height(T->right);
}

// CÁC HÀM XOAY CÂY AVL ĐỂ CÂY AVL CÂN BẰNG
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











