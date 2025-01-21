#include <iostream>
#include <vector>
using namespace std;

class Node {
public:
    Node* next;
    char data;

    Node(char val) {
        data = val;
        next = NULL;
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
        head = newNode;
    }

    void insertatTail(char val) {
        Node* newNode = new Node(val);
        Node* curr = head;

        if (head == NULL) {
            head = newNode;
            return;
        }

        while (curr->next != NULL) {
            curr = curr->next;
        }

        curr->next = newNode;
    }

    void insertAtMiddle(char data, char key) {
        Node* newNode = new Node(data);

        if (head == NULL) {
            head = newNode;
            return;
        }
        Node* curr = head;

        while (curr != NULL) {
            if (curr->data == key) {
                newNode->next = curr->next;
                curr->next = newNode;
                return;
            }
            curr = curr->next;
        }
    }

    bool deleteFromHead() {
        if (head == NULL) {
            return false;
        }
        else {
            head = head->next;
            return true;
        }
    }

    bool deleteFromLast() {
        if (head == NULL) {
            return false;
        }
        Node* curr = head;

        while (curr->next->next != NULL) {
            curr = curr->next;
        }

        curr->next = NULL;
        return true;
    }

    bool deleteMiddleNode() {
        Node* curr = head;
        int count = 0;

        if (head == NULL) {
            return false;
        }

        while (curr->next != NULL) {
            curr = curr->next;
            count++;
        }

        if (count == 1) {
            delete head;
            head = NULL;
            return true;
        }

        int middle = count / 2;
        Node* slow = NULL;
        curr = head;
        for (int i = 0;i < middle;i++) {
            slow = curr;
            curr = curr->next;
        }
        slow->next = curr->next;
        delete curr;
        return true;

    }

    bool isPalindrom() {
        vector<char> elements;
        Node* curr = head;

        if (head == NULL) {
            return false;
        }

        while (curr != NULL) {
            elements.push_back(curr->data);
            curr = curr->next;
        }

        int left = 0;
        int right = elements.size() - 1;

        while (left < right) {
            if (elements[left] != elements[right]) {
                return false;
            }
            left++;
            right--;
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
    L3.insertatTail('m');
    L3.insertatTail('a');
    L3.insertatTail('d');
    L3.insertatTail('a');
    L3.insertatTail('m');

    L3.display();
    if (L3.isPalindrom()) {
        cout << "\nLinkedList is Palindrome\n";
    }
    else {
        cout << "\nLinkedList is Not Palindrome\n";
    }



    //first list of objects
    LinkedList L1;
    L1.insertatTail('w');
    L1.insertatTail('a');
    L1.insertatTail('l');
    L1.insertatTail('e');
    L1.insertatTail('e');
    L1.insertatTail('d');

    L1.display();

    //second list of objects
    LinkedList L2;
    L2.insertatTail('a');
    L2.insertatTail('f');
    L2.insertatTail('z');
    L2.insertatTail('a');
    L2.insertatTail('l');
    L2.display();

    concatenate(L1, L2);
    cout << "After Concatenating: ";
    L1.display();

    LinkedList* reversedCopy = copyReverse(L1);
    cout << "After Reverse Copying LinkedList L1: ";
    reversedCopy->display();


    system("pause");
    return 0;

}