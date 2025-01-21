//#include<iostream>
//#include<string>
//using namespace std;
//
//class Node {
//public:
//	int data;
//	Node* next;
//
//	Node(int d) {
//		data = d;
//		next = NULL;
//	}
//};
//
//class Stack {
//	int capacity;
//	int currSize;
//	Node* top;
//
//public:
//	Stack(int size) {
//		capacity = size;
//		currSize = 0;
//		top = NULL;
//	}
//
//	bool isEmpty() {
//		if (top == NULL) {
//			return true;
//		}
//		else {
//			return false;
//		}
//	}
//
//	bool isFull() {
//		if (currSize == capacity) {
//			return true;
//		}
//		else {
//			return false;
//		}
//	}
//
//	void Push(int val) {
//		if (isFull()==true) {
//			cout << "Not Empty Space: Underflow!!\n";
//		}
//		else {
//			Node* newNode = new Node(val);
//			newNode->next = top;
//			top = newNode;
//			currSize++;
//			return;
//		}
//}
//	void Pop() {
//		if (isEmpty()) {
//			cout << "Underflow !! Nothing to Remove\n";
//		}
//		else {
//			Node* curr;
//			curr = top->next;
//			delete top;
//			top = curr;
//		}
//	}
//
//	void Peek() {
//		if (isEmpty()) {
//			cout << "Underflow !! Nothing to Display\n";
//		}
//		else {
//			cout << top->data;
//			cout << endl;
//		}
//	}
//
//};
//
//int main() {
//	Stack s1(5);
//	s1.Push(7);
//	s1.Peek();
//	s1.Push(2);
//	s1.Push(1);
//	s1.Push(3);
//	s1.Push(8);
//	s1.Peek();	
//	//s1.Push(6);
//	//s1.Peek();
//	s1.Pop();
//	s1.Peek();
//
//
//
//
//	system("pause");
//	return 0;
//
//}