#include "thuvien.h"
// Tạo bộ sinh số ngẫu nhiên cho toàn bộ chương trình
random_device rd; // Nguồn seed
mt19937 gen(rd()); // Engine được khởi tạo MỘT LẦN

// gán giá trị ban đầu cho biến counter là 0, nghĩa là chưa có sinh viên nào
int SinhVien::counter = 0;


// hàm tạo sinh viên
SinhVien::SinhVien()
{
	this->taoDanhSachMonHoc();
	taoNgauNhienDuLieuSinhVien();
}

void SinhVien::taoDanhSachMonHoc()
{
	MonHoc dataKhoiTao[] = {
	   {"IE101", "Co so ha tang cong nghe thong tin", 3, 0.0},
	   {"IE102", "Cac cong nghe nen", 3, 0.0},
	   {"IE103", "Quan ly du an", 4, 0.0},
	   {"IE104", "Internet va cong nghe Web", 4, 0.0},
	   {"IE101", "Co so ha tang cong nghe thong tin", 3, 0.0}, // Môn lặp
	   {"CS101", "Cau truc du lieu va giai thuat", 4, 0.0},
	   {"CS102", "Lap trinh huong doi tuong", 4, 0.0},
	   {"MA001", "Giai tich 1", 4, 0.0},
	   {"MA002", "Dai so tuyen tinh", 4, 0.0},
	   {"NT101", "Mang may tinh", 4, 0.0},
	   {"CS111", "He dieu hanh", 4, 0.0},
	   {"IS201", "He quan tri co so du lieu", 4, 0.0},
	   {"PH001", "Vat ly 1", 3, 0.0},
	   {"EN001", "Tieng Anh 1", 3, 0.0},
	   {"SE101", "Nhap mon Cong nghe phan mem", 3, 0.0}
	};


	// lấy phần tử của mảng môn học
	int n = sizeof(dataKhoiTao) / sizeof(MonHoc);





	// tạo điểm tổng kết ngẫu nhiên
	uniform_real_distribution<> distDiem(0.0, 10.0);



	// thêm các môn học vào DSLK
	for (int i = 0;i < n;i++) {
		double diemNgauNhien = distDiem(gen);
		diemNgauNhien = round(diemNgauNhien * 10.0) / 10.0;
		dataKhoiTao[i].tongKetMon = diemNgauNhien;
		this->DSMonHoc.push_back(dataKhoiTao[i]);
	}
}



void SinhVien::xuatMonHocCuaSinhVien(const SinhVien& sv)
{
	const vector<MonHoc>& danhSachMH = sv.getDSMonHoc();
	// 1. LÀM ĐẸP TIÊU ĐỀ CHÍNH (Căn đều với bảng)
	// Chiều rộng bảng là 66 ký tự (đã tính khoảng trắng đầu dòng)
	int totalWidth = 67;
	string title = "DANH SACH MON HOC CUA SINH VIEN CO MA SO: " + getMaSV();

	cout << "|\n  "; // Khoảng trắng đầu dòng
	cout << setfill('-') << setw(totalWidth) << "" << setfill(' ') << endl;

	// Căn giữa tiêu đề chính
	int padding = (totalWidth - title.length()) / 2;
	cout << " " << setw(padding) << right << " " << left << title << endl;


	printMonHocHeader();
	
	//duyệt lấy dữ liệu từ DSLK (vector)
	for (const MonHoc& mh : danhSachMH) {
		xuatMonHocTheoBang(mh);
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
	cin.ignore();
}
void SinhVien::nhapThongTinSinhVien(string hoTenSV, string maSV, string ngaySinh, double diemTB)
{
	this->hoTenSV = hoTenSV;
	this->maSV = maSV;
	this->ngaySinh = ngaySinh;
}
void SinhVien::inThongTinSinhVien() {
	cout << "\nHo ten sinh vien: " << this->hoTenSV;
	cout << "\nMa sinh vien: " << this->maSV;
	cout << "\nNgay sinh: " << this->ngaySinh;
}
void SinhVien::taoMaSV() {
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
	string ho[MAX_HO] = { "Nguyen", "Tran", "Pham", "Hoang", "Mai", "Doan", "Ngo", "Luu", };


	// Mảng chứa các tên Lót
	string tenLot[MAX_TENLOT] = { "Van", "Thi", "Quoc", "Minh", "Huu", "Thanh", "Duy", "Khanh", "Nhat", "Huynh", "Huu","Gia", "Quoc", "Huy" };

	// Mảng chứa các tên 
	string ten[MAX_TEN] = {
		"An", "Binh", "Chau", "Bao", "But", "Giang", "Hai", "Trinh",
		"Hoai", "An", "Hao", "Khoa", "Linh", "Minh", "Ngoc", "Khang",
		"Hoang", "Thuy", "Tien", "Anh"
	};

	// lấy các phần trong tên ngẫu nhiên
	uniform_int_distribution <> distHo(0, MAX_HO - 1);
	uniform_int_distribution <> distTenLot(0, MAX_TENLOT - 1);
	uniform_int_distribution <> distTen(0, MAX_TEN - 1);
	int indexHoNgauNhien = distHo(gen);
	int indexTenLotNgauNhien = distTenLot(gen);
	int indexTenNgauNhien = distTen(gen);

	// ghép các phần lại với nhau
	string hotenSV = ho[indexHoNgauNhien] + " " + tenLot[indexTenLotNgauNhien] + " " + ten[indexTenNgauNhien];
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
	if (s_day.length() == 1) {
		s_day.insert(0, "0");
	}
	if (s_month.length() == 1) {
		s_month.insert(0, "0");
	}

	string ngaySinhMoi = s_day + "/" + s_month + "/" + s_year;
	this->ngaySinh = ngaySinhMoi;
}


void SinhVien::taoNgauNhienDuLieuSinhVien()
{
	taoMaSV();
	taoNgaySinh();
	taoTenNgauNhien();
}






// xuất danh sách sinh viên-
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
}

