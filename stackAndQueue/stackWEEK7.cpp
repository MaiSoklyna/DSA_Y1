#include <iostream>
using namespace std;

int A[10];
int top = -1; 

bool isempty()
{
    return top == -1;
} 

bool isfull()
{
    return top == 10 - 1;
} 

void push(int value)
{
    if (isfull())
        cout << "Stack is full\n";
    else
    {
        top++;
        A[top] = value;
    }
}

void pop()
{
    if (isempty())
        cout << "Stack is empty\n";
    else
        top--;
}

void peek()
{
    if (isempty())
        cout << "Stack is empty\n";
    else
        cout << "Top element is: " << A[top] << endl;
}

void displayStack()
{
    if (isempty())
        cout << "Stack is empty\n";
    else
    {
        cout << "Stack elements: ";
        for (int i = top; i >= 0; i--)
            cout << A[i] << " ";
        cout << endl;
    }
}
int SIZE()
{
    return top + 1; 
}
int main()
{ 
    displayStack();
    cout << "Size of stack: " << SIZE() << endl;
    push(10);
    push(20);
    push(30);
    push(40);
    push(50);
    push(60);
    peek();
    displayStack();
    pop();
    peek();
    displayStack();
    cout << "Size of stack: " << SIZE() << endl;
    return 0;

    return 0;
}
