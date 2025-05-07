#include <iostream>
using namespace std;

class Link {
public:
    int value;
    Link* next;

    Link(int val = 0) {
        value = val;
        next = nullptr;
    }
};

class LinkedList {
private:
    Link* head;

public:
    LinkedList() {          
        head = nullptr;
    }

    // 1. Create 10 links and connect them to each other
    void createLinks() {
        for (int i = 1; i <= 10; i++) {
            insertAtTail(i);
        }
    }

    // 2. Insert a link at any position
    void insertAtPosition(int value, int position) {
        Link* newLink = new Link(value);

        // Insert at the beginning
        if (position == 0) {
            newLink->next = head;
            head = newLink;
            return;
        }

        Link* current = head;
        for (int i = 0; i < position - 1; i++) {
            if (current == nullptr) {
                cout << "Position out of bounds" << endl;
                delete newLink;
                return;
            }
            current = current->next;
        }

        newLink->next = current->next;
        current->next = newLink;
    }

    // 3. Delete a link at any position
    void deleteAtPosition(int position) {

        //check if empty
        if (head == nullptr) {
            cout << "List is empty" << endl;
            return;
        }

        // Delete at the beginning
        if (position == 0) {
            Link* temp = head;
            head = head->next;
            delete temp;
            return;
        }

        Link* current = head;
        for (int i = 0; i < position - 1; i++) {
            if (current == nullptr || current->next == nullptr) {
                cout << "Position out of bounds" << endl;
                return;
            }
            current = current->next;
        }

        Link* temp = current->next;
        current->next = current->next->next;
        delete temp;
    }

    // 4. Print all values and addresses of the links
    void printLinks() {
        Link* current = head;
        while (current != nullptr) {
            cout << "Value: " << current->value << ", Address: " << current << endl;
            current = current->next;
        }
    }

    // 5. Insert a link at the tail
    void insertAtTail(int value) {
        Link* newLink = new Link(value);

        //check if the begeinning is null
        if (head == nullptr) {
            head = newLink;
            return;
        }
        
        Link* current = head;
        while (current->next != nullptr) {
            current = current->next;
        }

        current->next = newLink;
    }





    ~LinkedList() {
        while (head != nullptr) {
            Link* temp = head;
            head = head->next;
            delete temp;
        }
    }
};

int main() {
    LinkedList list;

    // 1. Create 10 links and connect them to each other
    list.createLinks();

    // 2. Insert a link at position 5 with value 99
    list.insertAtPosition(99, 5);

    // 3. Delete a link at position 3
    list.deleteAtPosition(3);

    // 4. Print all values and addresses
    cout << "List contents after insertions and deletions:" << endl;
    list.printLinks();

    // 5. Insert a link at the tail with value 100
    list.insertAtTail(9999);

    // Print the final list
    cout << "\nList contents after inserting at the tail:" << endl;
    list.printLinks();

    return 0;
}
