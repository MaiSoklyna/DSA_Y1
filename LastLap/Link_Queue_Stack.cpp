#include <iostream>
using namespace std;

// Node structure
struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
}; 

// Stack using Linked List
class Stack {
private:
    Node* top;
public:
    Stack() : top(nullptr) {}

    void push(int value) {
        Node* newNode = new Node(value);
        newNode->next = top;
        top = newNode;
    }

    void pop() {
        if (top == nullptr) {
            cout << "Stack Underflow!\n";
            return;
        }
        Node* temp = top;
        top = top->next;
        delete temp;
    }

    int peek() {
        if (top == nullptr) {
            cout << "Stack is Empty!\n";
            return -1;
        }
        return top->data;
    }

    bool isEmpty() {
        return top == nullptr;
    }

    void display() {
        Node* temp = top;
        while (temp) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL\n";
    }
};

// Queue using Linked List
class Queue {
private:
    Node* front;
    Node* rear;
public:
    Queue() : front(nullptr), rear(nullptr) {}

    void enqueue(int value) {
        Node* newNode = new Node(value);
        if (rear == nullptr) {
            front = rear = newNode;
            return;
        }
        rear->next = newNode;
        rear = newNode;
    }

    void dequeue() {
        if (front == nullptr) {
            cout << "Queue Underflow!\n";
            return;
        }
        Node* temp = front;
        front = front->next;
        if (front == nullptr)
            rear = nullptr;
        delete temp;
    }

    int peek() {
        if (front == nullptr) {
            cout << "Queue is Empty!\n";
            return -1;
        }
        return front->data;
    }

    bool isEmpty() {
        return front == nullptr;
    }

    void display() {
        Node* temp = front;
        while (temp) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL\n";
    }
};

int main() {
    Stack stack;
    cout << "Stack Operations:\n";
    stack.push(10);
    stack.push(20);
    stack.push(30);
    stack.display(); 
    stack.pop();
    stack.display();
    cout << "Top Element: " << stack.peek() << "\n";

    Queue queue;
    cout << "\nQueue Operations:\n";
    queue.enqueue(1);
    queue.enqueue(2);
    queue.enqueue(3);
    queue.display();
    queue.dequeue();
    queue.display();
    cout << "Front Element: " << queue.peek() << "\n";

    return 0;
}
