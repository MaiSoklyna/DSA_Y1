#include <iostream>
using namespace std;

int main() {
    int n;          // Input variable
    int sum = 0;    // Sum initialization

    cout << "Enter a positive number: ";
    cin >> n;

    // Loop to calculate sum from 1 to n
    for(int i = 1; i <= n; i++) {
        sum = sum + i;                               // Addition operation
        cout << "Current number: " << i;             // Output operation
        cout << ", Running sum: " << sum << endl;    // Output operation
    }

    cout << "\nThe sum of numbers from 1 to " << n;  // Final output
    cout << " is: " << sum << endl;

    return 0;
}
