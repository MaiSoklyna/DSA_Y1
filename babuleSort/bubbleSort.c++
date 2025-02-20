#include <iostream>//week 4
using namespace std;

int main()
{
    int A[] = {-2, -3, 5, 1, 3, 42, 13, 44, 90, 6, 9};
    int n = sizeof(A) / sizeof(A[0]);

    // Bubble Sort 
    for (int i = 0; i < n - 1; i++)   //n-1
    {  
        for (int j = 0; j < n - i - 1; j++)//n-2
        {  
            if (A[j + 1] < A[j])  
            {  
                int pivot = A[j + 1];  
                A[j + 1] = A[j];  
                A[j] = pivot;   
            }  
        }  
    }

    // Print sorted array
    cout << "Sorted array: ";
    for (int i = 0; i < n; i++)  
    {  
        cout << A[i] << " ";  
    }
    cout << "\n";

    // Print array in reverse
    cout << "Reversed array: ";
    for (int i = n - 1; i >= 0; i--)  
    {  
        cout << A[i] << " ";  
    }
    cout << "\n";

    return 0;
}
