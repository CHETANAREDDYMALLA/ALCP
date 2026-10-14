#include <iostream>
#include <vector>
#include <string>
using namespace std;
void findPaths(int r, int c, vector<vector<int>>& m, int n, string path, vector<string>& allPaths, vector<vector<bool>>& visited) {
    if (r == n - 1 && c == n - 1) {
        allPaths.push_back(path);
        return;
    }
    visited[r][c] = true;
    if (r + 1 < n && m[r + 1][c] == 1 && !visited[r + 1][c]) {
        findPaths(r + 1, c, m, n, path + 'D', allPaths, visited);
    }
    if (c - 1 >= 0 && m[r][c - 1] == 1 && !visited[r][c - 1]) {
        findPaths(r, c - 1, m, n, path + 'L', allPaths, visited);
    }
    if (c + 1 < n && m[r][c + 1] == 1 && !visited[r][c + 1]) {
        findPaths(r, c + 1, m, n, path + 'R', allPaths, visited);
    }
    if (r - 1 >= 0 && m[r - 1][c] == 1 && !visited[r - 1][c]) {
        findPaths(r - 1, c, m, n, path + 'U', allPaths, visited);
    }
    visited[r][c] = false;
}
vector<string> ratInAMaze(vector<vector<int>>& m, int n) {
    vector<string> allPaths;
    if (m[0][0] == 0 || m[n - 1][n - 1] == 0) {
        return allPaths;
    }
    vector<vector<bool>> visited(n, vector<bool>(n, false));
    findPaths(0, 0, m, n, "", allPaths, visited);
    return allPaths;
}
int main() {
    int n;
    cout << "Enter the size of the maze (N): ";
    cin >> n;
    vector<vector<int>> m(n, vector<int>(n));
    cout << "Enter the maze matrix (" << n << " x " << n << "):" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> m[i][j];
        }
    }
    vector<string> result = ratInAMaze(m, n);
    if (result.empty()) {
        cout << "No paths found!" << endl;
    } else {
        cout << "All possible paths:" << endl;
        for (int i = 0; i < result.size(); i++) {
            cout << result[i] << endl;
        }
    }
    return 0;
}
