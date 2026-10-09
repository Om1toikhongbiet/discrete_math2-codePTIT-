#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ifstream in("DT.INP");
    ofstream out("DT.OUT");

    if (!in.is_open()) return 0;

    int t;
    if (!(in >> t)) return 0;

    int n, m;
    in >> n >> m;

    vector<int> deg_minus(n + 1, 0);
    vector<int> deg_plus(n + 1, 0);
    vector<vector<int>> adj(n + 1);

    for (int i = 0; i < m; ++i) {
        int u, v;
        in >> u >> v;
        deg_plus[u]++;
        deg_minus[v]++;
        adj[u].push_back(v);
    }

    if (t == 1) {
        for (int i = 1; i <= n; ++i) {
            out << deg_minus[i] << " " << deg_plus[i] << "\n";
        }
    } else if (t == 2) {
        out << n << "\n";
        for (int i = 1; i <= n; ++i) {
            sort(adj[i].begin(), adj[i].end());
            out << adj[i].size();
            for (int v : adj[i]) {
                out << " " << v;
            }
            out << "\n";
        }
    }

    in.close();
    out.close();

    return 0;
}
