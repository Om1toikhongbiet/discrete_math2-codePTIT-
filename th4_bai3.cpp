#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
vector<vector<int>> adj;
vector<int> num, low;
vector<bool> is_cut;
int time_dfs = 0;

void dfs(int u, int p) {
    num[u] = low[u] = ++time_dfs;
    int children = 0;
    for (int v = 1; v <= n; ++v) {
        if (adj[u][v]) {
            if (v == p) continue;
            if (num[v]) {
                low[u] = min(low[u], num[v]);
            } else {
                children++;
                dfs(v, u);
                low[u] = min(low[u], low[v]);
                if (p != 0 && low[v] >= num[u]) {
                    is_cut[u] = true;
                }
            }
        }
    }
    if (p == 0 && children > 1) {
        is_cut[u] = true;
    }
}

int main() {
    ifstream in("TK.INP");
    ofstream out("TK.OUT");

    if (!in.is_open()) return 0;

    if (!(in >> n)) return 0;

    adj.assign(n + 1, vector<int>(n + 1, 0));
    num.assign(n + 1, 0);
    low.assign(n + 1, 0);
    is_cut.assign(n + 1, false);

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            in >> adj[i][j];
        }
    }

    for (int i = 1; i <= n; ++i) {
        if (!num[i]) {
            dfs(i, 0);
        }
    }

    vector<int> cut_vertices;
    for (int i = 1; i <= n; ++i) {
        if (is_cut[i]) {
            cut_vertices.push_back(i);
        }
    }

    out << cut_vertices.size() << "\n";
    if (!cut_vertices.empty()) {
        for (size_t i = 0; i < cut_vertices.size(); ++i) {
            out << cut_vertices[i] << (i + 1 == cut_vertices.size() ? "" : " ");
        }
        out << "\n";
    }

    in.close();
    out.close();

    return 0;
}
