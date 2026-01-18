#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

void bubbleSort(vector<int> &arr) {
  int n = arr.size();
  for (int i = 0; i < n - 1; i++) {
    for (int j = 0; j < n - i - 1; j++) {
      if (arr[j] > arr[j + 1]) {
        swap(arr[j], arr[j + 1]);
      }
    }
  }
}

void quickSort(vector<int> &arr, int low, int high) {
  if (low < high) {
    int pivot = arr[high];
    int i = (low - 1);
    for (int j = low; j < high; j++) {
      if (arr[j] < pivot) {
        i++;
        swap(arr[i], arr[j]);
      }
    }
    swap(arr[i + 1], arr[high]);
    int pi = i + 1;

    quickSort(arr, low, pi - 1);
    quickSort(arr, pi + 1, high);
  }
}

void selectionSort(vector<int> &arr) {
  int n = arr.size();
  for (int i = 0; i < n - 1; i++) {
    int min_idx = i;
    for (int j = i + 1; j < n; j++) {
      if (arr[j] < arr[min_idx]) {
        min_idx = j;
      }
    }
    swap(arr[min_idx], arr[i]);
  }
}

void insertionSort(vector<int> &arr) {
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

void heapify(vector<int> &arr, int n, int i) {
  int largest = i;
  int left = 2 * i + 1;
  int right = 2 * i + 2;

  if (left < n && arr[left] > arr[largest])
    largest = left;

  if (right < n && arr[right] > arr[largest])
    largest = right;

  if (largest != i) {
    swap(arr[i], arr[largest]);
    heapify(arr, n, largest);
  }
}

void heapSort(vector<int> &arr) {
  int n = arr.size();
  for (int i = n / 2 - 1; i >= 0; i--) {
    heapify(arr, n, i);
  }
  for (int i = n - 1; i > 0; i--) {
    swap(arr[0], arr[i]);
    heapify(arr, i, 0);
  }
}

void merge(vector<int> &arr, int left, int mid, int right) {
  int n1 = mid - left + 1;
  int n2 = right - mid;

  vector<int> L(n1), R(n2);

  for (int i = 0; i < n1; i++)
    L[i] = arr[left + i];
  for (int j = 0; j < n2; j++)
    R[j] = arr[mid + 1 + j];

  int i = 0, j = 0, k = left;
  while (i < n1 && j < n2) {
    if (L[i] <= R[j]) {
      arr[k] = L[i];
      i++;
    } else {
      arr[k] = R[j];
      j++;
    }
    k++;
  }

  while (i < n1) {
    arr[k] = L[i];
    i++;
    k++;
  }

  while (j < n2) {
    arr[k] = R[j];
    j++;
    k++;
  }
}

void mergeSort(vector<int> &arr, int left, int right) {
  if (left < right) {
    int mid = left + (right - left) / 2;
    mergeSort(arr, left, mid);
    mergeSort(arr, mid + 1, right);
    merge(arr, left, mid, right);
  }
}

int main() {
  vector<int> arr = {64, 34, 25, 12, 22, 11, 90};

  cout << "Original array: ";
  for (int num : arr) {
    cout << num << " ";
  }
  cout << endl;

  vector<int> arr1 = arr;
  bubbleSort(arr1);
  cout << "Sorted array using Bubble Sort: ";
  for (int num : arr1) {
    cout << num << " ";
  }
  cout << endl;

  vector<int> arr2 = arr;
  quickSort(arr2, 0, arr2.size() - 1);
  cout << "Sorted array using Quick Sort: ";
  for (int num : arr2) {
    cout << num << " ";
  }
  cout << endl;

  vector<int> arr3 = arr;
  selectionSort(arr3);
  cout << "Sorted array using Selection Sort: ";
  for (int num : arr3) {
    cout << num << " ";
  }
  cout << endl;

  vector<int> arr4 = arr;
  insertionSort(arr4);
  cout << "Sorted array using Insertion Sort: ";
  for (int num : arr4) {
    cout << num << " ";
  }
  cout << endl;

  vector<int> arr5 = arr;
  heapSort(arr5);
  cout << "Sorted array using Heap Sort: ";
  for (int num : arr5) {
    cout << num << " ";
  }
  cout << endl;

  vector<int> arr6 = arr;
  mergeSort(arr6, 0, arr6.size() - 1);
  cout << "Sorted array using Merge Sort: ";
  for (int num : arr6) {
    cout << num << " ";
  }
  cout << endl;

  return 0;
}
