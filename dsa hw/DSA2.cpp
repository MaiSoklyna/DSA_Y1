#include <iostream>

using namespace std;

int main()
{
    int array[10]={1,2,3,4,5,6,7,83,83};
    int key = 83;
    int j;
    int count=0;
    for( j= 0; j< 10; ++j){
        if (array[j]==key)
        {
            count++;
        }
    }
    cout << "find " << count << " times";
    return 0;
}