//queue implementation by using array with mannual writing of operations
#include<iostream>
#define MAX 5
using namespace std;

int front=-1;
int rear=-1;
int arr[MAX];

void push(int data) {
    
    //check overflow
    if(rear == MAX-1) {
        cout << "\nQueue is Full" << endl;
        return;
    }

    if(front == -1) {
        front += 1;
    }

    rear++;
    arr[rear] = data;
    cout << "\n" << data << " is inserted in queue" << "\n";
    return;
}

void pop(){
    if(front == -1 || front > rear) {
        cout << "\nQueue is Empty" << "\n";
        return;
    }
    
    for (int i = 0; i < rear; i++)
    {
        arr[i] = arr[i+1];
    }
    rear--;
    return;  
}

void showAll() {
    if(front == -1) {
        cout << "\nQueue is Empty" << "\n";
        return;
    }

    cout << "\nQueue Elements are : \n";
    for (int i = front; i <= rear; i++)
    {
        cout << arr[i] << "\t";
    }
    
    return;
}
int main() {
    cout << "hello" << "\n";
 
    push(28);
    push(90);
    push(56);
    push(45);
    push(79);
    push(100);

//	cout << "Popped 6 times" << endl;
//    pop();
//    pop();
//    pop();
//    pop();
//    pop();
//    pop();
	
    cout << "\nThe rear is : " << arr[rear] << endl;
    cout << "\nThe front is : " << arr[front] << endl;

    showAll();
//
//    push(40);
//    push(89);
//    push(36);
//    push(48);

    return 0;
}
