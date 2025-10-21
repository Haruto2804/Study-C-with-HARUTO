#include "thuvien.h"
#include <sstream>

string chuyenChuHoaThanhChuThuong(const string &chuoiGoc)
{
	string chuoiMoi = "";
	for (char c : chuoiGoc) {
		char chuyen_doi = tolower(c); // tolower chuyen chu hoa thanh chu thuong trong thu vien cctype
		chuoiMoi += chuyen_doi;
	}
	return chuoiMoi;
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
string taoTenFileThoiGian(const string& tenGoc)
{
	time_t currentTime = time(nullptr); // lấy thời gian hiện tại
	std::tm formatTime = *std::localtime(&currentTime); // chuyển đổi dạng thời gian thô sang dạng thời gian mà người đọc được
	std::stringstream ss;
	size_t lastDot = tenGoc.find_last_of('.'); // vị trí của dấu chấm cuối cùng
	ss << tenGoc.substr(0, lastDot) << "_"; // cắt chuỗi của tên gốc từ đầu cho đến trước . cuối cùng rồi chèn _
	ss << std::put_time(&formatTime, "%d%m%Y_%H%M%S"); // định dạng ngày-thang-nam_gio-phut-giay
	ss << tenGoc.substr(lastDot); //tengoc.substr, (string.substr), lấy chuỗi con từ chuỗi gốc bắt đầu từ vị trí của last dot - lấy phần mở rộng rồi chèn vào luồng ss
	return ss.str(); // chuyển đổi luồng stream thành chuỗi rồi trả về tên mới
}

