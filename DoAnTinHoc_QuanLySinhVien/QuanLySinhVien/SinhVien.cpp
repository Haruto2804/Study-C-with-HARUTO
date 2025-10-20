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
	cout << "\nNhap Que quan cua sinh vien: ";
	cin >> this->queQuan;
	cin.ignore();
	cin.ignore();
}
void SinhVien::nhapThongTinSinhVien(string hoTenSV, string maSV, string ngaySinh, string queQuan)
{
	this->hoTenSV = hoTenSV;
	this->maSV = maSV;
	this->ngaySinh = ngaySinh;
	this->queQuan = queQuan;
}
void SinhVien::inThongTinSinhVien() {

	double gpa = tinhDiemGPA();
	cout << "\nHo ten sinh vien: " << this->hoTenSV;
	cout << "\nMa sinh vien: " << this->maSV;
	cout << "\nNgay sinh: " << this->ngaySinh;
	cout << "\nQue quan: " << this->queQuan;
	cout << "\nDiem GPA: " << gpa;
	cout << "\nXep loai: " << chuyenDoiSangXepLoai();
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



void SinhVien::taoQueQuanNgauNhien() {
	std::string tinhThanh[] = {
		// Các đơn vị được giữ lại tên hoặc tên mới
		"Ha Noi",         // 1 (Thanh pho Ha Noi)
		"Hue",            // 2 (Thanh pho Hue)
		"Lai Chau",       // 3 (Tinh Lai Chau)
		"Dien Bien",      // 4 (Tinh Dien Bien)
		"Son La",         // 5 (Tinh Son La)
		"Lang Son",       // 6 (Tinh Lang Son)
		"Quang Ninh",     // 7 (Tinh Quang Ninh)
		"Thanh Hoa",      // 8 (Tinh Thanh Hoa)
		"Nghe An",        // 9 (Tinh Nghe An)
		"Ha Tinh",        // 10 (Tinh Ha Tinh)
		"Cao Bang",       // 11 (Tinh Cao Bang)

		// Các đơn vị sau hợp nhất
		"Tuyen Quang",    // 12 (Tinh Tuyen Quang)
		"Lao Cai",        // 13 (Tinh Lao Cai)
		"Thai Nguyen",    // 14 (Tinh Thai Nguyen)
		"Phu Tho",        // 15 (Tinh Phu Tho)
		"Bac Ninh",       // 16 (Tinh Bac Ninh)
		"Hung Yen",       // 17 (Tinh Hung Yen)
		"Hai Phong",      // 18 (Thanh pho Hai Phong)
		"Ninh Binh",      // 19 (Tinh Ninh Binh)
		"Quang Tri",      // 20 (Tinh Quang Tri)
		"Da Nang",        // 21 (Thanh pho Da Nang)
		"Quang Ngai",     // 22 (Tinh Quang Ngai)
		"Gia Lai",        // 23 (Tinh Gia Lai)
		"Khanh Hoa",      // 24 (Tinh Khanh Hoa)
		"Lam Dong",       // 25 (Tinh Lam Dong)
		"Dak Lak",        // 26 (Tinh Dak Lak)
		"Ho Chi Minh",    // 27 (Thanh pho Ho Chi Minh)
		"Dong Nai",       // 28 (Tinh Dong Nai)
		"Tay Ninh",       // 29 (Tinh Tay Ninh)
		"Can Tho",        // 30 (Thanh pho Can Tho)
		"Vinh Long",      // 31 (Tinh Vinh Long)
		"Dong Thap",      // 32 (Tinh Dong Thap)
		"Ca Mau",         // 33 (Tinh Ca Mau)
		"An Giang"        // 34 (Tinh An Giang)
	};
	size_t soTinhThanh = sizeof(tinhThanh) / sizeof(tinhThanh[0]);
	uniform_int_distribution <> dist(0, 33);
	int indexTinhThanhNgauNhien = dist(gen);
	this->queQuan = tinhThanh[indexTinhThanhNgauNhien];
}
void SinhVien::taoNgauNhienDuLieuSinhVien()
{
	taoMaSV();
	taoNgaySinh();
	taoTenNgauNhien();
	taoQueQuanNgauNhien();
}






// xuất danh sách sinh viên-
// Các hàm format ouput cho Danh sách sinh viên
// Đặt độ rộng cố định cho từng cột
#define COL_WIDTH_STT 5
#define COL_WIDTH_MSSV 15
#define COL_WIDTH_NAME 30
#define COL_WIDTH_DATE 15
#define COL_WIDTH_QUEQUAN 15
#define COL_TOTAL_WIDTH (COL_WIDTH_STT + COL_WIDTH_MSSV + COL_WIDTH_NAME + COL_WIDTH_DATE + COL_WIDTH_QUEQUAN+5) // Tổng độ rộng + khoảng cách

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
	cout << left << setw(COL_WIDTH_QUEQUAN) << " QueQuan";
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
	cout << left << setw(COL_WIDTH_DATE - 1) << this->queQuan << " ";
	cout << "|";
}


// tính điểm TB, ta có điểm quy đổi GPA như sau: 
//DIEM SO(Thang 10) | DIEM CHU | DIEM QUY DOI(Thang 4.0)
//-------------------- | ---------- | --------------------------
//>= 9.0 | A + | 4.0
//8.5 - 8.9 | A | 4.0
//8.0 - 8.4 | B + | 3.5
//7.0 - 7.9 | B | 3.0
//6.5 - 6.9 | C + | 2.5
//5.5 - 6.4 | C | 2.0
//5.0 - 5.4 | D + | 1.5
//4.0 - 4.9 | D | 1.0
//< 4.0 | F | 0.0
double SinhVien::tinhDiemGPA() const
{
	double tongDiemTrongSo = 0.0;
	int tongTinChi = 0;
	for (const auto& monHoc : this->DSMonHoc) {
		double diemQuyDoi;
		// AP DUNG BANG QUY DOI BEN TREN: quy đổi thanh điểm 10 thành thang điểm 4
		if (monHoc.tongKetMon >= 8.5) { // Bao gom ca A+ va A
			diemQuyDoi = 4.0;
		}
		else if (monHoc.tongKetMon >= 8.0) {
			diemQuyDoi = 3.5;
		}
		else if (monHoc.tongKetMon >= 7.0) {
			diemQuyDoi = 3.0;
		}
		else if (monHoc.tongKetMon >= 6.5) {
			diemQuyDoi = 2.5;
		}
		else if (monHoc.tongKetMon >= 5.5) {
			diemQuyDoi = 2.0;
		}
		else if (monHoc.tongKetMon >= 5.0) {
			diemQuyDoi = 1.5;
		}
		else if (monHoc.tongKetMon >= 4.0) {
			diemQuyDoi = 1.0;
		}
		else {
			diemQuyDoi = 0.0;
		}
		tongDiemTrongSo += diemQuyDoi * monHoc.soTinChi;
		tongTinChi += monHoc.soTinChi;
	}

	// tránh trường hợp lỗi khi sinh viên ko có tín chỉ nào
	if (tongTinChi == 0) {
		return 0.0;
	}

	return round((tongDiemTrongSo / tongTinChi) * 100) / 100;
}

string SinhVien::chuyenDoiSangXepLoai() const
{
	// 1. Tính toán GPA hiện tại
	double gpa = tinhDiemGPA();
	string xepLoai;

	// 2. Phân loại GPA (Sử dụng các ngưỡng GPA tiêu chuẩn)
	if (gpa >= 3.6) {
		xepLoai = "Xuat sac (A+)";
	}
	else if (gpa >= 3.2) {
		xepLoai = "Gioi (A)";
	}
	else if (gpa >= 2.5) { // Thường là Khá giỏi/Khá
		xepLoai = "Kha (B+)";
	}
	else if (gpa >= 2.0) {
		xepLoai = "Trung binh (C)";
	}
	else if (gpa >= 1.0) {
		xepLoai = "Trung binh yeu (D)";
	}
	else {
		xepLoai = "Kem (F)";
	}

	return xepLoai;
}

void SinhVien::resetDiemMonHoc()
{
	for (auto& monHoc : this->DSMonHoc) {
		monHoc.tongKetMon = 0;
	}

}

