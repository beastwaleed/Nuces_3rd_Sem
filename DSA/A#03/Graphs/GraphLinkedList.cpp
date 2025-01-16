#include<iostream>
#include<string>
#include<vector>
#include<queue>
#include<stack>
using namespace std;

class Node {
public:
	int data;
	Node* next;
};

class AdjList {
public:
	Node* head;
};


class Graph {
	int V;
	AdjList* array;

public:
	Graph(int num) {
		V = num;
		array = new AdjList[V];

		for (int i = 0;i < V;i++) {
			array[i].head = NULL;
		}
	}

	void addEdge(int src, int dest) {
		Node* newNode = new Node;
		newNode->data = dest;
		newNode->next = NULL;

		newNode->next = array[src].head;
		array[src].head = newNode;


		newNode = new Node;
		newNode->data = src;
		newNode->next = NULL;

		newNode->next = array[dest].head;
		array[dest].head = newNode;

	}

	vector<int> BFS(int start) {
		vector<bool> visited(V, false);
		queue <int> q;
		vector<int> result;

		q.push(start);
		visited[start] = true;

		while (!q.empty()) {
			int curr = q.front();
			q.pop();

			result.push_back(curr);

			Node* temp = array[curr].head;

			while (temp != NULL) {
				int adj = temp->data;
				if (!visited[adj]) {
					q.push(adj);
					visited[adj] = true;
				}
				temp = temp->next;
			}
		}
		return result;
	}

	vector<int> DFS(int start) {
		vector<bool> visited(V, false);
		stack<int> s;
		vector<int> result;

		s.push(start);
		visited[start] = true;

		while (!s.empty()) {
			int curr = s.top();
			s.pop();
			result.push_back(curr);

			//Explore all neighbour vertices
			Node* temp = array[curr].head;
			while (temp != NULL) {
				int adj = temp->data;
				if (!visited[adj]) {
					s.push(adj);
					visited[adj] = true;
				}
				temp = temp->next;
			}
		}
		return result;
	}



	void printGraph() {
		for (int i = 0; i < V; i++) {
			cout << "Vertex " << i << ":";
			Node* temp = array[i].head;
			while (temp != NULL) {
				cout << " -> " << temp->data;
				temp = temp->next;
			}
			cout << endl;
		}
	}

};


int main() {


	int vertices;
	cout << "Enter Vertices Numbers: ";
	cin >> vertices;

	Graph  G1(vertices);

	int edges;
	cout << "Enter Edges Numbers: ";
	cin >> edges;


	int src, dest;
	for (int i = 0;i < edges;i++) {
		cout << "Add Edges: [Src Dest]: ";
		cin >> src >> dest;
		G1.addEdge(src, dest);
	}

	cout << "Displaying Graph in Adjacency List: \n";
	G1.printGraph();

	int bfs;
	cout << "Enter Starting Vertice for BFS: ";
	cin >> bfs;

	vector<int> bfsResult = G1.BFS(bfs);
	for (int i = 0;i < bfsResult.size();i++) {
		cout << bfsResult[i] << " ";
	}

	int dfs;
	cout << "\nEnter Starting Vertice for BFS: ";
	cin >> dfs;

	vector<int> dfsResult = G1.BFS(bfs);
	for (int i = 0;i < bfsResult.size();i++) {
		cout << dfsResult[i] << " ";
	}

	return 0;

}