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

    bool isEmpty() {
        return front == NULL;
    }

    // Function to add an element to the queue
    void enqueue(int value) {
        Node* newNode = new Node(value);
        if (rear == NULL) {
            front = rear = newNode;
        } else {
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

        Node* temp = front;
        front = front->next;
        if (front == NULL) {
            rear = NULL;
        }
        delete temp;
    }

    int Viewfront() {
        if (front == NULL) {
            cout<<"Queue is empty"\n;
        }
        return front->data;
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
};

class Stack {
public:
    Queue Q1, Q2;

    void push(int x) {
        // Enqueue new element to the empty Q2
        Q2.enqueue(x);

        // Enqueue all elements from Q1 to Q2
        while (!Q1.isEmpty()) {
            Q2.enqueue(Q1.Viewfront());
            Q1.dequeue();
        }

        // Swap Q1 and Q2
        Queue temp = Q1;
        Q1 = Q2; 
        Q2 = temp;
    }

    void pop() {
        if (Q1.isEmpty()) {
            cout << "Stack is empty!" << endl;
            return;
        }
        Q1.dequeue();
    }

    int top() {
        if (Q1.isEmpty()) {
           cout<< "Stack is empty";
        }
        return Q1.Viewfront();
    }
};

int main() {
    Stack s;
    s.push(1);
    s.push(2);
    s.push(3);
    cout << "Top element: " << s.top() << endl; // Should print 3
    s.pop();
    cout << "Top element after pop: " << s.top() << endl; // Should print 2

    return 0;
}
