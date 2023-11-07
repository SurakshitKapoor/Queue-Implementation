//queue implementation by using array and loop with switch case with user choice operations 
#include<iostream> 
#define MAX 5
using namespace std;

int arr[MAX];
int front = -1, rear = -1;
int data;
bool full;
bool empty;

bool isEmpty() {
	if(front == -1 || front > rear) {
		return 1;
	}	
	else{
		return 0;
	}
}

bool isFull() {
	if(rear == MAX-1) {
		return 1;
	}
	else{
		return 0;
	}
}

void push(int data){
	if(isFull()){
		cout << "\n Queue is Full \n";
		return;
	}
	if(front == -1) {
		front ++;
	}
	rear ++;
	arr[rear] = data;
	cout << data << " is inserted in queue \n";
	return;
}

void pop() {
	if(isEmpty()) {
		cout << "\n Queue is Empty \n";
		return ;
	}
	data = arr[front];
	for(int i = front; i<rear; i++) {
		arr[i] = arr[i+1];
	}
	rear--;
	cout << data << " is deleted from queue \n";
	return;
}

void showAll() {
	if(isEmpty()){
		cout << "\n Queue is Empty \n";
		return;
	}
	cout << "\n The Queue Elements are :\n";
	for(int i=front; i<=rear; i++){
		cout << arr[i] << "\t";
	}
	return;
}
int main() {
	cout << "hello" << endl;
	cout << "Choose the operation to perform on queue : " << "\n";
	int ch;
	
	do {
	cout << "1.Push; \t 2.Pop; \t 3.Front; \t 4.Rear; \t 5.ShowAll; \t 6.isEmpty; \t 7.isFull; \t 8.End \n" ;
	cin >> ch;
	
	switch(ch) {
		case 1: 
			full = isFull();
			if(full){
				cout << "\n Queue is Full \n";
			}
			else{
				cout << "Enter the data to insert: " << "\n";
				cin >> data;
				push(data);
			}
			break;	
		
		case 2:
			empty = isEmpty();
			if(empty) {
				cout << "\n Queue is Empty \n";
			}
			else{
				pop();
			}
			break;
		
		case 3: 
			empty = isEmpty();
			if(empty) {
				cout << "\n Queue is Empty \n";
			}
			else{
				cout << "\n Front is : " << arr[front] << "\n";
			}
			break;
			
		case 4:
			empty = isEmpty();
			if(empty) {
				cout << "\n Queue is Empty \n";
			}
			else{
				cout << "\n Rear is : " << arr[rear] << "\n";
			}
			break;
			
		case 5: 
			showAll();
			break;
			
		case 6:
			empty = isEmpty();
			if(empty) {
				cout << "\n Queue is Empty \n";
			}
			else{
				cout << "\n Queue is Not Empty \n";
			}
			break;
			
		case 7:
			full = isFull();
			if(full) {
				cout << "\n Queue is Full \n";
			}
			else{
				cout << "\n Queue is Not Full \n";
			}
			break;
			
		case 8: 
			exit(0);
		
		default: 
			cout << "\n Pls enter a valid choice; \n";
			break;
			 
		}
	} while(1);
}
