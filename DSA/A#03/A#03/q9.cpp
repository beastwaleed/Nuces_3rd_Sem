#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;
    Node(int d) : data(d), left(NULL), right(NULL) {}
};

class BinaryTree {
    Node* root;

    int search(int postorder[], int key, int start, int end) {
        for (int i = start; i <= end; i++) {
            if (postorder[i] == key) {
                return i;
            }
        }
        return -1;
    }

    Node* construct(int preorder[], int postorder[], int& preIndex, int start, int end) {
        if (start > end)
            return NULL;

        root = new Node(preorder[preIndex]);
        ++preIndex;

        if (start == end)
            return root;
        
        int postIndex = search(postorder, preorder[preIndex], start, end);

        root->left = construct(preorder, postorder, preIndex, start, postIndex);
        root->right = construct(preorder, postorder, preIndex, postIndex + 1, end - 1);

        return root;
    }

    void inorderTraversal(Node* root) {
        if (root == NULL) 
            return;
        inorderTraversal(root->left);
        cout << root->data << " ";
        inorderTraversal(root->right);
    }

public:
    BinaryTree() : root(NULL) {}

    Node* constructFromPrePost(int preorder[], int postorder[], int size) {
        int preIdx = 0;
        root = construct(preorder, postorder, preIdx, 0, size - 1);
    }

    void display() {
        inorderTraversal(root);
    }
};

int main() {
    int preorder[] = { 1, 2, 4, 5, 3, 6, 7 };
    int postorder[] = { 4, 5, 2, 6, 7, 3, 1 };
    int size = sizeof(preorder) / sizeof(preorder[0]);

    BinaryTree tree;

    tree.constructFromPrePost(preorder, postorder, size);

    cout << "\nConstructed Tree : ";
    tree.display();  // Expected output: 4 2 5 1 6 3 7
    
    cout << endl;
    system("pause");
    return 0;
}
