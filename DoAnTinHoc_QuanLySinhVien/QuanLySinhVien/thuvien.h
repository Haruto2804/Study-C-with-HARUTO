#include <iostream> // thư viện chuẩn cho input/output
#include <string> // thư viện để định dạng chuỗi
#include <iomanip> // thư viện cho việc định dạng output
#include <random> // thư viện cho việc tạo sinh số ngẫu nhiên
#include "cmath" // thư viện cho việc làm tròn (round)
#include <vector>
using namespace std;
struct MonHoc {
	string maMon;
	string tenMon;
	int soTinChi;
	double tongKetMon; // Điểm tổng kết cuối cùng của môn
};

class SinhVien {
private:
	string hoTenSV, maSV, ngaySinh, queQuan;
	std::vector<MonHoc> DSMonHoc;

public:
	static int counter;

	// hàm tạo
	SinhVien();
	//tạo danh sách môn học
	void taoDanhSachMonHoc();

	//getter,setter
	// lấy danh sách môn học ủa sinh viên đó - ko thay đổi dữ liệu môn học
	const vector<MonHoc>& getDSMonHoc() const {
		return DSMonHoc;
	}
	// update mon hoc cho sinh vien
	vector<MonHoc>& getDSMonHocForUpdate() {
		return DSMonHoc;
	}

	void xuatMonHocCuaSinhVien(const SinhVien& sv);

	// hàm nhập thông tin sinh viên
	void nhapThongTinSinhVien();
	// hàm này để nhập bằng cách truyền đối số
	void nhapThongTinSinhVien(string hoTenSV, string maSV, string ngaySinh, string queQuan);


	// hàm in thông tin của sinh viên
	void inThongTinSinhVien();
	// các hàm tạo dữ liệu ngẫu nhiên, để check kết quả cho nhanh
	void taoMaSV();
	void taoTenNgauNhien();
	void taoNgaySinh();
	void taoNgauNhienDuLieuSinhVien();
	void taoQueQuanNgauNhien();

	string getMaSV();
	// lấy data từ sinh viên
	void printDataRow(int stt);
	double tinhDiemGPA()const;
	string chuyenDoiSangXepLoai() const;
	void resetDiemMonHoc();
};

struct Node{
	SinhVien data;
	Node* left;
	Node* right;
	int height;
};



void printMonHocHeader();
void xuatMonHocTheoBang(MonHoc mh);

typedef Node* NodePtr;

class AVLTree {
private:
	NodePtr head; // cho head là private nhằm che dấu dữ liệu của cây

public:
	//Tạo hàm tạo gán head ban đầu là null
	AVLTree();

	// vì là đang làm việc cấp phát bộ nhớ động, do đó cần tạo hàm hủy để giải phóng bộ nhớ, tránh tình trạng bị rò rỉ bộ nhớ (memory leak)
	~AVLTree() {
		deleteTree(this->head);
		this->head = nullptr;
	}

	
	void deleteTree(NodePtr T);




	// dùng hàm bọc để dùng cho main sau khi gọi hàm này thì hàm bọc sẽ gọi hàm insert ở dưới
	void insertSV(SinhVien data);
	NodePtr insertSV(NodePtr T, SinhVien data); // hàm chèn Sinh viên vào cây AVL

	void deleteSV(string maSVCanXoa);
	NodePtr deleteSV(NodePtr T, string maSVCanXoa);
	
	NodePtr search(string maSVCanTim);
	NodePtr search(NodePtr T, string maSVCanTim);

	NodePtr createNode(SinhVien data);

	int height(NodePtr T); // tính chiều cao tại nốt đang xét

	int getBalance(NodePtr T);

	NodePtr RotateRight(NodePtr T);

	NodePtr RotateLeft(NodePtr T);

	void updateDiemSV(const double &diemMoi, const string &maSV, const string& maMH);
	// tạo hàm bọc cho LNR
	void LNR(); // tăng dần theo mssv
	void RNL();
	void xuatDanhSachSinhVienTheoThuTuTangDanMSSV();
	void RNL(NodePtr T);
	void LNR(NodePtr T);
	void xuatDanhSachSinhVienTheoThuTuTangDanMSSV(NodePtr T);

	//xuất danh sách môn hoc theo maSV
	void xuatDanhSachMonHocTheoMaSV(const string& maSV);
};

bool checkNamNhuan(int year);
int layNgayTrongThang(int month, int year);
void printHeader();
void printLine();
NodePtr findMAX(NodePtr T);
void showBasicMenu();

