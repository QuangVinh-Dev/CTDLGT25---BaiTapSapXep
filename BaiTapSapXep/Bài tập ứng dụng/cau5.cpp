#include <iostream>

using namespace std;

const int MAX_M = 100, MAX_N = 100;  
 // Hàm tính tổng một dòng trong ma trận

int sum_of_row(int A[][MAX_N], int row, int n) {
    int sum = 0;
    for (int j = 0; j < n; j++) {
        sum += A[row][j];  
    }
    return sum;
}

void swap_rows(int A[][MAX_N], int row1, int row2, int n) {
    for (int j = 0; j < n; j++) {
        swap(A[row1][j], A[row2][j]);  
    }
}

// Sắp xếp các dòng theo tổng giảm dần (Insertion Sort)
void sort_rows_by_sum(int A[][MAX_N], int m, int n) {
    for (int i = 1; i < m; i++) {
        int key_sum = sum_of_row(A, i, n); 
        int j = i - 1;

        
        while (j >= 0 && sum_of_row(A, j, n) < key_sum) {
            swap_rows(A, j, j + 1, n);
            j--;
        }
    }
}

void print_matrix(int A[][MAX_N], int m, int n) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cout << A[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    int m = 3, n = 4;  
    int A[MAX_M][MAX_N] = { 
        {4, 2, 7, 1},  
        {8, 3, 5, 6},  
        {1, 9, 2, 3}  
    };

    cout << "Ma trận ban đầu:\n";
    print_matrix(A, m, n);

    // Sắp xếp dòng theo tổng giảm dần (Insertion Sort)
    sort_rows_by_sum(A, m, n);
    cout << "Ma trận sau khi sắp xếp theo tổng dòng giảm dần:\n";
    print_matrix(A, m, n);

    return 0;
}
