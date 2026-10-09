#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int nVertices, nEdges;
    if(!(cin >> nVertices >> nEdges)) return 0;
    // limit for this simple example (original code used 5x5 matrix)
    const int MAX_N = 100; // adjust as needed
    if(nVertices > MAX_N) {
        cerr << "Too many vertices (max " << MAX_N << ")\n";
        return 1;
    }

    // adjacency matrix, initialized to 0
    vector<vector<int>> mat(nVertices, vector<int>(nVertices, 0));

    for(int i = 0; i < nEdges; ++i) {
        int u, v;
        cin >> u >> v;
        // assuming vertices are 0‑based; adjust if 1‑based
        if(u >= 0 && u < nVertices && v >= 0 && v < nVertices) {
            mat[u][v] = 1;
        }
    }

    // print matrix row by row
    for(int i = 0; i < nVertices; ++i) {
        for(int j = 0; j < nVertices; ++j) {
            cout << mat[i][j] << ' ';
        }
        cout << '\n';
    }
    return 0;
}
