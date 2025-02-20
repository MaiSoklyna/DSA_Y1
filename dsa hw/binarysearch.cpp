#include <iostream>
#include <vector>
using namespace std;

int binary_search(const vector<int>& arr, int target) {
    // Initialize the start and end indices
    int start = 0, end = arr.size() - 1;

    while (start <= end) {
        // Calculate the middle index
        int mid = start + (end - start) / 2;

        // Check if the middle element is the target
        if (arr[mid] == target) {
            return mid; // Target found, return index
        }

        // If target is greater, ignore the left half
        else if (arr[mid] < target) {
            start = mid + 1;
        }

        // If target is smaller, ignore the right half
        else {
            end = mid - 1;
        }
    }

    return -1; // Target not found
}

int main() {
    vector<int> array = {2, 7, 9, 11, 20, 25, 27, 50, 51, 60};
    int target = 25;
    int result = binary_search(array, target);

    if (result != -1) {
        cout << "Element " << target << " found at index " << result << "." << endl;
    } else {
        cout << "Element " << target << " not found in the array." << endl;
    }

    return 0;
}
