//#include <iostream>
//#include <vector>
//#include <queue>
//#include <stack>
//using namespace std;
//
//class Graph {
//	int V;
//	vector<vector<int>> mat;
//public:
//	Graph(int vertices) : V(vertices) {
//		mat = vector<vector<int>>(V, vector<int>(V, 0));
//	}
//
//	// Weighted undirected graph
//	void addEdge(int row, int col, int val) {
//		mat[row][col] = val;
//		mat[col][row] = val;
//	}
//
//	bool checkSymmetric() {
//		for (int i = 0; i < V; i++) {
//			for (int j = 0; j < V; j++) {
//				if (mat[i][j] != 0) {
//					if (mat[i][j] != mat[j][i]) {
//						return false;
//					}
//				}
//			}
//		}
//	}
//
//	void BFS(int vertice) {
//		vector<bool> visited(V, false);
//		queue<int> q;
//
//		q.push(vertice);		// 1
//		visited[vertice] = true;
//
//		while (!q.empty()) {
//			int current = q.front();
//			q.pop();
//			cout << current << " ";
//
//			for (int k = 0; k < V; k++) {
//				if (mat[current][k] != 0 && visited[k] == false) {
//					q.push(k);
//					visited[k] = true;
//				}
//			}
//
//		}
//
//	}
//
//	void DFS(int vertice) {
//		vector<bool> visited(V, false);
//		stack<int> stck;
//
//		stck.push(vertice);
//		visited[vertice] = true;
//		cout << vertice << " ";
//
//		while (!stck.empty()) {
//			int current = stck.top();
//
//			for (int k = 0; k < mat.size(); k++) {
//				if (mat[current][k] != 0 && !visited[k]) {
//					stck.push(k);
//					visited[k] = true;
//					cout << k << " ";
//					break;
//				}
//			}
//
//			if (stck.top() == current)
//				stck.pop();
//		}
//	}
//
//	void display() {
//		for (const auto& i : mat) {
//			for (const auto& j : i) {
//				cout << j << " ";
//			}
//			cout << endl;
//		}
//	}
//
//};
//
//int main() {
//	int V = 0;
//	bool falseInput;
//	string userInput;
//
//	do {
//		int temp = 0;
//		falseInput = false;
//		cout << "Enter Total Number of Vertices : ";
//		cin >> userInput;
//
//		for (auto index : userInput) {
//			V *= 10;
//			if (index < '1' || index > '9') {
//				falseInput = true;
//				break;
//			}
//			V += index - '0';
//		}
//
//		if (falseInput) {
//			cout << "\n-----Invalid Input!-----\n";
//		}
//
//	} while (falseInput);
//
//	Graph adjMat(V);
//
//	adjMat.display();
//
//	cout << "\n\nInstructions:"
//		<< "\n-> '0' indicates there is no edge butween the vertices at (row, col) and (col, row)."
//		<< "\n-> Add '0' to remove the edge at any row, col."
//		<< "\n-> Enter 'E' or 'e' to stop adding edges." << endl;
//
//	int i, j;
//	char row, col;
//	double val;
//	do {
//		cout << "\nAdd Weighted Edge at (row): ";
//		cin >> row;
//
//		if (row == 'E' || row == 'e')
//			break;
//
//		i = row - '0';
//		if (i < 0 || i >= V) {
//			cout << "\n-----Invalid Input!-----\n";
//			continue;
//		}
//
//		cout << "Add Weighted Edge at (col): ";
//		cin >> col;
//
//		if (col == 'E' || col == 'e')
//			break;
//
//		j = col - '0';
//		if (j < 0 || j >= V) {
//			cout << "\n-----Invalid Input!-----\n";
//			continue;
//		}
//
//		cout << "Enter value : ";
//		cin >> val;
//
//		adjMat.addEdge(i, j, val);
//	} while (row != 'E' && row != 'e' && col != 'E' && col != 'e');
//
//	do {
//		cout << "\nEnter starting vertice number : ";
//		cin >> i;
//
//		if (i < 0 || i > V) {
//			cout << "\n-----Invalid Input!-----\n"; 
//		}
//
//	} while (i < 0 || i > V);
//
//	cout << "\nBFS : ";
//	adjMat.BFS(i);
//
//	cout << "\nDFS : ";
//	adjMat.DFS(i);
//	
//	cout << endl;
//	system("pause");
//	return 0;
//}