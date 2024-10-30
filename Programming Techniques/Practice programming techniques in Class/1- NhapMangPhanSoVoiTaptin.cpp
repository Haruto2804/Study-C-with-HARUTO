#include <iostream>
using namespace std;
#pragma warning (disable : 4996)
#define MAX 100
#define _CRT_SECURE_NO_WARNINGS
// VIET 1 ham luu mang phan so sau do dua no vao file!
struct PhanSo {
	int mauSo;
	int tuSo;
};
struct MangPhanSo {
	int soPhanTu;
	PhanSo mangPhanSo[MAX];
};
void nhapPhanSo(PhanSo &ps) {

	cout << "\nNhap tu so: ";
	cin >> ps.tuSo;
	do {
		cout << "Nhap mau so: "
			;
		cin >> ps.mauSo;
		if (ps.mauSo == 0) {
			cout << "Mau so phai khac 0!" << endl;
		}
	} while (ps.mauSo == 0);
}
void nhapMangPhanSo(MangPhanSo& mps) {
	cout << "Nhap so phan tu cua mang phan so: ";
	cin >> mps.soPhanTu;
	for (int i = 0; i < mps.soPhanTu;i++) {
		cout << "Nhap vao phan tu " << i << ": ";
		nhapPhanSo(mps.mangPhanSo[i]);
	}
}
void xuatMangPhanSo(MangPhanSo mps)
{
	for (int i = 0; i<mps.soPhanTu; i++) {
		cout << "Phan tu " << i << " la ";
		cout << mps.mangPhanSo[i].tuSo << "/" << mps.mangPhanSo[i].mauSo;
		cout << endl;
	}
}
bool luuMangPhanSo(MangPhanSo mps, const char* tenFile) {
	FILE* f;
	f = fopen(tenFile, "w");
	fprintf(f, "So phan tu cua mang la: %d\n", mps.soPhanTu);
	for (int i = 0; i < mps.soPhanTu; i++) {
		fprintf(f, "%d/%d\t", mps.mangPhanSo[i].tuSo, mps.mangPhanSo[i].mauSo);
	}
	fclose(f);
	return true;
}
//================================================================
int main() {
	FILE* fp;
	int mang[] = { 1,2,3,5 };
	const char* str = "HELLO WORLD GUYS";
	size_t n = sizeof(mang) / sizeof(mang[0]);
	fp = fopen("text.txt", "wb+");
	if (fp == NULL) {
		perror("Loi mo file: ");
	}
	else {
		cout << "Mo file thanh cong!\n";
	}
	// ham main chay fwrite====================================
	//size_t written = fwrite(&mang[0], sizeof(int), n, fp); // ghi vao file bang mang
	//size_t written = fwrite(str, sizeof(char), strlen(str), fp); // ghi vao file bang 1 chuoi
	//size_t written = fwrite(&str[0], sizeof(char), strlen(str), fp); // ban chat const char* str la mot mang ki tu nen ta cp the dung &str[0]
	//cout << "\nSo phan tu da ghi thanh cong vao file la: " << written;
	//===================================================================================

	// ===============================ham main chay chuong trinh phan so==================
	struct PhanSo x;
	struct MangPhanSo mangps;
	nhapMangPhanSo(mangps);
	xuatMangPhanSo(mangps);
	luuMangPhanSo(mangps, "MangPhanSo.txt");
	//
	return 0;
}