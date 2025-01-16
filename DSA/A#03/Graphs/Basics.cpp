#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <climits>
using namespace std;

class Graph {
private:
    int V;
    vector<vector<int>> matrix; // Adjacency Matrix

public:
    Graph(int ver) {
        V = ver;
        matrix = vector<vector<int>>(V, vector<int>(V, 0));
    }

    // Add an edge between two vertices
    void addEdge(int row, int col, int weight) {
        if (row >= 0 && row < V && col >= 0 && col < V) {
            matrix[row][col] = weight;
            matrix[col][row] = weight;
        }
        else {
            cout << "Invalid Edge! Vertices must be between 0 and " << V - 1 << "\n";
        }
    }

    void deleteEdge(int row, int col) {
        if (row >= 0 && row < V && col >= 0 && col < V) {
            matrix[row][col] = 0;
            matrix[col][row] = 0;
        }
        else {
            cout << "Invalid Edge! Vertices must be between 0 and " << V - 1 << "\n";
        }
    }

    void updateEdge(int row, int col, int weight) {
        if (row >= 0 && row < V && col >= 0 && col < V) {
            matrix[row][col] = weight;
            matrix[col][row] = weight;
        }
        else {
            cout << "Invalid Edge! Vertices must be between 0 and " << V - 1 << "\n";
        }
    }

    void display() {
        cout << "\nAdjacency Matrix:" << endl;
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                cout << matrix[i][j] << " ";
            }
            cout << endl;
        }
    }

    bool checkSymmetric() {
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                if (matrix[i][j] != matrix[j][i]) {
                    return false;
                }
            }
        }
        return true;
    }

    void BFS(int vertice) {
        cout << "\nBFS:\n";
        vector<bool> visited(V, false);
        queue<int> q;

        q.push(vertice);
        visited[vertice] = true;

        while (!q.empty()) {
            int current = q.front();
            q.pop();
            cout << current << " ";

            for (int i = 0; i < V; i++) {
                if (matrix[current][i] != 0 && !visited[i]) {
                    q.push(i);
                    visited[i] = true;
                }
            }
        }
        cout << endl;
    }

    void DFS(int vertice) {
        cout << "\nDFS:\n";
        vector<bool> visited(V, false);
        stack<int> s;

        s.push(vertice);
        visited[vertice] = true;
        cout << vertice << " ";

        while (!s.empty()) {
            int curr = s.top();
            bool found = false;

            for (int i = 0; i < V; i++) {
                if (matrix[curr][i] != 0 && !visited[i]) {
                    s.push(i);
                    visited[i] = true;
                    cout << i << " ";
                    found = true;
                    break;
                }
            }

            if (!found) {
                s.pop();
            }
        }
        cout << endl;
    }

    vector<int> ShortestPath(int src) {
        vector<bool> visited(V, false);
        queue<int> q;
        vector<int> dist(V, -1);

        q.push(src);
        dist[src] = 0; // Distance to itself is 0
        visited[src] = true;

        while (!q.empty()) {
            int curr = q.front();
            q.pop();

            for (int i = 0; i < V; i++) {
                if (matrix[curr][i] != 0 && !visited[i]) {
                    visited[i] = true;
                    q.push(i);
                    dist[i] = dist[curr] + 1;
                }
            }
        }
        return dist;
    }

    int BFSDiameter(int src) {
        vector<int> dist(V, -1);
        queue<int> q;

        dist[src] = 0;
        q.push(src);

        int maxDist = 0;
        while (!q.empty()) {
            int node = q.front();
            q.pop();

            for (int i = 0; i < V; i++) {
                if (matrix[node][i] != 0 && dist[i] == -1) {
                    dist[i] = dist[node] + 1;
                    q.push(i);

                    if (dist[i] > maxDist) {
                        maxDist = dist[i];
                    }
                }
            }
        }
        return maxDist;
    }

    int computeDiameter() {
        int diameter = 0;

        for (int i = 0; i < V; i++) {
            int maxDist = BFSDiameter(i);
            if (maxDist > diameter) {
                diameter = maxDist;
            }
        }
        return diameter;
    }


    void primMST() {
        vector<int> key(V, INT_MAX);       // Initialize the key values for all vertices to infinity.
        vector<bool> mstSet(V, false);     // Initialize the MST set to false for all vertices.
        vector<int> parent(V, -1);         // Initialize the parent array to store the MST.

        // Loop to find the minimum spanning tree
        for (int count = 0; count < V; count++) {
            int u = -1;

            // Find the vertex with the minimum key value that is not yet included in MST
            for (int i = 0; i < V; i++) {
                if (mstSet[i] != true && (u == -1 || key[i] < key[u])) {
                    u = i;
                }
            }

            mstSet[u] = true; // Include the selected vertex in the MST

            // Update the key values and parent index of the adjacent vertices
            for (int v = 0; v < V; v++) {
                if (matrix[u][v] && !mstSet[v] && matrix[u][v] < key[v]) {
                    key[v] = matrix[u][v];  // Update the key value
                    parent[v] = u;          // Update the parent index
                }
            }
        }

        // Print the constructed MST
        cout << "\nEdge \tWeight\n";
        for (int i = 1; i < V; i++) {
            cout << parent[i] << " - " << i << " \t" << matrix[i][parent[i]] << " \n";
        }
    }


};

int main() {
    int vertices, edges;
    cout << "Enter Number of Vertices: ";
    cin >> vertices;

    Graph G(vertices);

    cout << "Enter Number of Edges: ";
    cin >> edges;

    G.display();

    int r, c, w;

    for (int i = 0; i < edges; i++) {
        cout << "Enter Edge (Row, Col, Weight): ";
        cin >> r >> c >> w;
        G.addEdge(r, c, w);
    }

    G.display();

    if (G.checkSymmetric()) {
        cout << "\nGraph is Symmetric\n";
    }
    else {
        cout << "\nGraph is not Symmetric\n";
    }

    int node;
    cout << "Enter Starting Vertex for BFS & DFS: ";
    cin >> node;

    G.BFS(node);
    G.DFS(node);


    G.primMST();

    /* cout << "\nEnter Starting Node for Shortest Path Calculation: ";
     int source;
     cin >> source;

     vector<int> distances = G.ShortestPath(source);

     cout << "\nShortest Distances from Node " << source << ":\n";
     for (int i = 0; i < distances.size(); i++) {
         if (distances[i] == -1) {
             cout << "Node " << i << ": Not Reachable\n";
         }
         else {
             cout << "Node " << i << ": " << distances[i] << "\n";
         }
     }

     cout << "Diameter of the Graph is: " << G.computeDiameter() << endl;*/

    return 0;
}
