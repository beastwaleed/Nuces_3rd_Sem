//#include<iostream>
//#include<vector>
//using namespace std;
//
//class Graph {
//	int V;
//	vector<vector<pair<int, int>>> adjlist;
//
//public:
//	Graph(int ver) {
//		V = ver;
//		adjlist = vector<vector<pair<int, int>>>(V);
//	}
//
//	void addEdge(int v1, int v2, int w) {
//		if (v1 >= 0 && v1 < V && v2 >= 0 && v2 < V) {
//
//			adjlist[v1].push_back({ v2,w });
//			adjlist[v2].push_back({ v1,w });
//		}
//
//		else {
//			cout << "Invalid Edge!! Vertices must be between 0 - " << V - 1 << endl;
//		}
//	}
//
//	void displayList() {
//		cout << "Adjacency List: \n";
//		for (int i = 0;i < V;i++) {
//			cout << i + 1 << " -> ";
//			for (auto edge : adjlist[i]) {
//				cout << "(" << edge.first << ", " << edge.second << ")";
//			}
//			cout << endl;
//		}
//
//	}
//
//};
//
//
//int main() {
//
//	int vertices, edges;
//	int r, c, w;
//
//	cout << "Enter Number of Vertices: ";
//	cin >> vertices;
//
//	Graph G(vertices);
//
//	G.displayList();
//
//
//	cout << "Enter Number of Edges: \n";
//	cin >> edges;
//
//	cout << "Add Edges: (Row, Col, Weight)\n";
//	for (int i = 0;i < edges;i++) {
//		cin >> r >> c >> w;
//		G.addEdge(r, c, w);
//
//	}
//
//	G.displayList();
//
//
//}