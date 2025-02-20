#include <iostream>
using namespace std;

int main()
{
    int A[100];
    int lower=0, upper = 100;
    int key=13;
    int middle;
    int count=0;
    for(int i=0; i<100;i++){
        A[i]=i+1;
    }
    while(1)
    {
        middle =(lower + upper)/2;
        if(middle < key)
        {
            lower = middle+1;
        }else if(middle > key)
        {
            upper= middle-1;
        }else if(middle == key)
        {
            cout << "found in " <<count;
            break;
        }
        count++;
    }
    return 0;
}
