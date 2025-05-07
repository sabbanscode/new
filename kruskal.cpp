#include <iostream>
using namespace std;

#define MAX_V 100
#define MAX_E 100

struct Edge {
    int u, v; 
    int weight; 
};

int parent[MAX_V];

int find(int x) {
    while (parent[x] != x) {
        x = parent[x];
    }
    return x;
}

void unionSets(int u, int v) {
    parent[find(u)] = find(v);
}

void sortEdges(Edge edges[], int e) {
    for (int i = 0; i < e - 1; i++) {
        for (int j = 0; j < e - i - 1; j++) {
            if (edges[j].weight > edges[j + 1].weight) {
                Edge temp = edges[j];
                edges[j] = edges[j + 1];
                edges[j + 1] = temp;
            }
        }
    }
}

void kruskal(Edge edges[], int V, int E) {
    for (int i = 0; i < V; i++) {
        parent[i] = i; 
    }

    sortEdges(edges, E);

    Edge mst[MAX_E];
    int mstCount = 0;
    int totalWeight = 0;

    for (int i = 0; i < E; i++) {
        int u = edges[i].u;
        int v = edges[i].v;
        int w = edges[i].weight;

        if (find(u) != find(v)) {
            mst[mstCount] = edges[i]; 
            mstCount++;
            totalWeight += w;
            unionSets(u, v); 
        }
    }

    cout << "Minimum Spanning Tree edges:\n";
    for (int i = 0; i < mstCount; i++) {
        cout << mst[i].u << " - " << mst[i].v << ": " << mst[i].weight << endl;
    }
    cout << "Total weight: " << totalWeight << endl;
}

int main() {
    int V, E;
    Edge edges[MAX_E];

    cout << "Enter number of vertices: ";
    cin >> V;
    cout << "Enter number of edges: ";
    cin >> E;

    cout << "Enter edges (u v weight, 0-based vertices):\n";
    for (int i = 0; i < E; i++) {
        cin >> edges[i].u >> edges[i].v >> edges[i].weight;
    }

    kruskal(edges, V, E);

    return 0;
}