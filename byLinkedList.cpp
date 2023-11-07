#include<bits/stdc++.h>
#define MAX 5
using namespace std;

struct node{
	int data;
	node *next;
};

struct node *front = NULL;
struct node *rear = NULL;

struct node *ptr = (struct node *) malloc(sizeof(struct node));


void push(int data) {
	struct node *newNode = (struct node *) malloc(sizeof(struct node));
	newNode -> data = data;
	newNode -> next = NULL;

	if(front == NULL) {
		front = newNode;
	}
	rear = newNode;
	free(newNode);
	
	cout << "\n" << data << " is inserted in queue";
	return;
}

void pop() {
	if(front == NULL && rear == NULL) {
		cout << "\nQueue is Empty" << "\n";
		return;
	}
	struct node *temp = (struct node *) malloc (sizeof(struct node));
	temp = front;
	front = front -> next;
	cout <<"\n" << temp->data << " is deleted from queue \n"<< endl;
	free (temp);
	
	return;
	
}

int main() {
	cout << "\n Queue implementation using Linked List";
	push(12);
	ptr -> data = 19;
	ptr -> next = NULL;
	cout << "\n" << ptr->data << endl;
	cout << front << endl;
	cout << front->data << endl;
	push(6);
	push(45);
	push(95);
	push(40);
	push(18);
	
	cout << front << endl;
	cout << front->data << endl;
	cout << rear -> data << endl;
	pop();
	pop();
	
	return 0;
}

