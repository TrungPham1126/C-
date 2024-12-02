#include <iostream>
#include <iomanip>
#include <cstring>

using namespace std;

// Khai b�o c?u tr�c d? li?u cho sinh vi�n
struct SinhVien {
    char hodem[20];
    char ten[10];
    char gioitinh[10];
    float diemTK;
};

struct Node {
    SinhVien data;
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

// H�m nh?p th�ng tin sinh vi�n
void nhapSinhVien(SinhVien& sv) {
    cout << "Nhap ho dem: ";
    cin.ignore();
    cin.getline(sv.hodem, 20);
    cout << "Nhap ten: ";
    cin.getline(sv.ten, 10);
    cout << "Nhap gioi tinh (Nam/Nu): ";
    cin.getline(sv.gioitinh, 10);
    cout << "Nhap diem tong ket: ";
    cin >> sv.diemTK;
}

// H�m nh?p danh s�ch sinh vi�n
void nhapDS(Tro& L) {
    initializer(L);
    int n;
    cout << "Nhap so luong sinh vien (tu 3 tro len): ";
    cin >> n;

    if (n < 3) {
        cout << "So luong sinh vien phai tu 3 tro len!" << endl;
        return;
    }

    for (int i = 0; i < n; i++) {
        SinhVien sv;
        cout << "Nhap thong tin sinh vien thu " << i + 1 << ":" << endl;
        nhapSinhVien(sv);

        Node* P = new Node;
        P->data = sv;
        P->next = L;
        L = P; // Th�m sinh vi�n v�o d?u danh s�ch
    }
}

// H�m xu?t danh s�ch sinh vi�n
void xuatDS(Tro L) {
    if (isEmpty(L)) {
        cout << "Danh sach rong." << endl;
        return;
    }

    cout << setw(5) << "STT"
         << setw(20) << "Ho dem"
         << setw(10) << "Ten"
         << setw(10) << "Gioi tinh"
         << setw(15) << "Diem TK" << endl;

    int i = 1;
    for (Tro Q = L; Q != NULL; Q = Q->next) {
        cout << setw(5) << i++
             << setw(20) << Q->data.hodem
             << setw(10) << Q->data.ten
             << setw(10) << Q->data.gioitinh
             << setw(15) << Q->data.diemTK << endl;
    }
}

// H�m t�m ki?m sinh vi�n theo t�n
void timSinhVien(Tro L, const char* ten) {
    cout << "Ket qua tim kiem sinh vien co ten '" << ten << "':" << endl;
    bool found = false;

    for (Tro Q = L; Q != NULL; Q = Q->next) {
        if (strcmp(Q->data.ten, ten) == 0) {
            cout << "Ho dem: " << Q->data.hodem << ", Ten: " << Q->data.ten
                 << ", Gioi tinh: " << Q->data.gioitinh << ", Diem TK: " << Q->data.diemTK << endl;
            found = true;
        }
    }

    if (!found) {
        cout << "Khong tim thay sinh vien co ten '" << ten << "'." << endl;
    }
}

// H�m x�a sinh vi�n theo t�n
void xoaSinhVien(Tro& L, const char* ten) {
    if (isEmpty(L)) return;

    Tro Q = L, prev = NULL;
    while (Q != NULL && strcmp(Q->data.ten, ten) != 0) {
        prev = Q;
        Q = Q->next;
    }

    if (Q != NULL) { // N?u t�m th?y sinh vi�n
        if (prev == NULL) {
            L = Q->next; // X�a d?u danh s�ch
        } else {
            prev->next = Q->next; // X�a gi?a ho?c cu?i danh s�ch
        }
       delete Q; // Gi?i ph�ng b? nh?
        cout << "Da xoa sinh vien co ten '" << ten << "'." << endl;
    } else {
        cout << "Khong tim thay sinh vien co ten '" << ten << "' de xoa." << endl;
    }
}

// H�m ch�n sinh vi�n m?i v�o tru?c sinh vi�n th? 3 theo chi?u tang d?n c?a di?m t?ng k?t
void chenSinhVien(Tro& L, SinhVien sv) {
    Node* P = new Node;
    P->data = sv;
    P->next = NULL;

    if (isEmpty(L)) {
        L = P;
        return;
    }

    Tro Q = L, prev = NULL;
    int count = 1;

    while (Q != NULL && count < 3) {
        prev = Q;
        Q = Q->next;
        count++;
    }

    if (count == 3) {
        P->next = Q; // Ch�n v�o tru?c sinh vi�n th? 3
        if (prev != NULL) {
            prev->next = P;
        } else {
            L = P; // N?u danh s�ch ch? c� 2 sinh vi�n
        }
    } else {
        cout << "Danh sach khong co du 3 sinh vien de chen." << endl;
        delete P; // Gi?i ph�ng b? nh? n?u kh�ng ch�n
    }
}

int main() {
    Tro dssv;
    nhapDS(dssv);
    xuatDS(dssv);

    char ten[10];
    cout << "Nhap ten sinh vien can tim: ";
    cin.ignore();
    cin.getline(ten, 10);
    timSinhVien(dssv, ten);

    cout << "Xoa sinh vien co ten '" << ten << "'." << endl;
    xoaSinhVien(dssv, ten);
    xuatDS(dssv);

    SinhVien sv;
    cout << "Nhap thong tin sinh vien moi de chen:" << endl;
    nhapSinhVien(sv);
    chenSinhVien(dssv, sv);
    cout << "Danh sach sau khi chen:" << endl;
    xuatDS(dssv);

    return 0;
} 
