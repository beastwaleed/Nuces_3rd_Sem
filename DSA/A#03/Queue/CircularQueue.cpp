#include<iostream>
#include<string>
using namespace std;

class CircularQueue {
	int* array;
	int queueSize;
	int front;
	int rear;
	int count;

public:
	CircularQueue(int s) {
		array = new int[s];
		queueSize = s;
		front = -1;
		rear = -1;
		count = 0;
	}

	bool isEmpty() {
		if (rear == -1 && front == -1) {
			return true;
		}
		else {
			return false;
		}
	}

	bool isFull() {
		if ((rear + 1) % queueSize == front) {
			return true;
		}
		else {
			return false;
		}
	}

	void enqueue(int num) {
		if (isFull()) {
			cout << "OVERFLOW!!" << endl;
			return;
		}
		else if (isEmpty()) {
			rear = front = 0;
		}
		else {
			rear = (rear + 1) % queueSize;
		}
		cout << "Data Enqueued: " << num << endl;
		count++;
		array[rear] = num;
	}

	int dequeue() {
		int num = 0;
		if (isEmpty()) {
			cout << "UNDERFLOW!!" << endl;
			return -1;
		}
		num = array[front];
		array[front] = -1;

		if (front == rear) {
			front = rear = -1;
		}
		else {
			front = (front + 1) % queueSize;
		}
		cout << "Data Dequeued: " << num << endl;
		count--;
		return num;
	}

	void display() {
		if (isEmpty()) {
			cout << "Queue is empty" << endl;
			return;
		}
		cout << "Displaying Circular Queue (-1 Shows the Index is Empty):\n";
		int i = front;
		while (true) {
			cout << array[i] << " ";
			if (i == rear) break;
			i = (i + 1) % queueSize;
		}
		cout << endl;
	}

};

int main() {
	CircularQueue Q1(10);
	Q1.enqueue(1);
	Q1.enqueue(2);
	Q1.enqueue(3);
	Q1.enqueue(5);
	Q1.enqueue(10);
	Q1.dequeue();
	Q1.enqueue(24);
	Q1.dequeue();
	Q1.enqueue(60);
	Q1.display();

	system("pause");
	return 0;
}