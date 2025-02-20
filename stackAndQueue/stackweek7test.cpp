#include <iostream>
using namespace std;

// Function prototypes
bool isFull();     // Check if the stack is full
bool isEmpty();    // Check if the stack is empty

// Global variables
int A[10]; // Stack with a maximum size of 10
int top = -1; // Index of the top element

// Push value to stack (Array A)
void Push(int Value) {
    // Check if the stack is full
    if (isFull()) {
        cout << "Stack Overflow! Cannot push " << Value << endl;
        return;
    }
    top++;          // Increase top index
    A[top] = Value; // Add value to the stack
}

// Remove the top element
void Pop() {
    // Check if the stack is empty
    if (isEmpty()) {
        cout << "Stack Underflow! Nothing to pop." << endl;
        return;
    }
    top--; // Decrease top index
}

// Return the top element without removing it
int Peek() {
    // Check if the stack is empty
    if (isEmpty()) {
        cout << "Stack is empty! No top element." << endl;
        return -1; // Return an invalid value to indicate failure
    }
    return A[top];
}

// Return the number of elements in the stack
int Size() {
    return top + 1;
}

// Return true if the stack is empty, else false
bool isEmpty() {
    return top == -1;
}

// Return true if the stack is full, else false
bool isFull() {
    return top == 9; // Maximum index for a stack of size 10
}

// Print elements in the stack
void PrintStack() {
    if (isEmpty()) {
        cout << "Stack is empty!" << endl;
        return;
    }
    for (int i = 0; i <= top; ++i)
        cout << A[i] << " ";
    cout << endl;
}

// Main function
int main() {
        
    Push(10);
    Push(5);
    Push(8);
    Push(8);
    Push(8);
    Push(8);
    Push(8);
    Push(8);
    Push(8);
    Push(8);
    Push(8);
    PrintStack();

    Pop();
    PrintStack();

    Push(100);
    PrintStack();

    cout << "Top element is: " << Peek() << endl;
    cout << "Stack size is: " << Size() << endl;
    cout << "Is stack empty? " << (isEmpty() ? "Yes" : "No") << endl;
    cout << "Is stack full? " << (isFull() ? "Yes" : "No") << endl;

    return 0;
}