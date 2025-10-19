#include "LinkedList.h"
#include "MonHoc.h"
void LinkedList::taoDanhSachMonHoc()
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


	// thêm các môn học vào DSLK
	for (int i = 0;i < n;i++) {
		NodePtr1 newNode = makeNodeDSLK(dataKhoiTao[i]);
		themDau(newNode->data);
	}
}



void printMonHocHeader() {
	// Thêm một cột "+-" với độ rộng 8
	cout << "  +-" << setfill('-') << setw(9) << "-"  // Ma Mon
		<< "+-" << setw(36) << "-" // Ten Mon
		<< "+-" << setw(5) << "-"  // So TC
		<< "+-" << setw(8) << "-+" << setfill(' ') << endl; // Diem TK (MỚI)

	// Thêm tiêu đề cột "Diem TK"
	cout << "  | " << left << setw(8) << "Ma Mon"
		<< " | " << left << setw(35) << "Ten Mon Hoc"
		<< " | " << right << setw(2) << "TC" << " |"
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
		<< " | " << right << setw(2) << mh.soTinChi << " |"

		// Thêm cột điểm tổng kết (MỚI)
		// fixed + setprecision(1): Luôn hiển thị 1 chữ số thập phân
		// setw(7): Căn phải trong 7 ký tự
		<< " | " << right << fixed << setprecision(1) << setw(7) << mh.tongKetMon << " |" << endl;
}