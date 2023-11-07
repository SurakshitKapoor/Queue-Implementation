//circular queue implementation by using array and loop with switch case with user choice operations 
#include<iostream>
#define MAX 5
using namespace std;

int front = -1;
int rear = -1;

int arr[MAX];

bool isEmpty() {
	if(front == -1) {
		return 1;
	}
	else {
		return 0;
	}
}

bool isFull() {
	if((front == 0 && rear == MAX-1) || (front == rear + 1)){
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
	else if(front == -1) {
		front = 0;
		rear = 0;
	}
	else if(rear == MAX-1 && front > 0) {
		rear = 0;
	}
	else {
		rear ++;
	}
	arr[rear] = data;
	cout << "\n" << data << " is inserted in circular queue \n";
	return ;
}

void pop() {
	int data;
	
	if(isEmpty()) {
		cout << "\n Queue is Empty \n";
		return;
	}
	else if(front == MAX-1 && rear > 0) {
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
	return ;
}

int main() {
	cout << "\n Circular Queue using Array with Loop \n";
	cout << "Enter the operation to perform on circular queue \n";
	
	do {
	cout << "1. Push; \t2. Pop; \t3. isFull; \t4. isEmpty; \t5. getFront; \t6. getRear; \t7. End" << endl;
	int ch;
	cin >> ch;
	int data;
	switch(ch) {
		case 1: 
			cout << "Enter the data to insert: "<< endl;
			cin >> data;
			push(data);
			break;
			
		case 2: 
			pop();
			break;
			
		case 3: 
			if(isFull()) {
				cout << "\n Queue is Full \n";
			}
			else {
				cout << "\n Queue is not Full \n";
			}
			break;
		
		case 4:
			if(isEmpty()) {
				cout << "\n Queue is Empty \n";
			}
			else {
				cout << "\n Queue is not Empty \n";
			}
			break;
			
		case 5:
			if(isEmpty()) {
				cout << "\n Queue is Empty \n";
			}
			cout << "Front : " << arr[front] << endl;
			break;
			
		case 6:
			if(isEmpty()) {
				cout << "\n Queue is Empty \n";
				break;
			}
			cout << "Rear : " << arr[rear] << endl;
			break;
			
		case 7:
			exit(0);
			break;
			
		default:
			cout << "\n Please Enter a Valid choice \n";
			break;
	}
	} while (1);
}
