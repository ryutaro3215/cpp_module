#include <iostream>
#include <vector>
using namespace std;

void merge(vector<int>& A, int left, int mid, int right) {
    int n1 = mid - left;
    int n2 = right - mid;

    vector<int> L(A.begin() + left, A.begin() + mid);
    vector<int> R(A.begin() + mid, A.begin() + right);

    /* for (int i = 0; i < n1; i++) { */
    /*     cout << "L[i] = " << L[i] << endl; */
    /* } */
    /* for (int j = 0; j < n2; j++) { */
    /*     cout << "R[j] = " << R[j] << endl; */
    /* } */
    int i = 0, j = 0;
    for (int k = left; k < right; k++) {
        if (i < n1 && (j >= n2 || L[i] <= R[j])) {
            A[k] = L[i++];
        } else {
            A[k] = R[j++];
        }
    }
}

void mergeSort(vector<int>& A, int left, int right) {
    if (right - left <= 1) return;
    int mid = (left + right) / 2;
    mergeSort(A, left, mid);
    mergeSort(A, mid, right);
    merge(A, left, mid, right);
}

int binarySearch(const vector<int>& A, int key, int left, int right) {
    while (left < right) {
        int mid = (left + right) / 2;
        if (key< A[mid])
            right = mid;
        else 
            left = mid + 1;
    }
    return left;
}

void binaryInsertionSort(vector<int> &A) {
    int n = A.size();

    for (int i = 1; i < n; i++) {
        int key = A[i];
        
        int pos = binarySearch(A, key, 0, i);

        for (int j = i; j > pos; j--) {
            A[j] = A[j - 1];
        }
        A[pos] = key;
    }
}

int main() {
    /* int n; */
    /* cin >> n; */

    std::vector<int> A;
    A.push_back(5);
    A.push_back(2);
    A.push_back(9);
    A.push_back(1);
    A.push_back(3);
    A.push_back(4);

    /* mergeSort(A, 0, n); */

    /* for (int i = 0; i < n; i++) { */
    /*     cout << A[i] << (i < n - 1 ? " " : "\n"); */
    /* } */
    cout << "Before sorting: ";
    for (unsigned long i = 0; i < A.size(); i++) {
        cout << A[i] << (i < A.size() - 1 ? " " : "\n");
    }

    binaryInsertionSort(A);
    cout << "After sorting: ";
    for (unsigned long i = 0; i < A.size(); i++) {
        cout << A[i] << (i < A.size() - 1 ? " " : "\n");
    }

    return 0;
}

