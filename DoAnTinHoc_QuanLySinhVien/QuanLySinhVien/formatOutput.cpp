#include "thuvien.h"


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




