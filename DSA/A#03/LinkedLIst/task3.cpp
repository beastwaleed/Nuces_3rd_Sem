#include<iostream>
#include<string>
using namespace std;

class Node
{
public:
	int data;
	Node* next;
	Node* prev;

	Node(int val)
	{
		data = val;
		next = NULL;
		prev = NULL;
	}
};

class DoublyList {
private:
	Node* head;
public:
	DoublyList() {
		head = NULL;
	}

	void insertAtHead(int val) {
		Node* newNode = new Node(val);

		newNode->next = head;
		newNode->prev = NULL;

		if (head != NULL) {
			head->prev = newNode;
		}

		head = newNode;

	}

	void insertAtTail(int val) {
		Node* newNode = new Node(val);
		if (head == NULL) {
			head = newNode;
			return;
		}

		Node* curr = head;
		while (curr->next != NULL) {
			curr = curr->next;
		}
		curr->next = newNode;
		newNode->prev = curr;
		//newNode->next = NULL;
	}

	void insertNodeinMiddle(int val, int key) {
		Node* newNode = new Node(val);
		Node* curr = head;
		Node* temp = head;

		while (curr != NULL) {
			if (curr->data == key) {
				newNode->prev = curr;
				newNode->next = curr->next;
				curr->next = newNode;
				newNode->next->prev = newNode;
			}
			curr = curr->next;
		}

	}

	void removeFirst() {
		if (head == NULL) {
			cout << "List is empty!" << endl;
			return;
		}
		head = head->next;	
		head->prev = NULL;
	}

	void removeLast() {
		Node* curr = head;

		if (head == NULL) {
			cout << "List is Empty" << endl;
		}
		if (head->next == NULL) {
			delete head;
			head = NULL;
			return;
		}
		while (curr->next != NULL) {
			curr = curr->next;
		}
		curr->prev->next = NULL;  // Remove the last node from the list
		delete curr;			 // Free the memory of the last node
	}

	bool search(int data) {
		Node* curr = head;

		while (curr != NULL) {
			if (curr->data == data) {
				return true;
			}
			curr = curr->next;
		}
		return false;

	}


	void printList() {
		Node* curr = head;
		while (curr != NULL) {
			cout << curr->data << " ";
			curr = curr->next;
		}
		cout << endl;
	}

	void removeAtPosition(int key) {
		Node* curr = head;
		int counter = 1;
		while (curr != NULL) {
			if (curr->data == key) {
				curr->prev->next = curr->next;
				curr->next->prev = curr->prev;
			}
			curr = curr->next;
			counter++;
		}
	}
};

class CircularList {
private:
	Node* head;
public:
	CircularList() {
		head = NULL;
	}

	void insertNodeAtBeginning(int data) {
		Node* newNode = new Node(data);
		Node* curr = head;
		if (head == NULL) {
			head = newNode;
			newNode->next = head;

		}
		else {
			while (curr->next != head) {
				curr = curr->next;
			}
			newNode->next = head;
			curr->next = newNode;
			head = newNode;
		}
	}

	void insertNodeAtTail(int val) {
		Node* newNode = new Node(val);
		Node* curr = head;

		if (head == NULL) {
			head = newNode;
		}
		else {
			do {
				curr = curr->next;
			} while (curr->next != head);
			curr->next = newNode;
			newNode->next = head;

		}
	}

	void display() {
		Node* curr = head;
		do {
			cout << curr->data << " ";
			curr = curr->next;
		} while (curr != head);
	}

	bool deleteFirstNode() {
		Node* curr = head;
		Node* temp = head;
		if (head == NULL) { //if no node 
			return false;
		}   //for 1 node
		else if (head->next == NULL) {
			delete head;
			head = NULL;
		}
		do {
			curr = curr->next;
		} while (curr->next != head);

		head = head->next;

		if (curr == head) {
			curr->next = NULL;
			delete temp;
		}

		else {
			curr->next = head;
			delete temp;
		}
		return true;
	}

	bool deleteLastNode() {
		Node* curr = head;
		Node* temp = head;
		if (head == NULL) { //if no node
			return false;
		}
		if (head->next == NULL) { // if only 1 node
			head = NULL;
			return true;
		}
		//if 2 nodes
		if (curr->next->next == head) {
			while (curr->next != head) {
				curr = curr->next;
			}
			head->next = NULL;
			delete curr;
			return true;
		}

		else { //more than 2 nodes
			do {
				curr = curr->next;
			} while (curr->next != head);

			// Finding the second-to-last node
			while (temp->next != curr) {
				temp = temp->next;
			}

			// Updating the second-to-last node to point to head
			temp->next = head;
			delete curr;  // Deleting the last node

			return true;
		}
	}

	bool deleteNode(int key) {
		Node* curr = head;
		Node* temp = head;

		if (head == NULL) { //list empty
			return false;
		}

		if (curr->data == key && curr->next == NULL) {
			delete head;
		}

		if (curr->data == key) {
			if (deleteFirstNode()) {
				return true;
			}
			return false;
		}

		while (curr->next != head) {
			curr = curr->next;
		}
		if (curr->data == key) {
			if (deleteLastNode()) {
				return true;
			}
			return false;
		}

		curr = head;
		while (curr->next != head) {
			if (curr->data == key) {
				if (curr->next != head) {
					temp->next = curr->next;
					delete curr;
					return true;
				}
				else {
					if (curr->next == head) {
						temp = head;
						while (temp->next != curr) {
							temp = temp->next;
						}
						temp->next = head;
						delete curr;
						return true;
					}
					// return true;
				}
			}
			else {
				temp = curr;
				curr = curr->next;
			}
		}
		return true;
	}


	bool search(int key) {

		if (head == NULL) {
			return false;  // List is empty
		}

		Node* curr = head;
		do {
			if (curr->data == key) {  // Correct comparison
				return true;  // Value found
			}
			curr = curr->next;
		} while (curr != head);  // Loop until we return to the head

		return false;
	}

};

int main() {
	DoublyList L1;
	L1.insertAtTail(10);
	L1.insertAtTail(20);
	L1.insertAtTail(30);
	L1.insertAtTail(40);
	L1.printList();
	L1.insertNodeinMiddle(25, 30);
	L1.printList();
	L1.removeAtPosition(25);
	L1.printList();
	if (L1.search(20)) {
		cout << "Data available in List\n";
	};
	L1.printList();

	cout << "\n===> CIRCULAR LINKEDLIST <========\n\n";

	CircularList CL1;
	CL1.insertNodeAtBeginning(10);
	CL1.insertNodeAtBeginning(20);
	CL1.insertNodeAtBeginning(30);
	CL1.display();
	cout << endl;
	CL1.insertNodeAtTail(700);
	CL1.insertNodeAtTail(800);
	CL1.insertNodeAtTail(900);
	CL1.display();
	cout << endl;
	CL1.deleteFirstNode();
	CL1.display();
	cout << endl;
	CL1.deleteLastNode();
	CL1.insertNodeAtTail(900);
	CL1.display();
	CL1.deleteNode(800);
	cout << endl;
	CL1.display();
	if (CL1.search(7000) == true) {
		cout << "\nValue Found\n";
	}
	else {
		cout << "\nValue Not Found\n";
	}


}