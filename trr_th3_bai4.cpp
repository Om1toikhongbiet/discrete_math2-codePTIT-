/*
BÀI 4: Chu trình Hamilton qua một cạnh bắt buộc
- Đồ thị vô hướng. Tìm chu trình Hamilton BẮT BUỘC chứa cạnh (u, v).
- Chu trình phải bắt đầu bằng min(u, v), tiếp theo là max(u, v).
- Nếu có nhiều chu trình, chọn chu trình có thứ tự từ điển nhỏ nhất.
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// DP mảng 2 chiều. Số đỉnh tối đa là 15, 2^15 = 32768
bool dp[1 << 15][15];
int adj[20][20];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    // Đọc ghi file theo yêu cầu (Nộp CodePTIT nên comment lại nếu báo lỗi)
    freopen("DT.INP", "r", stdin);
    freopen("DT.OUT", "w", stdout);

    int t;
    if (!(cin >> t)) return 0;

    int n, u, v;
    cin >> n >> u >> v;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> adj[i][j];
        }
    }

    // Xác định 2 đỉnh đầu tiên của chu trình (0-indexed)
    // Đỉnh bắt đầu luôn là X, đỉnh thứ 2 luôn là Y
    int X = min(u, v) - 1;
    int Y = max(u, v) - 1;

    // Tính toán mảng DP bằng Quy hoạch động Trạng thái (Bitmask DP)
    // Ý tưởng: Tìm đường đi Hamilton bắt đầu từ Y, kết thúc tại một đỉnh kề với X,
    // đi qua tất cả các đỉnh còn lại (tức là mọi đỉnh ngoại trừ X).
    
    for (int mask = 1; mask < (1 << n); mask++) {
        // Chúng ta không bao giờ đưa đỉnh X vào mask, vì X là điểm kết thúc chu trình
        if (mask & (1 << X)) continue;
        
        for (int curr = 0; curr < n; curr++) {
            // Nếu đỉnh curr không nằm trong mask hiện tại thì bỏ qua
            if (!(mask & (1 << curr))) continue;
            
            // Base case: Nếu mask chỉ chứa đúng 1 đỉnh (chính là curr)
            // Đỉnh này phải là đỉnh cuối cùng của đường đi và CÓ CẠNH nối về X để khép kín chu trình
            if (mask == (1 << curr)) {
                dp[mask][curr] = (adj[curr][X] == 1);
            } else {
                dp[mask][curr] = false;
                // Transition: Thử đi từ curr đến một đỉnh nxt
                for (int nxt = 0; nxt < n; nxt++) {
                    if (nxt != curr && (mask & (1 << nxt))) {
                        // Nếu có cạnh nối và phần còn lại của đường đi là hợp lệ
                        if (adj[curr][nxt] == 1 && dp[mask ^ (1 << curr)][nxt]) {
                            dp[mask][curr] = true;
                            break; // Chỉ cần biết LÀ CÓ THỂ ĐI ĐƯỢC
                        }
                    }
                }
            }
        }
    }

    // Mask của tất cả các đỉnh cần đi qua (ngoại trừ X)
    int start_mask = ((1 << n) - 1) ^ (1 << X);

    if (t == 1) {
        // Có tồn tại chu trình bắt đầu từ Y không?
        if (dp[start_mask][Y]) cout << 1 << "\n";
        else cout << 0 << "\n";
    } 
    else if (t == 2) {
        if (!dp[start_mask][Y]) {
            cout << "NO\n";
        } else {
            // Khôi phục chu trình có thứ tự từ điển nhỏ nhất
            vector<int> path;
            path.push_back(X + 1); // Đỉnh đầu tiên luôn là X
            
            int curr = Y;
            int current_mask = start_mask;
            
            while (current_mask > 0) {
                path.push_back(curr + 1);
                current_mask ^= (1 << curr);
                
                if (current_mask == 0) break; // Đã đi hết
                
                // Chọn đỉnh tiếp theo (ưu tiên đỉnh nhỏ nhất có thể đi tới đích)
                for (int nxt = 0; nxt < n; nxt++) {
                    if ((current_mask & (1 << nxt)) && adj[curr][nxt] == 1 && dp[current_mask][nxt]) {
                        curr = nxt;
                        break;
                    }
                }
            }
            path.push_back(X + 1); // Quay về đỉnh đầu để khép kín chu trình
            
            // In chu trình
            for (int i = 0; i < path.size(); i++) {
                cout << path[i] << (i == path.size() - 1 ? "" : " ");
            }
            cout << "\n";
        }
    }

    return 0;
}
