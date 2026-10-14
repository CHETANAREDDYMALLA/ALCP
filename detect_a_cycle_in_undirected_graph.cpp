#include <iostream>
#include <vector>
using namespace std;
bool isCyclicDFS(int v, int parent, const vector<vector<int>>& adj, vector<bool>& visited) {
    visited[v] = true;
    for (int neighbor : adj[v]) {
        if (!visited[neighbor]) {
            if (isCyclicDFS(neighbor, v, adj, visited))
                return true;
        } else if (neighbor != parent) {
            return true;
        }
    }
    return false;
}
bool isCyclic(int V, const vector<vector<int>>& adj) {
    vector<bool> visited(V, false);
    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            if (isCyclicDFS(i, -1, adj, visited))
                return true;
        }
    }
    return false;
}
int main() {
    int V = 4;
    vector<vector<int>> adj(V);
    adj[0].push_back(1);
    adj[1].push_back(0);
    adj[1].push_back(2);
    adj[2].push_back(1);
    adj[2].push_back(3);
    adj[3].push_back(2);
    adj[3].push_back(1);
    adj[1].push_back(3);
    if (isCyclic(V, adj))
        cout << "Graph contains cycle" << endl;
    else
        cout << "Graph doesn't contain cycle" << endl;
    return 0;
}
