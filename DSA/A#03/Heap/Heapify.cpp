//#include<iostream>
//using namespace std;
//
//class Heap {
//public:
//	int arr[100];
//	int size;
//	Heap() {
//		size = 0;
//	}
//
//	void maxHeapify
//	(int size, int i) {
//		int index = i;
//		int left = 2 * i;
//		int right = 2 * i + 1;
//		int largest = index;
//
//		if (left <= size && arr[largest] < arr[left]) {
//			largest = left;
//		}
//		if (right <= size && arr[largest] < arr[right]) {
//			largest = right;
//		}
//		//check if largest updated or not
//		if (largest != index) {
//			//swap
//			swap(arr[largest], arr[index]);
//			index = largest;
//			//recursive call
//			maxHeapify(size, index);
//		}
//	}
//
//	void insert(int val) { //inserting in Max Heap
//		size++;
//		int index = size;
//		arr[index] = val;
//
//		//place value so that heap property is satisfied
//		while (index > 1) { //Making Max Heap
//			int parent = index / 2;
//			if (arr[parent] < arr[index]) {
//				swap(arr[parent], arr[index]);
//
//				//update index
//				index = parent;
//			}
//
//			else {
//				break;
//			}
//		}
//	}
//
//	int deleteValue() {
//		int ans = arr[1];
//		//replace root node with last node
//		arr[1] = arr[size];
//		size--;
//
//		//heap property to be satisfied
//		int index = 1;
//		maxHeapify(size, index);
//		return ans;
//	}
//
//	void display() {
//		cout << "Max Heap is: ";
//		for (int i = 1;i < size + 1;i++) {
//			cout << arr[i] << " ";
//		}
//	}
//};
//
//
//int main() {
//	Heap H1;
//	H1.insert(50);
//	H1.insert(30);
//	H1.insert(70);
//	H1.insert(40);
//
//	H1.insert(90);
//	H1.insert(100);
//	H1.insert(95);
//
//	H1.display();
//
//	cout << "\nDeleted: " << H1.deleteValue();
//
//	cout << "\nAfter Deleting ";
//	H1.display();
//
//	system("pause");
//	return 0;
//}
