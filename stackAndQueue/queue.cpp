#include <iostream>
using namespace std;
#define SIZE 5

int A[SIZE];
int front = -1;
int rear = -1;

bool isempty()
{
    if (front == -1 && rear == -1)
        return true;
    else
        return false;
}

void enqueue(int value)
{
    if (rear == SIZE - 1) // queue is full
        cout << "Queue is full\n";
    else
    {
        if (front == -1) // first element is inserted
            front = 0;
        rear++;
        A[rear] = value; // insert at rear
    }
}

void dequeue()
{
    if (isempty())
        cout << "Queue is empty\n";
    else
    {
        if (front == rear) // only one element
            front = rear = -1;
        else
            front++;
    }
}

void showfront()
{
    if (isempty())
        cout << "Queue is empty\n";
    else
        cout << "Element at front is: " << A[front] << endl;
}

void displayQueue()
{
    if (isempty())
        cout << "Queue is empty\n";
    else
    {
        cout << "Queue elements: ";
        for (int i = front; i <= rear; i++)
            cout << A[i] << " ";
        cout << endl;
    }
}

int main()
{
    enqueue(10);
    enqueue(20);
    enqueue(30);
    showfront();
    displayQueue();
    dequeue();
    showfront();
    displayQueue();
    return 0;
}
