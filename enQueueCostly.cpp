//making enQueue operation costly
#include<iostream>
#include<stack>
using namespace std;

//globally declaring two stacks
stack<int>s1;
stack<int>s2;

void insertFunc(int n) {

    while (!s1.empty())
    {
        s2.push(s1.top());
        s1.pop();
    }
    s1.push(n);
    while (!s2.empty())
    {
        s1.push(s2.top());
        s2.pop();
    }
    cout << n << " is inserted\n";  
}

void deleteFunc() {
    if (s1.empty())
    {
        cout << "No Element is present\n";
        return;
    }
    int data = s1.top();
    s1.pop();
    cout << data << " is deleted\n";
}

//by recursion
void printQueue(stack<int>s1) 
{
    //base case
    if(s1.empty()) {
        cout << "Done" << "\n";
        return;
    }

    //printing the top or front data
    cout << s1.top() << "\t";

    //storing data for restoring on reversing from recursive stack
    int data = s1.top();

    //breaking the stack 
    s1.pop();

    //recursive call
    printQueue(s1);
    
    //restoring data on reversing 
    s1.push(data);
} 

int main() {
    cout << "Queue using stack, making qnQueue operation constly\n";

    insertFunc(12);
    insertFunc(15);
    insertFunc(17);
    insertFunc(20);

    printQueue(s1);

    cout << s1.top() << endl;

    deleteFunc();
    // deleteFunc();
    // deleteFunc();
    // deleteFunc();
    // deleteFunc();
    // deleteFunc();

    insertFunc(30);
    insertFunc(35);

    printQueue(s1);
}