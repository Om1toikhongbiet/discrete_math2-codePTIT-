#include <bits/stdc++.h>
using namespace std;
vector<int> adjlist[1500];

/*dfs */
bool visitt[1500] = {0};
void dfs(int u)
{

    cout << u << " ";
    for (auto v : adjlist[u])
    {
        if (!visitt[u])
        {

            dfs(v);
            visitt[v] = 1;
        }
    }
}
int main()
{

    /*edgelist to adjlist */
    int verticals, edge;
    cin >> verticals >> edge;
    for (int i = 0; i < edge; i++)
    {

        int n, m;
        cin >> n >> m;
        adjlist[n].push_back(m);
        adjlist[m].push_back(n);

    }
    dfs(1) ; 
}