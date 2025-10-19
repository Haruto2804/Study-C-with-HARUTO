#include "thuvien.h"
int main() {
    AVLTree DSSV;
    for (int i = 0;i < 10;i++) {
        SinhVien sv;
        DSSV.insertSV(sv);
        
    }
    DSSV.xuatDanhSachMonHocTheoMaSV("DH52300003");
    DSSV.NLR();
    return 0;
}