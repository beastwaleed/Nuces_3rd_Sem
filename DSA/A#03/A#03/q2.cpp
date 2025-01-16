#include <iostream>
using namespace std;

struct Node {
	int data;
	Node* left, * right;
	Node(int d) : data(d), left(NULL), right(NULL) {}
};

class BST {
	Node* root;

	void inorder(Node* node) {
		if (node == NULL)
			return;
		inorder(node->left);
		cout << node->data << " ";
		inorder(node->right);
	}

	Node* array2BST(int arr[], int start, int end) {
		if (start > end)
			return NULL;

		int mid = (start + end) / 2;
		Node* newNode = new Node(arr[mid]);

		newNode->left = array2BST(arr, start, mid - 1);
		newNode->right = array2BST(arr, mid + 1, end);

		return newNode;
	}

public:
	BST() : root(NULL) {}

	void insert(int arr[], int start, int end) {
		root = array2BST(arr, start, end);
	}

	void display() {
		inorder(root);
	}
};

int main() {
	BST tree;
	int arr[] = { 1,2,3,4,5,6,7 };
	int size = sizeof(arr) / sizeof(arr[0]);

	tree.insert(arr, 0, size-1);
	tree.display();
	cout << endl;

	system("pause");
	return 0;
}