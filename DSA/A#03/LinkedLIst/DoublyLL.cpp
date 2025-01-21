#include <iostream>
using namespace std;

class Node {
public:
    Node* next;
    Node* prev;
    char data;

    Node(char val) {
        data = val;
        next = NULL;
        prev = NULL;
    }
};

class LinkedList {
    Node* head;

public:
    LinkedList() {
        head = NULL;
    }

    void insertAtHead(char val) {
        Node* newNode = new Node(val);
        newNode->next = head;
        newNode->prev = NULL;
        if (head != NULL) {
            head->prev = newNode;
        }
        head = newNode;
    }

    void insertAtTail(char val) {
        Node* newNode = new Node(val);
        if (head == NULL) {
            head = newNode;
            return;
        }

        Node* curr = head;
        while (curr->next != NULL) {
            curr = curr->next;
        }
        curr->next = newNode;
        newNode->prev = curr;
    }

    void insertAtMiddle(char data, char key) {
        Node* newNode = new Node(data);
        if (head == NULL) {
            return;
        }
        Node* curr = head;
        while (curr != NULL) {
            if (curr->data == key) {
                newNode->next = curr->next;
                newNode->prev = curr;
                if (curr->next != NULL) {
                    curr->next->prev = newNode;
                }
                curr->next = newNode;
                return;
            }
            curr = curr->next;
        }
    }

    bool deleteFromHead() {
        if (head == NULL) {
            cout << "List is Empty\n";
            return false;
        }
        Node* temp = head;
        head = head->next;
        if (head != NULL) {
            head->prev = NULL;
        }
        delete temp;
        return true;
    }

    bool deleteFromLast() {
        if (head == NULL) {
            cout << "List is Empty\n";
            return false;
        }
        Node* curr = head;
        while (curr->next != NULL) {
            curr = curr->next;
        }
        if (curr->prev != NULL) {
            curr->prev->next = NULL;
        }
        else {
            head = NULL;
        }
        delete curr;
        return true;
    }

    bool deleteMiddleNode(char key) {
        if (head == NULL) {
            cout << "List is Empty\n";
            return false;
        }
        Node* curr = head;
        while (curr != NULL) {
            if (curr->data == key) {
                if (curr->prev != NULL) {
                    curr->prev->next = curr->next;
                }
                else { 
                    head = curr->next;
                }
                if (curr->next != NULL) {
                    curr->next->prev = curr->prev;
                }
                delete curr;
                return true;
            }
            curr = curr->next;
        }
        cout << "Key not found\n";
        return false;
    }

    bool isPalindrome() {
        if (head == NULL) {
            return true;
        }
        Node* left = head;
        Node* right = head;
        while (right->next != NULL) {
            right = right->next;
        }
        while (left != right && right->next != left) {
            if (left->data != right->data) {
                return false;
            }
            left = left->next;
            right = right->prev;
        }
        return true;
    }

    void display() {
        Node* curr = head;
        while (curr != NULL) {
            cout << curr->data << " ";
            curr = curr->next;
        }
        cout << endl;
    }

    Node* gethead() {
        return head;
    }
};

void concatenate(LinkedList& L1, LinkedList& L2) {
    Node* curr = L1.gethead();

    if (curr == NULL) {
        L1 = L2;
        return;
    }

    while (curr->next != NULL) {
        curr = curr->next;
    }

    curr->next = L2.gethead();
    if (L2.gethead() != NULL) {
        L2.gethead()->prev = curr;
    }
}

LinkedList* copyReverse(LinkedList L1) {
    LinkedList* CopyL1 = new LinkedList();
    Node* curr = L1.gethead();
    while (curr != NULL) {
        CopyL1->insertAtHead(curr->data);
        curr = curr->next;
    }
    return CopyL1;
}

int main() {
    LinkedList L3;
    L3.insertAtTail('m');
    L3.insertAtTail('a');
    L3.insertAtTail('d');
    L3.insertAtTail('a');
    L3.insertAtTail('m');

    L3.display();
    if (L3.isPalindrome()) {
        cout << "\nLinkedList is Palindrome\n";
    }
    else {
        cout << "\nLinkedList is Not Palindrome\n";
    }

    // first list of objects
    LinkedList L1;
    L1.insertAtTail('w');
    L1.insertAtTail('a');
    L1.insertAtTail('l');
    L1.insertAtTail('e');
    L1.insertAtTail('e');
    L1.insertAtTail('d');

    L1.display();

    // second list of objects
    LinkedList L2;
    L2.insertAtTail('a');
    L2.insertAtTail('f');
    L2.insertAtTail('z');
    L2.insertAtTail('a');
    L2.insertAtTail('l');
    L2.display();

    concatenate(L1, L2);
    cout << "After Concatenating: ";
    L1.display();

    LinkedList* reversedCopy = copyReverse(L1);
    cout << "After Reverse Copying LinkedList L1: ";
    reversedCopy->display();

    return 0;
}
