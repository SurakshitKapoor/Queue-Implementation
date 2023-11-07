//deque implementation by using array and loop with switch case with user choice operations 
#include<iostream>
#define MAX 5
using namespace std;

int front = -1;
int rear = -1;
int data;
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

void pushRear(int data) {
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
	cout << "\n" << data << " is inserted in hqueue \n";
	return ;
}

void popFront() {
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

void pushFront(int data) {
	if(isFull()) {
		cout << "\n Queue is Full \n";
		return;
	}
	else if(front == -1) {
		front = MAX-1;
		rear = MAX-1;
	}
	
//	here, if rear == MAX-1. then means, queue is full; also we can avoid this condition as if queue is Full, then its alread checked in isFull
	else if(front == 0 && rear != MAX-1) {
		front = MAX-1;
	}
	else{
		front --;
	}
	
	arr[front] = data;
	cout << "\n" << data << " is inserted in queue \n";
	return;
	
}

void popRear() {
	
	if(isEmpty()){
		cout << "\n Queue is Empty \n";
		return;
	}
	else if(front == rear) {
		data = arr[rear];
		front = -1;
		rear = -1;
	}
	else if(rear == 0) {
		data = arr[rear];
		rear = MAX-1;
	}
	else {
		data = arr[rear];
		rear --;
	}
	cout << "\n" << data << " is deleted from queue \n";
	return;
}

int main() {
	cout << "\n  Dequeue using Array with Loop \n";
	cout << "Enter the operation to perform on  Dequeue \n";
	
	do {
	cout << "1. PushRear; \t2. PopFront; \t3. PushFront; \t4. PopRear; \t5. isFull; \t6. isEmpty; \t7. getFront; \t8. getRear; \t9. End" << endl;
	int ch;
	cin >> ch;
	switch(ch) {
		case 1: 
			cout << "Enter the data to insert: "<< endl;
			cin >> data;
			pushRear(data);
			break;
			
		case 2: 
			popFront();
			break;
			
		case 3:
			cout << "Enter the data to insert: "<< endl;
			cin >> data;
			pushFront(data);
			break;
		
		case 4:
			popRear();
			break;
			
		case 5: 
			if(isFull()) {
				cout << "\n Queue is Full \n";
			}
			else {
				cout << "\n Queue is not Full \n";
			}
			break;
		
		case 6:
			if(isEmpty()) {
				cout << "\n Queue is Empty \n";
			}
			else {
				cout << "\n Queue is not Empty \n";
			}
			break;
			
		case 7:
			if(isEmpty()) {
				cout << "\n Queue is Empty \n";
			}
			cout << "Front : " << arr[front] << endl;
			break;
			
		case 8:
			if(isEmpty()) {
				cout << "\n Queue is Empty \n";
				break;
			}
			cout << "Rear : " << arr[rear] << endl;
			break;
			
		case 9:
			exit(0);
			break;
			
		default:
			cout << "\n Please Enter a Valid choice \n";
			break;
	}
	} while (1);
}
