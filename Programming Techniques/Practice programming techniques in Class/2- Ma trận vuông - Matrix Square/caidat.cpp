#include "thuvien.h"
void nhapMaTran(maTran& mt) {
	cout << "Nhap cap cho ma tran: ";
	cin >> mt.n;
	for (int i = 0; i < mt.n; i++) {
		for (int j = 0; j < mt.n; j++) {
			cout << "Nhap vao phan tu a[" << i << "][" << j << "]= ";
			cin >> mt.matrix[i][j];
		}
	}
}
void xuatMaTran(maTran mt) {
	cout << left;
	for (int i = 0; i < mt.n; i++) {
		for (int j = 0; j < mt.n; j++) {
			cout << setw(5) << mt.matrix[i][j];
		}
		cout << endl;
	}
}
int tongMaTranTamGiacTrenPhai(maTran mt) {
	int tong = 0;
	for (int i = 0; i < mt.n; i++) {
		for (int j = i; j <mt.n; j++) {
			tong += mt.matrix[i][j];
		}
	}
	return tong;
}
int maxTamGiacDuoiTrai(maTran mt) {
	int max = mt.matrix[0][0];
	for (int i = 0; i < mt.n; i++) {
		for (int j = 0; j <= i; j++) {
			if (mt.matrix[i][j] > max) {
				max = mt.matrix[i][j];
			}
		}
	}
	return max;
}
int demSoDuongMaTranTamGiacTrenPhai(maTran mt) {
	int count = 0;
	for (int i = 0; i < mt.n; i++) {
		for (int j = i; j < mt.n; j++) {
			if (mt.matrix[i][j] > 0) {
				count++;
			}
		}
	}
	return count;
}
bool maxAmMaTranTamGiacDuoiTrai(maTran mt, int &max) {
	bool flag = false; // chua tim thay max amm
	for (int i = 0; i<mt.n; i++) {
		for (int j = 0; j <= i; j++) {
			if (mt.matrix[i][j] < 0) {
				if (!flag) {
					max = mt.matrix[i][j];
					flag = true;
				}
				else if (mt.matrix[i][j] > max) {
					max = mt.matrix[i][j];
				}
			}
			
		}
	}
	return flag;
}
void phatSinhMaTran(maTran& mt) {
	cout << "Nhap cap cho ma tran: ";
	cin >> mt.n;
	random_device rd;
	mt19937_64 rng(rd());
	uniform_int_distribution<int> dis(-10, 10);
	for (int i = 0; i < mt.n; i++) {
		for (int j = 0; j < mt.n; j++) {
			mt.matrix[i][j] = dis(rng);
		}
	}
}