#include <iostream>
using namespace std;

#define MAX_SIZE 10 // Maximum capacity of the stack
//last in first out LIFO (please explain me more ?)



class Stack { 
private:
    int Array[MAX_SIZE]; // Array to hold stack elements
    int top = -1;             // Index of the top element in the stack

public:  
    
    // Function to display all elements in the stack
    void PrintStack() {
        if (isEmpty()) {
            cout << "Stack is empty." << endl;
            return;
        }
        cout << "Stack elements: ";
        for (int i = 0; i <= top; i++) {
            cout << Array[i] << " ";
        }
        cout << endl;
    }

    // Function to push an element onto the stack
    void push(int Value) {
        if (isFull()) {
            cout << "Stack is full. Cannot push new item." << endl;
            return;
        }
        Array[++top] = Value;
    }

    // Function to pop an element from the stack
    int pop() {
        if (isEmpty()) {
            cout << "Stack is empty. Cannot pop an item." << endl;
            return -1;
        }
        return Array[top--];
    }

    // Function to peek at the top element without removing it
    int peek() {
        if (isEmpty()) {
            cout << "Stack is empty. Nothing to peek." << endl;
            return -1;
        }
        return Array[top];
    }

    // Function to get the current size of the stack
    int size() {
        return top + 1;
    }

    // Function to check if the stack is empty
    bool isEmpty() {
        return top == -1;
    }  

    // Function to check if the stack is full
    bool isFull() {
        return top == MAX_SIZE - 1;
    } 
};

int main() {
    Stack Myvariable;
    int choice, value;

    while (true) {
        cout << "\nStack Operations:" << endl;
        cout << "1. Show stack" << endl;
        cout << "2. Push" << endl;
        cout << "3. Pop" << endl;
        cout << "4. Peek" << endl;
        cout << "5. Size" << endl;
        cout << "6. Check if Empty" << endl;
        cout << "7. Check if Full" << endl;
        cout << "0. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                Myvariable.PrintStack();
                break;
            case 2:
                cout << "Enter value to push: ";
                cin >> value;
                Myvariable.push(value);
                break;
            case 3:
                value = Myvariable.pop();
                    cout << "Popped value: " << value << endl;
                break;
            case 4:
                value = Myvariable.peek();
                    cout << "Top value: " << value << endl;
                break;
            case 5:
                cout << "Stack size: " << Myvariable.size() << endl;
                break;
            case 6:
                cout << (Myvariable.isEmpty() ? "Stack is empty." : "Stack is not empty.") << endl;
                break;
            case 7:
                cout << (Myvariable.isFull() ? "Stack is full." : "Stack is not full.") << endl;
                break;
            case 0:
                cout << "Exiting program." << endl;
                return 0;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }
}
