#include "thuvien.h"
// Hàm này sẽ tự động in ra danh sách từ vector
void showBasicMenu() {
    // --- Tiêu đề ---
    cout << "\n======================================================\n";
    cout << "          MENU QUAN LY SINH VIEN (AVL TREE)           \n";
    cout << "======================================================\n";

    // --- Các lựa chọn ---
    cout << " 1. Them sinh vien moi\n";
    cout << " 2. Xoa sinh vien\n";
    cout << " 3. Tim kiem sinh vien theo Ma SV\n";
    cout << " 3. Cap nhat lai thong tin cho sinh vien\n";
    cout << " 4. Cap nhat Diem TK mon hoc\n";
    cout << " 5. Reset toan bo Diem mon hoc\n";
    cout << " 6. Cap nhat Thong tin sinh vien (Ten, NS, QQ)\n";
    cout << " 7. In danh sach SV theo Ma SV (Tang dan)\n";
    cout << " 8. In danh sach SV theo thu tu nguyen thuy\n";
    cout << " 9. Xuat Danh sach Mon Hoc cua mot SV\n";
    cout << " 10. Tinh va In Diem Trung Binh (GPA)\n";
    cout << " 11. Xóa toàn bộ danh sách sinh viên\n";
    cout << " 12. Ghi danh sach SV ra file\n";

    cout << "------------------------------------------------------\n";

    cout << " 0. Thoat chuong trinh\n";

    cout << "======================================================\n";
    cout << "Nhap lua chon cua ban (0-11): ";
}