#include <iostream>
#include <vector>
#include <algorithm> 

using namespace std;

void bubbleSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

void selectionSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        int minIdx = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIdx]) {
                minIdx = j;
            }
        }
        swap(arr[i], arr[minIdx]);
    }
}

void insertionSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

int main() {
    vector<int> arr = {39, 8, 5, 1, 3, 6, 9, 12, 4, 7, 10};
    vector<int> arrCopy;

    // Bubble Sort
    arrCopy = arr; // Copy the original array
    bubbleSort(arrCopy);
    cout << "Bubble Sort: ";
    for (int num : arrCopy) {
        cout << num << " ";
    }
    cout << endl;

    // Selection Sort
    arrCopy = arr; // Copy the original array
    selectionSort(arrCopy);
    cout << "Selection Sort: ";
    for (int num : arrCopy) {
        cout << num << " ";
    }
    cout << endl;

    // Insertion Sort
    arrCopy = arr; // Copy the original array
    insertionSort(arrCopy);
    cout << "Insertion Sort: ";
    for (int num : arrCopy) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
