#include<iostream>
using namespace std;

class TwoStacks {
private:
    int* arr;
    int top1;
    int top2;
    int capacity;

public:
    // Constructor
    TwoStacks(int cap) {
        capacity = cap;
        arr = new int[capacity];
        top1 = -1;                // Stack 1 starts from the beginning
        top2 = capacity;          // Stack 2 starts from the end
    }

    // Check if Stack 1 is empty
    bool isEmptyStack1() {
        return (top1 == -1);
    }

    // Check if Stack 2 is empty
    bool isEmptyStack2() {
        return (top2 == capacity);
    }

    // Check if the array is full (both stacks are full)
    bool isFull() {
        return (top1 + 1 == top2);
    }

    // Push element into Stack 1
    void pushStack1(int val) {
        if (isFull()) {
            cout << "Cannot Push!!! Stack Overflow\n";
            return;
        }
        arr[++top1] = val;  // Increment top1 and push the value
    }

    // Push element into Stack 2
    void pushStack2(int val) {
        if (isFull()) {
            cout << "Cannot Push!!! Stack Overflow\n";
            return;
        }
        arr[--top2] = val;  // Decrement top2 and push the value
    }

    // Pop element from Stack 1
    int popStack1() {
        if (isEmptyStack1()) {
            cout << "Cannot Pop!! Stack 1 is Empty\n";
            return -1;
        }
        return arr[top1--];  // Return top1 value and decrement it
    }

    // Pop element from Stack 2
    int popStack2() {
        if (isEmptyStack2()) {
            cout << "Cannot Pop!! Stack 2 is Empty\n";
            return -1;
        }
        return arr[top2++];  // Return top2 value and increment it
    }

    // Display elements of Stack 1
    void displayStack1() {
        if (isEmptyStack1()) {
            cout << "Stack 1 is Empty\n";
            return;
        }
        cout << "Stack 1 elements: ";
        for (int i = 0; i <= top1; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    // Display elements of Stack 2
    void displayStack2() {
        if (isEmptyStack2()) {
            cout << "Stack 2 is Empty\n";
            return;
        }
        cout << "Stack 2 elements: ";
        for (int i = capacity - 1; i >= top2; i--) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

// Main function to test the TwoStacks class
int main() {
    TwoStacks ts(5); // Create a TwoStacks object with a capacity of 5

    // Testing Stack 1
    ts.pushStack1(1);
    ts.pushStack1(2);
    ts.pushStack1(3);
    ts.displayStack1();

    // Testing Stack 2
    ts.pushStack2(10);
    ts.pushStack2(9);
    ts.displayStack2();

    // Popping from both stacks
    cout << "Popping from Stack 1: " << ts.popStack1() << endl;
    cout << "Popping from Stack 2: " << ts.popStack2() << endl;

    // Display stacks again after pop
    ts.displayStack1();
    ts.displayStack2();

    return 0;
}
