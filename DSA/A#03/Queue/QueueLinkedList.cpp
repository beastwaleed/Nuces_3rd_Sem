#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = NULL;
    }
};

// Queue class
class Queue {
private:
    Node* front, * rear;

public:
    // Constructor to initialize front and rear
    Queue() {
        front = rear = NULL;
    }

    // Function to add an element to the queue
    void enqueue(int value) {
        Node* newNode = new Node(value);
        newNode->next = NULL;

        // If the queue is empty, front and rear are the same
        if (rear == NULL) {
            front = rear = newNode;

        }

        else {// Otherwise, add the new node to the end and update rear
            rear->next = newNode;
            rear = newNode;
        }
    }
    // Function to remove an element from the queue
    void dequeue() {
        if (front == NULL) {
            cout << "Queue is empty!" << endl;
            return;
        }

        // Store the current front and move front one node ahead
        Node* temp = front;
        front = front->next;

        // If front becomes nullptr, also set rear to nullptr
        if (front == NULL) {
            rear = NULL;
        }

        delete temp;

    }

    // Function to display the queue
    void display() {
        if (front == NULL) {
            cout << "Queue is empty!" << endl;
            return;
        }

        Node* temp = front;
        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }



    void reverseQueue() {
        if (front == NULL) {
            cout << "Empty List!!\n";
            return;
        }

        Node* prev = NULL;
        Node* curr = front;
        Node* next = NULL;

        while (curr != NULL) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        rear = front;
        front = prev;


    }
};

int main() {
    Queue q;

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);


    cout << "Queue: ";
    q.display();

    q.dequeue();
    cout << "After dequeue\nQueue: ";
    q.display();

    q.reverseQueue();
    cout << "After Reversing \nQueue: ";
    q.display();

    return 0;
}