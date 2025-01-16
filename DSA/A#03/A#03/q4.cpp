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
    Node* prev;

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
        if (root == NULL) return;

        inorderTraversal(root->left);
        cout << root->data << " ";
        inorderTraversal(root->right);
    }

    void ConvertToDLL(Node*& root) {
        if (root == NULL) {
            return;
        }

        ConvertToDLL(root->left);

        if (prev != nullptr) {
            prev->right = root;
            root->left = prev;
        }

        prev = root;

        ConvertToDLL(root->right);
    }

    void DisplayCDLL(Node* head) {
        cout << "\nDisplaying Circular Doubly Linked List: ";
        Node* temp = head;
        if (temp == NULL) return;

        do {
            cout << temp->data << " ";
            temp = temp->right;
        } while (temp != head);
        cout << endl;
    }

public:

    BST() : root(NULL), prev(NULL) {}

    bool insert(int data) {
        return insertNode(root, data);
    }

    bool bstToCDLL() {
        if (root == NULL) {
            return false;
        }

        ConvertToDLL(root);

        Node* head = root;
        while (head->left != NULL)
            head = head->left;

        root = head;

        root->left = prev;
        prev->right = root;

        return true;
    }

    void DisplayInOrder() {
        cout << "\nDisplaying InOrder: ";
        inorderTraversal(root);
    }

    void DisplayCDLL() {
        DisplayCDLL(root);
    }
};

int main() {
    BST T1;
    int value = 0;

    cout << "Enter Values to Store (-1 To Exit): " << endl;
    while (value != -1) {
        cin >> value;
        if (value != -1) {
            T1.insert(value);
        }
    }

    T1.DisplayInOrder();

    T1.bstToCDLL();
    T1.DisplayCDLL();

    return 0;
}
