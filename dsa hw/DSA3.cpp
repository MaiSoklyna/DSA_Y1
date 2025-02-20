#include <iostream>
using namespace std;

int main() 
{
    int A[100];
    int lower = 0, upper = 100; // lower limit and upper limit
    int key = 80;               // the number we want to search for
    int middle;                 // the middle value of lower and upper
    int count = 1;              // count how many time it take to find the number we want

    // loop to 1-100 in array in a sorted style
    for (int i = 0; i < 100; i++)
    {
        A[i] = i + 1;
    }
    while (1)
    {
        middle = (lower + upper) / 2; // calculating the middle value
        if (middle < key)             // if condition are met replace to lower limit with the middle value
        {
            lower = middle + 1;
        }
        else if (middle > key) // if condition are met replace to upper limit with the middle value
        {
            upper = middle - 1;
        }
        else if (middle == key) // condition when found
        {
            cout << "found in " << count;
            break; // break the loop when found
        }
        count++;
    }
    return 0;
}