#include <stdio.h>
#include <iostream>
#include  <vector>


void merge(std::vector<int>& arr, int low, int mid, int high) {

    int n1 = mid - low + 1;
    int n2 = high - mid;

    std::vector<int> L(n1), R(n2);

    for (int i = 0; i < n1; i++) {
        L[i] = arr[low + i]; // we consider till mid in this
    }

    for (int j=0; j<n2 ; j++) {
        R[j] = arr[mid + 1 + j]; // since we consider from mid + 1
    }

    int i=0, j=0, k=low;

    while(i<n1 && j<n2) {
        if(L[i] <= R[j]) {
            arr[k]  = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }


    //move all untouched elements back to arr

    while(i<n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while(j<n2) {
        arr[k] = R[j];
        j++;
        k++;
    }

}

void merge_sort(std::vector<int>& arr, int low, int high) {

    if (low < high) {
        int mid = (low + high) / 2;
        // int mid = low + (high - low) / 2;

        merge_sort(arr, low, mid);
        merge_sort(arr, mid + 1, high);

        merge(arr, low, mid, high);
    }

}


void printArray(const std::vector<int>& arr) {
    for (int i : arr)
        std::cout << i << " ";
    std::cout << std::endl;
}

int main() {
    std::vector<int> arr = {1,4,5,2,44,5,8};
    std::cout << "Array before sorting: ";
    printArray(arr);

    merge_sort(arr, 0, arr.size() - 1);

    std::cout << "Array after sorting: ";
    printArray(arr);

}