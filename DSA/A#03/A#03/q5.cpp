#include <iostream>
using namespace std;

class Node {
public:
	int data;
	Node* left, * right;
	Node(int d) : data(d), left(NULL), right(NULL) {}
};

class BST {
	Node* root;

	bool insert(Node* node, int d) {
		if (node == NULL) {
			node = new Node(d);
			return true;
		}
		
		if (d < node->data)
			insert(node->left, d);
		else if (d > node->data)
			insert(node->right, d);
		else if (d == node->data)
			return false;

		return true;
	}

	void kthSmallest(Node* node, int& k, int& min) {
		if (node != NULL) {		// Inorder traversal method
			kthSmallest(node->left, k, min);
			--k;
			if (k == 0) {
				min = node->data;
				return;
			}
			kthSmallest(node->right, k, min);
		}
	}

public:
	BST() : root(NULL) {}

	bool insert(int d) {
		return insert(root, d);
	}

	int kthSmallest(int k) {
		int min;
		kthSmallest(root, k, min);
		return min;
	}

};

int main() {
	BST bst;
	char choice;
	int value, k;

	do {
		cout << "\n--- Menu ---\n";
		cout << "1. Insert a node\n";
		cout << "2. Find kth smallest element\n";
		cout << "3. Exit\n";
		cout << "Enter your choice: ";
		cin >> choice;

		switch (choice) {
		case '1':
			cout << "Enter value to insert: ";
			cin >> value;
			if (bst.insert(value)) {
				cout << "Node inserted successfully.\n";
			}
			else {
				cout << "Node with value " << value << " already exists.\n";
			}
			break;
		case '2':
			cout << "Enter the value of k: ";
			cin >> k;
			cout << "The " << k << "th smallest element is: " << bst.kthSmallest(k) << endl;
			break;
		case '3':
			cout << "Exiting...\n";
			break;
		default:
			cout << "Invalid choice. Please try again.\n";
			break;
		}
	} while (choice != '3');

	system("pause");
	return 0;
}