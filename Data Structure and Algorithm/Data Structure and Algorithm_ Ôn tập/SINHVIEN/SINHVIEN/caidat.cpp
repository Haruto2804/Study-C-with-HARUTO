#include <iostream>
#include <vector> // nho khai bao thu vien vector
using namespace std;
struct SinhVien {
	char hoTenSV[50];
	int namSinh;
	char MSSV[15];
	char diaChi[50];
};
vector<SinhVien> danhSachSV;
int main() {
	// khoi tao danh sach mang dong v mang kieu int
	vector <int> v = { 10,20,30 };
	//tra ve phan tu dau tien cua danh sach
	int front = v.front();
	cout << "\nPhan tu dau tien cua v la: " << front;
	// tra ve phan tu cuoi cung cua danh sach v
	int back = v.back();
	cout << "\nPhan tu cuoi cung cua v la: " << back;
	// tao con tro tro den dia chi cua danh sach v;
	int* ptr = v.data();
	// gia tri dau tien cua danh sach chinh la nam dia chi dau tien cua danh sach
	cout << "\nGia tri dau tien cua danh sach v la: ";
	cout << *ptr;
	int size = v.size();
	// tra ve so luong hien tai cua vector
	cout<<"\nSo luong hien tai cua danh sach v la: " << size;
	// khi danh sach v day thi se cap phat them bo nho(capacity) de chua them
	cout << "\nCapacity ban dau: " << v.capacity() << endl; // Dang la 3
	for (int i = 0; i < 10; ++i) {
		v.push_back(i);
		cout << "Size: " << v.size() << ", Capacity: " << v.capacity() <<endl;
	}
	// reserve yeu cau cap phat(capacity chi dinh)
	cout << "Capacity hien tai: " << v.capacity();
	v.reserve(100);
	cout << "\nCapacity sau khi cap phat them: " << v.capacity();

	// yeu cau cap phat lai capacityy = size, xu li truong hop thua o nho
	cout << "\nCapacity truoc khi shrink_to_fit: " << v.capacity();
	v.shrink_to_fit();
	cout << "\nCapacity hien tai: " << v.capacity();
	return 0;
}