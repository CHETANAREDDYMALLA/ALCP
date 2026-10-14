#include <iostream>
#include <vector>
using namespace std;
bool isSafe(int v, const vector<vector<int>>& graph, const vector<int>& color, int c) {
    for (int i = 0; i < graph.size(); i++) {
        if (graph[v][i] == 1 && color[i] == c) {
            return false;
        }
    }
    return true;
}
bool colorGraphUtil(int v, int m, const vector<vector<int>>& graph, vector<int>& color) {
    int n = graph.size();
    if (v == n) {
        return true;
    }
    for (int c = 1; c <= m; c++) {
        if (isSafe(v, graph, color, c)) {
            color[v] = c;
            if (colorGraphUtil(v + 1, m, graph, color)) {
                return true;
            }
            color[v] = 0;
        }
    }
    return false;
}
bool graphColoring(const vector<vector<int>>& graph, int m) {
    int n = graph.size();
    vector<int> color(n, 0);
    if (!colorGraphUtil(0, m, graph, color)) {
        cout << "Solution does not exist with " << m << " colors." << endl;
        return false;
    }
    cout << "Assigned Colors to Vertices:" << endl;
    for (int i = 0; i < n; i++) {
        cout << "Vertex " << i << " ---> Color " << color[i] << endl;
    }
    return true;
}
int main() {
    int n, m;
    cout << "Enter the number of vertices: ";
    cin >> n;
    vector<vector<int>> graph(n, vector<int>(n));
    cout << "Enter the adjacency matrix (" << n << " x " << n << "):" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> graph[i][j];
        }
    }
    cout << "Enter the number of colors (m): ";
    cin >> m;
    graphColoring(graph, m);
    return 0;
}
