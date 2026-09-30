/*
BÀI 3: Độ bền Hamilton khi loại bỏ đỉnh trên đồ thị có hướng
Dùng Quy hoạch động trạng thái (Bitmask DP) để giải quyết triệt để vấn đề TLE 
với độ phức tạp O(n^2 * 2^n), cực kỳ an toàn cho n <= 16.
*/
#include <iostream>
#include <vector>

using namespace std;

// Kích thước tối đa là 16 đỉnh. 2^16 = 65536.
bool dp[1 << 16][16];
int adj[20][20];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    // Đọc ghi file theo yêu cầu đề bài
    freopen("DT.INP", "r", stdin);
    freopen("DT.OUT", "w", stdout);

    int t;
    if (!(cin >> t)) return 0;

    int n, x;
    if (t == 1) {
        cin >> n >> x;
    } else {
        cin >> n;
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> adj[i][j];
        }
    }

    // Khởi tạo mảng DP
    // dp[mask][u] = true nếu tồn tại đường đi qua tập đỉnh (mask) và kết thúc tại đỉnh u.
    for (int i = 0; i < (1 << n); ++i) {
        for (int j = 0; j < n; ++j) {
            dp[i][j] = false;
        }
    }

    // Base case: Đường đi bắt đầu tại bất kì đỉnh nào (độ dài 1 đỉnh)
    for (int i = 0; i < n; ++i) {
        dp[1 << i][i] = true;
    }

    // DP Transitions (Quy hoạch động)
    for (int mask = 1; mask < (1 << n); ++mask) {
        for (int u = 0; u < n; ++u) {
            // Nếu có đường đi kết thúc tại u với tập đỉnh là mask
            if (dp[mask][u]) {
                for (int v = 0; v < n; ++v) {
                    // Nếu đỉnh v chưa nằm trong mask và có cạnh nối từ u -> v
                    if (!(mask & (1 << v)) && adj[u][v] == 1) {
                        dp[mask | (1 << v)][v] = true;
                    }
                }
            }
        }
    }

    // Xử lý Output theo từng loại truy vấn
    if (t == 1) {
        // Tìm đường đi phủ toàn bộ đồ thị ngoại trừ đỉnh x
        // Phép XOR (^) sẽ tắt bit tương ứng với đỉnh x (1-indexed -> x-1)
        int target_mask = ((1 << n) - 1) ^ (1 << (x - 1));
        bool found = false;
        
        for (int u = 0; u < n; ++u) {
            if (dp[target_mask][u]) {
                found = true;
                break;
            }
        }
        cout << (found ? 1 : 0) << "\n";
    } 
    else if (t == 2) {
        vector<int> ans;
        for (int i = 1; i <= n; ++i) {
            int target_mask = ((1 << n) - 1) ^ (1 << (i - 1));
            bool found = false;
            for (int u = 0; u < n; ++u) {
                if (dp[target_mask][u]) {
                    found = true;
                    break;
                }
            }
            if (found) ans.push_back(i);
        }
        
        // In kết quả
        if (ans.empty()) {
            cout << 0 << "\n";
        } else {
            for (size_t i = 0; i < ans.size(); ++i) {
                cout << ans[i] << (i == ans.size() - 1 ? "" : " ");
            }
            cout << "\n";
        }
    }

    return 0;
}
