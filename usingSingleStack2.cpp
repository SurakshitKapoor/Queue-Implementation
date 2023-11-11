//implemented queue using single stack with costly enQueue operation
#include<iostream>
#include<stack>
using namespace std;

//globally declaring stack s
stack<int>s;

void enQueue(int n) {
    if (s.empty())
    {
        s.push(n);
        cout << s.top() << " is inserted\n";
        return;
    }
    int data;
    data = s.top();

    s.pop();

    enQueue(n);

    s.push(data);
}

void deQueue() {
    if (s.empty())
    {
        cout << "No element to show\n";
        return;
    }
    int data = s.top();
    s.pop();
    cout << data << " is deleted\n";  
}

void printQueue() {
    if (s.empty())
    {
        cout << "Reached the end on printing\n";
        return;
    }
    cout << s.top() << "\t";
    int data = s.top();

    s.pop();

    printQueue();

    s.push(data);     
}
int main() {
    cout << "Queue using single stack with costly enQueue operation\n";

    enQueue(15);
    enQueue(20);
    enQueue(8);
    enQueue(17);

    printQueue();

    deQueue();
    deQueue();

    printQueue();

    enQueue(45);
    enQueue(28);
    enQueue(96);
    enQueue(100);

    printQueue();
}