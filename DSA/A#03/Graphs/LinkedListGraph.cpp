#include <iostream>
#include <vector>
#include <queue>
#include <stack>
using namespace std;

class Node {
public:
    int vertex;
    Node* next;
    int weight;

    Node(int v,int w) {
        vertex = v;
        weight = w;
        next = NULL;
    }
};

class Graph {
private:
    int V; // number of vertices
    Node** adjList; // Array of pointers to represent the adjacency list

public:
    Graph(int ver) {
        V = ver;
        adjList = new Node * [V];

        for (int i = 0; i < V; i++) {
            adjList[i] = NULL;
        }
    }

    Node* createNode(int vertex,int weight) {
        Node* newNode = new Node(vertex, weight);
        return newNode;
    }

    void addEdge(int src, int dest) {
        Node* newNode = createNode(dest);
        newNode->next = adjList[src];
        adjList[src] = newNode;

        newNode = createNode(src,weight); // Add this line to make the graph undirected
        newNode->next = adjList[dest];
        adjList[dest] = newNode;
    }

    vector<int> shortestPath(int src) {
        vector<int> dist(V, -1);
        vector<bool> visited(V, false);
        queue<int> q;

        visited[src] = true;
        dist[src] = 0;
        q.push(src);

        while (!q.empty()) {
            int curr = q.front();
            q.pop();

            Node* temp = adjList[curr];
            while (temp != NULL) {
                if (!visited[temp->vertex]) {
                    visited[temp->vertex] = true;
                    dist[temp->vertex] = dist[curr] + 1;
                    q.push(temp->vertex);
                }
                temp = temp->next;
            }
        }

        return dist;
    }

    int computeDiameter() {
        int diameter = 0;
        for (int i = 0; i < V; i++) {
            vector<int> dist = shortestPath(i);
            for (int d : dist) {
                if (d > diameter) {
                    diameter = d;
                }
            }
        }
        return diameter;
    }

    void primMST() {
    
        vector<int>key(V, INT_MAX);
        vector<bool>mstSet(V, false);
        vector<int>parent(V, -1);

        for (int count = 0;count < V;count++) {
            int u = -1;
            for (int i = 0;i < V;i++) {
                if (mstSet != true && (u == -1 || key[i] < key[u])) {
                    u = i;
                }
            }
            mstSet[u] = true;

            Node* temp = adjList[u];
            while (temp != NULL) {
                int v = temp->vertex;
                int weight = temp->weight;
                
                if (mstSet[v] && weight < key[v]) {
                    key[v] = weight;
                    parent[v] = u;
                }
            }
        }
        cout << "Prims Traversal\n";
        cout << "\n Edge \tWeight\n";
        for (int i = 1; i < V; i++) {
            cout << parent[i] << " - " << i << " \t" << key[i] << " \n";
        }
            
    }



    void display() {
        for (int i = 0; i < V; i++) {
            cout << i;
            Node* temp = adjList[i];

            while (temp != NULL) {
                cout << " -> " << temp->vertex << "("<<temp->weight")";
                temp = temp->next;
            }
            cout << endl;
        }
    }

    void BFS(int start) {
        vector<bool> visited(V, false);
        queue<int> q;

        visited[start] = true;
        q.push(start);

        while (!q.empty()) {
            int curr = q.front();
            q.pop();
            cout << curr << " ";

            Node* temp = adjList[curr];
            while (temp != NULL) {
                if (!visited[temp->vertex]) {
                    visited[temp->vertex] = true;
                    q.push(temp->vertex);
                }
                temp = temp->next;
            }
        }
        cout << endl;
    }

    void DFS(int src) {
        vector<bool> visited(V, false);
        stack<int> s;

        s.push(src);

        while (!s.empty()) {
            int curr = s.top();
            s.pop();

            if (!visited[curr]) {
                visited[curr] = true;
                cout << curr << " ";
            }

            Node* temp = adjList[curr];
            while (temp != NULL) {
                if (!visited[temp->vertex]) {
                    s.push(temp->vertex);
                }
                temp = temp->next;
            }
        }
        cout << endl;
    }
};

int main() {
    int vertices, edges;

    cout << "Enter Number of Vertices: ";
    cin >> vertices;

    Graph G(vertices);

    cout << "Enter the number of edges: ";
    cin >> edges;

    for (int i = 0; i < edges; i++) {
        int s, d;
        cout << "Enter Src and Dest: ";
        cin >> s >> d;
        G.addEdge(s, d);
    }

    G.display();

    cout << "Breadth-First Search starting from vertex 0:" << endl;
    G.BFS(0);

    cout << "Depth-First Search starting from vertex 0:" << endl;
    G.DFS(0);

    int diameter = G.computeDiameter();
    cout << "The diameter of the graph is: " << diameter << endl;

    cout << endl;
    G.primMST();
    cout << endl;

    return 0;
}
