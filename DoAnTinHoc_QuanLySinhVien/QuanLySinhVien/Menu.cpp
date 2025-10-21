#include "thuvien.h"
// Khai báo các hằng số cho menu
#define MENU_INSERT_RANDOM 1
#define MENU_INSERT 2
#define MENU_DELETE_STUDENT 3
#define MENU_UPDATE_INFO_STUDENT 4
#define MENU_UPDATE_DIEM 5
#define MENU_SEARCH 6
#define MENU_PRINT_STUDENT 7
#define MENU_PRINT_DSSV 8
#define MENU_PRINT_MONHOC 9
#define MENU_LOC_GPA 10
#define MENU_EXIT 0


void menuUpdateStudent() {
	// Chiều rộng tổng cộng của menu (50 ký tự)
	const int WIDTH = 60;
	const char HORZ = '=';
	const char VERT = '|';
	string title = "MENU CAP NHAT THONG TIN SINH VIEN (AVL)";

	// --- Khung trên (Top Border) ---
	cout << "\n" << setfill(HORZ) << setw(WIDTH + 2) << "" << endl;

	// --- Tiêu đề (Title) ---
	cout << VERT << setfill(' ') << setw((WIDTH - title.length()) / 2) << ""
		<< title
		<< setw((WIDTH - title.length()) / 2 + (WIDTH - title.length()) % 2 + 1) << "" << VERT << endl;

	// --- Đường phân cách ---
	cout << VERT << setfill('-') << setw(WIDTH) << "" << VERT << endl;

	// --- Các lựa chọn (Options) ---
	// setw(WIDTH - 1) để trừ đi ký tự '|' ở đầu
	cout << VERT << setfill(' ') << left << setw(WIDTH) << " 1. Sua Ten Sinh Vien" << VERT << endl;
	cout << VERT << left << setw(WIDTH) << " 2. Sua Ma So Sinh Vien" << VERT << endl;
	cout << VERT << left << setw(WIDTH) << " 3. Sua Que Quan Sinh Vien" << VERT << endl;
	cout << VERT << left << setw(WIDTH) << " 4. Sua Ngay Sinh cua Sinh Vien" << VERT << endl;

	// --- Đường phân cách giữa tùy chọn và Thoát ---
	cout << VERT << setfill('-') << setw(WIDTH) << "" << VERT << endl;

	// --- Thoát (Exit) ---
	cout << VERT << setfill(' ') << left << setw(WIDTH) << " 0. Thoat" << VERT << endl;

	// --- Khung dưới (Bottom Border) ---
	cout << setfill(HORZ) << setw(WIDTH + 2) << "" << endl;

	cout << "\nHay nhap lua chon cua ban: ";
	cout << setfill(' '); // Trả lại fill mặc định
}
// Hàm hiển thị menu (cần định nghĩa)
void showBasicMenu() {
	cout << "\n================= MENU QUAN LY SINH VIEN (AVL) =================";
	cout << "\n| 1. Them sinh vien ngau nhien (Insert)                        |";
	cout << "\n| 2. Them sinh vien vao danh sach (Insert)                     |";
	cout << "\n| 3. Xoa sinh vien theo MSSV (Delete)                          |";
	cout << "\n| 4. Sua thong tin sinh vien (Update)                          |";
	cout << "\n| 5. Cap nhat diem mon hoc (Update)                            |";
	cout << "\n| 6. Tim kiem sinh vien theo MSSV (Search)                     |";
	cout << "\n| 7. Xuat thong tin sinh vien ra Console (LNR)                 |";
	cout << "\n| 8. Xuat danh sach sinh vien (LNR)			       |";
	cout << "\n| 9. Xuat bang diem mon hoc cua SV theo MSSV                   |";
	cout << "\n| 10. Loc sinh vien theo diem GPA toi thieu                    |";
	cout << "\n| 0. Thoat chuong trinh                                        |";
	cout << "\n================================================================";
	cout << "\nHay nhap lua chon cua ban. ";
}
void switchCaseForChoice(AVLTree& DSSV) {

	int choice = -1;
	do {
		system("cls");
		showBasicMenu();
		cout << "\nVui long nhap lua chon cua ban: ";
		if (!(cin >> choice)) { // nếu cin ko hợp lệ
			cin.clear(); // reset báo lỗi cin
			cin.ignore(numeric_limits<streamsize>::max(), '\n'); // dọn rác mà người dùng nhập sai
			choice = -1; // Đặt giá trị không hợp lệ - default value
		}
		else {
			// Trường hợp người dùng nhập SỐ thành công (ví dụ: 1, 5, 0)
			// Chúng ta vẫn cần xóa ký tự '\n' (phím Enter) còn lại
			// để các hàm (ví dụ: getline) sau đó không bị lỗi
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
		cout << endl; // Thêm 1 dòng trống cho dễ đọc

		switch (choice) {
		case MENU_INSERT_RANDOM: {
			system("cls");
			cout << "[Chuc nang 1: Them sinh vien ngau nhien vao danh sach]" << endl;
			SinhVien sv;
			sv.taoNgauNhienDuLieuSinhVien();
			sv.taoDanhSachMonHoc();
			sv.taoMaSV();
			DSSV.insertSV(sv);
			cout << "Da them thanh cong SV voi MSSV: " << sv.getMaSV() << endl;
			system("pause"); // Dọn màn hình trước khi xử lý
			break;
		}
		case MENU_INSERT: {
			system("cls");
			cout << "[Chuc nang 2: Them sinh vien vao danh sach]" << endl;
			SinhVien sv;
			sv.nhapThongTinSinhVien();
			bool result = DSSV.insertSV(sv);
			if (result) {
				cout << "Da them thanh cong SV voi MSSV: " << sv.getMaSV() << endl;
			}
			else {
				cout << "Da co sinh vien voi MSSV: " << sv.getMaSV() << " trong danh sach" << endl;
			}
			system("pause");
			break;
		}
		case MENU_DELETE_STUDENT: {
			system("cls");
			cout << "[Chuc nang 3: Xoa sinh vien theo ma so sinh vien]" << endl;
			SinhVien sv;
			cout << "Nhap ma sinh vien ma ban muon xoa: ";
			string maCanTim; cin >> maCanTim;
			bool result = DSSV.deleteSV((maCanTim));
			if (result) {
				cout << "Da xoa thanh cong SV voi MSSV: " << maCanTim << endl;
			}
			else {
				cout << "Khong tim thay sinh vien voi MSSV: " << maCanTim << " trong danh sach" << endl;
			}


			system("pause"); // Dọn màn hình trước khi xử lý
			break;
		}
		case MENU_SEARCH: {
			system("cls");
			cout << "[Chuc nang 6: Tim sinh vien trong danh sach theo tu khoa]" << endl;
			string keyword;
			cout << "\n Nhap tu khoa ma ban muon tim: ";
			getline(cin, keyword);
			system("cls");
			bool isEmpty = true;
			std::vector<SinhVien> danhSachSV;
			danhSachSV = DSSV.locSinhVienTheoTuKhoa(keyword, isEmpty);
			if (isEmpty) {
				cout << "\nKhong co sinh vien voi tu khoa " << keyword << " ma ban tim!";
			}
			cout << "\n Ban co muon in danh sach sinh vien vao file hay khong?" << endl;
			cout << "YES/NO: ";
			std::string choice;
			getline(cin, choice);
			string choice_chuyenDoi = chuyenChuHoaThanhChuThuong(choice);
			// nếu người dùng chọn có
			if (choice == "yes") {
				
				string tenFile = "Filter_Data_Directory/Danh_Sach_SV.txt";
				// bắt đầu in ra file
				inDanhSachSinhVienRaFile_Vector(danhSachSV, tenFile);
				cout << "\nGhi file thanh cong, file duoc luu tai " << tenFile << endl;
			}
			system("pause"); // Dọn màn hình trước khi xử lý
			break;
		}
		case MENU_PRINT_DSSV: {
			system("cls");
			cout << "[Chuc nang 8: Xuat danh sach sinh vien]" << endl;
			DSSV.xuatDanhSachSinhVienTheoThuTuTangDanMSSV();
			cout << endl;
			system("pause"); // Dọn màn hình trước khi xử lý
			break;
		}
		case MENU_UPDATE_INFO_STUDENT: {
			system("cls");
			cout << "[Chuc nang 4: Sua thong tin sinh vien]" << endl;

			string maCanTim;
			cout << "\nNhap ma sinh vien ma ban muon cap nhat: ";

			// 1. NHẬP VÀ TÌM KIẾM (Chỉ thực hiện 1 lần)
			cin >> maCanTim;
			cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Xóa bộ đệm

			NodePtr p = DSSV.search(maCanTim);

			if (p == nullptr) {
				// Sinh viên không tồn tại, kết thúc chức năng ngay lập tức
				cout << "\nKhong co sinh vien co ma so " << maCanTim << " trong danh sach!" << endl;
				system("pause");
				break; // Thoát khỏi case MENU_UPDATE_INFO_STUDENT
			}

			// 2. NẾU TÌM THẤY: Bắt đầu vòng lặp menu cập nhật chi tiết
			// Sử dụng tham chiếu (&) để cập nhật trực tiếp dữ liệu trong node p
			SinhVien& sv = p->data;
			int choice_update_menu = -1; // Khởi tạo khác 0

			do {
				system("cls");
				cout << "\n==================================================================";
				cout << "\nCAP NHAT THONG TIN CHO SINH VIEN CO MA SO " << maCanTim << endl;
				cout << "Thong tin hien tai:" << endl;
				sv.inThongTinSinhVien(); // In thông tin hiện tại
				menuUpdateStudent(); // Hiển thị menu tùy chọn
				cout << "\nVui long nhap lua chon cua ban: ";

				// Xử lý nhập liệu
				if (!(cin >> choice_update_menu)) {
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
					choice_update_menu = -1;
				}
				else {
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
				}
				cout << endl;

				// 3. XỬ LÝ LỰA CHỌN CẬP NHẬT
				switch (choice_update_menu) {
				case 1: { // Sửa tên sinh viên
					string tenMoi;
					cout << "Nhap ten moi cho sinh vien: ";
					getline(cin, tenMoi);
					sv.setTenSV(tenMoi);
					cout << "Cap nhat ten sinh vien co ma " << maCanTim << " thanh cong!" << endl;
					system("pause");
					break;
				}
				case 2: { // Sửa mã số sinh viên
					// *LƯU Ý QUAN TRỌNG: KHÔNG THỂ CẬP NHẬT TRỰC TIẾP KHÓA (MSSV) TRONG CÂY AVL.*
					// Nếu muốn thay đổi khóa, bạn phải: 1. Xóa SV cũ. 2. Thêm SV mới.
					cout << "CHU Y: Viec cap nhat Ma Sinh Vien (Key) trong cay AVL rat phuc tap." << endl;
					cout << "Vui long su dung chuc nang XOA va THEM MOI neu muon doi Ma SV." << endl;
					system("pause");
					break;
				}
				case 3: { // Sửa quê quán
					string queQuanMoi;
					cout << "Nhap que quan moi cho sinh vien: ";
					getline(cin, queQuanMoi); // Nên dùng getline nếu quê quán có dấu cách
					sv.setQueQuan(queQuanMoi);
					cout << "Cap nhat que quan thanh cong!" << endl;
					system("pause");
					break;
				}
				case 4: { // Sửa ngày sinh
					string ngaySinhMoi;
					cout << "Nhap ngay sinh moi (dd/mm/yyyy): ";
					cin >> ngaySinhMoi; // Giả sử ngày sinh không có khoảng trắng
					sv.setNgaySinh(ngaySinhMoi); // **SỬA LỖI: gọi setNgaySinh**
					cout << "Cap nhat ngay sinh thanh cong!" << endl;
					system("pause");
					break;
				}
				case 0: {
					cout << "Hoan tat cap nhat. Quay lai menu chinh." << endl;
					system("pause");
					break; // Thoát vòng lặp do-while
				}
				default: {
					cout << "Lua chon khong hop le. Vui long chon lai." << endl;
					system("pause");
				}
				}
			} while (choice_update_menu != 0);

			break; // Thoát khỏi case MENU_UPDATE_INFO_STUDENT
		}
		case MENU_UPDATE_DIEM: {
			system("cls");
			cout << "[Chuc nang 5: Cap nhat diem cho sinh vien]" << endl;

			string maCanTim, maMonCapNhat;
			double diemMoi;

			cout << "\nNhap ma sinh vien ma ban muon cap nhat: ";
			cin >> maCanTim;

			// Xóa bộ đệm sau cin >> maCanTim (cần cho getline tiếp theo)
			cin.ignore(numeric_limits<streamsize>::max(), '\n');

			NodePtr p = DSSV.search(maCanTim);

			if (p == nullptr) {
				cout << "\nKhong co sinh vien co ma so " << maCanTim << " trong danh sach!" << endl;
				system("pause");
				break;
			}

			SinhVien& sv = p->data; // Lấy tham chiếu đến đối tượng SinhVien gốc

			// Đảm bảo getHoTenSV() là const
			cout << "\n=> Thong tin Sinh Vien: " << sv.getMaSV() << " - " << sv.getHoTenSV() << endl;
			sv.xuatMonHocCuaSinhVien(sv);
			cout << endl;

			// --- BẮT ĐẦU CẬP NHẬT ---
			cout << "\n------------------------------------------------------";
			cout << "\nNhap Ma Mon Hoc can cap nhat: ";
			getline(cin, maMonCapNhat);

			do {
				cout << "Nhap Diem moi (Thang 10, tu 0.0 den 10.0): ";

				if (!(cin >> diemMoi)) {
					// Lỗi nhập ký tự
					cout << "\nLoi: Du lieu diem phai la so. Thu lai!";
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
				}
				else if (diemMoi < 0.0 || diemMoi > 10.0) {
					// Lỗi nhập ngoài phạm vi
					cout << "\nLoi: Diem phai nam trong khoang 0.0 den 10.0. Thu lai!";
				}
				else {
					// Điểm hợp lệ
					break;
				}
			} while (true);

			// Cập nhật điểm và tính lại GPA
			DSSV.updateDiemSV(diemMoi, maCanTim, maMonCapNhat);

			cout << "\n--- KET QUA SAU KHI CAP NHAT ---" << endl;

			// Gọi hàm tính GPA mới nhất
			cout << "GPA hien tai: " << std::fixed << std::setprecision(2) << sv.tinhDiemGPA() << endl;
			cout << "Xep loai moi: " << sv.chuyenDoiSangXepLoai() << endl;

			system("pause");
			break;
		}



		default: {
			if (choice != -1) {
				cout << "Lua chon khong ton tai. Vui long chon lai." << endl;
			}
			else {
				cout << "Loi nhap lieu. Vui long nhap mot so nguyen hop le." << endl;
			}
			system("pause"); // TẠM DỪNG
			break;
		}
		}

	} while (choice != MENU_EXIT);
}


