//#include <iostream>
//#include <queue>
//#include <stack>
//#include <vector>
//using namespace std;
//
//struct Node {
//	int vertex;
//	Node* next;
//	Node(int V) : vertex(V), next(nullptr) {}
//};
//
//class Graph {
//	Node** adjList;
//	int vertices;
//
//public:
//	Graph(int V) {
//		vertices = V;
//		adjList = new Node * [vertices];
//		for (int i = 0; i < vertices; i++) {
//			adjList[i] = nullptr;
//		}
//	}
//
//	// Function to add edge for undirected graph
//	void addEdge(int src, int dest) const {
//		Node* newNode = new Node(dest);
//		if (adjList[src] == nullptr) {
//			adjList[src] = newNode;
//		}
//		else {
//			Node* temp = adjList[src];
//			while (temp->next != nullptr) {
//				temp = temp->next;
//			}
//			temp->next = newNode;
//		}
//
//		newNode = new Node(src);
//		if (adjList[dest] == nullptr) {
//			adjList[dest] = newNode;
//		}
//		else {
//			Node* temp = adjList[dest];
//			while (temp->next != nullptr) {
//				temp = temp->next;
//			}
//			temp->next = newNode;
//		}
//	}
//
//	void BFS(int start) {
//		queue<int> q;
//		bool* visited = new bool[vertices]();
//		char user;
//
//		q.push(start);
//		visited[start] = true;
//
//		cout << "BFS Traversal : ";
//
//		while (!q.empty()) {
//			int current = q.front();
//			q.pop();
//
//			user = 'A' + current;
//			cout << user << " ";
//
//			Node* temp = adjList[current];
//
//			while (temp != nullptr) {
//				if (!visited[temp->vertex]) {
//					visited[temp->vertex] = true;
//					q.push(temp->vertex);
//				}
//				temp = temp->next;
//			}
//		}
//		cout << endl;
//		delete[] visited;
//	}
//
//	void DFS(int start) {
//		stack<int> stack;
//		Node* temp;
//		char user;
//		bool* visited = new bool[vertices]();
//
//		cout << "DFS Traversal : ";
//
//		visited[start] = true;
//		stack.push(start);
//
//		user = 'A' + start;
//		cout << user << " ";
//
//		while (!stack.empty()) {
//			int current = stack.top();
//			temp = adjList[current];
//
//			while (visited[temp->vertex] && temp->next != nullptr) {
//				temp = temp->next;
//			}
//
//			if (!visited[temp->vertex]) {
//				visited[temp->vertex] = true;
//				stack.push(temp->vertex);
//				user = 'A' + temp->vertex;
//				cout << user << " ";
//			}
//
//			else {
//				stack.pop();
//			}
//		}
//		cout << endl;
//		delete[] visited;
//	}
//
//	void findShortestPath(int start, int end) {
//		queue<int> q;
//		vector<int> distance(vertices, -1);
//		vector<int> parent(vertices, -1);
//		char user1, user2;
//
//		q.push(start);
//		distance[start] = 0;
//
//		while (!q.empty()) {
//			int current = q.front();
//			q.pop();
//
//			Node* temp = adjList[current];
//
//			while (temp != nullptr) {
//				if (distance[temp->vertex] == -1) {
//					distance[temp->vertex] = distance[current] + 1;
//					parent[temp->vertex] = current;
//					q.push(temp->vertex);
//				}
//				temp = temp->next;
//			}
//		}
//
//		if (distance[end] == -1) {
//			user1 = 'A' + start;
//			user2 = 'A' + end;
//			cout << "No path exists between " << user1 << " and " << user2 << "." << endl;
//		}
//		else {
//			user1 = 'A' + start;
//			user2 = 'A' + end;
//			cout << "Shortest path between " << user1 << " and " << user2 << " is: ";
//			vector<int> path;
//			for (int at = end; at != -1; at = parent[at]) {
//				path.push_back(at);
//			}
//			for (int i = path.size() - 1; i >= 0; i--) {
//				cout << char('A' + path[i]) << (i > 0 ? " -> " : "");
//			}
//			cout << " (Distance: " << distance[end] << ")" << endl;
//		}
//	}
//
//	~Graph() {
//		for (int i = 0; i < vertices; i++) {
//			Node* head = adjList[i];
//			while (head->next != nullptr) {
//				Node* temp = head;
//				head = head->next;
//				delete temp;
//			}
//		}
//		delete[] adjList;
//	}
//};
//
//int main() {
//	Graph adjListObj(6);
//
//	adjListObj.addEdge(0, 1); // A-B
//	adjListObj.addEdge(0, 2); // A-C
//	adjListObj.addEdge(1, 3); // B-D
//	adjListObj.addEdge(1, 4); // B-E
//	adjListObj.addEdge(2, 5); // C-F
//
//	// Final Adjacency List (when adding edge at head)
//	// 0 : 2 1
//	// 1 : 4 3 0
//	// 2 : 5 0
//	// 3 : 1
//	// 4 : 1
//	// 5 : 2
//
//	adjListObj.BFS(0);
//	adjListObj.DFS(0);
//
//	adjListObj.findShortestPath(0, 5);
//	adjListObj.findShortestPath(0, 3);
//
//	system("pause");
//	return 0;
//}