#include "thuvien.h"

// Tạo bộ sinh số ngẫu nhiên cho toàn bộ chương trình
random_device rd; // Nguồn seed
mt19937 gen(rd()); // Engine được khởi tạo MỘT LẦN

// gán giá trị ban đầu cho biến counter là 0, nghĩa là chưa có sinh viên nào
int SinhVien::counter = 0;




// Các hàm format ouput cho Danh sách sinh viên
// Đặt độ rộng cố định cho từng cột
#define COL_WIDTH_STT 5
#define COL_WIDTH_MSSV 15
#define COL_WIDTH_NAME 30
#define COL_WIDTH_DATE 15
#define COL_WIDTH_DIEM 10
#define COL_TOTAL_WIDTH (COL_WIDTH_STT + COL_WIDTH_MSSV + COL_WIDTH_NAME + COL_WIDTH_DATE + COL_WIDTH_DIEM + 6) // Tổng độ rộng + khoảng cách

void printLine() {
	cout << "\n+" << setfill('-') << setw(COL_TOTAL_WIDTH) << "+";
	cout << setfill(' '); // Trả lại fill mặc định
}

void printHeader() {
	printLine();
	cout << "\n|";
	cout << left << setw(COL_WIDTH_STT) << " STT";
	cout << "|";
	cout << left << setw(COL_WIDTH_MSSV) << " MA SINH VIEN";
	cout << "|";
	cout << left << setw(COL_WIDTH_NAME) << " HO TEN";
	cout << "|";
	cout << left << setw(COL_WIDTH_DATE) << " NGAY SINH";
	cout << "|";
	cout << left << setw(COL_WIDTH_DIEM) << " DIEM TB";
	cout << "|";
	printLine();
}

void SinhVien::printDataRow(int stt) {
	// In dòng dữ liệu của sinh viên
	cout << "\n|";
	cout << left << setw(COL_WIDTH_STT - 1) << stt << " "; // Căn phải STT
	cout << "|";
	cout << left << setw(COL_WIDTH_MSSV - 1) << this->maSV << " ";
	cout << "|";
	cout << left << setw(COL_WIDTH_NAME - 1) << this->hoTenSV << " ";
	cout << "|";
	cout << left << setw(COL_WIDTH_DATE - 1) << this->ngaySinh << " ";
	cout << "|";
	cout << fixed << setprecision(2); // Định dạng điểm 2 số thập phân
	cout << right << setw(COL_WIDTH_DIEM - 1) << this->diemTB << " "; // Căn phải điểm TB
	cout << "|";
}
















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









//định nghĩa hàm cho lớp Sinh viên
void SinhVien::nhapThongTinSinhVien() {
	string hoTenSV, maSV, ngaySinh;
	double diemTB;

	cout << "\nNhap ten sinh vien: ";
	getline(cin, this->hoTenSV);
	cout << "\nNhap ma sinh vien: ";
	cin >> this->maSV;
	cout << "\nNhap ngay sinh cua sinh vien: ";
	cin >> this->ngaySinh;
	cout << "\nNhap diem trung binh cua sinh vien: ";
	cin >> this->diemTB;
	cin.ignore();
}
void SinhVien::nhapThongTinSinhVien(string hoTenSV, string maSV, string ngaySinh, double diemTB)
{
	this->hoTenSV = hoTenSV;
	this->maSV = maSV;
	this->ngaySinh = ngaySinh;
	this->diemTB = diemTB; 
}
void SinhVien::inThongTinSinhVien() {
	cout << "\nHo ten sinh vien: " << this->hoTenSV;
	cout << "\nMa sinh vien: " << this->maSV;
	cout << "\nNgay sinh: " << this->ngaySinh;
	cout << "\nDiem trung binh: " << this->diemTB;
}
void SinhVien::taoMaSV(){
	counter++;
	// kết quả ta muốn là có mã sinh viên có dạng DH52300000, tiền tố là DH523, 5 số cuối còn lại là số thứ tự tăng dần (0-99999)
	//B1: ta lưu tiền tố DH523
	string tienTo = "DH523";
	//B2: Thực hiện tính 5 chữ số cuối cuối là chuỗi
	// chuyển số thành chuỗi
	string thuTu = to_string(counter);
	// chèn các số 0 còn lại vào trước số thứ tự
	thuTu.insert(0, 5 - thuTu.length(), '0');
	this->maSV = tienTo + thuTu;
}
string SinhVien::getMaSV() {
	return this->maSV;
}
void SinhVien::taoTenNgauNhien() {
	const int MAX_HO = 8;
	const int MAX_TENLOT = 14;
	const int MAX_TEN = 20;

	// Mảng chứa họ
	string ho[MAX_HO] = { "Nguyen", "Tran", "Pham", "Hoang", "Mai", "Doan", "Ngo", "Luu",};


	// Mảng chứa các tên Lót
	string tenLot[MAX_TENLOT] = { "Van", "Thi", "Quoc", "Minh", "Huu", "Thanh", "Duy", "Khanh", "Nhat", "Huynh", "Huu","Gia", "Quoc", "Huy" };

	// Mảng chứa các tên 
	string ten[MAX_TEN] = {
		"An", "Binh", "Chau", "Bao", "But", "Giang", "Hai", "Trinh",
		"Hoai", "An", "Hao", "Khoa", "Linh", "Minh", "Ngoc", "Khang",
		"Hoang", "Thuy", "Tien", "Anh"
	};

	// lấy các phần trong tên ngẫu nhiên
	uniform_int_distribution <> distHo(0, MAX_HO-1);
	uniform_int_distribution <> distTenLot(0, MAX_TENLOT - 1);
	uniform_int_distribution <> distTen(0, MAX_TEN - 1);
	int indexHoNgauNhien = distHo(gen);
	int indexTenLotNgauNhien = distTenLot(gen);
	int indexTenNgauNhien = distTen(gen);

	// ghép các phần lại với nhau
	string hotenSV =  ho[indexHoNgauNhien] + " " + tenLot[indexTenLotNgauNhien] + " " + ten[indexTenNgauNhien];
	this->hoTenSV = hotenSV;
}


void SinhVien::taoNgaySinh()
{
	// cho năm của khóa sinh viên D23 là 2005
	int year = 2005;
	// tạo tháng
	uniform_int_distribution <> khoangThang(1, 12);
	int month = khoangThang(gen);

	// tạo ngày, phức tạp hơn
	// logic: nếu năm nhuận: tháng 2 có 29 ngày, không phải năm nhuận, tháng 2 28 ngày
	
	uniform_int_distribution <>khoangNgay(1, layNgayTrongThang(month, year));
	int day = khoangNgay(gen);


	// đổi số sang chuỗi
	string s_day = to_string(day);
	string s_month = to_string(month);
	string s_year = to_string(year);

	// thêm số 0 đệm trước các chuỗi có một chữ số
	if(s_day.length() == 1) { 
		s_day.insert(0, "0");
	}
	if (s_month.length() == 1) {
		s_month.insert(0, "0");
	}

	string ngaySinhMoi = s_day + "/" + s_month + "/" + s_year;
	this->ngaySinh = ngaySinhMoi;
}

void SinhVien::taoDiemNgauNhien()	
{
	this->diemTB = 0;
	uniform_real_distribution <> dist_diem(0.0, 10.0);
	double diemTho = dist_diem(gen); // kết quả trả về có thể ở dạng 2.45678
	// làm tròn 2 chữ số thập phân
	double diemLamTron = round(diemTho * 100.0) / 100.0; // ví dụ: 2.45678 * 100 = round (245.678) = 245 /100 = 2.45
	this->diemTB = diemLamTron;
}

void SinhVien::taoNgauNhienDuLieuSinhVien()
{
	taoMaSV();
	taoNgaySinh();
	taoTenNgauNhien();
	taoDiemNgauNhien();
}

// logic tính năm nhuận: thỏa 1 trong các điều kiện sau: năm đó chia hết cho 4 nhưng ko chia hết cho 100 hoặc năm đó chia hết cho 400
bool checkNamNhuan(int year) {
	return (year % 400 == 0) || (year % 4 == 0 && year % 100 != 0);
}



// hàm lấy ngày tối đa trong tháng
int layNgayTrongThang(int month, int year) {
	if (month == 2) {
		return (checkNamNhuan(year)) ? 29 : 28; // nếu năm nhuận trả 29 ngày, ngược lại là 28 ngày
	}
	// Các tháng 4, 6, 9, 11 có 30 ngày
	else if (month == 4 || month == 6 || month == 9 || month == 11) {
		return 30;	
	}
	// Các tháng còn lại có 31 ngày
	else {
		return 31;
	}
}

