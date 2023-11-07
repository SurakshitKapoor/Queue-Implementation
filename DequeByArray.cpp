//deque implementation by using array with mannual writing of operations
#include<iostream>
#define MAX 5
using namespace std;

int arr[MAX];
int front=-1;
int rear=-1;

bool isFull() {
	if((front ==0 && rear == MAX-1) || (front == rear+1)){
		return 1;
	}
	else{
		return 0;
	}
}

bool isEmpty() {
	if(front==-1) {
		return 1;
	}
	else{
		return 0;
	}
}
void pushRear(int data) {
	if(isFull() ) {
		cout << "\n Queue is Full \n" << endl;
		return;
	}
	else if(front == -1) {
		front = 0;
		rear = 0;
	}
	
	//if front == 0, then, array is full; we can also ignore this condition as isFull already checked
	else if(rear == MAX-1 && front > 0) {
		rear = 0;
	}
	else{
		rear++;
	}
	arr[rear] = data;
	cout << "\n" << data << " is inserted in Dequeue \n";
	return;
}

void popFront() {
	int data;
	if(isEmpty()){
		cout << "\n Queue is Empty \n";
		return;
	}
	else if(front == rear) {
		
		data = arr[front];
		front = -1;
		rear = -1;
	}
	else if(front == MAX-1 && rear != front) {
		data = arr[front];
		front = 0;
	}
	else {
		
		data = arr[front];
		front ++;
	}
	cout << "\n" << data << " is deleted from dequeue \n";
	return;
}

void pushFront(int data) {
	if(isFull()){
		cout << "\nQueue is Full \n";
		return;
	}
	else if(front==-1){
		front = MAX-1;
		rear = MAX-1;
	}
	
	else if(front == 0 && rear != MAX-1){
		front = MAX-1;
	}
	
	else{
		front = front-1;
	}
	arr[front] = data;
	cout << "\n" << data << " is inserted in dequeue" << "\n";
	return;	
}

void popRear() {
	int data;
	if(isEmpty()) {
		cout << "\n Queue is Empty \n" ;
		return;
	}
	else if(front == rear) {
		data = arr[front];
		front = -1;
		rear = -1;
	}
	else if(rear == 0) {
		data = arr[rear];
		rear = MAX-1;
	}
	else{
		data = arr[rear];
		rear--;
	}
	
	cout << "\n" << data << " is deleted from dequeue" << endl;
	return;
}

void getFront() {
	if(isEmpty()) {
		cout << "\n Queue is Empty \n";
	}
	else{
		cout << "\n Front is : " << arr[front] << "\n";
	}
}

void getRear() {
	if(isEmpty()) {
		cout << "\n Queue is Empty \n";
	}
	else{
		cout << "\n Rear is : " << arr[rear] << "\n";
	}
}
int main() {
	cout << "WELCome in DEQUEUE \n" << endl;
	
	pushRear(12);
	pushRear(13);
	pushRear(14);
	pushRear(15);
	pushRear(16);
	pushRear(17);
	
	cout << "\n IsFull: "<<isFull() << "\n";
	cout << "\n isEmpty: "<< isEmpty() << "\n";
	
	getFront();
	getRear();
	
	popFront();
	popFront();
	
	getFront();
	getRear();
	
	pushFront(30);
	pushFront(40);
	pushFront(50);

	getFront();
	getRear();

	popRear();
	popFront();

	getFront();
	getRear();
		
}
