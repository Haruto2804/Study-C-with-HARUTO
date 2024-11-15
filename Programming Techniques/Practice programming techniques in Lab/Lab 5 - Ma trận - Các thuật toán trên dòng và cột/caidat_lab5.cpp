#include "thuvien_lab5.h"
void nhapMaTran(MaTran& a) {
	cout << "\nNhap so dong: ";
	cin >> a.dong;
	cout << "Nhap so cot: ";
	cin >> a.cot;
	for (int i = 0; i < a.dong; i++) {
		for (int j = 0; j < a.cot; j++) {
			cout << "arr[" << i << "][" << j << "]= ";
			cin >> a.arr[i][j];
		}
	}
}
void xuatMaTran(MaTran a) {
	for (int i = 0; i < a.dong; i++) {
		for (int j = 0; j < a.cot; j++) {
			cout << "\t" << a.arr[i][j];
		}
		cout << endl;
	}
}
bool docMaTran(MaTran& a, const char* tenFile) {
	FILE* f;
	f = fopen(tenFile, "r");
	if (f == NULL) {
		return false;
	}
	fscanf(f, "%d %d\n", &a.dong, &a.cot);
	for (int i = 0; i < a.dong; i++) {
		for (int j = 0; j < a.cot; j++) {
			fscanf(f, "%d\t", &a.arr[i][j]);
		}
	}
	fclose(f);
	return true;
}
bool luuMaTran(MaTran a, const char* tenFile) {
	FILE* f;
	f = fopen(tenFile, "w");
	if (f == NULL) {
		return false;
	}
	fprintf(f, "%d %d\n", a.dong, a.cot);
	for (int i = 0; i < a.dong; i++) {
		for (int j = 0; j < a.cot; j++) {
			fprintf(f, "%d\t", a.arr[i][j]);
		}
	}
	fclose(f);
	return true;
}
int tong(MaTran a) {
	int s = 0;
	for (int i = 0; i < a.dong; i++) {
		for (int j = 0; j < a.cot; j++) {
			s += a.arr[i][j];
		}
	}
	return s;
}
int demDuong(MaTran a) {
	int dem = 0;
	for (int i = 0; i < a.dong; i++) {
		for (int j = 0; j < a.cot; j++) {
			if (a.arr[i][j] > 0) {
				dem++;
			}
		}
	}
	return dem;
}
int max(MaTran a) {
	int m = a.arr[0][0];
	for (int i = 0; i < a.dong; i++) {
		for (int j = 0; j < a.cot; j++) {
			if (a.arr[i][j] > m) {
				m = a.arr[i][j];
			}
		}
	}
	return m;
}
int tongChan(MaTran a) {
	int s = 0;
	for (int i = 0; i < a.dong; i++) {
		for (int j = 0; j < a.cot; j++) {
			if (a.arr[i][j] % 2 == 0) {
				s += a.arr[i][j];
			}
		}
	}
	return s;
}
bool checkSoChinhPhuong(int n) {
	int can = sqrt(n);
	if (can * can == n) {
		return true;
	}
	return false;
}
int demSoChinhPhuong(MaTran a) {
	int dem = 0;
	for (int i = 0; i < a.dong; i++) {
		for (int j = 0; j < a.cot; j++) {
			if (checkSoChinhPhuong(a.arr[i][j])) {
				dem++;
			}
		}
	}
	return dem;
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
bool maxSoNguyenTo(MaTran a, int& max) {
	bool flag = false;
	for (int i = 0; i < a.dong; i++) {
		for (int j = 0; j < a.cot; j++) {
			if (checkSNT(a.arr[i][j])) {
				if (!flag) {
					max = a.arr[i][j];
					flag = true;
				}
				else if (a.arr[i][j] > max) {
					max = a.arr[i][j];
				}
			}
		}
	}
	return flag;
}
void tinhTongCacDong(MaTran a) {
	for (int i = 0; i < a.dong; i++) {
		int tong = 0;
		cout << "Tong cua dong " << i + 1 << " la: ";
		for (int j = 0; j < a.cot; j++) {
			;
			tong += a.arr[i][j];
		}
		cout << tong << endl;
	}
}
void DongCoTongMax(MaTran a) {
	int vitriDongMax = 0;
	int max = a.arr[0][0] + a.arr[0][1] + a.arr[0][2];// max la tong cua dong dau tien
	for (int i = 0; i < a.dong; i++) {
		int tong = 0;
		for (int j = 0; j < a.cot; j++) {
			tong += a.arr[i][j];
		}
		if (tong > max) {
			max = tong;
			vitriDongMax = i;
		}
	}
	cout << "Dong " << vitriDongMax + 1 << " co tong lon nhat" << endl;
}
int tongCacMaxMoiDong(MaTran a) {
	int tongMax = 0;
	for (int i = 0; i < a.dong; i++) {
		int maxDong = a.arr[i][0]; //max la thang dau tien cua moi dong
		for (int j = 0; j < a.cot; j++) {
			if (a.arr[i][j] > maxDong) {
				maxDong = a.arr[i][j];
			}
		}
		// da tim duoc max cua dong i;
		tongMax += maxDong; // tong cua max cua cac dong
	}
	return tongMax;
}
void tongCacCot(MaTran a) {
	for (int j = 0; j < a.cot; j++) {
		int tong = 0;
		for (int i = 0; i < a.dong; i++) {
			tong += a.arr[i][j];
		}// thoat khoi for ta tinh dc tong cot j
		cout << "\nTong cua cot " << j + 1 << " la: " << tong << endl;
	}
}
void hoanDoiHaiCot(MaTran& a, int k, int j) {
	for (int i = 0; i < a.dong; i++) {
		swap(a.arr[i][k], a.arr[i][j]);
	}
}

void sapXepTangDanTungCot(MaTran& a) {
	for (int j = 0; j < a.cot; j++) {
		for (int i = 0; i < a.dong; i++) {
			for (int k = i + 1; k < a.dong; k++) {
				if ((a.arr[k][j] < a.arr[i][j])) { // s
					swap(a.arr[k][j], a.arr[i][j]);
				}
			}
		}
	}
}
void sapXepGiamDanTungDong(MaTran& a) {
	for (int i = 0; i < a.dong; i++) {
		for (int j = 0; j < a.cot; j++) {
			for (int k = j + 1; k < a.cot; k++) {
				if ((a.arr[i][k] > a.arr[i][j])) {
					swap(a.arr[i][k], a.arr[i][j]);
				}
			}
		}
	}
}