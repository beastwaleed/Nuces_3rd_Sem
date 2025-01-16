#include <iostream>
#include <string>
using namespace std;

class Customer {
public:
    int billAmount;
    int TokenNo;

    Customer(int bill, int token) {
        billAmount = bill;
        TokenNo = token;
    }
};

// Queue class
class Queue {
private:
    Customer* heap[100];
    int size;

    void  percolateUp(int index) {
        while (index > 0) {
            int parent = (index - 1) / 2;
            if (heap[index]->billAmount > heap[parent]->billAmount) {
                swap(heap[index], heap[parent]);
                index = parent;
            }
            else {
                break;
            }
        }
    }

    void percolateDown(int index) {
        while (index < size) {
            int leftChild = 2 * index + 1;
            int rightChild = 2 * index + 2;
            int largest = index;

            if (leftChild<size && heap[leftChild]->billAmount> heap[largest]->billAmount) {
                largest = leftChild;
            }
            if (rightChild < size && heap[rightChild]->billAmount > heap[largest]->billAmount) {
                largest = rightChild;
            }
            if (largest != index) {
                swap(heap[index], heap[largest]);
                index = largest;
            }
            else {
                break;
            }
        }
    }


public:
    Queue() {
        size = 0;
    }

    void enqueue(int amt, int tok) {

        if (size >= 100) {
            return;
        }

        Customer* newNode = new Customer(amt, tok);
        heap[size] = newNode;
        percolateUp(size);
        size++;

    }

    void dequeue() {
        if (size == 0) {
            cout << "Queue is Empty!!";
            return;
        }

        Customer* TopNode = heap[0];
        cout << "Deleting Top Priority Customer: ";
        cout << "Bill Amount: " << TopNode->billAmount << " Token No: " << TopNode->TokenNo << endl;
        heap[0] = heap[size - 1];
        delete TopNode;

        heap[size - 1] = NULL;
        size--;
        percolateDown(0);

        return;

    }

    // Function to display the queue
    void display() {
        if (size == 0) {
            cout << "Queue is empty!" << endl;
            return;
        }

        for (int i = 0;i < size;i++) {
            cout << "Token No: " << heap[i]->TokenNo << " Bill: " << heap[i]->billAmount << endl;
        }
        cout << endl;
    }
};

int main() {
    Queue q;

    q.enqueue(3000, 101);
    q.enqueue(5000, 104);
    q.enqueue(1320, 107);


    cout << "Queue after enqueuing customers:" << endl;
    q.display();

    cout << "After dequeue\n";
    q.dequeue();
    cout << endl;
    q.display();

    return 0;
}