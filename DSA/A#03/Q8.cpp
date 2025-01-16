#include <iostream>
#include <string>
using namespace std;

class SongNode {
public:
    string songName;
    SongNode* next;

    SongNode(string name) : songName(name), next(nullptr) {}
};


class Node {
public:
    string songName;
    int frequency;
    int height;
    SongNode* songList;  // To store songs with the same frequency
    Node* left;
    Node* right;

    Node(string name, int freq) : songName(name), frequency(freq), height(1), left(nullptr), right(nullptr), songList(nullptr) {}
};

int FindMax(int a, int b) {
    if (a > b) {
        return a;
    }
    else {
        return b;
    }
}

int getHeight(Node* node) {
    if (node == nullptr) {
        return 0;
    }
    return node->height;
}

int getBalance(Node* node) {
    if (node == nullptr) {
        return 0;
    }
    return getHeight(node->left) - getHeight(node->right);
}

Node* rightRotate(Node* y) { //right rotate
    Node* x = y->left;
    Node* T2 = x->right;

    x->right = y;
    y->left = T2;

    // Update heights
    y->height = FindMax(getHeight(y->left), getHeight(y->right)) + 1;
    x->height = FindMax(getHeight(x->left), getHeight(x->right)) + 1;

    return x;  // New root
}

// Left rotate 
Node* leftRotate(Node* x) {
    Node* y = x->right;
    Node* T2 = y->left;

    y->left = x;
    x->right = T2;

    // Update heights
    x->height = FindMax(getHeight(x->left), getHeight(x->right)) + 1;
    y->height = FindMax(getHeight(y->left), getHeight(y->right)) + 1;

    return y;  // New root
}

Node* insertSong(Node* node, const string& songName, int frequency) {
    if (node == nullptr) {
        return new Node(songName, frequency);
    }

    if (songName < node->songName) {
        node->left = insertSong(node->left, songName, frequency);
    }
    else if (songName > node->songName) {
        node->right = insertSong(node->right, songName, frequency);
    }
    else {
        // If song already exists, add it to the linked list of songs with the same frequency
        SongNode* newSong = new SongNode(songName);
        newSong->next = node->songList;
        node->songList = newSong;
        return node;
    }

    node->height = 1 + FindMax(getHeight(node->left), getHeight(node->right));
    int balance = getBalance(node);

    // Balance the node if needed
    if (balance > 1 && songName < node->left->songName) {
        return rightRotate(node);
    }

    if (balance < -1 && songName > node->right->songName) {
        return leftRotate(node);
    }

    if (balance > 1 && songName > node->left->songName) {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    if (balance < -1 && songName < node->right->songName) {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    return node;
}

// Play a song (increasing the frequency)
Node* playSong(Node* node, const string& songName) {
    if (node == nullptr) {
        return nullptr;
    }

    if (songName < node->songName) {
        node->left = playSong(node->left, songName);
    }
    else if (songName > node->songName) {
        node->right = playSong(node->right, songName);
    }
    else {
        // Song found, increase its frequency
        node->frequency++;

        // Rebalance the tree
        int balance = getBalance(node);
        if (balance > 1 && songName < node->left->songName) {
            return rightRotate(node);
        }

        if (balance < -1 && songName > node->right->songName) {
            return leftRotate(node);
        }

        if (balance > 1 && songName > node->left->songName) {
            node->left = leftRotate(node->left);
            return rightRotate(node);
        }

        if (balance < -1 && songName < node->right->songName) {
            node->right = rightRotate(node->right);
            return leftRotate(node);
        }
    }

    return node;
}

// Inorder traversal to display songs
void inorderTraversal(Node* root) {
    if (root == nullptr) {
        return;
    }

    inorderTraversal(root->left);
    cout << "Song: " << root->songName << ", Frequency: " << root->frequency << endl;

    // Display songs in the linked list with the same frequency
    SongNode* temp = root->songList;
    while (temp != nullptr) {
        cout << "Song: " << temp->songName << ", Frequency: " << root->frequency << endl;
        temp = temp->next;
    }

    inorderTraversal(root->right);
}

int main() {
    Node* root = nullptr;

    // Initial songs and frequencies
    string songs[] = { "Song_A", "Song_B", "Song_C", "Song_D", "Song_E", "Song_F", "Song_G", "Song_H", "Song_I", "Song_J", "Song_K" };
    int frequencies[] = { 1, 5, 9, 2, 4, 6, 8, 3, 7, 9, 5 };

    // Insert initial songs into the AVL tree
    for (int i = 0; i < 11; i++) {
        root = insertSong(root, songs[i], frequencies[i]);
    }

    int choice;
    do { //menu driven program
        cout << "\nMenu:" << endl;
        cout << "1. Add Song" << endl;
        cout << "2. Play Song" << endl;
        cout << "3. Display Songs" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        string songName;
        switch (choice) {
        case 1:
            cout << "Enter song name: ";
            cin >> songName;
            cout << "Enter frequency: ";
            int frequency;
            cin >> frequency;
            root = insertSong(root, songName, frequency);
            break;
        case 2:
            cout << "Enter song name to play: ";
            cin >> songName;
            root = playSong(root, songName);
            break;
        case 3:
            cout << "Songs in the tree:" << endl;
            inorderTraversal(root);
            break;
        case 4:
            cout << "Exiting..." << endl;
            break;
        default:
            cout << "Invalid choice!" << endl;
        }
    } while (choice != 4);

    return 0;
}
