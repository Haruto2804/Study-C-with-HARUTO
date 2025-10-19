#pragma once
struct MonHoc {
	string maMon;
	string tenMon;
	int soTinChi;
	double tongKetMon; // Điểm tổng kết cuối cùng của môn
};
void xuatMonHoc(MonHoc data);
void printMonHocHeader();
void xuatMonHocTheoBang(MonHoc mh);