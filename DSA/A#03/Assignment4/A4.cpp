#include <iostream>
#include <vector>
using namespace std;

class MST {
	vector<vector<int>> mat;
	int vertices;
public:
	MST(int V) {
		vertices = V;			// (rows, vector<int>(vertices));
		mat = vector<vector<int>>(vertices, vector<int>(vertices));
	}

	void insertMatrix() {
		cout << "Enter the adjacency matrix (use 0 for no edge): " << endl;
		for (int row = 0; row < mat.size(); row++) {
			for (int col = 0; col < mat[row].size(); col++) {
				cin >> mat[row][col];
			}
		}
		cout << endl;
	}


	void primsMST() {
		vector<int> key(vertices, 1000);
		vector<bool> inMST(vertices, false);
		vector<int> parent(vertices, -1);
		key[0] = 0;
		int mstWeight = 0;

		cout << "\nPrim's MST:\n";

		for (int count = 0; count < vertices - 1; count++) {

			int minKey = 1000, u = -1;
			for (int v = 0; v < vertices; v++) {
				if (!inMST[v] && key[v] < minKey) {
					minKey = key[v];
					u = v;
				}
			}

			inMST[u] = true;


			for (int v = 0; v < vertices; v++) {
				if (mat[u][v] != 0 && mat[u][v] != 1000 && !inMST[v] && mat[u][v] < key[v]) {
					key[v] = mat[u][v];
					parent[v] = u;
				}
			}
		}


		for (int v = 1; v < vertices; v++) {
			if (parent[v] != -1) {
				cout << parent[v] << " - " << v << "\tWeight: " << mat[parent[v]][v] << endl;
				mstWeight += mat[parent[v]][v];
			}
		}

		cout << "Minimum cost using Prim's: " << mstWeight << endl;
	}
};

int main() {
	int V;

	// Prompt the user to enter the number of vertices
	cout << "Enter the number of vertices : ";
	cin >> V;

	MST graph(V);

	graph.insertMatrix();		// Calling function take user input
	graph.primsMST();			// Calling function to calculate Prim's MST

	system("pause");
	return 0;
}