//circular queue implementation by using array with mannual writing of operations
#include<iostream>
#define MAX 5
using namespace std;

int arr[MAX];
int front = -1;
int rear = -1;
bool full;
bool empty;

bool isFull() {
	if((front==0 && rear==MAX-1) || (front==rear+1)) {
//		cout << "\n Queue is Full \n";
		return 1;
	}
	else {
		return 0;
	}
}

bool isEmpty() {
//	if(front == -1)
	if(front == -1 && rear == -1) {
		return 1;
	}
	else {
		return 0;
	}
}

void push(int data) {
	if(isFull()) {
		cout << "\n Queue is Full \n";
		return;
	}
	else if(rear == MAX -1 && front > 0) {
		rear = 0;
	}
	else if(front == -1) {
		front++;
		rear++;
	}
	else{
		rear++;	
	}
	arr[rear] = data;
	cout << "\n" << data << " is inserted in queue \n";
	return;
}

void pop() {
	int data;
	if(isEmpty()) {
		cout << "\n Queue is Empty \n";
		return;
	}
	else if(front == MAX-1 && rear != front){
		data = arr[front];
		front = 0;
	}
	else if(front == rear) {
		data = arr[front];
		front = -1;
		rear = -1;
	}
	else {
		data = arr[front];
		front ++;
	}
	cout << "\n" << data << " is deleted from queue \n";
	return;
	
}

void showAll() {
	if(isEmpty()) {
		cout << "\n Queue is Full \n";
		return;
	}
	
	//yeh tricky hai 
	cout << "\n The Queue is :  \n";
	for (int i = front; i <= rear; i++)
	{
		if(i == MAX-1) {
			i=0;
		}
		cout << arr[i] << "\t";
	}
	
	return;
}

int main() {
	cout << "Hello, its Circular Queue" << endl;
	
	push(11);
	push(12);
	push(13);
	push(14);
	push(15);
	push(16); 	//full
	
	cout << "\n 4-elements popped \n";
	pop();
	pop();
	pop();
	pop();
	
	cout << "\n Now, push \n";
	push(45);
	push(78);
	push(10);
	
	cout << front << endl;
	cout << rear << endl;
	showAll();
}
