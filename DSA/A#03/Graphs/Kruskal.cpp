#include <iostream>
#include <vector>
using namespace std;

struct Edge {
    char src, dest;
    double weight;

    Edge(char s, char d, double w) : src(s), dest(d), weight(w) {}
};

class UnionFind {
    vector<int> parent, sizeOfSet;
    int numOfComponents;    // Tracks the number of components in the union-find
public:
    UnionFind(int size) {
        parent.resize(size);
        sizeOfSet.resize(size, 0);
        numOfComponents = size;

        for (int i = 0; i < size; i++) {
            parent[i] = i;
            sizeOfSet[i] = 1;            // Each set is originally of size 1
        }
    }

    int find(int x) {
        if (parent[x] != x)
            return find(parent[x]);
        return x;
    }

    void unionSets(int parentX, int parentY) {
        if (sizeOfSet[parentX] > sizeOfSet[parentY])
            parent[parentY] = parentX;
        else if (sizeOfSet[parentY] > sizeOfSet[parentX])
            parent[parentX] = parentY;
        else {
            parent[parentY] = parentX;
            sizeOfSet[parentX]++;
        }
    }
};

class Kruskal {
    vector<Edge> mst;

    bool compare(Edge a, Edge b) {
        return (a.weight < b.weight);
    }

public:
    Kruskal() {}

    void kruskal(vector<Edge>& edges, int n) {
        // Sort edges by weight
        sort(edges);
        UnionFind uf(n);

        for (const Edge& edge : edges) {
            int parentX = uf.find(edge.src - 'A');
            int parentY = uf.find(edge.dest - 'A');
            if (parentX != parentY) {
                mst.push_back(edge);  // Add edge to the MST
                uf.unionSets(parentX, parentY);
            }
        }
    }

    void sort(vector<Edge>& edges) {
        int n = edges.size();

        // Bubble Sort for sorting edges based on weight
        for (int i = 0; i < n - 1; ++i) {
            for (int j = 0; j < n - i - 1; ++j) {
                if (edges[j].weight > edges[j + 1].weight) {
                    // Swap edges[j] and edges[j + 1]
                    Edge temp = edges[j];
                    edges[j] = edges[j + 1];
                    edges[j + 1] = temp;
                }
            }
        }
    }

    void display() {
        int total_cost = 0;
        cout << "Kruskal's Algorithm\n"
            << "Edges in the Minimum Spanning Tree :\n";
        for (const Edge& edge : mst) {
            cout << edge.src << " - " << edge.dest << " : " << edge.weight << "\n";
            total_cost += edge.weight;
        }
        cout << "Total Cost : " << total_cost << endl;
    }
};

int main() {
    int nodes = 6;
    vector<Edge> edges = {
        Edge('A', 'B', 4), Edge('A', 'C', 3), Edge('B', 'C', 1),
        Edge('B', 'D', 2), Edge('C', 'D', 4), Edge('D', 'E', 2),
        Edge('E', 'F', 6)
    };

    Kruskal mst;
    mst.kruskal(edges, nodes);
    mst.display();

    system("pause");
    return 0;
}
