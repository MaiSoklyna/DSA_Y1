#include <iostream>
#include <queue>

using namespace std;
int main(){
    /*priority queue is different from queue
    priority take the largest value element and put it and the
    front (or top) of the queue. or priority queue sort the element from largest value
    to smallest value*/

    priority_queue<int> pri_q1, pri_q2;//creating 2 queue of interger
    
    //adding element to the priority queue 1
    pri_q1.push(30);
    pri_q1.push(3);//back element
    pri_q1.push(7);
    pri_q1.push(8);
    pri_q1.push(40);//top or front element

    //adding element to queue 2
    pri_q2.push(1);//back element
    pri_q2.push(3);
    pri_q2.push(9);
    pri_q2.push(10);
    pri_q2.push(60);//top element

    //printing out if priority queue 1 is empty or not. 0 = not empty, 1 is empty
    cout << "is the priority queue 1 empty? " << pri_q1.empty() << "\n";
    //printing out the size of the priority queue 1
    cout << "what is the priority queue 1 size? " << pri_q1.size() << "\n";
    //printing out the top element in the priority queue 1
    cout << "what is the top element in the priority queue 1? " << pri_q1.top() << "\n";

    //tell the user im going to delete element in the front of the queue
    cout << "deleting the top element in the queue 1\n";
    pri_q1.pop();//deleting that front element

    //printing out the new top element in the queue
    cout << "now the top element in the priority the queue 1 is " << pri_q1.top() << "\n";

    //telling user im going to add the number 45 to the priority queue
    cout << "adding 45 into the priority queue 1\n";
    pri_q1.emplace(45);//adding 45 into the priority queue

    //printing out the new top element in the pririty queue
    cout << "now the new top element in the priority queue is " << pri_q1.top() << "\n";

    //telling to user im going to swap the priority queue 1 with the priority queue 2
    cout << "swapping priority queue 1 wtih priority queue 2\n";
    pri_q1.swap(pri_q2);//swapping the queue

    //printing out the new front and back element of the queue
    cout << "now the front element is " << pri_q1.top() << "\n";

    return 0;
}