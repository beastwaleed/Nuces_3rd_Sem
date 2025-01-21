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
		Node* prev = NULL;

		if (head == NULL) {
			cout << "No Nodes Present\n";
			return false;
		}

		// Handle deletion when the list has only 1 node
		if (head->next == NULL) {
			if (head->data == key) {
				delete head;
				head = NULL;
				return true;
			}
			return false;
		}

		// for 2 nodes
		if (head->next->next == NULL) {
			curr = head;
			while (curr != NULL) {
				if (curr->data == key && curr == head) {
					head = head->next;
					delete curr;
					return true;
				}
				if (curr->data == key && curr->next != NULL) {
					curr = curr->next;
					delete curr;
					head->next = NULL;
					return true;
				}
				curr = curr->next;
			}
			return false;
		}

		// for more than 2 nodes
		curr = head;
		while (curr != NULL) {
			if (curr->data == key) {
				if (curr == head) {
					head = curr->next;
					delete curr;
					curr = head;
				}
				else {
					prev->next = curr->next;
					delete curr;
					curr = prev->next;
				}
				return true;
			}
			prev = curr;
			curr = curr->next;
		}

		return false;
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
				return true;
				break;
			}
			curr = curr->next;
			counter++;
		}
		// 		cout << "Value " << val << " Found at Position " << counter << endl;
		return false;
	}

	void display() {
		Node* curr = head;
		while (curr != NULL) {
			cout << curr->data << " ";
			curr = curr->next;
		}
		cout << endl;

	}
	void removeDuplicate() {
		cout << "After Removing Duplicates: \n";
		Node* curr = head;
		Node* temp = NULL;
		if (head == NULL) {
			cout << "No Nodes Present\n";
		}
		if (head->next == NULL) {
			cout << "Only 1 node present\n";
		}

		if (head->next->next == NULL) { //for 2 nodes
			temp = curr;
			curr = curr->next;
			if (temp->data == curr->data) {
				delete temp;
				head = curr;
				// delete curr;
				// curr==NULL;
			}
			else {
				cout << "Both Nodes have different Data/Values\n";
			}
		}

		// For more than 2 nodes
		curr = head;
		while (curr != NULL) {
			Node* temp = curr;
			Node* prevTemp = curr;
			Node* nextTemp = curr->next;

			while (nextTemp != NULL) {
				if (curr->data == nextTemp->data) {
					// Remove duplicate node
					prevTemp->next = nextTemp->next;
					delete nextTemp;
					nextTemp = prevTemp->next; // Update nextTemp
				}
				else {
					prevTemp = nextTemp;
					nextTemp = nextTemp->next;
				}
			}
			curr = curr->next;
		}
	}


};

int main() {
	LinkedList L1;
	L1.insertNodeAtEnd(3);
	L1.insertNodeAtEnd(3);
	L1.insertNodeAtEnd(7);
	L1.insertNodeAtEnd(2);
	L1.insertInMiddle(9, 3);
	L1.display();
	L1.removeDuplicate();
	L1.display();
	L1.insertNodeAtEnd(3);
	L1.display();
	L1.removeDuplicate();
	L1.display();
	L1.insertNodeAtEnd(5);
	L1.display();
	L1.deleteNode(3); //deleting the node with value 1
	L1.display();
	L1.deleteLastNode();
	L1.display();
	if (L1.search(2)) {
		cout << "Value Found\n";
	};
	L1.display();


}