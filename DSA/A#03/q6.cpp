#include <iostream>
using namespace std;

template <class T>
class Node {
public:
	T data;
	Node* left, * right;
	Node(T d) : data(d), left(NULL), right(NULL) {}
};

template <class T>
class AVL {
	Node<T>* root;

	int getHeight(Node<T>* node) {
		if (node == NULL)
			return -1;			// Empty tree height = -1

		int leftHeight = getHeight(node->left);
		int rightHeight = getHeight(node->right);

		if (leftHeight > rightHeight)
			return 1 + leftHeight;

		return 1 + rightHeight;
	}

	int getBalanceFactor(Node<T>* node) {
		if (node == NULL)
			return 0;
		return getHeight(node->left) - getHeight(node->right);
	}

	void rightRotation(Node<T>* &node) {
		Node<T>* leftChild = node->left;
		Node<T>* childRight = leftChild->right;
		leftChild->right = node;
		node->left = childRight;
		node = leftChild;				// Update node to new root after rotation
		cout << "\n-----Right Rotation Successfully Performed!-----\n";
	}

	 void leftRotation(Node<T>* &node) {
		Node<T>* rightChild = node->right;
		Node<T>* childLeft = rightChild->left;
		rightChild->left = node;
		node->right = childLeft;
		node = rightChild;				// Update node to new root after rotation
		cout << "\n-----Left Rotation Successfully Performed!-----\n";
	}

	void checkAVL(Node<T>* &node) {
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

	bool insertNode(Node<T>*& node, T data) {
		if (node == NULL) {
			node = new Node<T>(data);
			return true;
		}

		if (data < node->data)
			insertNode(node->left, data);
		else if (data > node->data)
			insertNode(node->right, data);
		else
			return false;
		
		// Check whether the tree is balanced or not after every insertion
		checkAVL(node);
			
		return true;
	}

	bool deleteNode(Node<T>* &node, T key) {
		if (node == NULL)
			return false;

		if (key < node->data)
			deleteNode(node->left, key);
		else if (key > node->data)
			deleteNode(node->right, key);
		else if (key == node->data) {			// Key found
			Node<T>* temp = node;
			
			// Case : 0-children & 1-children
			if (node->left == NULL || node->right == NULL) {
				if (node->left == NULL)
					node = node->right;
				else
					node = node->left;
				delete temp;
			}

			// Case : 2-children
			else if (node->left != NULL && node->right != NULL) {
				temp = node->right;

				while (temp->left != NULL) {
					temp = temp->left;
				}

				node->data = temp->data;
				deleteNode(node->right, temp->data); 
				
			}

			// Check whether the tree is balanced or not
			if (node != NULL)
				checkAVL(node);

			return true;
		}

		return false;		// Key not found
	}

	void inorder(Node<T>* node) {
		if (node == NULL)
			return;
		inorder(node->left);
		cout << node->data << " ";
		inorder(node->right);
	}


public:
	AVL() : root(NULL) {}

	bool insertNode(T data) {
		return insertNode(root, data);
	}

	bool display() {
		if (root == NULL)
			return false;

		inorder(root);
		return true;
	}

	bool deleteNode(T key) {
		return deleteNode(root, key);
	}
};

int main() {
	AVL<int> tree;
	int data, key;
		
	cout << "Enter values to insert (-1 to stop): ";
	while (true) {
		cin >> data;
		if (data == -1)
			break;
		tree.insertNode(data);
	}

	cout << "\nInorder traversal : ";
	tree.display();

	cout << "\nEnter key to delete : ";
	cin >> key;
	tree.deleteNode(key);

	cout << "\nInorder traversal after deletion : ";
	tree.display();

	cout << endl;
	system("pause");
	return 0;
}