#include <iostream>
#include <vector>
using namespace std;
bool isSafe(int v, const vector<vector<int>>& graph, const vector<int>& path, int pos) {
    if (graph[path[pos - 1]][v] == 0) {
        return false;
    }
    for (int i = 0; i < pos; i++) {
        if (path[i] == v) {
            return false;
        }
    }
    return true;
}
bool hamiltonianCycleUtil(const vector<vector<int>>& graph, vector<int>& path, int pos) {
    int n = graph.size();
    if (pos == n) {
        if (graph[path[n - 1]][path[0]] == 1) {
            return true;
        }
        return false;
    }
    for (int v = 1; v < n; v++) {
        if (isSafe(v, graph, path, pos)) {
            path[pos] = v;
            if (hamiltonianCycleUtil(graph, path, pos + 1)) {
                return true;
            }
            path[pos] = -1;
        }
    }
    return false;
}
bool hamiltonianCycle(const vector<vector<int>>& graph) {
    int n = graph.size();
    vector<int> path(n, -1);
    path[0] = 0;
    if (!hamiltonianCycleUtil(graph, path, 1)) {
        cout << "No Hamiltonian cycle exists." << endl;
        return false;
    }
    cout << "Hamiltonian cycle found:" << endl;
    for (int i = 0; i < n; i++) {
        cout << path[i] << " ";
    }
    cout << path[0] << endl;
    return true;
}
int main() {
    int n;
    cout << "Enter the number of vertices: ";
    cin >> n;
    vector<vector<int>> graph(n, vector<int>(n));
    cout << "Enter the adjacency matrix (" << n << " x " << n << "):" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> graph[i][j];
        }
    }
    hamiltonianCycle(graph);
    return 0;
}
