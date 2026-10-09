#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main() {
    ifstream in("DT.INP");
    ofstream out("DT.OUT");

    if (!in.is_open()) return 0;

    int t;
    if (!(in >> t)) return 0;

    int n;
    in >> n;

    vector<vector<int>> A(n, vector<int>(n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            in >> A[i][j];
        }
    }

    if (t == 1) {
        for (int i = 0; i < n; ++i) {
            int deg_minus = 0;
            int deg_plus = 0;
            for (int j = 0; j < n; ++j) {
                deg_plus += A[i][j];
                deg_minus += A[j][i];
            }
            out << deg_minus << " " << deg_plus << "\n";
        }
    } else if (t == 2) {
        vector<pair<int, int>> edges;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (A[i][j] == 1) {
                    edges.push_back({i, j});
                }
            }
        }

        int m = edges.size();
        out << n << " " << m << "\n";

        vector<vector<int>> M(n, vector<int>(m, 0));
        for (int k = 0; k < m; ++k) {
            int u = edges[k].first;
            int v = edges[k].second;
            if (u != v) {
                M[u][k] = 1;
                M[v][k] = -1;
            }
            // Nếu u == v (khuyên), theo thông thường trong ma trận liên thuộc có thể để là 0.
        }

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                out << M[i][j] << (j == m - 1 ? "" : " ");
            }
            out << "\n";
        }
    }

    in.close();
    out.close();

    return 0;
}
