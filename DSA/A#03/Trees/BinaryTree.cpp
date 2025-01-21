#include <iostream>
#include <queue>
using namespace std;

template <typename k, typename v>
class TNode {
public:
    k key;
    v value;
    int nodeCount;
    TNode* left;
    TNode* right;

    TNode(k key, v value) {
        this->key = key;
        this->value = value;
        left = NULL;
        right = NULL;
        nodeCount = 1;
    }
};

template <typename k, typename v>
class BinaryTree {
private:
    TNode<k, v>* root;

    int height(TNode<k, v>* node) const {
        if (node == NULL) {
            return 0;
        }
        int leftHeight = height(node->left);
        int rightHeight = height(node->right);

        return 1 + max(leftHeight, rightHeight);
    }

    void insertion(TNode<k, v>*& node, k key, v value) {
        if (node == NULL) {
            node = new TNode<k, v>(key, value);
            return;
        }

        if (CountNodes(node->left) <= CountNodes(node->right)) {
            insertion(node->left, key, value);
        }
        else {
            insertion(node->right, key, value);
        }
        node->nodeCount = 1 + CountNodes(node->left) + CountNodes(node->right);
    }

    int searchDuplicate(TNode<k, v>* node, k key) const {
        if (node == NULL) {
            return 0;
        }

        int count = 0;
        if (node->key == key) {
            count = 1;
        }

        return count + searchDuplicate(node->left, key) + searchDuplicate(node->right, key);
    }

    bool isPerfectUtil(TNode<k, v>* node, int depth, int level) const {
        if (node == NULL) {
            return true;
        }

        if (node->left == NULL && node->right == NULL) {
            return depth == level + 1;
        }

        if (node->left == NULL || node->right == NULL) {
            return false;
        }

        return isPerfectUtil(node->left, depth, level + 1) && isPerfectUtil(node->right, depth, level + 1);
    }

public:
    BinaryTree() {
        root = NULL;
    }

    int CountNodes(TNode<k, v>* node) const {
        if (node == NULL) return 0;
        int left = CountNodes(node->left);
        int right = CountNodes(node->right);

        return 1 + left + right;
    }

    int balanceFactor(TNode<k, v>* node) const {
        if (node == NULL) {
            return 0;
        }

        int leftHeight = height(node->left);
        int rightHeight = height(node->right);

        return leftHeight - rightHeight;
    }

    void insert(k key, v value) {
        insertion(root, key, value);
    }

    int search(k key) const {
        return searchDuplicate(root, key);
    }

    bool isPerfect() const {
        int depth = height(root);
        return isPerfectUtil(root, depth, 0);
    }

    void displayInOrder(TNode<k, v>* node) const {
        if (node == NULL) {
            return;
        }
        displayInOrder(node->left);
        cout << node->key << " ";
        displayInOrder(node->right);
    }

    void display() const {
        displayInOrder(root);
        cout << endl;
    }

    TNode<k, v>* getRoot() const {
        return root;
    }
};

int main() {
    BinaryTree<int, int> tree;
    tree.insert(10, 20);
    tree.insert(5, 15);
    tree.insert(15, 25);
    tree.insert(17, 35);


    cout << "Tree in-order traversal: ";
    tree.display();

    cout << "Root Balance Factor: " << tree.balanceFactor(tree.getRoot()) << endl;

    int key = 10;
    cout << "Number of times key " << key << " is present: " << tree.search(key) << endl;

    cout << "Is the tree perfect? " << (tree.isPerfect() ? "Yes" : "No") << endl;

    return 0;
}
