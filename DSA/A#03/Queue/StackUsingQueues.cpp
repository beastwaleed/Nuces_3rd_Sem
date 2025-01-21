#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int value) {
        data = value;
        next = nullptr;
    }
};

class Queue {
private:
    Node* front, * rear;

public:
    Queue() {
        front = rear = nullptr;
    }

    void enqueue(int value) {
        Node* newNode = new Node(value);


        if (rear == nullptr) {
            front = rear = newNode;
            return;
        }
        else {
            rear->next = newNode;
            rear = newNode;
        }
    }
    // Function to remove an element from the queue
    void dequeue() {
        if (front == nullptr) {
            cout << "Queue is empty!" << endl;
            return;
        }

        // Move front one node ahead
        Node* temp = front;
        front = front->next;

        // If front becomes nullptr, set rear to nullptr as well
        if (front == nullptr) {
            rear = nullptr;
        }

        delete temp;
    }

    // Function to get the front element
    int frontElement() {
        if (front == nullptr) {
            cout << "Queue is empty!" << endl;
            return -1;
        }
        return front->data;
    }

    // Function to check if the queue is empty
    bool isEmpty() {
        return front == nullptr;
    }
};

class Stack {
private:
    Queue q1;  // Main queue
    Queue q2;  // Auxiliary queue

public:
    // Push element onto the stack
    void push(int x) {
        // Enqueue the new element into q2
        q2.enqueue(x);

        // Move all elements from q1 to q2
        while (!q1.isEmpty()) {
            q2.enqueue(q1.frontElement());
            q1.dequeue();
        }

        // Swap q1 and q2
        Queue temp = q1;
        q1 = q2;
        q2 = temp;
    }

    // Pop element from the stack
    void pop() {
        if (q1.isEmpty()) {
            cout << "Stack is empty!" << endl;
            return;
        }
        q1.dequeue();
    }

    // Get the top element of the stack
    int top() {
        if (q1.isEmpty()) {
            cout << "Stack is empty!" << endl;
            return -1;
        }
        return q1.frontElement();
    }

    // Check if the stack is empty
    bool isEmpty() {
        return q1.isEmpty();
    }

    // Display the elements in the stack (for debugging)
    void display() {
        if (q1.isEmpty()) {
            cout << "Stack is empty!" << endl;
            return;
        }

        Queue temp = q1;
        while (!temp.isEmpty()) {
            cout << temp.frontElement() << " ";
            temp.dequeue();
        }
        cout << endl;
    }
};

int main() {
    Stack stack;

    stack.push(1);
    stack.push(2);
    stack.push(3);

    cout << "Current Stack: ";
    stack.display();

    cout << "Top element: " << stack.top() << endl;

    stack.pop();
    cout << "After popping, Current Stack: ";
    stack.display();

    cout << "Top element: " << stack.top() << endl;

    return 0;
}