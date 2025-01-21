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
		if (front == -1) {
			return true;
		}
		else {
			return false;
		}
	}

	bool isFull() {
		if (rear == queueSize - 1) {
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
		if (isEmpty()) {
			rear = front = 0;
		}
		else {
			rear++;
		}
		array[rear] = num;
		cout << "Data Enqueued: " << num << endl;
		count++;
	}

	int dequeue() {
		int num = 0;
		if (isEmpty()) {
			cout << "UNDERFLOW!!" << endl;
			return -1;
		}
		num = array[front];

		if (front == rear) {
			// 			num = array[front];
			front = rear = -1;
		}
		else {
			front++;
		}
		cout << "Data Dequeued: " << num << endl;
		count--;
		return num;
	}

	void display() {
		front = 0;
		cout << "Queue Data List: " << endl;
		for (int i = front;i <= rear;i++) {
			cout << array[i] << endl;
		}
		cout << endl;
	}

};

int main() {
	CircularQueue Q1(10);
	Q1.enqueue(2);
	Q1.enqueue(4);
	Q1.enqueue(6);
	Q1.enqueue(8);
	Q1.enqueue(10);
	Q1.dequeue();
	// 	cout << num << endl;
	Q1.enqueue(44);
	Q1.enqueue(100);
	Q1.display();

	system("pause");
	return 0;
}