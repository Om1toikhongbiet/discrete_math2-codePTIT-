/* 
BÀI 2: Chu trình Hamilton có tổng trọng số lớn nhất
- Đồ thị vô hướng, n đỉnh (n <= 10).
- Tìm chu trình Hamilton bắt đầu từ 1, có tổng trọng số lớn nhất.
- Nếu cùng trọng số, lấy chu trình có thứ tự từ điển nhỏ nhất.
*/

#include <iostream>
#include <vector>

using namespace std;

int q, n, m;
int adj[15][15]; // Ma trận kề lưu trọng số cạnh (0 nghĩa là không có cạnh)
bool visited[15];
int path[15];
int best_path[15];
long long max_weight = -1;

void dfs(int curr, int count, long long current_weight) {
    // Nếu đã đi qua đủ n đỉnh
    if (count == n) {
        // Kiểm tra xem có đường quay về đỉnh 1 không
        if (adj[curr][1] > 0) {
            long long total_weight = current_weight + adj[curr][1];
            
            // Vì vòng lặp duyệt đỉnh từ nhỏ đến lớn (2 đến n),
            // chu trình tìm thấy đầu tiên luôn có thứ tự từ điển nhỏ nhất.
            // Do đó, ta chỉ cập nhật khi tìm được trọng số LỚN HƠN hẳn.
            if (total_weight > max_weight) {
                max_weight = total_weight;
                for (int i = 0; i < n; i++) {
                    best_path[i] = path[i];
                }
            }
        }
        return;
    }

    // Duyệt các đỉnh tiếp theo từ 2 đến n (vì 1 luôn là đỉnh đầu/cuối)
    for (int next_v = 2; next_v <= n; ++next_v) {
        // Nếu đỉnh chưa thăm và có cạnh nối
        if (!visited[next_v] && adj[curr][next_v] > 0) {
            visited[next_v] = true;
            path[count] = next_v; // Lưu vào đường đi tại vị trí count
            
            // Đệ quy đi tiếp
            dfs(next_v, count + 1, current_weight + adj[curr][next_v]);
            
            // Quay lui (Backtrack)
            visited[next_v] = false;
        }
    }
}

int main() {
    // Tối ưu tốc độ I/O
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    // Đọc ghi file theo yêu cầu đề bài (Nếu nộp CodePTIT bị lỗi thì comment 2 dòng này)
    freopen("DT.INP", "r", stdin);
    freopen("DT.OUT", "w", stdout);

    if (cin >> q >> n >> m) {
        // Khởi tạo đồ thị
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                adj[i][j] = 0;
            }
            visited[i] = false;
        }
        max_weight = -1;

        // Đọc danh sách cạnh
        for (int i = 0; i < m; ++i) {
            int u, v, w;
            cin >> u >> v >> w;
            // Đồ thị vô hướng
            adj[u][v] = w;
            adj[v][u] = w;
        }

        // Bắt đầu từ đỉnh 1
        path[0] = 1;
        visited[1] = true;
        
        // Gọi Backtracking (đỉnh hiện tại=1, số đỉnh đã đi=1, trọng số ban đầu=0)
        dfs(1, 1, 0);

        // Xử lý Output
        if (max_weight == -1) {
            cout << -1 << "\n";
        } else {
            if (q == 1) {
                cout << max_weight << "\n";
            } else if (q == 2) {
                cout << max_weight << "\n";
                // In ra n + 1 đỉnh của chu trình
                for (int i = 0; i < n; i++) {
                    cout << best_path[i] << " ";
                }
                cout << 1 << "\n"; // Kết thúc tại 1
            }
        }
    }

    return 0;
}
