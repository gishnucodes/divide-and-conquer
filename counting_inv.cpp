//
// Created by Gishnu Madhu on 10/26/24.
//

// g++ executable creation script
//  g++ -std=c++11 -o counting_inv counting_inv.cpp



#include <iostream>
#include <vector>
#include <utility> // for std::pair

using namespace std;

// Function to merge two halves and count inversions
pair<vector<int>, int> merge_and_count(const vector<int>& B, const vector<int>& C) {
    int n1 = B.size(), n2 = C.size();
    vector<int> A(n1 + n2);
    int i = 0, j = 0, count = 0;

    while (i < n1 || j < n2) {
        if (j >= n2 || (i < n1 && B[i] <= C[j])) {
            A[i + j] = B[i];
            i++;
            count += j; // Count inversions
        } else {
            A[i + j] = C[j];
            j++;
        }
    }

    return make_pair(A, count);
}

// Function to sort and count inversions
pair<vector<int>, int> sort_and_count(const vector<int>& A) {
    int n = A.size();
    if (n == 1) {
        return make_pair(A, 0);
    } else {
        int mid = n / 2;
        auto left_result = sort_and_count(vector<int>(A.begin(), A.begin() + mid));
        auto right_result = sort_and_count(vector<int>(A.begin() + mid, A.end()));

        auto merged_result = merge_and_count(left_result.first, right_result.first);

        int total_inversions = left_result.second + right_result.second + merged_result.second;

        return make_pair(merged_result.first, total_inversions);
    }
}

int main() {
    std::vector<int> A = {8, 4, 2, 1};
    auto result = sort_and_count(A);

    cout << "Sorted array: ";
    for (int num : result.first) {
        cout << num << " ";
    }
    cout << endl;

    cout << "Total inversions: " << result.second << endl;

    return 0;
}