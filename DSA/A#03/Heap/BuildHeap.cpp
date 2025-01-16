//#include<iostream>
//using namespace std;
//
//class Heap {
//public:
//    int arr[100];
//    int size;
//
//    Heap() {
//        size = 0;
//    }
//
//    void maxHeapify(int size, int i) {
//        int index = i;
//        int left = 2 * i;
//        int right = 2 * i + 1;
//        int largest = index;
//
//        if (left <= size && arr[largest] < arr[left]) {
//            largest = left;
//        }
//        if (right <= size && arr[largest] < arr[right]) {
//            largest = right;
//        }
//
//        if (largest != index) {
//            swap(arr[index], arr[largest]);
//            maxHeapify(size, largest);
//        }
//    }
//
//    void insert(int val) {  // Inserting in Max Heap
//        size++;
//        int index = size;
//        arr[index] = val;
//
//        while (index > 1) {  // Making Max Heap
//            int parent = index / 2;
//            if (arr[parent] < arr[index]) {
//                swap(arr[parent], arr[index]);
//                index = parent;
//            }
//            else {
//                break;
//            }
//        }
//    }
//
//    int deleteValue() {
//        int ans = arr[1];
//        arr[1] = arr[size];
//        size--;
//
//        int index = 1;
//        maxHeapify(size, index);
//        return ans;
//    }
//
//    void buildHeap(int inputArr[], int n) {
//        // Copy elements from inputArr to arr
//        size = n;
//        for (int i = 1; i <= n; i++) {
//            arr[i] = inputArr[i - 1];  // Fill the array starting from index 1
//        }
//
//        // Build max heap by calling maxHeapify for each non-leaf node starting from last non-leaf node
//        for (int i = size / 2; i >= 1; i--) {
//            maxHeapify(size, i);
//        }
//    }
//
//    void display() {
//        cout << "Max Heap is: ";
//        for (int i = 1; i <= size; i++) {
//            cout << arr[i] << " ";
//        }
//        cout << endl;
//    }
//};
//
//int main() {
//    Heap H1;
//
//    // Example of building a heap
//    int inputArr[] = { 50, 30, 70, 40, 90, 100, 95 };
//    int n = sizeof(inputArr) / sizeof(inputArr[0]);
//
//    // Build heap from input array
//    H1.buildHeap(inputArr, n);
//    H1.display();
//
//    H1.insert(110);  // Insert a new value into the heap
//    cout << "After Insertion: ";
//    H1.display();
//
//    cout << "Deleted: " << H1.deleteValue() << endl;
//
//    cout << "After Deleting: ";
//    H1.display();
//
//    system("pause");
//    return 0;
//}
