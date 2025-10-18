#include "thuvien.h"
int main() {
    // Điều này đảm bảo mỗi lần chạy chương trình sẽ có kết quả khác nhau


    //SinhVien sv[8100]; // nếu dùng mảng thì
    AVLTree dsSV;
    for (int i = 0;i < 10;i++) {
        SinhVien sv; // tạo 1 đối tượng sinh viên
        sv.taoNgauNhienDuLieuSinhVien(); // nhập ngẫu nhiên thông tin sinh viên
        dsSV.insert(sv);
    }
    printHeader();
    dsSV.NLR();
   // delete[] sv;
    return 0;
}