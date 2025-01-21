//#include<iostream>
//#include<string>
//using namespace std;
//
//class Queue {
//	int* queueArray;
//	int queueSize;
//	int front;
//	int rear;
//	int added = 0;
//
//public:
//	Queue(int size) {
//		queueSize = size;
//		queueArray = new int[size];
//		front = 0;
//		rear = 0;
//	}
//
//	bool isEmpty() {
//		if (rear == front) {
//			return true;
//		}
//
//		return false;
//	}
//
//	bool isFull() {
//		if (added == queueSize) {
//			return true;
//		}
//		else {
//			return false;
//		}
//	}
//
//	void enQueue(int val) {
//		if (isFull() == true) {
//			cout << "OVERFLOW!!\n";
//		}
//		else {
//			queueArray[rear] = val;
//			rear++;
//			added++;
//		}
//	}
//
//	int deQueue() {
//		int num = 0;
//		if (isEmpty() == true) {
//			cout << "Queue is Empty\n";
//			return -1;
//
//		}
//
//		else {
//			num = queueArray[front];
//			queueArray[front] = -1;
//			front++;
//			added--;
//
//
//		}
//		return num;
//
//	}
//
//	int frontNum() {
//		if (isEmpty()) {
//			return -1;
//		}
//		else {
//			return queueArray[front];
//		}
//	}
//
//	void currentElements() {
//		cout << "Current Elements in Queue are: " << added << endl;
//	}
//};
//
//int main() {
//	int popNum;
//	int frontElement;
//
//	Queue Q1(5);
//	Q1.enQueue(1);
//	Q1.enQueue(3);
//	Q1.enQueue(4);
//	Q1.enQueue(7);
//	Q1.enQueue(9);
//	Q1.currentElements();
//	Q1.enQueue(10);
//
//	popNum = Q1.deQueue();
//	cout << popNum << endl;
//
//	frontElement = Q1.frontNum();
//	cout << frontElement << endl;
//
//	system("pause");
//	return 0;
//
//}