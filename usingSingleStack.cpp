//implemented queue using single stack with costly deQueue operation
#include<iostream>
#include<stack>
using namespace std;

//globally declaring the stack
stack<int>s;

void enQueue(int n) {
    s.push(n);
    cout << s.top() << " is inserted\n";
}

void deQueue() {
    if (s.empty())
    {
        cout << "No data to show\n";
        return;
    }
    if (s.size() == 1)
    {
        int delData = s.top();
        s.pop();
        cout << delData << " is deleted\n";
        return;
    }
    
    int data = s.top();

    s.pop();

    deQueue();

    s.push(data);

    return;
    
}

//first/oldest value of queue is at last of stack
void printQueue(stack<int>s) {
    if (s.empty())
    {
        cout << "Reached the End on printing the data\n";
        return;
    }
    int data = s.top();

    s.pop();

    printQueue(s);

    s.push(data);
    cout << s.top() << "\t";
    
}
int main() {
    cout << "Queue using single stack\n";

    enQueue(12);
    enQueue(23);
    enQueue(45);
    enQueue(51);
    enQueue(54);

    deQueue();

    printQueue(s);
    cout << "\n";

    enQueue(96);

    deQueue();
    // deQueue();
    // deQueue();
    // deQueue();
    printQueue(s);
    cout << "\n";

}