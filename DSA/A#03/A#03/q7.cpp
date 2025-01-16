#include <iostream>
using namespace std;

class Node {
public:
	int data;
	Node* left;
	Node* right;
	Node(int d) : data(d), left(NULL), right(NULL) {}
};

class AVL {
	Node* root;

	int getHeight(Node* node) {
		if (node == NULL)
			return -1;			// Empty tree height = -1

		int leftHeight = getHeight(node->left);
		int rightHeight = getHeight(node->right);

		if (leftHeight > rightHeight)
			return 1 + leftHeight;

		return 1 + rightHeight;
	}

	int getBalanceFactor(Node* node) {
		if (node == NULL)
			return 0;
		return getHeight(node->left) - getHeight(node->right);
	}

	void rightRotation(Node*& node) {
		Node* leftChild = node->left;
		Node* childRight = leftChild->right;
		leftChild->right = node;
		node->left = childRight;
		node = leftChild;				// Update node to new root after rotation
		cout << "-----Right Rotation Successfully Performed!-----" << endl;
	}

	void leftRotation(Node*& node) {
		Node* rightChild = node->right;
		Node* childLeft = rightChild->left;
		rightChild->left = node;
		node->right = childLeft;
		node = rightChild;				// Update node to new root after rotation
		cout << "-----Left Rotation Successfully Performed!-----" << endl;
	}

	void checkAVL(Node*& node) {
		int rootBF = getBalanceFactor(node);

		if (rootBF > 1) {
			int childBF = getBalanceFactor(node->left);

			if (childBF < 0)		// Left-Right (LR) case
				leftRotation(node->left);

			rightRotation(node);	// Left-Left (LL) case
		}

		else if (rootBF < -1) {
			int childBF = getBalanceFactor(node->right);

			if (childBF >= 0)		// Right-Left (RL) case
				rightRotation(node->right);

			leftRotation(node->right);		// Right-Right (RR) case
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

		// Check whether the tree is balanced or not
		checkAVL(node);

		return true;
	}

	void join(Node* node) {
		if (node == NULL)
			return;
		join(node->left);
		insertNode(this->root, node->data); // Insert every node from the second tree into first tree
		join(node->right);
	}

	void inorder(Node* node) {
		if (node == NULL)
			return;
		inorder(node->left);
		cout << node->data << " ";
		inorder(node->right);
	}

public:
	AVL() : root(NULL) {}

	bool insert(int data) {
		return insertNode(root, data);
	}

	bool display() {
		if (root == NULL)
			return false;

		inorder(root);
		return true;
	}

	void join(AVL& secondTree) {
		join(secondTree.root);
	}
};

int main() {
	AVL T1, T2;

	int valuesT1[] = { 3,5,7,10,15,20 };
	int const n1 = sizeof(valuesT1) / sizeof(valuesT1[0]);

	for (int i = 0; i < n1; i++) {
		T1.insert(valuesT1[i]);
	}
	cout << endl;

	int valuesT2[] = { 22,25,28,30,35 };
	int const n2 = sizeof(valuesT2) / sizeof(valuesT2[0]);

	for (int i = 0; i < n2; i++) {
		T2.insert(valuesT2[i]);
	}
	cout << endl;


	cout << "\nT1: ";
	T1.display();
	cout << "\nT2: ";
	T2.display();
	cout << endl;

	// Join T1 with T2
	cout << "\n-----Merging T1 & T2-----\n";
	T1.join(T2);

	cout << "\nMerged AVL Tree: ";
	T1.display();

	cout << endl;
	system("pause");
	return 0;
}