#include "thuvien.h"

void printMonHocHeader() {
	// Thêm một cột "+-" với độ rộng 8
	cout << "  +-" << setfill('-') << setw(9) << "-"  // Ma Mon
		<< "+-" << setw(36) << "-" // Ten Mon
		<< "+-" << setw(5) << "-"  // So TC
		<< "+-" << setw(8) << "-+" << setfill(' ') << endl; // Diem TK (MỚI)

	// Thêm tiêu đề cột "Diem TK"
	cout << "  | " << left << setw(8) << "Ma Mon"
		<< " | " << left << setw(35) << "Ten Mon Hoc"
		<< " | " << right << setw(3) << "TC" << " |"
		<< " | " << right << setw(7) << "Diem TK" << " |" << endl; // (MỚI)

	// Thêm dòng kẻ tương ứng
	cout << "  +-" << setfill('-') << setw(9) << "-"
		<< "+-" << setw(36) << "-"
		<< "+-" << setw(5) << "-"
		<< "+-" << setw(8) << "-+" << setfill(' ') << endl;
}
void xuatMonHocTheoBang(MonHoc mh) {
	cout << "  | " << left << setw(8) << mh.maMon
		<< " | " << left << setw(35) << mh.tenMon
		<< " | " << right << setw(3) << mh.soTinChi << " |"

		// Thêm cột điểm tổng kết (MỚI)
		// fixed + setprecision(1): Luôn hiển thị 1 chữ số thập phân
		// setw(7): Căn phải trong 7 ký tự
		<< " | " << right << fixed << setprecision(1) << setw(7) << mh.tongKetMon << " |" << endl;
}