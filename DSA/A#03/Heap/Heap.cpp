//#include<iostream>
//using namespace std;
//
//class heap {
//public:
//	int arr[100];
//	int size;
//	heap() {
//		size = 0;
//	}
//
//	void insert(int val) { //inserting in max heap
//		size++;
//		int index = size;
//		arr[index] = val;
//
//		//place value so that heap property is satisfied
//		while (index > 1) { //making max heap
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
//	int deletevalue() {
//		int ans = arr[1];
//		//replace root node with last node
//		arr[1] = arr[size];
//		size--;
//		
//		//heap property to be satisfied
//		int index = 1;
//		while (index < size) {
//			int left = 2 * index;
//			int right = 2 * index + 1;
//			//find max value among parent & child
//			int largest = index;
//			if (left <= size && arr[largest] < arr[left]){
//				largest = left;
//			}
//			if (right <= size && arr[largest] < arr[right]){
//				largest = right;
//			}//if root is the largest
//			if (largest == index) {
//				break;
//			}
//			else {
//				swap(arr[index], arr[largest]);
//				//update looping variable
//				index = largest;
//			}
//		}
//		return ans;
//	}
//
//	void display() {
//		cout << "max heap is: ";
//		for(int i=1;i<size+1;i++){
//			cout << arr[i] << " ";
//		}
//	}
//};
//
//
//int main() {
//	heap h1;
//	h1.insert(50);
//	h1.insert(30);
//	h1.insert(70);
//	h1.insert(40);
//	h1.insert(80);
//	h1.insert(100);
//
//	h1.display();
//
//	cout<<"\ndeleted: " << h1.deletevalue();
//
//	cout << "\nafter deleting ";
//	h1.display();
//
//	system("pause");
//	return 0;
//}
