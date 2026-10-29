#include <bits/stdc++.h>
using namespace std;
int n, m;
vector<int> adj[105];
void solve1()
{
    
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for (int i = 1; i <= n; i++)
    {
        
        cout << adj[i].size() << " ";
    }
}
void solve2()
{
    int matrix[105][105] = {0};
    
   
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for (int i = 1; i <= n; i++)
    {
        
        for (auto x : adj[i])
        {
            matrix[i][x] = 1;
        }
    }
    for (int i = 1; i < n + 1; i++)
    {
        
        for (int j = 1; j < n + 1; j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}
int main()
{
    freopen("DT.INP","r",stdin);
    freopen("DT.OUT","w",stdout);
    int t;
    cin >> t >> n>>m;
    if (t == 1)
    {
        solve1();
    }
    else
    {
        solve2();
    }
}   