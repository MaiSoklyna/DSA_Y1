#include <iostream>
#include <stack>

using namespace std;

int main(){
    stack<int> int_stack;//creating a stack of integer

    //add element to the stack
    int_stack.push(1);//the bottom element
    int_stack.push(5);
    int_stack.push(8);
    int_stack.push(2);//the top element

    //check if the stack is empty. empty() return 0 or 1 meaning 1 is empty, 0 is not empty
    cout << "is stack empty? " << int_stack.empty() << "\n";
    //print the top element on the stack
    cout << "the element at he top of the stack are: " << int_stack.top() << "\n";
    //tellng the user im deleting top element in the stack
    cout << "deleting the element on top of the stack\n";

    int_stack.pop();//deleting the top element

    //print the new top element in the stack
    cout << "after delete, the top element in stack are: " << int_stack.top();

    return 0;
}