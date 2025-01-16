//#include<iostream>
//#include<string>
//using namespace std;
//
//class Node {
//public:
//	char data;
//	Node* next;
//
//	Node(char data) {
//		this->data = data;
//		next = NULL;
//	}
//};
//
//class Stack {
//	int capacity;
//	int currentSize;
//	Node* Top;
//public:
//	Stack(int size) {
//		capacity = size;
//		currentSize = 0;
//		Top = NULL;
//	}
//
//	bool isEmpty() {
//		if (Top == NULL) {
//			return true;
//		}
//		else { return false; }
//	}
//
//	bool isFull() {
//		if (currentSize == capacity) {
//			return true;
//		}
//		else {
//			return false;
//		}
//	}
//
//	bool push(char value) {
//		if (isFull()) {
//			cout << "Cannot Add More Characters!!!" << endl;
//			return false;
//		}
//		else {
//			Node* newNode = new Node(value);
//			newNode->next = Top;
//			Top = newNode;
//			//Top = Top->next;
//			return true;
//		}
//	}
//
//	char pop() {
//		char val = '0';
//		if (isEmpty()) {
//			cout << "Empty Stack!!!" << endl;
//			return '\0';
//		}
//		else {
//			Node* temp = Top;
//			val = Top->data;
//			Top = Top->next;
//			delete temp;
//		}
//		return val;
//	}
//
//	bool isPalindrome(string word) {
//		for (int i = 0;i < word.length();i++) {
//			push(word[i]);
//		}
//
//		for (int i = 0;i < word.length();i++) {
//			if (pop() != word[i]) {
//				return false;
//			}
//		}
//		return true;
//	}
//
//	void display() {
//		Node* curr = Top;
//		while (Top != NULL) {
//			cout << Top->data << " ";
//			Top = Top->next;
//		}
//		cout << endl;
//		Top = curr;
//	}
//};
//
//int main() {
//	Stack newWord(4);
//	string input;
//
//	cout << "Enter a String: ";
//	cin >> input;
//
//	if (newWord.isPalindrome(input) == true) {
//		cout << input << " is Palindrome" << endl;
//	}
//	else {
//		cout << input << " is Not Palindrome" << endl;
//	}
//
//	system("pause");
//	return 0;
//};
