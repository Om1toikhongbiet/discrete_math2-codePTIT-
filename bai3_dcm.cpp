#include <iostream>
#include <vector>
#include <queue>

using namespace std;

bool hasEulerianPath(int n, const vector<vector<int>>& adj) {
    int start = -1;
    vector<int> deg(n + 1, 0);
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            deg[i] += adj[i][j];
        }
        if (deg[i] > 0) {
            start = i;
        }
    }

    if (start == -1) return false; // Đồ thị không có cạnh thì không được coi là có đường đi Euler

    // Kiểm tra tính liên thông của các đỉnh có bậc > 0
    vector<bool> visited(n + 1, false);
    queue<int> q;
    q.push(start);
    visited[start] = true;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int v = 1; v <= n; ++v) {
            if (adj[u][v] && !visited[v]) {
                visited[v] = true;
                q.push(v);
            }
        }
    }

    // Nếu có đỉnh có cạnh mà không nằm trong thành phần liên thông thì không có đường đi Euler
    for (int i = 1; i <= n; ++i) {
        if (deg[i] > 0 && !visited[i]) return false;
    }

    // Đếm số đỉnh bậc lẻ
    int odd = 0;
    for (int i = 1; i <= n; ++i) {
        if (deg[i] % 2 != 0) odd++;
    }

    // Có đường đi Euler nếu số đỉnh bậc lẻ là 0 hoặc 2
    return (odd == 0 || odd == 2);
}

int main() {
    // Tối ưu hóa I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // Đọc từ file DT.INP và ghi ra file DT.OUT
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

        // Loại bỏ cạnh (u, v)
        if (adj[u][v] == 1) {
            adj[u][v] = 0;
            adj[v][u] = 0;
            if (hasEulerianPath(n, adj)) {
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
        // Duyệt qua tất cả các cặp (u, v) với u < v
        for (int u = 1; u <= n; ++u) {
            for (int v = u + 1; v <= n; ++v) {
                if (adj[u][v] == 1) {
                    // Loại bỏ cạnh (u, v)
                    adj[u][v] = 0;
                    adj[v][u] = 0;

                    if (hasEulerianPath(n, adj)) {
                        edges.push_back({u, v});
                    }

                    // Khôi phục lại cạnh (u, v)
                    adj[u][v] = 1;
                    adj[v][u] = 1;
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
