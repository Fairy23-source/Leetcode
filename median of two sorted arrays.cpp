#include <iostream>
#include <vector>
using namespace std;

int main() {

    int n, m;

    cout << "Enter size of first array: ";
    cin >> n;

    vector<int> nums1(n);

    cout << "Enter elements of first sorted array: ";
    for (int i = 0; i < n; i++) {
        cin >> nums1[i];
    }

    cout << "Enter size of second array: ";
    cin >> m;

    vector<int> nums2(m);

    cout << "Enter elements of second sorted array: ";
    for (int i = 0; i < m; i++) {
        cin >> nums2[i];
    }

    vector<int> merged;

    int i = 0;
    int j = 0;

    // Merge both sorted arrays
    while (i < n && j < m) {

        if (nums1[i] < nums2[j]) {
            merged.push_back(nums1[i]);
            i++;
        }
        else {
            merged.push_back(nums2[j]);
            j++;
        }
    }

    // Add remaining elements of nums1
    while (i < n) {
        merged.push_back(nums1[i]);
        i++;
    }

    // Add remaining elements of nums2
    while (j < m) {
        merged.push_back(nums2[j]);
        j++;
    }

    int size = merged.size();
    double median;

    if (size % 2 == 1) {
        median = merged[size / 2];
    }
    else {
        median = (merged[size / 2 - 1] + merged[size / 2]) / 2.0;
    }

    cout << "Median = " << median << endl;

    return 0;
}
