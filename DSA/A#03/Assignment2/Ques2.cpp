#include<iostream>
using namespace std;

class Node {
public:
	Node* next;
	char data;
	Node(char val) {
		data = val;
		next = NULL;
	}
};

class Stack {
	Node* top;
public:
	Stack() {
		top = NULL;
	}

	bool isEmpty() {
		if (top == NULL) {
			return true;
		}
		return false;
	}

	void push(char val) {
		Node* newChar = new Node(val);
		newChar->next = top;
		top = newChar;
		displayStack();
		return;
	}

	char pop() {
		if (isEmpty()) {
			cout << "\nThere is Nothing to Pop!!" << endl;
			return '\0';
		}

		Node* temp = top;
		char value = top->data;
		top = top->next;
		delete temp;
		displayStack();
		return value;
	}

	void displayStack() {
		Node* curr = top;
		cout << "\nStack: ";

		while (curr != NULL) {
			cout << curr->data << " ";
			curr = curr->next;
		}
		cout << endl;
	}

	bool isOperand(char val) {
		if (val >= '0' && val <= '9') {
			return true;
		}
		else {
			return false;
		}
	}

	bool checkPrecedence(char element) {
		if (element == '+' || element == '-') {
			return 1;
		}
		else if (element == '*' || element == '/' || element == '%') {
			return 2;
		}
		return 0;
	}

	string PostfixConversion(string original) {
		string postFix = "";
		//int operator1;
		char temp;
		int index = 0;

		while (index < original.length()) {
			char symbol = original[index];
			cout << "\nProcessing: " << symbol << endl;

			switch (symbol) {
			case'(':
				push(symbol);
				break;
			case')':
				while (top && top->data != '(') {
					temp = pop();
					postFix += temp;
					cout << "\nPostfix so far: " << postFix << endl;
				}

				pop(); //also remove '('
				break;

			default:

				if (isOperand(symbol) == true) {
					postFix += symbol;
					cout << "\nPostfix so far: " << postFix << endl;
				}
				else {
					int precedence = checkPrecedence(symbol);
					while (!isEmpty() && checkPrecedence(top->data) >= precedence) {
						postFix += pop();
						cout << "\nPostfix so far: " << postFix << endl;
					}
					push(symbol);
				}
				break;
			}
			index++;
		}
		while (!isEmpty()) {
			postFix += pop();
			cout << "\nPostfix so far: " << postFix << endl;

		}
		cout << "\n==> Final PostFix Expression: " << postFix << endl;
		evaluatePostfix(postFix);
		return postFix;

	}

	void evaluatePostfix(string postfix) {
		int* arr = new int[postfix.length()];
		int index = 0;

		cout << "\n ---- Postfix Evaluation ----" << endl;
		int i = 0;
		while (i < postfix.length()) {
			char symbol = postfix[i];

			if (isOperand(symbol)) {
				arr[index++] = symbol - '0'; //typecasting to int
			}
			else {
				int op2 = arr[--index];
				int op1 = arr[--index];
				int result = 0;

				switch (symbol) {
				case'+':
					result = op1 + op2;
					break;


				case'-':
					result = op1 - op2;
					break;

				case'*':
					result = op1 * op2;
					break;
				case'/':
					result = op1 / op2;
					break;
				case'%':
					result = op1 % op2;
					break;
				}

				arr[index++] = result;
				cout << op1 << " " << symbol << " " << op2 << " = " << result << endl;
			}
			i++;

		}
		cout << "\n ----> Final Result: " << arr[0] << endl;
		delete[]arr;
	}

	string PrefixConversion(string original) {
		string reversedInfix = ""; //for storing reversed Original Infix 
		string prefix = "";
		int i = original.length() - 1; //for loop

		//Step1: revversing the infix expression

		while (i >= 0) {
			if (original[i] == '(') {
				reversedInfix += ')';
			}
			else if (original[i] == ')') {
				reversedInfix += '(';
			}
			else {
				reversedInfix += original[i];
			}
			i--;
		}
		//Step2: convert reveresed expresssion into postfix
		string reversedPostfix = "";
		i = 0;
		while (i < reversedInfix.length()) {
			char symbol = reversedInfix[i];
			cout << "\nProcessing: " << symbol << endl;

			switch (symbol) {
			case '(':
				push(symbol);
				break;
			case ')':
				while (top && top->data != '(') {
					reversedPostfix += pop();
					cout << "\nReversed Postfix so far: " << reversedPostfix << endl;
				}
				pop(); // Remove '('
				break;
			default:
				if (isOperand(symbol)) {
					reversedPostfix += symbol;
					cout << "\nReversed Postfix so far: " << reversedPostfix << endl;
				}
				else {
					int precedence = checkPrecedence(symbol);
					while (!isEmpty() && checkPrecedence(top->data) >= precedence) {
						reversedPostfix += pop();
						cout << "\nReversed Postfix so far: " << reversedPostfix << endl;
					}
					push(symbol);
				}
				break;
			}
			i++;
		}
		while (!isEmpty()) {
			reversedPostfix += pop();
			cout << "\nReversed Postfix so far: " << reversedPostfix << endl;
		}

		//Step3: reversing the postfix to get prefix
		i = reversedPostfix.length() - 1;
		do {
			prefix += reversedPostfix[i];
			i--;
		} while (i >= 0);

		cout << "\n==> Final Prefix Expression: " << prefix << endl;
		evaluatePrefix(prefix);

		return prefix;
	}


	void evaluatePrefix(string prefix) {
		int* arr = new int[prefix.length()];
		int index = -1;

		cout << "\n--- Prefix Evaluation ---" << endl;

		int i = prefix.length() - 1;
		while (i >= 0) {
			char symbol = prefix[i];

			if (isOperand(symbol)) {
				arr[++index] = symbol - '0';
			}
			else {
				int op1 = arr[index--];
				int op2 = arr[index--];
				int result = 0;

				switch (symbol) {
				case'+':
					result = op1 + op2;
					break;


				case'-':
					result = op1 - op2;
					break;

				case'*':
					result = op1 * op2;
					break;
				case'/':
					result = op1 / op2;
					break;
				case'%':
					result = op1 % op2;
					break;
				}

				arr[++index] = result;
				cout << op1 << " " << symbol << " " << op2 << " = " << result << endl;

			}
			i--;
		}
		cout << "\n---> Final Result: " << arr[0] << endl;
		delete[] arr;
	}
};

int main() {
	Stack s1;
	int input;
	string infix;

	do {
		cout << "\n<==> INFIX TO POSTFIX/PREFIX CALCULATOR <==>" << endl
			<< "1. Infix  to Prefix Calculation: " << endl
			<< "2. Infix to Postfix Calculation: " << endl
			<< "3. Exit" << endl;
		cin >> input;

		if (input == 1) {
			cout << "Enter Infix Expression: ";
			cin >> infix;
			s1.PostfixConversion(infix);
		}

		if (input == 2) {
			cout << "Enter Infix Expression: ";
			cin >> infix;
			s1.PrefixConversion(infix);
		}
	}

	while (input != 3);
	//s.PrefixConversion(Infix);

	system("pause");
	return 0;
}