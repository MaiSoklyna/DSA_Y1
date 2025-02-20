#include <iostream>
#include <queue>

using namespace std;
int main(){

    queue<int> q, q2;//creating 2 queue of interger
    
    //adding element to queue 1
    q.push(1);//front element
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);//back element

    //adding element to queue 2
    q2.push(7);//front 
    q2.push(8);
    q2.push(9);
    q2.push(10);
    q2.push(11);//back

    //printing out if queue 1 is emoty or not. 0 = not empty, 1 is empty
    cout << "is queue 1 empty? " << q.empty() << "\n";
    //printing out the size of the queue 1
    cout << "what is queue 1 size? " << q.size() << "\n";
    //printing out the front element in queue 1
    cout << "what is the element in front of the queue 1? " << q.front() << "\n";
    //printing out the back element of queue 1
    cout << "what is the element in back of the queue 1? " << q.back() << "\n";

    //tell the user im going to delete element in the front of the queue
    cout << "deleting the front element in the queue 1\n";
    q.pop();//deleting that front element
    //printing out the new front element in the queue
    cout << "now the element in front of the queue 1 is " << q.front() << "\n";

    //telling user im going to add the number 6 to the back of the queue
    cout << "adding 6 to end of the queue 1\n";
    q.emplace(6);//adding 6 to the back of the queue
    //printing out the new back element of the queue
    cout << "now the element in back of the queue 1 is " << q.back() << "\n";

    //telling to user im going to swap the queue 1 with queue 2
    cout << "swapping queue 1 wtih queue 2\n";
    q.swap(q2);//swapping the queue

    //printing out the new front and back element of the queue
    cout << "now the front element is " << q.front() << "\n";
    cout << "and the back element is " << q.back();

    return 0;
}