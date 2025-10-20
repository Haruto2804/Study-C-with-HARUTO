#include "thuvien.h"
int main() {
    AVLTree DSSV;

    for (int i = 0;i < 70;i++) {
        int stt = i+1;
        SinhVien sv;
        sv.taoMaSV();
        DSSV.insertSV(sv);
        sv.ghiBangDiemSinhVien("DH52300151.txt");
    }
    DSSV.xuatDanhSachSinhVienTheoThuTuTangDanMSSV();
    return 0;
}