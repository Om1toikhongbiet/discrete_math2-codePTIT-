#include <iostream>
#include <vector>
#include <fstream>
using namespace std;
int main() {
    ifstream cin("DT.INP");
    int t;
    if (!(cin >> t)) return 0;
    cout << "t=" << t << endl;
    if (t == 1) {
        int n, u, v;
        cin >> n >> u >> v;
        cout << "n=" << n << " u=" << u << " v=" << v << endl;
        vector<vector<int>> adj(n + 1, vector<int>(n + 1));
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                cin >> adj[i][j];
                cout << adj[i][j] << " ";
            }
            cout << endl;
        }
    }
}
