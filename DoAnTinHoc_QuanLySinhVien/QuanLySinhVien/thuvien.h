#include <iostream> // thư viện chuẩn cho input/output
#include <string> // thư viện để định dạng chuỗi
#include <iomanip> // thư viện cho việc định dạng output
#include <random> // thư viện cho việc tạo sinh số ngẫu nhiên
#include "cmath" // thư viện cho việc làm tròn (round)
#include <vector> // dùng cho tạo mảng động
#include <fstream> // thư viện dùng cho đọc/ghi file
#include <cctype> // dùng cho tolower
#include <ctime>   // Dùng cho time_t và localtime
#pragma warning(disable : 4996)// tắt thông báo lỗi đọc/ghi file
#define _CRT_SECURE_NO_WARNINGS // tắt thông báo lỗi đọc/ghi file


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
	void inThongTinSinhVien() const;
	// các hàm tạo dữ liệu ngẫu nhiên, để check kết quả cho nhanh
	void taoMaSV();
	void taoTenNgauNhien();
	void taoNgaySinh();
	void taoNgauNhienDuLieuSinhVien();
	void taoQueQuanNgauNhien();


	// lấy data từ sinh viên
	void printDataRow(int stt);
	double tinhDiemGPA()const;
	string chuyenDoiSangXepLoai() const;
	void resetDiemMonHoc();
	void ghiFile(int& stt, std::ofstream& ghi_file) const;
	void ghiBangDiemSinhVien(const string& TenFile);
	//getter,setter
	string getMaSV() const;
	string getHoTenSV() const;

	void setTenSV(const string& tenMoi);
	void setMaSV(const string& maSVMoi);
	void setNgaySinh(const string& ngaySinhMoi);
	void setQueQuan(const string& queQuanMoi);
	
	// tạo hàm kiểm tra sinh viên có chứa từ khóa hay ko, trả về bool
	bool sinhVienChuaTuKhoa(const string& keyword);

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
	// ta sẽ dùng vector - mảng động, để lưu trữ danh sách sinh viên đã lọc

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
	bool insertSV(SinhVien data);
	NodePtr insertSV(NodePtr T,  SinhVien data, bool &result); // hàm chèn Sinh viên vào cây AVL

	bool deleteSV(string maSVCanXoa);
	NodePtr deleteSV(NodePtr T, string maSVCanXoa, bool &result);
	
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
	void locSinhVienTheoDiemGPA(const double& minGPA);
	void locSinhVienTheoGPA_Recursive(NodePtr T, const double& minGPA);
	void inDanhSachSinhVien(const string& tenFile);
	void inDanhSachSinhVien(NodePtr T, int &stt, std::ofstream &os);


	// ta xây 
	// ta sẽ xây dựng hàm có chức năng xuất các sinh viên khớp với từ khóa và cho phép
	// người dùng có thể lưu vào FILE để xem, ở đây hàm này trả về danh sách sinh viên khớp với từ khóa

	std::vector<SinhVien> locSinhVienTheoTuKhoa(const string& keyword, bool &isEmpty);
	void locSinhVienTheoTuKhoa(NodePtr T, const string& keyword, std::vector<SinhVien> &DSSV);
};


string chuyenChuHoaThanhChuThuong(const string &chuoigoc);
bool checkNamNhuan(int year);
int layNgayTrongThang(int month, int year);
void printHeader();
void printLine();
NodePtr findMAX(NodePtr T);
void showBasicMenu();
void switchCaseForChoice(AVLTree& DSSV);
void inDanhSachSinhVienRaFile_Vector(const vector<SinhVien>& DSSV,const string &tenFile);
string taoTenFileThoiGian(const string& tenGoc);