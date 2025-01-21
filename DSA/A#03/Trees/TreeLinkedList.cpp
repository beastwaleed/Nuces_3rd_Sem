#include <iostream>
#include <vector>
#include<algorithm>
using namespace std;


class Node {
public:
    Node* left;
    Node* right;
    int data;

    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }

};

class BST {
private:
    Node* root;

    void insertBST(Node*& root, int val) {
        if (root == NULL)
        {
            root = new Node(val);
            return;
        }
        if (val < root->data) {
            insertBST(root->left, val);
        }
        else if (val > root->data) {
            insertBST(root->right, val);
        }
    }

    void deleteBST(Node*& temp) {
        Node* curr;

        if (temp->left == NULL && temp->right == NULL) {
            delete temp;
            temp = NULL;
            return;
        }

        if (temp->left == NULL) {
            curr = temp;
            temp = temp->right;
            delete curr;
            return;
        }

        if (temp->right == NULL) {
            curr = temp;
            temp = temp->left;
            delete curr;
            return;
        }

        curr = temp->right;
        Node* parent = temp;

        while (curr->left != NULL) {
            parent = curr;
            curr = curr->left;
        }
        temp->data = curr->data;

        if (parent->left == curr) {
            parent->left = curr->right;
        }
        else {
            parent->right = curr->right;
        }
        delete curr;
    }

    int maxFind(Node* node) {
        if (node == NULL) {
            return -1;
        }
        return max(node->data, maxFind(node->left));
    }

    int minFind(Node* node) {
        if (node == NULL) {
            return 1000;
        }
        return min(node->data, minFind(node->right));
    }

    bool isBST(Node* node) {
        if (node == NULL) return true;

        //check if the max of the left subtree is greater than current node
        if (node->left != NULL && maxFind(node->left) >= node->data) {
            return false;
        }

        //check if the min of the right subtree is lesser than current node

        if (node->right != NULL && minFind(node->right) <= node->data) {
            return false;
        }

        return isBST(node->left) && isBST(node->right);
    }


    void preOrderBST(Node* root) {
        if (root == NULL) return;
        cout << root->data << " ";
        preOrderBST(root->left);
        preOrderBST(root->right);
    }

    void inOrderBST(Node* root) {
        if (root == NULL) return;
        inOrderBST(root->left);
        cout << root->data << " ";
        inOrderBST(root->right);
    }

    void postOrderBST(Node* root) {
        if (root == NULL) return;

        postOrderBST(root->left);
        postOrderBST(root->right);
        cout << root->data << " ";
    }

    int LCA(Node* node, int n1, int n2) {
        if (node == NULL) {
            return -1;
        }
        if (node->data > n1 && node->data > n2) {
            return LCA(node->left, n1, n2);
        }

        if (node->data < n1 && node->data < n2) {
            return LCA(node->right, n1, n2);
        }

        return node->data;
    }


public:
    BST() {
        root = NULL;
    }


    void insert(int val) {
        insertBST(root, val);
    }

    void deleteNode(int val) {
        Node* temp = root;
        Node* parent = NULL;

        while (temp != NULL && temp->data != val) {
            parent = temp;
            if (val < temp->data) {
                temp = temp->left;
            }
            else {
                temp = temp->right;
            }
        }
        if (temp == NULL) {
            cout << "Value not Found!!";
            return;
        }

        if (parent == NULL) {
            deleteBST(root);
        }
        else {
            if (parent->left == temp)  deleteBST(parent->left);
            else deleteBST(parent->right);
        }
    }

    int LCAfind(int n1, int n2) {
        return LCA(root, n1, n2);
    }

    void preOrder() {
        preOrderBST(root);
        cout << endl;
    }

    void inOrder() {
        inOrderBST(root);
        cout << endl;
    }

    void postOrder() {
        postOrderBST(root);
        cout << endl;
    }

    bool search(int val) {
        Node* temp = root;
        while (temp != NULL) {
            if (temp->data == val) {
                return true;
            }
            if (temp->data > val) {
                temp = temp->left;
            }
            else {
                temp = temp->right;
            }
        }
        return false;
    }

    bool CheckBST() {
        return isBST(root);
    }

};

int main() {
    BST tree;
    tree.insert(10);
    tree.insert(5);
    tree.insert(22);
    tree.insert(9);
    tree.insert(2);

    tree.inOrder();
    tree.postOrder();
    tree.preOrder();

    //tree.deleteNode(5);
    cout << endl;
    tree.inOrder();

    cout << "Check if Tree is BST or not:" << endl;
    if (tree.CheckBST()) {
        cout << "True\n";
    }
    else {
        cout << "False\n";
    }

    if (tree.search(20)) {
        cout << "\nValue Found\n";
    }
    else {
        cout << "\nValue Not Found\n";
    }

    cout << "Enter Nodes for Finding its Least Common Ancestors: ";
    int n1, n2;
    cin >> n1 >> n2;

    cout << "LCA of Node ( " << n1 << " " << n2 << ") is: " << tree.LCAfind(n1, n2);
    system("pause");
    return 0;


}