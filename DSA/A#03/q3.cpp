#include<iostream>
using namespace std;

class Node {
public:
	int data;
	Node* left, * right;
	Node(int d) : data(d), left(NULL), right(NULL) {}
};

class BinaryTree {
	Node* root;
	int sum = 0;

	int maxPathsum(Node* node) {
		if (node == NULL) { 
			return 0;
		}

		int ans = -278000; //minimum value for comparing 

		// Case 1: store node data
		int one = node->data;

		// Case 2: store node's left data + node's data
		int two = maxPathsum(node->left) + node->data;
		
		// Case 3: store node's right data + node's data
		int three = maxPathsum(node->right) + node->data; 
		
		// Case 4: store node's left data + node's right + node's data
		int four = maxPathsum(node->left) + maxPathsum(node->right) + node->data;

		int temp = max(max(one, two), max(three, four)); //calculate the maximum of 4 of the cases above
		ans = max(ans, temp); //store the one maximum case in ans

		return ans;
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

public:
	BinaryTree() : root(NULL) {}

	bool insert(int data) {
		return insertNode(root, data);
	}

	int callMaxSum() {
		return maxPathsum(root);
	}

	void DisplayInOrder() {
		cout << "\nDisplaying InOrder: ";
		inorderTraversal(root);
	}

};

int main() {
	int value = 0;
	BinaryTree T1;

	cout << "Enter Values to Store (-1 To Exit): " << endl;
	while (value != -1) {
		cin >> value;
		if (value != -1) {
			T1.insert(value); // Insert only if value is not -1
		}
	}

	T1.DisplayInOrder();

	cout << "\n==> Maximum Sum in BST: ";
	cout << T1.callMaxSum() << endl;

	system("pause");
	return 0;
}