//#include<iostream>
//using namespace std;
//
//class Queue { //queue class
//private:
//	char* arr;
//	int front;
//	int rear;
//	int capacity;
//	int counter;
//
//public:
//	Queue(int size) {
//		arr = new char[size];
//		capacity = size;
//		front = -1;
//		rear = -1;
//		counter = 0;
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
//		if (counter == capacity) {
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
//			arr[rear] = val;
//			rear++;
//			counter++;
//		}
//	}
//
//	char deQueue() {
//		char val = 0;
//		if (isEmpty() == true) {
//			cout << "Queue is Empty\n";
//			return '\0';
//
//		}
//
//		else {
//			val = arr[front];
//			arr[front] = -1;
//			front++;
//			counter--;
//
//
//		}
//		return val;
//
//	}
//
//	int peek() {
//		if (isEmpty()) {
//			return '\0';
//		}
//		else {
//			return arr[front];
//		}
//	}
//
//	void currentSize() {
//		cout << "Current Elements in Queue are: " << counter << endl;
//	}
//};
//
//class Stack { //stack class
//	char* arr;
//	int top;
//	int capacity;
//
//public:
//	Stack(int cap) {
//		capacity = cap;
//		arr = new char[capacity];
//		top = -1;
//	}
//
//	bool isFull() {
//		if (top == capacity - 1) {
//			return true;
//		}
//		else {
//			return false;
//		}
//	}
//
//	bool isEmpty() {
//		if (top == -1) {
//			return true;
//		}
//		else {
//			return false;
//		}
//	}
//
//	void push(char val) {
//		if (isFull()) {
//			cout << "Stack is Full, Cannot Push More!!!" << endl;
//		}
//		top++;
//		arr[top] = val;
//	}
//
//	char pop() {
//		if (isEmpty()) {
//			cout << "Stack is Empty, Cannot Pop!!" << endl;
//		}
//		else {
//			return arr[top--];
//		}
//		return '\0';
//	}
//
//};
//
////palindrome check function
//bool palindromeCheck(char arr[], int size) { //passing user input character array from main and its length
//	Queue q(size); //creating a queue object to store all characters in queue
//	Stack s(size); //creating a stack object to store all character in stack
//
//	for (int i = 0;i < size;i++) { //storing all character in stack and queue one by one
//		q.enQueue(arr[i]);
//		s.push(arr[i]);
//	}
//
//	//now compare each character of stack with queue and vice versa
//	for (int i = 0;i < size;i++) { 
//		char queue = q.deQueue(); //dequeuing and saving a char from queue in a variable
//		char stack = s.pop(); //popping and saving a char from stack in a variable
//
//		if (queue != stack) { //if both characters are not equal then return false
//			return false;
//		}
//	}
//	return true; //else return truee;
//}
//
//int main() {
//	string userInput; //for getting string from user
//
//	cout << "=============================================\n"
//		<< "~~~~~~~~~~~~PALINDROME CHECKER~~~~~~~~~~~~\n"
//		<< "=============================================\n";
//
//	cout << "Enter a String to check Palindrome: " << endl;
//	cin >> userInput;
//
//	int count = userInput.length(); //size of string
//	char characters[count]; //making a array of size of characters
//
//	for (int i = 0;i < count;i++) {
//		characters[i] = userInput[i]; //moving all characters from string to character array
//	}
//
//	//calling palidrome function with array and size arguments
//	if (palindromeCheck(characters, count) == true) { 
//		cout << "String is Palindrom :D" << endl;
//	}
//	else {
//		cout << "String is Not Palindrome :(" << endl;
//	}
//
//	system("pause");
//	return 0;
//}