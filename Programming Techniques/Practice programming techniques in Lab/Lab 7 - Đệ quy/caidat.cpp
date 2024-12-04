#include "thuvien.h"
long giaiThua(int n) {
	if (n == 0 || n == 1) {
		return 1;
	}
	return giaiThua(n - 1) * n;
}

int fibonacci(int n) {
	if (n < 1) {
		return 0;
	}
	if (n < 3) {
		return 1;
	}
	return fibonacci(n - 1) + fibonacci(n - 2);
}
int binarySearch(int a[], int l, int r, int x) {
	if (l > r) {
		return -1;
	}
	int mid = (l + r) / 2;
	if (a[mid] == x) {
		return mid;
	}
	if (a[mid] > x) {
		return binarySearch(a, l, mid - 1, x); // tim x trong nua mang ben trai
	}
	return binarySearch(a, mid + 1, r, x);
	// l la chi so trai, r la chi so phai
}
void quickSort(int a[], int l, int h) {
	if (l >= h) {
		return;
	}
	//pi la vi tri cua phan tu chia mang lam 2 mang trai va phai
	int pi = partition(a, l, h);
	quickSort(a, l, pi - 1);
	quickSort(a, pi + 1, h);
}
int partition(int a[], int low, int high) {
	int pivot = a[high];
	int left = low;
	int right = high;
	int i = left - 1;
	for (int j = left; j < right; j++) {
		if (a[j] <= pivot) {
			i++;
			swap(a[i], a[j]);
		}
	}
	i++;
	swap(a[i], a[right]);
	return i;
}

void xuatMang(int a[], int n)
{
	for (int i = 0; i < n; i++) {
		cout << "a[" << i << "]= " << a[i] << endl;
	}
}
DanhSachSV taoDuLieu() {
	DanhSachSV ds = { 10,{
		{"SV01","Le Thi","Be",7.7},
		 {"SV03","Nguyen Ngoc","Ti",4.5},
		  {"SV06","Le Van","Phuoc",8.0},
		   {"SV04","Tran Thi","Binh",6.0},
			{"SV05","Ngo Bao","Chau",7.0},
			 {"SV07","Le Thanh","Tam",9.0},
			  {"SV02","Le Thi Hong","Gam",3.5},
			   {"SV08","Nguyen Duy","An",8.5},
		}
	};
	return ds;
}
DanhSachSV loadDuLieu(const char* tenFile) {
	DanhSachSV ds;
	ds.siSo = 0;
	FILE* file;
	errno_t file_in;
	//mo file de doc
	file_in = fopen_s(&file, tenFile, "rb");
	if (file == NULL) {
		cout << "Loi doc file!";
		return ds;
	}
	int i = 0;
	fread(&ds, sizeof(DanhSachSV), 1, file);
	fclose(file);
	return ds;
}
bool luuDanhSachSV(DanhSachSV ds, const char* tenFile) {
	FILE* file;
	errno_t file_in;
	// mo file de doc
	file_in = fopen_s(&file, tenFile, "wb");
	if (file == NULL) {
		cout << "Loi doc file!";
		return false;
	}
	fwrite(&ds, sizeof(DanhSachSV), 1, file);
	fclose(file);
	return true;
}
void inSinhVien(SinhVien sv) {
	cout << left; // can le trai
	cout << setw(10) << sv.ten << setw(15) << sv.hoLot << setw(15) << sv.maSV << setw(5) << sv.diemTrungBinh << endl;
}
void inDanhSachSV(DanhSachSV dssv) {
	cout << left;
	cout <<setw(10) << "Ten" << setw(15) << "Ho lot" << setw(15) << "Ma SV" << setw(5) << "DTB" << endl;
	for (int i = 0; i < 9; i++) {
		inSinhVien(dssv.mang[i]);
	}
}
//cac ham ben duoi chua co dinh nghia ham. SV xay dung cac dinh nghia ham theo yeu cau trong bai tap tong hop
void quickSortGiamDan(SinhVien a[], int l, int h);
int partition(SinhVien a[], int low, int high);
int binarySearch(SinhVien a[], int l, int r, char* maSV);
// BAI TAP LAM THEM
int maxChuSo(int n) { //n =45
	// dieu kien dung
	if (n < 10) {
		return n;
	}
	int tam = maxChuSo(n / 10); // tam = 4
	return tam > n % 10 ? tam : n % 10;
}
int minChuSo(int n) { //34
	if (n < 10) {
		return n;
	}
	int tam = minChuSo(n / 10);
	return tam < n % 10 ? tam : n % 10;
}
bool checkChuSoToanChan(int n) { //453
	if (n < 10) { // base case
		return n % 2 == 0;
	}

	if (n % 2 == 1) {
		return false;
	}
	return checkChuSoToanChan(n / 10);
}
bool checkChuSoToanLe(int n) { //453
	if (n < 10) { // base case
		return n % 2 == 1;
	}

	if (n % 2 == 0) {
		return false;
	}
	return checkChuSoToanLe(n / 10);
}
void daoNguocSo(int n) {
	// base case;
	if (n < 10) {
		cout << n;
		return;
	}
	cout << n % 10;
	daoNguocSo(n / 10);
}
void xuatCacChuSoLe(int n) { // 4 1
	// base case
	if (n == 0) {
		return;
	}
	xuatCacChuSoLe(n / 10);
	if (n % 2 == 1) {
		cout << n % 10 << " ";
	}
}
int demChuSo(int n) // 412
{
	if (n <10) {
		return 1;
	}
	return 1 + demChuSo(n/10);
}
void xuatCacChuSoChan(int n) {
	// base case
	if (n == 0) {
		return;
	}
	xuatCacChuSoChan(n / 10);
	if (n % 2 == 0) {
		cout << n % 10 << " ";
	}
}
bool checkSNT(int n) {
	if (n < 2) {
		return false;
	}
	for (int i = 2; i <= sqrt(n); i++) {
		if (n % i == 0) {
			return false;
		}
	}
	return true;
}
void xuatCacChuSoNguyenTo(int n) { // 3 1
	if (n == 0) {
		return;
	}
	xuatCacChuSoNguyenTo(n / 10);
	if (checkSNT(n%10)) {
		cout << n%10 << " ";
	}
}


