#include <iostream>
#include <stack> //last in first out
#include <queue> //first in first out
#include <list> 
#include <math.h> 
// benifit of  STL please tell me

// 1. Write a function to convert a given binary number to decimal
int binaryToDecimal(int binaryNumber)
{
        int decimalNumber = 0, i = 0, remainder;

        while (binaryNumber != 0)
        {
                remainder = binaryNumber % 10;
                decimalNumber = decimalNumber + remainder * pow(2, i); // pow must add libraly math.h
                binaryNumber = binaryNumber / 10;
                i++;
        }
        return decimalNumber;
}

void stackOperations()
{
        std::stack<int> s;
        s.push(10);
        s.push(20);
        s.push(30);
        std::stack<int> tempStack = s;

        std::cout << "\nStack Operations:\n";
        std::cout << "Top: " << s.top() << std::endl;
        s.pop();
        std::cout << "Top after pop: " << s.top() << std::endl;
        // pust 40 to top
        s.push(40);
        std::cout << "Top after push 40: " << s.top() << std::endl;
        // print all stack

        std::cout << "Stack Elements (LIFO Order): ";
        while (!tempStack.empty())
        {
                std::cout << tempStack.top() << " ";
                tempStack.pop();
        }
        std::cout << std::endl;

        std::cout << "Size: " << s.size() << ", Empty: " << (s.empty() ? "Yes" : "No") << "\n";
}

void queueOperations()
{ //remove front
        std::queue<int> q;
        q.push(1);
        q.push(2);
        q.push(3);
        q.push(4);
        q.push(5);
        q.push(6);

        std::cout << "\nQueue Operations:\n";
        std::cout << "Front: " << q.front() << ", Back: " << q.back() << std::endl;
        q.pop();
        std::cout << "Front after pop: " << q.front() << std::endl;
        std::cout << "Size: " << q.size() << ", Empty: " << (q.empty() ? "Yes" : "No") << "\n";
}

void priorityQueueOperations()
{
        std::priority_queue<int> maxPQ;
        std::priority_queue<int, std::vector<int>, std::greater<int>> minPQ;

        maxPQ.push(10);
        maxPQ.push(30);
        maxPQ.push(20);

        minPQ.push(50);
        minPQ.push(60);
        minPQ.push(100);

        std::cout << "\nMax Priority Queue:\n";
        std::cout << "Top: " << maxPQ.top() << std::endl;
        maxPQ.pop();
        std::cout << "Top after pop: " << maxPQ.top() << std::endl;

        std::cout << "\nMin Priority Queue:\n";
        std::cout << "Top: " << minPQ.top() << std::endl;
        minPQ.pop();
        std::cout << "Top after pop: " << minPQ.top() << std::endl;
}

void linkedListOperations()
{
        std::list<int> myList = {10, 20, 30};
        myList.push_front(5);
        myList.push_back(40);
        // my link after push

        std::cout << "\nLinked List Operations:\n";
        std::cout << "Front: " << myList.front() << ", Back: " << myList.back() << std::endl;
        std::cout << "my linked list after push"
                  << std::endl;
        for (auto it = myList.begin(); it != myList.end(); ++it)
        {
                std::cout << *it << " ";
        }
        std::cout << std::endl;

        std::cout << "Size: " << myList.size() << ", Max Size: " << myList.max_size() << std::endl;
        std::cout << "Empty: " << (myList.empty() ? "Yes" : "No") << std::endl;

        std::cout << "Elements (forward): ";
        for (int num : myList)
        {
                std::cout << num << " ";
        }

        std::cout << "\nElements (reverse): ";
        for (auto it = myList.rbegin(); it != myList.rend(); ++it)
        {
                std::cout << *it << " ";
        }
        std::cout << std::endl;
        // my link atfer pop
        myList.pop_front();
        myList.pop_back();
        std::cout << "Size after pop: " << myList.size() << ", Max Size: " << myList.max_size() << std::endl;
        std::cout << "Elements (after pop): ";
        for (int num : myList)
        {
                std::cout << num << " ";
        }
        std::cout << std::endl;
}

int main()
{
        int binaryNumber = 10101; // Example binary number
        int decimalNumber = binaryToDecimal(binaryNumber);

        std::cout << "Decimal equivalent of " << binaryNumber << " is: " << decimalNumber << std::endl;
        stackOperations(); // STL Stack follows the LIFO (Last In First Out) principle. It uses deque as the underlying container.
        queueOperations(); // STL Queue follows the FIFO (First In First Out) principle. It uses deque as the underlying container.
        priorityQueueOperations(); // STL Priority Queue does not follow any of the FIFO or LIFO principle, but the deletion of elements is done on the basis of its priority. So, the element with the highest (by default) is always removed first. By default, it uses vector as underlying container.
        linkedListOperations();// STL List is a doubly linked list. It is a sequence container that allows constant time insert and erase operations anywhere within the sequence, and iteration in both directions. It uses doubly linked list as the underlying container.

        return 0;
}
