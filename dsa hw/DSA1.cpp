#include <iostream>

using namespace std;

int main()
{
    int array[10]={1,2,3,4,5,6,7,8,83};
    int key = 83;
    int j;
    for( j= 0; j< 10; j++){
        if (array[j]==key)
        {
            break;
        }
    }
    if (j < 10){
        cout << "found";
    }else {
        cout << "not found";
    }
    return 0;
}