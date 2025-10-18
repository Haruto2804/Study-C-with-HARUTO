#include "thuvien.h"
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