#include <iostream>
#include <vector>

void Merge(std::vector<int>& A, int left, int mid1, int mid2, int right) {
    int n1 = left;
    int n2 = mid1;
    int n3 = mid2;

    std::vector<int> B(right + 1);
    int index = left;
    int n1Idx = left;
    int n2Idx = mid1 + 1;
    int n3Idx = mid2 + 1;

    while (n1Idx <= mid1 && n2Idx <= mid2 && n3Idx <= right) {
        if (A[n1Idx] <= A[n2Idx] && A[n1Idx] <= A[n3Idx]) {
            B[index] = A[n1Idx];
            n1Idx++;
        }
        else if (A[n2Idx] <= A[n1Idx] && A[n2Idx] <= A[n3Idx]) {
            B[index] = A[n2Idx];
            n2Idx++;
        }
        else {
            B[index] = A[n3Idx];
            n3Idx++;
        }
        index++;
    }

    while (n1Idx <= mid1 && n2Idx <= mid2) {
        if (A[n1Idx] <= A[n2Idx]) {
            B[index] = A[n1Idx];
            n1Idx++;
        }
        else {
            B[index] = A[n2Idx];
            n2Idx++;
        }
        index++;
    }

    while (n2Idx <= mid2 && n3Idx <= right) {
        if (A[n2Idx] <= A[n3Idx]) {
            B[index] = A[n2Idx];
            n2Idx++;
        }
        else {
            B[index] = A[n3Idx];
            n3Idx++;
        }
        index++;
    }

    while (n1Idx <= mid1 && n3Idx <= right) {
        if (A[n1Idx] <= A[n3Idx]) {
            B[index] = A[n1Idx];
            n1Idx++;
        }
        else {
            B[index] = A[n3Idx];
            n3Idx++;
        }
        index++;
    }

    while (n1Idx <= mid1) {
        B[index] = A[n1Idx];
        n1Idx++;
        index++;
    }

    while (n2Idx <= mid2) {
        B[index] = A[n2Idx];
        n2Idx++;
        index++;
    }

    while (n3Idx <= right) {
        B[index] = A[n3Idx];
        n3Idx++;
        index++;
    }

    for (int i = left; i <= right; i++) {
        A[i] = B[i];
    }
}

void MergeSort(std::vector<int>& A, int left, int right) {
    if (left < right) {
        int mid1 = left + (right - left) / 3;
        int mid2 = left + 2 * (right - left) / 3;
        MergeSort(A, left, mid1);
        MergeSort(A, mid1 + 1, mid2);
        MergeSort(A, mid2 + 1, right);
        Merge(A, left, mid1, mid2, right);
    }
}

int main() {
    std::vector<int> Arr = { 42, 17, 9, 34, 56, 23, 71, 5, 98, 12, 28 };
    int arrSize = Arr.size();

    MergeSort(Arr, 0, arrSize - 1);

    std::cout << "Sorted array: ";
    for (int i = 0; i < arrSize; i++) {
        std::cout << Arr[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}
