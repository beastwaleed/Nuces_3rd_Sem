//#include<iostream>
//using namespace std;
//
//template <typename T> //template for queues
//class Queue {
//	T* array; //dyanmic array
//	int front;
//	int rear;
//	int size;
//	int counter;
//
//public:
//	Queue(int s) { //constructor
//		array = new T[s];
//		size = s;
//		front = -1;
//		rear = -1;
//		counter = 0;
//	}
//
//	~Queue() { //destructor
//		delete[] array;
//	}
//
//	bool isEmpty() { //check either queue is empty
//		if (counter == 0) {
//			return true;
//		}
//		else {
//			return false;
//		}
//	}
//
//	bool isFull() { //check either queue is full
//		if (counter == size) {
//			return true;
//		}
//		else {
//			return false;
//		}
//	}
//
//	void Enqueue(T val) { //push function
//		if (isFull()) {
//			cout << "OVERFLOW!!!" << endl;
//			return;
//		}
//
//		if (isEmpty()) {
//			front = 0;
//		}
//		rear = (rear + 1) % size;
//		array[rear] = val;
//		counter++;
//	}
//
//	T Dequeue() { //function to pop
//		if (isEmpty()) {
//			cout << "Queue Is Empty!! Cannot Dequeue" << endl;
//
//			return -1;
//		}
//
//		T tempData = array[front];
//		front = (front + 1) % size;
//		counter--;
//
//		if (isEmpty()) {
//			front = -1;
//			rear = -1;
//		}
//
//		return tempData;
//	}
//
//};
//
//
//int main() {
//	int numQueues = 0; //
//	int numPeople = 0;
//
//	cout << "\n <~==~~==~==~> Movie Ticket Management <~==~~==~==~>\n";
//	cout << "Enter Number of Queues: "; //user input num of queues
//	cin >> numQueues;
//
//	do { //user input number of person (minimum 10)
//		cout << "Enter Number of People in Each Queue (Min 10): ";
//		cin >> numPeople;
//	} while (numPeople < 10);
//
//	//creating a dynamic 2darray for queues
//	Queue<int>** queues = new Queue<int>*[numQueues];
//
//	for (int i = 0; i < numQueues; i++) { // initializing array with numPeople
//		queues[i] = new Queue<int>(numPeople);
//	}
//
//	//enqueue num of People in every queue
//	for (int i = 0;i < numQueues;i++) {
//		for (int j = 0; j < numPeople;j++) {
//			queues[i]->Enqueue(j + 1);
//		}
//	}
//
//	while (true) { //function to simulate the queue one by one , starting from the last queue
//		if (queues[numQueues - 1]->isEmpty() == false) { //checking whether queue is empty or not
//			int firstperson = queues[numQueues - 1]->Dequeue(); //popping the fisrt person from last queue where the collector is standing 
//			cout << "---------------------------------------------------------------------";
//			cout << "\n-- Proccessed Person  " << firstperson << " from Queue " << numQueues << endl;
//			cout << "---------------------------------------------------------------------";
//
//
//			for (int i = numQueues - 2;i >= 0;i--) { //loop for the above queue if total queues are 3 then this will be queue 2
//				if (queues[i]->isEmpty() == false) { //checking whether queue is empty or not
//					int movedPerson = queues[i]->Dequeue(); //popping the fisrt person from queue and saving into varibale
//
//					queues[numQueues - 1]->Enqueue(movedPerson); //pushing that saved person to last(n-1) queue 
//
//					cout << "\n==> Moved Person " << movedPerson << " from Queue " << i + 1 << " to Queue " << numQueues << endl;
//					break;
//				}
//			}
//
//		}
//
//		else { //else checking if all the queues were empty
//			bool allEmpty = true; //Flag to check
//			for (int i = 0;i < numQueues;i++) {
//				if (queues[i]->isEmpty() == false) { //isEmpty function to check
//					allEmpty = false;
//					break;
//				}
//			}
//			if (allEmpty) { //if yes then ----
//				cout << "\n<===>All Queues are Empty. Proccessing Completedd!!<===>" << endl;
//				break;
//			}
//		}
//	}
//
//	//deleting dynamic queues once the queues are empty
//	for (int i = 0; i < numQueues; i++) {
//		delete queues[i];
//	}
//	delete[] queues; //deleting queue also
//	system("pause");
//
//	return 0;
//
//}