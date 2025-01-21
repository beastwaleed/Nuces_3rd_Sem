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
		if (head != NULL) {
			head->prev = NULL;
		}
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
		delete curr;  // Free the memory of the last node
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

	void deleteNode(int key) {
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

	void sorting() {
		cout << "After Sorting:\n";

		if (head == NULL) {  // No node
			cout << "No Data to Sort\n";
			return;
		}

		if (head->next == NULL) {  // Only one node
			cout << "Cannot Sort only 1 Data\n";
			return;
		}

		Node* curr = head;

		if (head->next->next == NULL) {  // Two nodes
			curr = curr->next;
			if (head->data > curr->data) {
				// Swap the two nodes
				curr->next = head;
				head->prev = curr;
				head->next = NULL;
				curr->prev = NULL;
				head = curr;
			}
			return;
		}

		// More than 2 nodes case
		int count = 0;
		curr = head;

		// Counting total nodes in the list
		while (curr != NULL) {
			count++;
			curr = curr->next;
		}

		// Bubble sort logic with node swaps 
		for (int i = 0; i < count - 1; i++) {
			curr = head;

			for (int j = 0; j < count - 1 - i; j++) {
				Node* temp = curr->next;

				if (curr->data > temp->data) {
					// Adjust the previous node of `urr if curr is not head
					if (curr->prev != NULL) {
						curr->prev->next = temp;
					}
					else {
						head = temp;  // Update head if curr is head node
					}

					// Adjust the next node of temp if temp is not the last node
					if (temp->next != NULL) {
						temp->next->prev = curr;
					}

					// Swap the nodes
					curr->next = temp->next;
					temp->prev = curr->prev;
					temp->next = curr;
					curr->prev = temp;
				}

				curr = temp;
			}
		}
	}


};

int main() {
	cout << "\n===> DOUBLY LINKEDLIST <========\n\n";
	DoublyList L1;
	L1.insertAtTail(5);
	L1.insertAtTail(20);
	L1.insertAtTail(10);
	L1.insertAtTail(40);
	L1.printList(); //(5,20,10,40)
	L1.sorting(); //calling sorting 
	L1.printList(); //(5, 10, 20, 40)

	L1.insertAtTail(9); //inserting 9 at the tail
	L1.printList(); //(5,10,20,40,9)
	L1.sorting(); //calling sorting function
	L1.printList(); //after sorting (5,9,10,20,40)


	L1.insertAtHead(2);
	L1.insertAtHead(1);
	L1.insertAtHead(50);

	L1.printList();
	L1.removeFirst();
	L1.printList();
	L1.removeLast();
	L1.printList();
	L1.insertAtTail(33);
	L1.printList();
	L1.deleteNode(9);
	L1.printList();

	system("pause");


	return 0;
}
