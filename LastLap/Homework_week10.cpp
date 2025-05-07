#include <iostream>                                                       
using namespace std;

//=================== Homework " Build Stack LinkedList " ============================//
// Learned = :"LinkedList with Queue and stack"

class Link{
public:                          
    int Data;
    Link *pNext;
     void InitLink(int data);
    void DisplayLink();
}; 
//====================================================================//
//====================================================================//
void Link::InitLink(int data){
    Data = data;
    pNext = NULL;
};
//====================================================================//
void Link::DisplayLink(){
    cout << "Data: " << Data << " " << "Address:" << pNext << endl;
};                                                                              
//====================================================================//

//====================================================================//
//====================================================================//
// In these case our linklist is a stack because we can do only push (like insert first) and pop (Remove first)
class LinkList{ // stack
private:
    Link *pFirst; // First link on list (Top of stack)
    int count;    // Count the number of elements in the stack
public:
    void InitLinkList();
    void InsertFirst(int data); // To insert at the first (head)
    void RemoveFirst();         // Remove the first element (pop)
    void PrintFirst();          // Print value and address of pFirst
    void DeleteLinkList();      // Remove all links/elements in the stack
    void Size();                // Count how many links/elements in the stack
    void Peek();                // No remove or delete - display value of element on the top
};                                                


//====================================================================//
//====================================================================//
void LinkList::InitLinkList(){
    pFirst = NULL;
    count = 0; // Initialize count to 0
}
//====================================================================//
void LinkList::InsertFirst(int data){
    Link *NewLink = new Link(); // Make new link
    NewLink->InitLink(data);    // Set value of Data to data
    NewLink->pNext = pFirst;    // newLink --> old first set pNext = NULL
    pFirst = NewLink;           // Set pFirst --> newLink
    count++;                    // Increase the size of the stack
} 
//====================================================================//
void LinkList::RemoveFirst(){
    Link *pTemp = pFirst;   // Temporary link
    pFirst = pFirst->pNext; // Unlink it: pFirst ==> old pNext
    delete pTemp;           // Free memory
    count--;                // Decrease stack size
}
//====================================================================//
void LinkList::PrintFirst(){ 
    cout << "Value(Top): " << pFirst->Data << " Address(Next): " << pFirst->pNext << endl;
}
//======================================6  
],m==============================//
void LinkList::DeleteLinkList(){
    Link *pCurrent = pFirst; // start at the beginning of list
    while (pCurrent != NULL){                               // until the end of list
        Link *pOldCur = pCurrent;   // save current link
        pCurrent = pCurrent->pNext; // move to new link
        delete pOldCur;             // delete old current
    }
    pFirst = NULL; // Set head to NULL after deletion
    count = 0;     // Reset count to 0
};
//====================================================================//
void LinkList::Size(){
    cout << "Stack size: " << count << endl; // Print current size
};
//====================================================================//
void LinkList::Peek(){
    cout << "Peek the top element: " << pFirst->Data << endl; // Display top element
};
//====================================================================//

int main(){
    LinkList MyLinkList;
    MyLinkList.InitLinkList();

    MyLinkList.InsertFirst(10);
    MyLinkList.InsertFirst(20);
    MyLinkList.InsertFirst(30); 

    MyLinkList.PrintFirst(); //  print 30
    MyLinkList.Size();       //  print Stack size: 3

    MyLinkList.RemoveFirst(); // Remove 30
    MyLinkList.Peek();        //  print 20

    MyLinkList.DeleteLinkList(); // delete the whole stack
    MyLinkList.Peek();

    return 0;
}
