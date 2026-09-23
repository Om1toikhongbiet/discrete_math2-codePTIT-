#include <iostream>
#include <vector>
#include <stack>
#include <queue>

using namespace std;

int main() {
    freopen ("CT.OUT","w",stdout);
    freopen ("CT.INP","r",stdin);
    // Tối ưu hóa I/O trong C++
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;

    if (t == 1) {
        int n;
        cin >> n;
        vector<vector<int>> adj(n + 1, vector<int>(n + 1));
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                cin >> adj[i][j];
            }
        }

        // Kiểm tra tính liên thông yếu của các đỉnh có bậc > 0
        vector<bool> visited(n + 1, false);
        int start = -1;
        for (int i = 1; i <= n; ++i) {
            int deg = 0;
            for (int j = 1; j <= n; ++j) {
                deg += adj[i][j] + adj[j][i];
            }
            if (deg > 0) {
                start = i;
                break;
            }
        }

        bool connected = true;
        if (start != -1) {
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

            // Đảm bảo mọi đỉnh có cạnh đều nằm trong cùng 1 thành phần liên thông yếu
            for (int i = 1; i <= n; ++i) {
                int deg = 0;
                for (int j = 1; j <= n; ++j) {
                    deg += adj[i][j] + adj[j][i];
                }
                if (deg > 0 && !visited[i]) {
                    connected = false;
                    break;
                }
            }
        }

        if (!connected) {
            cout << 0 << "\n";
        } else {
            int count_start = 0, count_end = 0;
            bool possible = true;
            for (int i = 1; i <= n; ++i) {
                int in_deg = 0, out_deg = 0;
                for (int j = 1; j <= n; ++j) {
                    out_deg += adj[i][j];
                    in_deg += adj[j][i];
                }
                if (out_deg == in_deg) continue;
                if (out_deg - in_deg == 1) count_start++;
                else if (in_deg - out_deg == 1) count_end++;
                else possible = false;
            }

            if (!possible) {
                cout << 0 << "\n";
            } else if (count_start == 0 && count_end == 0) {
                cout << 1 << "\n"; // Đồ thị Euler (có hướng)
            } else if (count_start == 1 && count_end == 1) {
                cout << 2 << "\n"; // Đồ thị nửa Euler (có hướng)
            } else {
                cout << 0 << "\n"; // Không phải cả hai
            }
        }
    } else if (t == 2) {
        int n, u;
        cin >> n >> u;
        vector<vector<int>> adj(n + 1, vector<int>(n + 1));
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                cin >> adj[i][j];
            }
        }

        // Tìm chu trình Euler bằng thuật toán Hierholzer
        stack<int> st;
        vector<int> path;
        st.push(u);

        while (!st.empty()) {
            int v = st.top();
            int next_v = -1;
            
            // Tìm đỉnh kề đầu tiên
            for (int i = 1; i <= n; ++i) {
                if (adj[v][i]) {
                    next_v = i;
                    break;
                }
            }

            if (next_v != -1) {
                // Xóa cạnh theo 1 chiều vì là đồ thị có hướng
                adj[v][next_v]--;
                st.push(next_v);
            } else {
                path.push_back(v);
                st.pop();
            }
        }

        // In chu trình theo thứ tự ngược lại của path
        for (int i = path.size() - 1; i >= 0; --i) {
            cout << path[i] << (i == 0 ? "" : " ");
        }
        cout << "\n";
    }

    return 0;
}
