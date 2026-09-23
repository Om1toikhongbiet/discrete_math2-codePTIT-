#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// Kiểm tra đồ thị có đường đi hoặc chu trình Euler có hướng hay không
bool hasDirectedEulerian(int n, const vector<vector<int>>& adj, bool cycle_only) {
    vector<int> in_deg(n + 1, 0);
    vector<int> out_deg(n + 1, 0);
    int start = -1;
    
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (adj[i][j]) {
                out_deg[i]++;
                in_deg[j]++;
            }
        }
    }
    
    // Tìm đỉnh đầu tiên có cạnh (tổng bậc > 0)
    for (int i = 1; i <= n; ++i) {
        if (in_deg[i] + out_deg[i] > 0) {
            start = i;
            break;
        }
    }
    
    // Nếu không có cạnh nào
    if (start == -1) return false;
    
    // Kiểm tra tính liên thông yếu
    vector<bool> visited(n + 1, false);
    queue<int> q;
    q.push(start);
    visited[start] = true;
    
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int v = 1; v <= n; ++v) {
            if ((adj[u][v] || adj[v][u]) && !visited[v]) {
                visited[v] = true;
                q.push(v);
            }
        }
    }
    
    // Các đỉnh có cạnh đều phải liên thông với nhau
    for (int i = 1; i <= n; ++i) {
        if (in_deg[i] + out_deg[i] > 0 && !visited[i]) {
            return false;
        }
    }
    
    // Kiểm tra điều kiện bậc
    int count_start = 0; // Số đỉnh có out - in = 1
    int count_end = 0;   // Số đỉnh có in - out = 1
    
    for (int i = 1; i <= n; ++i) {
        if (out_deg[i] == in_deg[i]) continue;
        
        if (out_deg[i] - in_deg[i] == 1) {
            count_start++;
        } else if (in_deg[i] - out_deg[i] == 1) {
            count_end++;
        } else {
            // Chênh lệch bậc > 1 => Không thể có đường đi/chu trình Euler
            return false; 
        }
    }
    
    if (cycle_only) {
        // Chu trình Euler: Tất cả các đỉnh đều phải có in == out
        return (count_start == 0 && count_end == 0);
    } else {
        // Đường đi Euler: Hoặc là chu trình, hoặc có đúng 1 đỉnh bắt đầu, 1 đỉnh kết thúc
        return (count_start == 0 && count_end == 0) || (count_start == 1 && count_end == 1);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    if (freopen("DT.INP", "r", stdin)) {}
    if (freopen("DT.OUT", "w", stdout)) {}

    int t;
    if (!(cin >> t)) return 0;

    if (t == 1) {
        int n, u, v;
        cin >> n >> u >> v;
        vector<vector<int>> adj(n + 1, vector<int>(n + 1));
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                cin >> adj[i][j];
            }
        }

        // Kiểm tra u != v và chưa có cung u -> v
        if (u != v && adj[u][v] == 0) {
            adj[u][v] = 1;
            if (hasDirectedEulerian(n, adj, false)) { // false = Kiểm tra đường đi
                cout << 1 << "\n";
            } else {
                cout << 0 << "\n";
            }
        } else {
            cout << 0 << "\n";
        }
    } else if (t == 2) {
        int n;
        cin >> n;
        vector<vector<int>> adj(n + 1, vector<int>(n + 1));
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                cin >> adj[i][j];
            }
        }

        vector<pair<int, int>> edges;
        for (int u = 1; u <= n; ++u) {
            for (int v = 1; v <= n; ++v) {
                if (u != v && adj[u][v] == 0) {
                    adj[u][v] = 1;
                    if (hasDirectedEulerian(n, adj, true)) { // true = Kiểm tra chu trình
                        edges.push_back({u, v});
                    }
                    adj[u][v] = 0; // Khôi phục trạng thái
                }
            }
        }

        if (edges.empty()) {
            cout << 0 << "\n";
        } else {
            cout << edges.size() << "\n";
            for (auto edge : edges) {
                cout << edge.first << " " << edge.second << "\n";
            }
        }
    }

    return 0;
}
