//#include <iostream>
//#include <vector>
//using namespace std;
//
//class MinHeap {
//	vector<int> heap;
//
//	void swap(int& num1, int& num2) {
//		int temp = num1;
//		num1 = num2;
//		num2 = temp;
//	}
//
//	void percolateUp(int index) {
//		while (index > 0) {
//			int parentIndex = (index - 1) / 2;
//			if (heap[index] < heap[parentIndex]) {
//				swap(heap[index], heap[parentIndex]);
//				index = parentIndex;
//			}
//			else
//				break;
//		}
//	}
//
//	void percolateDown(int index) {
//		int size = heap.size();
//
//		while (true) {
//			int leftChild = 2 * index + 1;
//			int rightChild = 2 * index + 2;
//			int smallest = index;
//
//			if (leftChild < size && heap[leftChild] < heap[smallest])
//				smallest = leftChild;
//			if (rightChild < size && heap[rightChild] < heap[smallest])
//				smallest = rightChild;
//			if (smallest == index)
//				break;
//			swap(heap[index], heap[smallest]);
//			index = smallest;
//		}
//	}
//
//public:
//	void insertHeap(int val) {
//		heap.push_back(val);
//		percolateUp(heap.size() - 1);
//	}
//
//	int deleteHeap() {
//		if (heap.size() == 0) //if size is zero
//			return -1;
//
//		//else
//		int min = heap.front(); //first value of heeap
//
//		if (heap.size() == 1)
//			heap.pop_back();
//		else {
//			heap.front() = heap.back();
//			heap.pop_back();
//			percolateDown(0);
//		}
//
//
//		return min;
//	}
//
//	void display() {
//		if (heap.size() == 0) {
//			cout << "\n-----Error! Heap is Empty-----\n";
//			return;
//		}
//
//		cout << "\nMin Heap : ";
//		for (int val : heap) {
//			cout << val << " ";
//		}
//		cout << endl;
//	}
//};
//
//int main() {
//	MinHeap heapObj;
//	char choice;
//	int val = 0;
//
//	do {
//		cout << "\n<======Min Heap Operations======>"
//			<< "\n1. Insert Tasks"
//			<< "\n2. Extract Highest Priority"
//			<< "\n3. Display Heap"
//			<< "\n4. Exit"
//			<< "\nEnter choice (1-4) : ";
//		cin >> choice;
//
//		switch (choice)
//		{
//		case '1':
//			cout << "Enter elements (end input with a non-numeric value) : ";
//			while (cin >> val) {
//				heapObj.insertHeap(val);
//			}
//			cin.clear();
//			cin.get();
//			cout << "\n-----Tasks Inserted Successfully!-----\n";
//			break;
//		case '2': {
//			cout << "\nEnter the number of priorities to be extracted : ";
//			cin >> val;
//			int i = 1;
//			while (i <= val) {
//				int priority = heapObj.deleteHeap();
//				if (priority != -1) {
//					cout << "Highest-Priority Task " << i << ": " << priority << endl;
//					++i;
//				}
//				else {
//					cout << "\n-----Error! Heap is Empty-----\n";
//					break;
//				}
//			}
//			break;
//		}
//		case '3':
//			heapObj.display();
//			break;
//		case '4':
//			cout << "\n-----Program Terminated!-----\n";
//			break;
//		default:
//			cout << "\n-----Invalid Input!-----\n";
//			break;
//		}
//	} while (choice != '4');
//
//	system("pause");
//	return 0;
//}