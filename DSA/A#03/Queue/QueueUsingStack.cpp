 #include<iostream>
using namespace std;

class Node {
public:
	int data;
	Node* next;

	Node(int val) {
		data = val;
		next = NULL;
	}

};

class Stack {
	Node* top;
	int size;

public:
	Stack() {
		top = NULL;
		size = 0;
	}

	bool isEmpty() {
		return top == NULL;
	}

	void Push(int x) {
		Node* newNode = new Node(x);
		newNode->next = top;
		top = newNode;
		size++;
	}

	void Pop() {
		if (isEmpty()) {
			cout << "Stack is Empty\n";
			return;
		}

		Node* temp = top;
		top = top->next;
		delete temp;
	}

	int TopElement() {
		if (isEmpty()) {
			return -1;
		}
		return top->data;
	}

};

class Queue {
	Stack s1, s2;
public:
	void enqueue(int val) {
		while (!s1.isEmpty()) {
			s2.Push(s1.TopElement());
			s1.Pop();
		}

		s1.Push(val);

		while (!s2.isEmpty()) {
			s1.Push(s2.TopElement());
			s2.Pop();
		}
	}

	void dequeue() {
		s1.Pop();
	}

	int peek() {
		return s1.TopElement();
	}
};

int main() {
	Queue q1;
	q1.enqueue(1);
	q1.enqueue(4);
	q1.enqueue(5);
	q1.enqueue(7);
	cout << q1.peek() << endl; //1
	q1.dequeue(); //delete 1
	cout << q1.peek() << endl; //4

}