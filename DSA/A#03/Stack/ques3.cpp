#include<iostream>
#include<string>
using namespace std;

class Stack {
private:
	string* arr;
	int top;
	int size;
	int capacity;

public:
	Stack(int s) {
		capacity = s;
		arr = new string[capacity];
		top = -1;
		size = 0;
	}

	bool isEmpty() {
		return top == -1;
	}

	bool isFull() {
		return top == capacity - 1;
	}

	void push(string val) {
		if (isFull()) {
			cout << "Cannot Push!!!!" << endl;
			return;
		}
		top++;
		arr[top] = val;
		size++;
	}

	string pop() {
		string returnVal;
		if (isEmpty()) {
			cout << "Stack is Empty!!!" << endl;
			return "";
		}
		returnVal = arr[top];
		top--;
		size--;
		return returnVal;
	}

	bool operatorCheck(char input) {
		if (input == '+' || input == '-' || input == '*' || input == '/' || input == '%') {
			return true;
		}
		return false;
	}


	string postfixToInfix(string input, int size) {
		char element;
		for (int i = 0; i < size; i++) {
			element = input[i];
			if (operatorCheck(element)) {
				string op2 = pop();
				string op1 = pop();
				if (op2.empty() || op1.empty()) {
					cout << "Invalid Expression:";
					return "";
				}
				string infix = "(" + op1 + element + op2 + ")";
				push(infix);
			}

			else {
				push(string(1, element));
			}
		}
		return pop();
	}
};

int main() {
	Stack s1(100);
	string input;
	cout << "Enter Postfix Expressiion: " << endl;
	cin >> input;

	int size = input.length();
	string infix = s1.postfixToInfix(input, size);
	if (!infix.empty()) {
		cout << "Infix Expression: " << infix << endl;

	}

	system("pause");
	return 0;
}
