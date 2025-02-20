#include <iostream>
using namespace std;

// Function to print an array
void printArray(int array[], int size) {
    for (int i = 0; i < size; i++) {
        cout << array[i] << " ";
    }
    cout << endl;
}
//a function of insertion sort. sort from smallest to biggest
void SmallToBig(int array[], int size) {

    for (int i = 1; i < size; i++) {
        int num = array[i];//the number that use for comparing
        int j = i - 1;//starting number of j 

        //loop to take an element to compare and swap
        while (num < array[j] && j >= 0) {//comparing backward until 0
            array[j+1] = array[j];//move the biggest number in this iteration to the next index

            --j;//here j = -1
        }
        array[j + 1] = num;//put the smallest number of in iteration to index 0
    }
}

void BigToSmall(int array[], int size) {
  for (int i = 1; i < size; i++) {
    int num = array[i];
    int j = i - 1;

    while (num > array[j] && j >= 0) {
        array[j + 1] = array[j];
        --j;
    }
    array[j + 1] = num;
    }
}

int main() {
    int A[] = {9,5,1,4,3,7,0,1};
    int size = sizeof(A) / sizeof(A[0]);

    //BigToSmall(A, size);
    //printArray(A, size);
    SmallToBig(A, size);
    printArray(A, size);

    return 0;
}