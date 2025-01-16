//#include<iostream>
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
//	Node* top;
//public:
//
//	Stack() {
//		top = NULL;
//	}
//
//	bool isEmpty() {
//		return top == NULL;
//	}
//
//	void push(int val)
//	{
//		Node* newNode = new Node(val);
//		newNode->next = top;
//		top = newNode;
//	}
//
//	int pop() {
//		if (isEmpty()) {
//			cout << "Stack Is Empty!!!" << endl;
//			return -1;
//		}
//		else {
//			Node* curr = top;
//			int value = top->data;
//			top = top->next;
//			delete curr;
//			return value;
//		}
//	}
//
//	int peek() {
//		if (isEmpty()) {
//			return -1;
//		}
//		return top->data;
//	}
//};
//
//int main() {
//	int choice, disk, moves = 0;
//	cout << "<========> TOWER OF HANOI GAME <========>" << endl;
//
//	// Ensure the user enters a valid number of disks
//	do {
//		cout << "Enter Number of Disk: ";
//		cin >> disk;
//	} while (disk <= 0);
//
//	Stack s1, s2, s3;
//
//	// Push disks into stack 1
//	for (int i = disk; i > 0; i--) {
//		s1.push(i);
//	}
//
//	do {
//		cout << "\n\n===> Play Your Moves\n"
//			<< "1. Move Stack 1 to Stack 3\n"
//			<< "2. Move Stack 1 to Stack 2\n"
//			<< "3. Move Stack 2 to Stack 1\n"
//			<< "4. Move Stack 2 to Stack 3\n"
//			<< "5. Move Stack 3 to Stack 1\n"
//			<< "6. Move Stack 3 to Stack 2\n"
//			<< "Your Move: ";
//		cin >> choice;
//
//		int s1Num = s1.peek();
//		int s2Num = s2.peek();
//		int s3Num = s3.peek();
//
//		if (choice == 1) {
//			if (s3Num > s1Num || s3Num == -1) {
//				s3.push(s1.pop());
//				moves++;
//			}
//			else {
//				cout << "Cannot Move " << s1Num << " to Stack 3 Because " << s1Num << " is Greater than " << s3Num << endl;
//			}
//		}
//		else if (choice == 2) {
//			if (s2Num > s1Num || s2Num == -1) {
//				s2.push(s1.pop());
//				moves++;
//			}
//			else {
//				cout << "Cannot Move " << s1Num << " to Stack 2 Because " << s1Num << " is Greater than " << s2Num << endl;
//			}
//		}
//		else if (choice == 3) {
//			if (s1Num > s2Num || s1Num == -1) {
//				s1.push(s2.pop());
//				moves++;
//			}
//			else {
//				cout << "Cannot Move " << s2Num << " to Stack 1 Because " << s2Num << " is Greater than " << s1Num << endl;
//			}
//		}
//		else if (choice == 4) {
//			if (s3Num > s2Num || s3Num == -1) {
//				s3.push(s2.pop());
//				moves++;
//			}
//			else {
//				cout << "Cannot Move " << s2Num << " to Stack 3 Because " << s2Num << " is Greater than " << s3Num << endl;
//			}
//		}
//		else if (choice == 5) {
//			if (s1Num > s3Num || s1Num == -1) {
//				s1.push(s3.pop());
//				moves++;
//			}
//			else {
//				cout << "Cannot Move " << s3Num << " to Stack 1 Because " << s1Num << " is Greater than " << s3Num << endl;
//			}
//		}
//		else if (choice == 6) {
//			if (s2Num > s3Num || s2Num == -1) {
//				s2.push(s3.pop());
//				moves++;
//			}
//			else {
//				cout << "Cannot Move " << s3Num << " to Stack 2 Because " << s2Num << " is Greater than " << s3Num << endl;
//			}
//		}
//		else {
//			cout << "Invalid Move!! Please select a Valid Option" << endl;
//		}
//
//	} while (!s3.isEmpty() && s3.peek() != disk);
//
//	cout << "\n!!! Congratulations!!! You Won the Game\nMoves: " << moves << endl;
//
//	return 0;
//}
