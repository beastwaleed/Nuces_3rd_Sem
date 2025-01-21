#include<iostream>
#include<string>
using namespace std;

class Stack {
private:
	char* arr;
	int top;
	int capacity;

public:
	Stack(int s) {
		arr = new char[s];
		top = -1;
		capacity = s;
	}

	bool isempty() {
		return top == -1;
	}

	bool isfull() {
		return top == capacity - 1;
	}

	void push(char val) {
		if (isfull()) {
			cout << "cannot push!!!!" << endl;
		}
		top++;
		arr[top] = val;
	}

	char pop() {
		if (isempty()) {
			cout << "stack is empty!!!" << endl;
			return '\0';
		}
		return arr[top--];
	}

	char peek() {
		if (isempty()) { return '\0'; }
		return arr[top];
	}

	void checkBrackets(string input, int size) {
		/*string infix;
		char op1, op2;*/

		for (int i = 0; i < size; i++) {
			if (input[i] == '(' && input[i + 1] == ')') {
				cout << "String is Correct\n";

			}
			else if (input[i] == '[' && input[i + 1] == ']') {
				cout << "String is Correct\n";
			}

			else if (input[i] == '{' && input[i + 1] == '}') {
				cout << "String is Correct\n";
			}
		}
	}

};

string removePairs(string input) {
	int size = input.size();
	Stack stack1(size);	//first stack
	Stack stack2(size);	//second stack


	for (char ch : input) {
		stack1.push(ch);
	}

	while (!stack1.isempty()) {
		char current = stack1.pop();

		if (!stack2.isempty() && stack2.peek() == current) {
			stack2.pop();
		}
		else {
			stack2.push(current);
		}
	}

	string result;
	while (!stack2.isempty()) {
		result += stack2.pop();
	}

	/*int n = result.size();
	for (int i = 0;i < n/2 ;i++){
		swap(result[i], result[n-i-1]);
		}*/

	return result;
}



int main() {
	Stack s1(100);
	string input;
	cout << "Enter String: ";
	cin >> input;

	cout << endl;
	cout << removePairs(input);
	cout << endl;



	//int size = input.length();

	//s1.checkBrackets(input, size);
	system("pause");
	return 0;

}