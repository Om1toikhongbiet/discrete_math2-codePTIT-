#include<bits/stdc++.h>
using namespace std;
int n ; 
int a[105][105];
bool chuaxet[105];
void dfs(int u) {

    chuaxet[u] = false;
    for ( int v = 1 ; v<=n ; v++){
        if ( a[u][v] ==1 && chuaxet[v] == true){

            dfs(v);
        }

    }
}
bool checkpath ( int start , int end ) {

    if ( start == end ) return true;
    for ( int i = 1 ; i <= n ; i++) chuaxet[i] = true;
    dfs(start);
    if ( chuaxet[end] == false ) return true;
    return false;

}

int main () {

    int  t ; 
    if ( !(cin >> t )) return 0 ;
    int u , v ,w , edge_a, edge_b;
    if ( t == 1 ) {
        cin >> n >> u >> v >> w;

    }else if ( t ==2) {

        cin >> n >> u >> v >> edge_a >>edge_b;

    }
    for ( int i = 1 ; i <= n ; i ++ ) {

        for ( int j = 1 ; j <=n ; j ++ ) {

            cin >> a[i][j];
        }
    }
    if ( t == 1 ) {

        if ( checkpath(u,w) == true && checkpath(w,v) == true ) {

            cout << 1 << endl;

        }else {

            cout << 0 << endl;
        }
    }
    else if ( t == 2) {

        if ( a[edge_a][edge_b]== 1 && checkpath( u , edge_a) == true && checkpath(edge_b, v ) == true ) {

            cout << 1 << endl;

        }else {

            cout << 0 << endl;
            
        }
    }
}