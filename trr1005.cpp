#include <bits/stdc++.h>
using namespace std;
vector<pair<int, int>> edge_list;
int n, m;
void solve1()
{
    int deg[105] = {0};
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        int u, v;
        cin >> u >> v;
        edge_list.push_back({u, v});
        deg[u]++;
        deg[v]++;
    }
    for (int i = 1; i <= n; i++)
    {

        cout << deg[i] << " ";
    }
}
void solve2()
{
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        edge_list.push_back({u, v});
    }
    vector<int> adj_list[105];
    for (int i = 0; i < edge_list.size() ; i++)
    {

        adj_list[edge_list[i].first].push_back(edge_list[i].second);
        adj_list[edge_list[i].second].push_back(edge_list[i].first);
    }
    cout << edge_list.size() << endl;
    for (int i = 1; i < n + 1; i++)
    {
        cout << i << " ";
        for (auto x : adj_list[i])
        {

            cout << x << " ";
        }
        cout << endl;
    }
}
int main()
{
freopen("DT.INP","r",stdin);
freopen("DT.OUT","w",stdout);
    int t;
    cin >> t;
    if (t == 1)
    {
        solve1();
    }
    else
    {

        solve2();
    }
}
