#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int MAX = 100;
vector<int> adj[MAX];
bool visited[MAX];

void addEdge(int u, int v) {
    adj[u].push_back(v);
    adj[v].push_back(u); 
}

void dfs(int node) {
    visited[node] = true;
    cout << node << " ";

    for (int neighbor : adj[node]) {
        if (!visited[neighbor]) {
            dfs(neighbor);
        }
    }
}

void bfs(int start) {
    queue<int> q;
    q.push(start);
    visited[start] = true;

    while (!q.empty()) {
        int node = q.front();
        q.pop();
        cout << node << " ";

        for (int neighbor : adj[node]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }
}

int main() {
    int nodes, edges;
    cout << "Enter number of nodes: ";
    cin >> nodes;

    cout << "Enter number of edges: ";
    cin >> edges;

    cout << "Enter edges (u v):" << endl;
    for (int i = 0; i < edges; i++) {
        int u, v;
        cin >> u >> v;
        addEdge(u, v);
    }

    int start;
    cout << "Enter start node for DFS and BFS: ";
    cin >> start;

    cout << "DFS starting from node " << start << ": ";
    fill(visited, visited + MAX, false);
    dfs(start);

    cout << "\nBFS starting from node " << start << ": ";
    fill(visited, visited + MAX, false);
    bfs(start);

    return 0;
}
