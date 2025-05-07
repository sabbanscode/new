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

    addEdge(0, 1);
    addEdge(0, 2);
    addEdge(1, 3);
    addEdge(1, 4);
    addEdge(2, 5);
    addEdge(2, 6);

    cout << "DFS starting from node 0: ";
    fill(visited, visited + MAX, false); 
    dfs(0);
    
    fill(visited, visited + MAX, false); 
    cout << "\nBFS starting from node 0: ";
    bfs(0);

    return 0;
}
