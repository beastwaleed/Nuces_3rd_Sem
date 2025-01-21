#include<iostream>
#include<string>
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

class LinkedList {
private:
	Node* head;
public:
	void insertAtBeginning(int val) {
		Node* newNode = new Node(val);
		newNode->next = head;
		head = newNode;
	}

	void insertInMiddle(int data, int key) {
		Node* newNode = new Node(data);
		Node* curr = head;
		int index = 1;

		while (curr->next != NULL) {
			if (curr->data == key)
			{
				break;

			}
			index = index + 1;
			curr = curr->next;
		}

		newNode->next = curr->next;
		curr->next = newNode;

	}

	void insertNodeAtEnd(int val) {
		Node* newNode = new Node(val);
		Node* curr = head;

		if (head == NULL) {
			head = newNode;
			return;
		}

		while (curr->next != NULL)
		{
			curr = curr->next;
		}
		curr->next = newNode;
	}

	bool deleteFirstNode() {
		Node* curr = head;
		if (head == NULL) {
			//cout << "There is No Node" << endl;
			return false;
		}
		else {
			head = head->next;
			return true;
		}
	}

	bool deleteNode(int key) {
		Node* curr = head;
		int index = 0;
		while (curr->next != NULL) {
			if (curr->data == key) {
				break;
			}

			index++;
			curr = curr->next;

		}
		curr = head;
		for (int i = 1;i < index;i++) {
			curr->next = curr->next->next;
		}

		curr = curr->next->next;
		// 		curr=NULL;
		return true;
	}

	bool deleteLastNode() {
		Node* curr = head;

		if (head == NULL) {
			cout << "List is Empty" << endl;
			return false;
		}

		while (curr->next->next != NULL) {
			curr = curr->next;
		}
		curr->next = NULL;
		// curr->next->next=NULL;
		return true;

	}

	bool search(int val) {
		Node* curr = head;
		int counter = 1;
		while (curr != NULL) {
			if (curr->data == val) {
				break;
			}
			curr = curr->next;
			counter++;
		}
		cout << "Value " << val << " Found at Position " << counter << endl;
		return true;
	}

	void display() {
		Node* curr = head;
		while (curr != NULL) {
			cout << curr->data << " ";
			curr = curr->next;
		}
		cout << endl;
	}
};

int main() {
	LinkedList L1;
	L1.insertNodeAtEnd(0);
	L1.insertNodeAtEnd(1);
	L1.insertNodeAtEnd(2);
	L1.insertNodeAtEnd(3);
	L1.insertInMiddle(4, 3);
	L1.insertNodeAtEnd(5);
	L1.deleteNode(2);
	L1.deleteLastNode();
	L1.display();
	L1.search(4);

	L1.display();

}