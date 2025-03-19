#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

// Hàm tạo mảng ngẫu nhiên
void generateRandomArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % (size * 10);  // Số ngẫu nhiên từ 0 đến size*10
    }
}

// Quick Sort
int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

// Merge Sort
void merge(int arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;
    
    int* L = new int[n1];
    int* R = new int[n2];
    
    for (int i = 0; i < n1; i++) L[i] = arr[left + i];
    for (int i = 0; i < n2; i++) R[i] = arr[mid + 1 + i];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) arr[k++] = L[i++];
        else arr[k++] = R[j++];
    }
    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];
    
    delete[] L;
    delete[] R;
}

void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

// Heap Sort
void heapify(int arr[], int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    if (left < n && arr[left] > arr[largest]) largest = left;
    if (right < n && arr[right] > arr[largest]) largest = right;
    if (largest != i) {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

void heapSort(int arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--) heapify(arr, n, i);
    //doi cho node dau tien voi node cuoi cung
    for (int i = n - 1; i > 0; i--) {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}

// Hàm đo thời gian chạy
void measureSortingTime(int size) {
    int* arr = new int[size];
    generateRandomArray(arr, size);

    clock_t start, end;
    double quickTime, mergeTime, heapTime;

    // Quick Sort
    int* arr1 = new int[size];
    copy(arr, arr + size, arr1);
    start = clock();
    quickSort(arr1, 0, size - 1);
    end = clock();
    quickTime = double(end - start) / CLOCKS_PER_SEC;
    delete[] arr1;

    // Merge Sort
    int* arr2 = new int[size];
    copy(arr, arr + size, arr2);
    start = clock();
    mergeSort(arr2, 0, size - 1);
    end = clock();
    mergeTime = double(end - start) / CLOCKS_PER_SEC;
    delete[] arr2;

    // Heap Sort
    int* arr3 = new int[size];
    copy(arr, arr + size, arr3);
    start = clock();
    heapSort(arr3, size);
    end = clock();
    heapTime = double(end - start) / CLOCKS_PER_SEC;
    delete[] arr3;

    // Kết quả
    cout << "Size: " << size 
         << " | QuickSort: " << quickTime << "s"
         << " | MergeSort: " << mergeTime << "s"
         << " | HeapSort: " << heapTime << "s" << endl;
        delete[] arr;
    
}



int main() {
    srand(time(0));

    int sizes[] = {1000, 5000, 10000, 50000, 100000};
    cout << "Measuring sorting time...\n";

    for (int i = 0; i < 5; i++) {
        measureSortingTime(sizes[i]);
    }

    return 0;
}
