#include<iostream>
using namespace std;

class Node {
public:
	int data;
	Node* left;
	Node* right;

	Node(int val) {
		data = val;
		left = NULL;
		right = NULL;
	}
};

class BST {
	Node* root; // Root node of the BST
public:


	BST() {
		root = NULL;
	}

	void InsertNode(int num) {
		Node* newNode = new Node(num);

		if (root == NULL) {
			root = newNode;
		}
		else { // Tree is not empty
			Node* temp = root; // create a pointer to traverse the tree 
			while (true) {
				if (num < temp->data) { // Left subtree
					if (temp->left != NULL) {
						temp = temp->left;
					}

					else {
						temp->left = newNode;
						return;
					}
				}
				else if (num > temp->data) {  // Right subtree
					if (temp->right != NULL) {
						temp = temp->right;
					}
					else {
						temp->right = newNode;
						return;
					}

				}
				else {
					cout << "Duplicate value found in tree.\n";
					break;
				}
			}
		}
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

	void deleteNode(int num) {
		Node* temp = root;
		while (temp != NULL) {
			if (temp->data == num) {
				makeDeletion(temp);
			}
			else if (temp->data > num) {
				temp = temp->left;
			}
			else if (temp->data < num) {
				temp = temp->right;
			}
			else {
				cout << "Value Not Found!!\n";
			}
		}
	}

	void makeDeletion(Node*& temp) {
		Node* temp2;

		if (temp->right == NULL) { //case 1: Leaf Node or One Left Child Node
			temp2 = temp;
			temp = temp->left;
			cout << temp2->data << " Deleted Successfully!!\n";
			delete temp2;
			return;
		}

		else if (temp->left == NULL) {//case2 for one Right Child Node
			temp2 = temp;
			temp = temp->right;
			cout << temp2->data << " Deleted Successfully!!\n";
			delete temp2;
			return;
		}

		else { //case for two children
			temp2 = temp->right;
			while (temp2->left) {
				temp2 = temp2->left;
			}
			temp2->left = temp->left;
			temp2 = temp;
			temp = temp->right;
			cout << temp2->data << " Deleted Successfully!!\n";
			delete temp2;
			return;

		}
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


	void PredecessorSuccessor(int key) {
		findPredecessorSuccessor(root, key);
	}

	// Function to find inorder predecessor and successor
	void findPredecessorSuccessor(Node* root, int key) {
		if (root == nullptr) return;

		// Variable to hold the predecessor and successor nodes
		Node* predecessor = nullptr;
		Node* successor = nullptr;

		// Find the node with the given key
		Node* current = root;
		while (current != nullptr) {
			if (current->data == key) {
				// Find predecessor
				if (current->left != nullptr) {
					predecessor = current->left;
					while (predecessor->right != nullptr) {
						predecessor = predecessor->right;
					}
				}

				// Find successor
				if (current->right != nullptr) {
					successor = current->right;
					while (successor->left != nullptr) {
						successor = successor->left;
					}
				}
				break;
			}
			else if (key < current->data) {
				successor = current;
				current = current->left;
			}
			else {
				predecessor = current;
				current = current->right;
			}
		}

		// Output the predecessor and successor if they exist
		if (predecessor != nullptr) {
			cout << "\nInorder Predecessor of " << key << " is " << predecessor->data << endl;
		}
		else {
			cout << "\nInorder Predecessor of " << key << " does not exist" << endl;
		}

		if (successor != nullptr) {
			cout << "\nInorder Successor of " << key << " is " << successor->data << endl;
		}
		else {
			cout << "\nInorder Successor of " << key << " does not exist" << endl;
		}
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
	//Node* root = NULL;
	int value = 0;
	BST T1;

	cout << "Enter Values to Store (-1 To Exit): " << endl;
	while (value != -1) {
		cin >> value;
		if (value != -1) {
			T1.InsertNode(value); // Insert only if value is not -1
		}
	}

	cout << "Enter any Value to Find in Tree: ";
	cin >> value;
	if (T1.FindValue(value) == true) {
		cout << "\nValue Found\n";
	}
	else {
		cout << "\nValue Not Found!\n";
	}

	cout << "Enter any Value to Delete in Tree: ";
	cin >> value;
	T1.deleteNode(value);

	T1.DisplayInOrder();
	T1.DisplayPostOrder();
	T1.DisplayPreOrder();

	T1.PredecessorSuccessor(50);

	system("pause");
	return 0;
}