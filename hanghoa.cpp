#include <iostream>
#include <iomanip>
#include <cstring>

using namespace std;

// Khai b�o c?u tr�c d? li?u cho h�ng h�a
struct HangHoa {
    char maHang[20];
    char tenHang[50];
    int soLuong;
};

struct Node {
    HangHoa data;
    Node* next;
};

typedef Node* Tro;

// H�m kh?i t?o danh s�ch r?ng
void initializer(Tro& L) {
    L = NULL;
}

// H�m ki?m tra danh s�ch r?ng
bool isEmpty(Tro L) {
    return L == NULL;
}

// H�m nh?p th�ng tin h�ng h�a
void nhapHangHoa(HangHoa& hh) {
    cout << "Nhap ma hang: ";
    cin.ignore();
    cin.getline(hh.maHang, 20);
    cout << "Nhap ten hang: ";
    cin.getline(hh.tenHang, 50);
    cout << "Nhap so luong: ";
    cin >> hh.soLuong;
}

// H�m nh?p danh s�ch h�ng h�a
void nhapDS(Tro& L) {
    initializer(L);
    int n;
    cout << "Nhap so luong mat hang (tu 3 tro len): ";
    cin >> n;

    if (n < 3) {
        cout << "So luong mat hang phai tu 3 tro len!" << endl;
        return;
    }

    for (int i = 0; i < n; i++) {
        HangHoa hh;
        cout << "Nhap thong tin mat hang thu " << i + 1 << ":" << endl;
        nhapHangHoa(hh);

        Node* P = new Node;
        P->data = hh;
        P->next = L;
        L = P; // Th�m h�ng h�a v�o d?u danh s�ch
    }
}

// H�m xu?t danh s�ch h�ng h�a
void xuatDS(Tro L) {
    if (isEmpty(L)) {
        cout << "Danh sach rong." << endl;
        return;
    }

    cout << setw(5) << "STT"
         << setw(20) << "Ma Hang"
         << setw(30) << "Ten Hang"
         << setw(10) << "So Luong" << endl;

    int i = 1;
    for (Tro Q = L; Q != NULL; Q = Q->next) {
        cout << setw(5) << i++
             << setw(20) << Q->data.maHang
             << setw(30) << Q->data.tenHang
             << setw(10) << Q->data.soLuong << endl;
    }
}

// H�m hi?n th? m?t h�ng c� s? lu?ng l?n nh?t
void hienThiMax(Tro L) {
    if (isEmpty(L)) {
        cout << "Danh sach rong." << endl;
        return;
    }

    int maxSoLuong = 0;
    for (Tro Q = L; Q != NULL; Q = Q->next) {
        if (Q->data.soLuong > maxSoLuong) {
            maxSoLuong = Q->data.soLuong;
        }
    }

    cout << "Mat hang co so luong lon nhat (" << maxSoLuong << "):" << endl;
    for (Tro Q = L; Q != NULL; Q = Q->next) {
        if (Q->data.soLuong == maxSoLuong) {
            cout << "Ma Hang: " << Q->data.maHang << ", Ten Hang: " << Q->data.tenHang
                 << ", So Luong: " << Q->data.soLuong << endl;
        }
    }
}

// H�m x�a m?t h�ng c� s? lu?ng l?n nh?t
void xoaMax(Tro& L) {
    if (isEmpty(L)) return;

    int maxSoLuong = 0;
    for (Tro Q = L; Q != NULL; Q = Q->next) {
        if (Q->data.soLuong > maxSoLuong) {
            maxSoLuong = Q->data.soLuong;
        }
    }

    Tro prev = NULL, Q = L;
    while (Q != NULL) {
        if (Q->data.soLuong == maxSoLuong) {
            if (prev == NULL) {
                L = Q->next;
            } else {
                prev->next = Q->next;
            }
            Tro temp = Q;
            Q = Q->next;
            delete temp;
        } else {
            prev = Q;
            Q = Q->next;
        }
    }
    cout << "Da xoa tat ca mat hang co so luong lon nhat." << endl;
}

// H�m ch�n m?t h�ng m?i v�o tru?c m?t h�ng th? hai
void chenHangHoa(Tro& L, HangHoa hh) {
    Node* P = new Node;
    P->data = hh;
    P->next = NULL;

    if (isEmpty(L) || L->next == NULL) {
        cout << "Danh sach khong du 2 phan tu de chen." << endl;
        delete P;
        return;
    }

    P->next = L->next;
    L->next = P;
    cout << "Da chen mat hang moi vao truoc mat hang thu hai." << endl;
}

int main() {
    Tro ds;
    nhapDS(ds);
    xuatDS(ds);

    cout << "\nHien thi mat hang co so luong lon nhat:" << endl;
    hienThiMax(ds);

    cout << "\nXoa mat hang co so luong lon nhat:" << endl;
    xoaMax(ds);
    xuatDS(ds);

    HangHoa hh;
    cout << "\nNhap thong tin mat hang moi de chen:" << endl;
    nhapHangHoa(hh);
    chenHangHoa(ds, hh);

    cout << "\nDanh sach sau khi chen:" << endl;
    xuatDS(ds);

    return 0;
}

