#include<iostream>
using namespace std;

class Node {
public:
	Node* next;
	int data;

	Node(int val) {
		data = val;
		next = NULL;
	}
};

class DEqueue {
private:
	Node* front, * rear;
	int size;
public:
	DEqueue() {
		front = rear = NULL;
		size = 0;
	}

	bool isEmpty() {
		if (front == NULL) {
			return true;
		}
		else {
			return false;
		}
	}

	void insertFront(int val) {
		Node* newNode = new Node(val);
		if (isEmpty()) {
			front = rear = newNode;
		}
		else {
			newNode->next = front;
			front = newNode;
		}
		size++;
	}

	void insertRear(int val) {
		Node* newNode = new Node(val);
		if (isEmpty()) {
			front = rear = newNode;
		}
		rear->next = newNode;
		rear = newNode;
		size++;
	}

	void RemoveFront() {
		if (front == NULL) {
			cout << "Queue Is Empty\n";
		}
		Node* temp = front;
		front = front->next;
		delete temp;
		size--;
	}

	void RemoveRear() {
		if (isEmpty()) {
			cout << "Stack is Empty\n";
			return;
		}

		if (front == rear) {
			delete front;
			front = rear = NULL;
			return;
		}

		Node* curr = front;
		while (curr->next != rear) {
			curr = curr->next;
		}
		delete rear;
		rear = curr;
		rear->next = NULL;
		size--;
	}

	int peek() {
		if (isEmpty()) {
			cout << "Stack is Empty\n";
			return -1;
		}
		return front->data;
	}

	void queueSize() {
		cout << "Total Elements in Queue are: " << size << endl;

	}

};

int main() {
	DEqueue q1;
	q1.insertFront(1);
	q1.insertFront(4);
	q1.insertRear(7);
	q1.queueSize();
	cout << q1.peek() << endl;
	q1.RemoveFront();
	cout << q1.peek() << endl;
	q1.RemoveFront();
	cout << q1.peek() << endl;
	q1.RemoveRear();
	cout << q1.peek() << endl;



}