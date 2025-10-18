#include "thuvien.h"

// Tạo bộ sinh số ngẫu nhiên cho toàn bộ chương trình
random_device rd; // Nguồn seed
mt19937 gen(rd()); // Engine được khởi tạo MỘT LẦN

// gán giá trị ban đầu cho biến counter là 0, nghĩa là chưa có sinh viên nào
int SinhVien::counter = 0;




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
