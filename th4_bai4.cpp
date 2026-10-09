#include <iostream>
#include <fstream>
#include <vector>
#include <queue>

using namespace std;

int n;
vector<vector<int>> adj;

int count_components(int skip_u, int skip_v) {
    vector<bool> visited(n + 1, false);
    int components = 0;
    
    for (int i = 1; i <= n; ++i) {
        if (!visited[i]) {
            components++;
            queue<int> q;
            q.push(i);
            visited[i] = true;
            
            while (!q.empty()) {
                int u = q.front();
                q.pop();
                
                for (int v = 1; v <= n; ++v) {
                    if (adj[u][v]) {
                        // Bỏ qua cạnh đang xét để kiểm tra cầu
                        if ((u == skip_u && v == skip_v) || (u == skip_v && v == skip_u)) {
                            continue;
                        }
                        if (!visited[v]) {
                            visited[v] = true;
                            q.push(v);
                        }
                    }
                }
            }
        }
    }
    
    return components;
}

int main() {
    ifstream in("TK.INP");
    ofstream out("TK.OUT");

    if (!in.is_open()) return 0;

    if (!(in >> n)) return 0;

    adj.assign(n + 1, vector<int>(n + 1, 0));

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            in >> adj[i][j];
        }
    }

    int initial_components = count_components(0, 0);
    vector<pair<int, int>> bridges;

    for (int u = 1; u <= n; ++u) {
        for (int v = u + 1; v <= n; ++v) {
            if (adj[u][v]) {
                int current_components = count_components(u, v);
                if (current_components > initial_components) {
                    bridges.push_back({u, v});
                }
            }
        }
    }

    out << bridges.size() << "\n";
    for (size_t i = 0; i < bridges.size(); ++i) {
        out << bridges[i].first << " " << bridges[i].second << "\n";
    }

    in.close();
    out.close();

    return 0;
}
