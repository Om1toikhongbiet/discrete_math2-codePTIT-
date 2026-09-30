/* 
cho trước đồ thị g ve gồm n đỉnh biểu diễn dưới dạng ma trận kề và một đỉnh u , yêu cầu , tìm tất cả các chi trình hamilton của G bắt đầu tại U , dữ liệu vào từ tệp CT.INP
dòng đầu chứa hai số nguyên dương n là số đỉnh và u là một đỉnh của G , 1 <= u <=n <= 100 , trong n dòng tiếp theo , mỗi dòng chứa n số 0 hoặc 1 mô tả ma trận kể của G .
Ghi ra tệp CT.OUT
nếu không tìm được chu trình hamilton thì gi ra giá trị 0 , trong trường hợp tìm được chu trình hamilton thì mỗi dòng ghi dãy các đỉnh của một chu trình hamilton .Dòng cuối cùng ghi giá trị t là số lượng các chu trình hamilton tìm được vd 
*/

#include <iostream>
#include <vector>

using namespace std;

int n, u;
vector<int> adj[105];  // Danh sách kề (Chỉ lưu các đỉnh có đường nối tới)
bool visited[105];
vector<int> path;
int cycles = 0;

void dfs(int curr) {
    // Khi đã đi qua tất cả n đỉnh
    if (path.size() == n) {
        // Kiểm tra xem đỉnh cuối có đường nối về đỉnh bắt đầu 'u' không
        for (int v : adj[curr]) {
            if (v == u) {
                for (int node : path) cout << node << " ";
                cout << u << "\n";
                cycles++;
                return;
            }
        }
        return;
    }

    // TỐI ƯU CỐT LÕI
   
    // Thay vì lặp từ 1 đến n (ma trận), ta chỉ duyệt các đỉnh thực sự kề với curr
    for (int next_v : adj[curr]) {

        if (!visited[next_v]) {
            visited[next_v] = true;
            path.push_back(next_v);
            
            dfs(next_v); // Tiếp tục tìm kiếm
            
            // Quay lui
            path.pop_back();
            visited[next_v] = false;
        }
    }
}

int main() {
    // Tối ưu I/O C++
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    // Nếu chấm trên CodePTIT thì nên comment 2 dòng freopen lại (tôi đã comment sẵn)
    freopen("CT.INP", "r", stdin);
    freopen("CT.OUT", "w", stdout);

    if (cin >> n >> u) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                int edge; cin >> edge;
                if (edge == 1) adj[i].push_back(j); // Build danh sách kề
            }
        }

        // Bắt đầu từ đỉnh u
        visited[u] = true;
        path.push_back(u);
        
        dfs(u);

        // Nếu cycles = 0, vòng lặp tự in 0. Nếu có chu trình, in tổng số lượng.
        cout << cycles << "\n"; 
    }
    return 0;
}