#include <iostream>

using namespace std;

// Định nghĩa struct SoHang để lưu số hạng của đa thức
struct SoHang {
    double heSo; // Hệ số
    int bac;     // Bậc
};

// Hàm hoán vị hai số hạng (đổi chỗ)
void swap(SoHang &a, SoHang &b) {
    SoHang temp = a;
    a = b;
    b = temp;
}

// Hàm sắp xếp theo bậc tăng dần (Interchange Sort)
void interchangeSort(SoHang arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i].bac > arr[j].bac) { 
                swap(arr[i], arr[j]); 
            }
        }
    }
}

int main() {
    // Mảng chứa các số hạng của đa thức
    SoHang daThuc[] = {
        {3.5, 2}, {1.2, 5}, {4.0, 3}, {2.1, 0}, {5.6, 1}
    };
    int size = sizeof(daThuc) / sizeof(daThuc[0]);

    // Gọi hàm sắp xếp
    interchangeSort(daThuc, size);

    // In kết quả sau khi sắp xếp
    cout << "Da sap xep theo bac:\n";
    for (int i = 0; i < size; i++) {
        cout << daThuc[i].heSo << "x^" << daThuc[i].bac << endl;
    }

    return 0;
}
