#include<bits/stdc++.h>
using namespace std;
int n ; 
int adj[105][105];
bool visited[105];
void dfs ( int u ) {

    visited[u] = true ;
    for ( int v = 1 ; v <= n ; v++){

        if (adj[u][v] ==1 && !visited[v]){
            dfs(v);
        }
    }
}