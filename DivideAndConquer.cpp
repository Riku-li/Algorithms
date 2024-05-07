// Ricardo Jiménez Ureña A01636825
// https://www.programiz.com/dsa/merge-sort
// Merge sort in C++

#include <iostream>
using namespace std;

void merge(double arr[], int p, int q, int r) {
  
  int n1 = q - p + 1;
  int n2 = r - q;

  double L[n1], M[n2];

  for (int i = 0; i < n1; i++)
    L[i] = arr[p + i];
  for (int j = 0; j < n2; j++)
    M[j] = arr[q + 1 + j];

  int i, j, k;
  i = 0;
  j = 0;
  k = p;

  // Complexity: O(N) where N is the number of elements being merged.
  while (i < n1 && j < n2) {
    if (L[i] >= M[j]) {
      arr[k] = L[i];
      i++;
    } else {
      arr[k] = M[j];
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
    arr[k] = M[j];
    j++;
    k++;
  }
}

void mergeSort(double arr[], int l, int r) {
  if (l < r) {
    int m = l + (r - l) / 2;

    mergeSort(arr, l, m);
    mergeSort(arr, m + 1, r);

    merge(arr, l, m, r);
  }
  // Overall Complexity: O(N log N) where N is the number of elements.
}

void printArray(double arr[], int size) {
  // Complexity: O(N) where N is the number of elements.
  for (int i = 0; i < size; i++)
    cout << arr[i] << " ";
  cout << endl;
}

int main() {
    int N;
    
    cout << "Enter the number of double values you will provide: ";
    cin >> N;

    double arr[N];
    
    cout << "Enter " << N << " double values, one per line:" << endl;
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    mergeSort(arr, 0, N - 1);

    cout << "Sorted array: \n";
    printArray(arr, N);
    return 0;
}
