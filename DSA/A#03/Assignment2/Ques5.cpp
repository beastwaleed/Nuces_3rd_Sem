#include<iostream>
using namespace std;

class Dequeue {
private:
	int* arr;
	int front;
	int rear;
	int capacity;
	int counter;
public:
	Dequeue(int cap) {
		capacity = cap;
		arr = new int[capacity];
		front = -1;
		rear = -1;
		counter = 0;
	}

	bool isFull() {
		if (counter == capacity) {
			return true;
		}
		else {
			return false;
		}
	}

	bool isEmpty() {
		if (counter == 0) {
			return true;
		}
		else {
			return false;
		}
	}

	void enqueueFront(int val) {
		if (isFull()) {
			cout << "Queue is Full, Can't Insert!!!" << endl;
			return;
		}
		else if (front == -1) {
			front = rear = 0;
		}
		else if (front == 0 && rear != capacity - 1) {
			front = capacity - 1;
		}
		else {
			front--;
		}
		arr[front] = val;
		counter++;
	}

	void enqueueLast(int val) {
		if (isFull()) {
			cout << "Queue is Full, Can't Insert!!!" << endl;
			return;
		}
		else if (front == -1) {
			front = rear = 0;
		}
		else if (front != 0 && rear == capacity - 1) {
			rear = 0;
		}
		else {
			rear++;
		}
		arr[rear] = val;
		counter++;
	}

	int dequeueFront() {
		int num = 0;
		if (isEmpty()) {
			cout << "Queue is Empty!!!" << endl;
			return -1;
		}
		num = arr[front];
		arr[front] = -1;

		if (front == rear) {
			front = rear = -1;
		}
		else if (front == capacity - 1) {
			front = 0;
		}
		else {
			front++;
		}

		counter--;
		return num;
	}

	int dequeueLast() {
		int num = 0;

		if (isEmpty()) {
			cout << "Queue is Empty!!!" << endl;
			return -1;
		}
		num = arr[rear];
		arr[rear] = -1;

		if (front == rear) {
			front = rear = -1;
		}
		else if (rear == 0) {
			rear = capacity - 1;
		}
		else {
			rear--;
		}
		counter--;
		return num;
	}
};


int main() {
	Dequeue d1(5);
	d1.enqueueLast(1);
	d1.enqueueLast(3);
	d1.enqueueLast(5);
	cout << d1.dequeueFront() << endl;
	cout << d1.dequeueLast() << endl;
	cout << d1.dequeueLast() << endl;
	cout << d1.dequeueLast() << endl;

	sytem("pause");
	return 0;
}