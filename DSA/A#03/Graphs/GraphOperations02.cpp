//#include <iostream>
//#include <vector>
//#include <queue>
//#include <stack>
//using namespace std;
//
//struct Node {
//	char vertice;
//	double weight;
//	Node* next;
//
//	Node(char v, double w) : vertice(v), weight(w), next(nullptr) {}
//};
//
//class Graph {
//	int V;
//	Node** list;
//
//	void displayMat(vector<vector<double>>& mat) const {
//		cout << "\nAdjacency Matrix : " << endl;
//		for (int i = 0; i < V; i++) {
//			for (int j = 0; j < V; j++) {
//				cout << mat[i][j] << "\t";
//			}
//			cout << endl;
//		}
//	}
//
//public:
//	Graph(int vertices) : V(vertices) {
//		list = new Node * [V];
//		for (int i = 0; i < vertices; i++) {
//			list[i] = nullptr;
//		}
//	}
//
//	// Undirected weighted graph
//	void addEdge(char src, double w, char dest) {
//		int row = src - 'A';
//		int col = dest - 'A';
//
//		Node* temp = new Node(dest, w);
//		if (list[row] == nullptr) {
//			list[row] = temp;
//		}
//		else {
//			Node* current = list[row];
//			while (current->next != nullptr) {
//				current = current->next;
//			}
//			current->next = temp;
//		}
//	}
//
//	void makeAdjMat() {
//		vector<vector<double>> mat(V, vector<double>(V, 0));
//
//		for (int i = 0; i < V; i++) {
//			Node* current = list[i];
//			
//			while (current != nullptr) {
//				int col = current->vertice - 'A';
//				mat[i][col] = current->weight;
//				
//				current = current->next;
//			}
//		}
//
//		displayMat(mat);
//	}
//
//	void BFS(char start) {
//		vector<bool> visited(V, false);
//		queue<char> q;
//
//		q.push(start);
//		visited[start] = true;
//
//		while (!q.empty()) {
//			char current = q.front();
//			q.pop();
//			cout << current << " ";
//
//			Node* temp = list[current - 'A'];
//			while (temp != nullptr) {
//				if (!visited[temp->vertice - 'A']) {
//					visited[temp->vertice - 'A'] = true;
//					q.push(temp->vertice);
//				}
//				temp = temp->next;
//			}
//		}
//		cout << endl;
//	}
//
//	void DFS(char start) {
//		vector<bool> visited(V, false);
//		stack<char> stck;
//
//		stck.push(start);
//		visited[start] = true;
//		cout << start << " ";
//
//		while (!stck.empty()) {
//			char current = stck.top();
//			
//			Node* temp = list[current - 'A'];
//			while (temp != nullptr) {
//				if (!visited[temp->vertice - 'A']) {
//					visited[temp->vertice - 'A'] = true;
//					stck.push(temp->vertice);
//					cout << temp->vertice << " ";
//				}
//			}
//
//			if (current == stck.top())
//				stck.pop();
//		}
//	}
//
//	void displayList() const {
//		if (list == nullptr)
//			return;
//
//		cout << "\nAdjacency List : " << endl;
//		for (int i = 0; i < V; i++) {
//			cout << char('A' + i);
//			Node* current = list[i];
//			while (current != nullptr) {
//				cout << " -> " << current->vertice;
//				current = current->next;
//			}
//			cout << endl;
//		}
//		cout << endl;
//	}
//};
//
//int main() {
//	int V;
//	char src, dest;
//	double w;
//
//	cout << "\nEnter Total Number of Vertices : ";
//	cin >> V;
//
//	if (V < 2)
//		return 0;
//
//	Graph adjList(V);
//
//	cout << "\nInstructions:"
//		<< "-> Enter '/' to exit.";
//
//	do {
//		int temp;
//		cout << "\nAdd Edge Source (A-Z) : ";
//		cin >> src;
//
//		if (src == '/')
//			break;
//
//		temp = src - 'A';
//
//		if (temp < 0 || temp >= V) {
//			cout << "\n-----Invalid Input!-----\n";
//			continue;
//		}
//
//		cout << "Add Edge Destination (A-Z) : ";
//		cin >> dest;
//
//		if (src == '/')
//			break;
//
//		temp = dest - 'A';
//
//		if (temp < 0 || temp >= V) {
//			cout << "\n-----Invalid Input!-----\n";
//			continue;
//		}
//
//		cout << "Add Weight : ";
//		cin >> w;
//
//		adjList.addEdge(src, w, dest);
//		adjList.addEdge(dest, w, src);
//
//	} while (true);
//
//	adjList.displayList();
//	adjList.makeAdjMat();
//
//	system("pause");
//	return 0;
//}