#include<iostream>
#include<queue>
using namespace std;

queue<int>q;

int main() {
	cout << "Queue std lib implementation !" << endl;
	q.push(12);
	q.push(90);
	q.push(56);
	q.push(25);
	q.push(50);
	
	cout << "Front: " << q.front() << endl;
	cout << "Back: " << q.back() << endl;
	cout << "IsEmpty: " << q.empty() << endl;
	
	q.pop();
	
	cout << "Front: " << q.front() << endl;
	
	return 0;
	
}
