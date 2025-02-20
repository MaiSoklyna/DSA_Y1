#include <iostream>

using namespace std;

int main()
{
    int temp;//use to tempary store value
    int A[]={1,12,3,4,90,9};//array

    //loop for repeating the comparing and swapping loop
    for (int i = 0; i < sizeof(A)/sizeof(A[0]); i++)
    {
        //loop for comparing and swapping elements if condition are met 
        for(int j = 0; j < (sizeof(A)/sizeof(A[0])); j++)
        {
            if(A[j+1] < A[j])//the condition
            {
                //swaping the smaller with the bigger number 
                temp = A[j+1];//tempary store the smaller number in temp
                A[j+1] = A[j];//replace the smaller number with the bigger number
                A[j] = temp;//put the tempary number back in the bigger number place
            } 
        }
    }
    for (int i = 0; i < sizeof(A)/sizeof(A[0]); i++)//loop for printing the sorted array
    {
        cout << A[i] << ", ";
    }
    return 0;
}
