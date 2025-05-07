#include <iostream>
using namespace std;                                  
//========================Homeowork: LinkList======================//
// 1. Make 10 Links and make them connect to each others
// 2. Write function to insert a link to any position
// 3. Write function to delete a link in any position
// 4. Write fucntion to print all value and address of the link
// 5. Wrtie function to insert a link at the tail
class Link
{
public:
    int Value;
    Link *Next; // pointer to store the address of the next link
    Link()
    {
        Value = -99;
        Next = NULL;
    }
}; 
//============================================================================//
// 2. Write function to insert a link to any position
void insertion(Link *&pointer, int value, int position)
{
    Link *newLink = new Link(); // create new link
    newLink->Value = value;     // assign value to new link

    if (position == 1) // insert at the beginning
    {
        newLink->Next = pointer; //// mean that the new link next is storing pointer(head) = &L1
        pointer = newLink;       //// make the newlink become new head
        return;
    }

    Link *tmp = pointer;                                  //// we create a temporary pointer tmp stores pointer = &L1(head)  to traverse the list
    for (int i = 1; i < position - 1 && tmp != NULL; i++) // Traverse or go through to position-1 (the position link before the newLink )
    {
        tmp = tmp->Next; // pNext of the position before our insertion to update it
    }

    if (tmp != NULL) // insert the new link
    {
        newLink->Next = tmp->Next; // connect new link to the next link
        tmp->Next = newLink;       // update previous link's next to new node
    }
    else
    {
        cout << "Position out of bounds.\n";
    }
}
//============================================================================//
// 3. Write function to delete a link in any position
void deletion(Link *&pointer, int position) 
{
    if (pointer == NULL) // check if the list is empty or not
        return;

    Link *tmp = pointer;

    if (position == 1) // at the beginning
    {
        pointer = tmp->Next;
        delete tmp;
        return;
    } 

    for (int i = 1; i < position - 1 && tmp != NULL; i++) // traverse to find position-1
    {
        tmp = tmp->Next;
    }

    if (tmp != NULL && tmp->Next != NULL) // delete the link if valid position
    {
        Link *toDelete = tmp->Next; // identify the link to be deleted by creating a new temporary pointer
        tmp->Next = toDelete->Next; // link the previous node to the next link
        delete toDelete;            // delete the identified link
    }

    else
    {
        cout << "Position out of bounds.\n";
    }
} 
//============================================================================//
// 4. Write function to print all value and address of the link
void print(Link *pointer)
{
    Link *tmp = pointer; 
    while (tmp != NULL) // traverse the list or loop through the list until reaching null
    {
        cout << "Value of: " << tmp->Value << "  | Address: " << tmp << endl;
        tmp = tmp->Next; // update move to the next link
    }
}
//============================================================================//
// 5. Write function to insert a link at the tail
void tail_insert(Link *&pointer, int value)
{
    Link *newLink = new Link(); // create new link
    newLink->Value = value;     // assign value
    newLink->Next = NULL;       // set next to null (the last link)

    if (pointer == NULL) // If list is empty, set head to new link
    {
        pointer = newLink;
        return;
    }

    Link *tmp = pointer;
    while (tmp->Next != NULL) // Traverse to the last node until it reach null
    {
        tmp = tmp->Next; // we move tmp to the next link
    }
    tmp->Next = newLink; //  Insert new node at the end
}
//============================================================================//
int main()
{
    // 1. Make 10 Links and make them connect to each other
    Link L1;
    L1.Value = 1;
    Link L2;
    L2.Value = 3;
    Link L3;
    L3.Value = 5;
    Link L4;
    L4.Value = 7;
    Link L5;
    L5.Value = 9;                                    
    Link L6;
    L6.Value = 11;
    Link L7;
    L7.Value = 13;
    Link L8;
    L8.Value = 15;
    Link L9;
    L9.Value = 17;
    Link L10;
    L10.Value = 19;

    // Connection
    L1.Next = &L2;
    L2.Next = &L3;
    L3.Next = &L4;
    L4.Next = &L5;
    L5.Next = &L6;
    L6.Next = &L7;
    L7.Next = &L8;
    L8.Next = &L9;
    L9.Next = &L10;

    Link *pointer = &L1; // Head of the linked list

    cout << "Original List:\n";
    print(pointer);

    // Test insertion
    cout << "\nInserting 55 at position 3:\n";
    insertion(pointer, 55, 3);
    print(pointer);

    // Test deletion
    cout << "\nDeleting at position 6:\n";
    deletion(pointer, 6);
    print(pointer);

    // Test tail insert
    cout << "\nInserting 100 at the tail:\n";
    tail_insert(pointer, 100);
    print(pointer);

    return 0;
}