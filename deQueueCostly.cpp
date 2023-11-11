//implementing queue using stack where, deQueue operation is costly
#include<iostream>
#include<stack>
using namespace std;

//globally declaring two stacks
stack<int>s1;
stack<int>s2;

void enQueue(int n) {
    s1.push(n);
    cout << n << " is inserted\n";
}

void deQueue() {
    if (s1.empty())
    {
        cout << "No element is present \n";
        return; 
    }
    int data;
    while (!s1.empty())
    {
        s2.push(s1.top());
        s1.pop();
    }
    data = s2.top();
    s2.pop();
    while (!s2.empty())
    {
        s1.push(s2.top());
        s2.pop();
    }
    cout << "\n" << data << " is deleted\n";
    return;    
}

//by recursion
void printQueue(stack<int>s1) {
    //base case
    if (s1.empty())
    {
        cout << "Reached front for printing" << "\n";
        return;
    }

    //storing data for restoring in stack on reversing
    int data = s1.top();

    //breaking stack for passing in recursive call
    s1.pop();

    //recursive call
    printQueue(s1);

    //restoring breaked data on reversing
    s1.push(data);
    //printing the front data
    cout << data << "\t";
    
}

int main() {
    cout << "Queue using stack, where Deletion is costly\n";

    enQueue(12);
    enQueue(16);
    enQueue(21);
    enQueue(25);

    printQueue(s1);

    deQueue();
    deQueue();

    enQueue(34);
    enQueue(42);

    printQueue(s1);
}