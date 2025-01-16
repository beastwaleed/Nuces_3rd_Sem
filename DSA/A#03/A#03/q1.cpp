#include<iostream>
using namespace std;

class Node {
public:
	int data;
	Node* left, * right;
	Node(int d) : data(d), left(NULL), right(NULL) {}
};

class BST {
	Node* root; // Root node of the BST

	void inorderTraversal(Node* root) {
		Node* temp = root;
		if (root == NULL) {
			return;
		}
		else {
			inorderTraversal(root->left);
			cout << root->data << " ";
			inorderTraversal(root->right);
		}
	}

	void PostorderTraversal(Node* root) {
		Node* temp = root;
		if (root == NULL) {
			return;
		}
		else {
			PostorderTraversal(root->left);
			PostorderTraversal(root->right);
			cout << root->data << " ";
		}
	}

	void PreorderTraversal(Node* root) {
		Node* temp = root;
		if (root == NULL) {
			return;
		}
		else {
			cout << root->data << " ";
			PreorderTraversal(root->left);
			PreorderTraversal(root->right);
		}
	}

	bool insertNode(Node*& node, int data) {
		if (node == NULL) {
			node = new Node(data);
			return true;
		}

		if (data < node->data)
			insertNode(node->left, data);
		else if (data > node->data)
			insertNode(node->right, data);
		else
			return false;
		return true;
	}

public:
	BST() : root(NULL) {}

	bool insert(int data) {
		return insertNode(root, data);
	}

	bool FindValue(int val) {
		Node* temp = root;
		while (temp != NULL) {
			if (temp->data == val) {
				return true;
			}

			else if (val < temp->data) {
				temp = temp->left;
			}
			else {
				temp = temp->right;
			}
		}
		return false;
	}

	void DisplayInOrder() {
		cout << "\nDisplaying InOrder: ";
		inorderTraversal(root);
	}

	void DisplayPreOrder() {
		cout << "\nDisplaying PreOrder: ";
		PreorderTraversal(root);
	}

	void DisplayPostOrder() {
		cout << "\nDisplaying PostOrder: ";
		PostorderTraversal(root);
	}

};

int main() {
	int value = 0;
	BST T1;

	cout << "Enter Values to Store (-1 To Exit): " << endl;
	while (value != -1) {
		cin >> value;
		if (value != -1) {
			T1.insert(value); // Insert only if value is not -1
		}
	}

	cout << "Enter Value to Find : ";
	cin >> value;
	if (T1.FindValue(value) == true) {
		cout << "\nValue Found\n";
	}
	else {
		cout << "\nValue Not Found!\n";
	}


	T1.DisplayInOrder();
	T1.DisplayPostOrder();
	T1.DisplayPreOrder();

	system("pause");
	return 0;
}