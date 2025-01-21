#include <iostream>
#include <string>
using namespace std;

class Node {
public:
	Node* prev, * next;
	char character;

	Node() {
		prev = NULL;
		next = NULL;
	}

	Node(char d) {
		character = d;
		prev = NULL;
		next = NULL;
	}
};

class DoublyCircularList {
	Node* head;
public:
	DoublyCircularList() {
		head = NULL;
	}

	void insertAtTail(char input) {
		Node* newNode = new Node(input);
		// When there is no node
		if (head == NULL) {
			head = newNode;
			newNode->next = head;
			head->prev = newNode;
			return;
		}

		Node* curr = head;

		// When there is only one node
		if (curr->next == head) {
			curr->next = newNode;
			curr->prev = newNode;
			newNode->prev = curr;
			newNode->next = curr;
		}

		// When there are n number of nodes
		do {
			curr = curr->next;
		} while (curr->next != head);

		curr->next = newNode;
		newNode->prev = curr;
		newNode->next = head;
		head->prev = newNode;

	}

	bool checkIfNumbers() {
		if (head == nullptr) {
			cout << "\n-- List is empty. Cannot check for digits.\n";
			return false;
		}

		Node* curr = head;
		bool allFoundDigits = true;

		do {
			if (curr->character < '0' || curr->character > '9') {
				allFoundDigits = false;
				break;
			}
			curr = curr->next;
		} while (curr != head);

		return allFoundDigits;
	}

	bool isVowelCheck(char ch) {
		return (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' ||
			ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U');
		//else return false if not vowel
		return false;
	}
	void rotateString() { //function for rotating string
		if (head == NULL) {
			cout << "\nList is Empty\n";
			return;
		}

		head = head->next;
	}
	void PigLatin() {
		if (head == NULL) { //if there is no node in list
			cout << "\nList is Empty\n";
			return;
		}

		Node* curr = head;

		// if first letter is vowel
		if (isVowelCheck(curr->character)) {
			displayChar();
			cout << "-way" << endl;
			return;
		}

		else {
			Node* Dash = new Node('-'); //for using it as condition fulfils
			insertAtTail('-');
		}

		if (checkIfNumbers()) {
			displayChar();
			cout << "way" << endl;
			return;
		}

		Node* endNode;
		while (curr->next != head) {
			curr = curr->next;
		}
		endNode = curr;
		curr = head;

		do {
			if (isVowelCheck(curr->character)) {
				displayChar();
				cout << "ay";
				return;
			}

			else {
				rotateString();
			}
			curr = curr->next;
		} while (curr->next != endNode);

		displayChar();
		cout << "ay" << endl;
	}

	void displayChar() {
		if (head == NULL) {
			cout << "\nList is Emptyn";
			return;
		}

		cout << "\nString is: \n\n";

		Node* curr = head;

		do {
			cout << curr->character;
			curr = curr->next;
		} while (curr != head);
	}
};

int main() {
	DoublyCircularList l1;
	string Userinput;

	cout << "Enter a string: ";
	getline(cin, Userinput);

	for (int i = 0; i < Userinput.length(); i++) {
		l1.insertAtTail(Userinput[i]);
	}

	// Display the original string
	cout << "Original string: ";
	l1.displayChar();

	// Converting the string to Pig Latin
// 	l1.display();
	cout << "\n\nPig Latin form ==>  ";
	l1.PigLatin();

	system("pause");
	return 0;
}
