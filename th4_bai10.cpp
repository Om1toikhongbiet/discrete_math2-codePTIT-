#include <iostream>
#include <fstream>
#include <vector>
#include <queue>

using namespace std;

int t, n, s;
vector<vector<int>> adj;
vector<pair<int, int>> edges;
vector<bool> visited;

void dfs(int u) {
    visited[u] = true;
    for (int v = 1; v <= n; ++v) {
        if (adj[u][v] && !visited[v]) {
            edges.push_back({u, v});
            dfs(v);
        }
    }
}

void bfs(int start) {
    queue<int> q;
    q.push(start);
    visited[start] = true;
    
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        
        for (int v = 1; v <= n; ++v) {
            if (adj[u][v] && !visited[v]) {
                visited[v] = true;
                edges.push_back({u, v});
                q.push(v);
            }
        }
    }
}

int main() {
    ifstream in("CK.INP");
    ofstream out("CK.OUT");

    if (!in.is_open()) return 0;

    if (!(in >> t)) return 0;
    in >> n >> s;

    adj.assign(n + 1, vector<int>(n + 1, 0));
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            in >> adj[i][j];
        }
    }

    visited.assign(n + 1, false);

    if (t == 1) {
        dfs(s);
    } else if (t == 2) {
        bfs(s);
    }

    bool connected = true;
    for (int i = 1; i <= n; ++i) {
        if (!visited[i]) {
            connected = false;
            break;
        }
    }

    if (connected) {
        // Có cây khung
        // Số cạnh của cây khung luôn là n - 1
        out << n - 1 << "\n";
        for (size_t i = 0; i < edges.size(); ++i) {
            int u = edges[i].first;
            int v = edges[i].second;
            if (u > v) swap(u, v);
            out << u << " " << v << "\n";
        }
    } else {
        // Không có cây khung (đồ thị không liên thông)
        out << 0 << "\n";
    }

    in.close();
    out.close();

    return 0;
}
