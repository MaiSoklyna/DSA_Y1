#include <iostream>
using namespace std;
//FIFO first in first out
class Myqueue
{
private:
        int A[10]; // Array to hold queue elements
        int front;
        int rear;
        int capacity; // Max size of the queue

public: 
        Myqueue()
        {
                front = -1;
                rear = -1;
                capacity = 10;
        } 

        void insert(int value);
        void pop();
        int peek();
        int size();
        bool isEmpty();
        bool isFull();
        void printQueue();
};

//==============================================
//  Insert elements into the queue (enqueue)
void Myqueue::insert(int value)
{
        if (isFull())
        {
                cout << "Queue Overflow! Cannot insert more elements." << endl;
                return;
        }
        if (front == -1)
                front = 0; // First element
        rear++;
        A[rear] = value;
        cout << value << " inserted into the queue." << endl;
}

//==============================================
//  Remove elements from the queue (dequeue)
void Myqueue::pop()
{
        if (isEmpty())
        {
                cout << "Queue Underflow! No elements to remove." << endl;
                return;
        }         
        cout << "Removing: " << A[front] << endl;
        front++; 
        if (front > rear)  //true
        { // Reset when the queue is empty
                front = -1;
                rear = -1;
        }            
}

//==============================================
//  Peek the front element
int Myqueue::peek()
{
        if (isEmpty())
        {
                cout << "Queue is empty! Cannot peek." << endl;
                return -1;
        }
        return A[front];
}

//==============================================
//  Get the current size of the queue
int Myqueue::size()
{
        if (isEmpty())
                return 0;
        return (rear - front + 1); 
}  

//==============================================
//  Check if the queue is empty
bool Myqueue::isEmpty()
{
        return (front == -1 || front > rear);
}

//==============================================
//  Check if the queue is full
bool Myqueue::isFull()
{
        return (rear == capacity - 1);              
}

//==============================================
//  Print the queue elements
void Myqueue::printQueue()
{
        if (isEmpty())
        {
                cout << "Queue is empty! Nothing to print." << endl;
                return;
        }
        cout << "Queue elements: ";
        for (int i = front; i <= rear; ++i)
        {
                cout << A[i] << " ";
        }
        cout << endl;
}

//============================================== 
//  Main function
int main()
{
        Myqueue myQueue;

        myQueue.insert(10);
        myQueue.insert(20);
        myQueue.insert(30);
        myQueue.insert(40);
        myQueue.insert(50);

        myQueue.printQueue();

        myQueue.pop();
        myQueue.pop();

        myQueue.printQueue();

        cout << "Front element is: " << myQueue.peek() << endl;
        cout << "Size of queue is: " << myQueue.size() << endl;
        cout << "Is queue empty? " << (myQueue.isEmpty() ? "Yes" : "No") << endl;
        cout << "Is queue full? " << (myQueue.isFull() ? "Yes" : "No") << endl;

        return 0;
}