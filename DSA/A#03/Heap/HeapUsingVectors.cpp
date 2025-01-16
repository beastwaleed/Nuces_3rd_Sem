#include <iostream>
#include <vector>
using namespace std;

class MinHeap {
    vector<int> heap;

    void percolateUp(int index) {
        while (index > 0) {
            int parentIndex = (index - 1) / 2;
            if (heap[index] < heap[parentIndex]) {
                swap(heap[index], heap[parentIndex]);
                index = parentIndex;
            }
            else {
                break;
            }
        }
    }

    void percolateDown(int index) {
        int size = heap.size();
        while (true) {
            int leftChild = index * 2 + 1;
            int rightChild = index * 2 + 2;
            int smallest = index;

            if (leftChild < size && heap[leftChild] < heap[smallest]) {
                smallest = leftChild;
            }
            if (rightChild < size && heap[rightChild] < heap[smallest]) {
                smallest = rightChild;
            }
            if (smallest == index) {
                break;
            }
            swap(heap[index], heap[smallest]);
            index = smallest;
        }
    }

public:
    void insert(int val) {
        heap.push_back(val);
        percolateUp(heap.size() - 1);
    }

    int deleteHeap() {
        if (heap.size() == 0) {
            return -1; // indicates the heap is empty
        }

        int min = heap.front();
        if (heap.size() == 1) {
            heap.pop_back();
        }
        else {
            heap.front() = heap.back();
            heap.pop_back();
            percolateDown(0);
        }
        return min;
    }

    void display() {
        if (heap.size() == 0) {
            cout << "HEAP IS EMPTY!!!\n";
        }
        else {
            cout << "Min Heap: ";
            for (int i = 0; i < heap.size(); i++) {
                cout << heap.at(i) << " ";
            }
            cout << endl;
        }
    }

    int kthSmallest(int k) {
        vector<int> sorted = heap;

        // Sorting the array in ascending order
        for (int i = 0; i < sorted.size(); i++) {
            for (int j = 0; j < sorted.size() - 1; j++) {
                if (sorted[i] > sorted[j]) {
                    swap(sorted[i], sorted[j]);
                }
            }
        }

        return sorted[k - 1]; // return kth smallest (adjusting for zero-based index)
    }
};

int main() {
    MinHeap H1;
    H1.insert(10);
    H1.insert(5);
    H1.insert(15);
    H1.insert(2);
    H1.display();

    int key;
    cout << "Enter the Kth Smallest Index: ";
    cin >> key;
    cout << H1.kthSmallest(key) << endl;

    H1.display();
    return 0;
}
