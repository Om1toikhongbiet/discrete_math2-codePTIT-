#include<bits/stdc++.h>
using namespace std;
int n , u , k  ; 
int  a [105][105];
int d[105];
void bfs ( int start) {

    memset(d, -1 , sizeof ( d));
    queue<int> q;
    q.push(start);
    d[start]=0 ;
    while (!q.empty()){

        int s = q.front() ;
        q.pop();
        for ( int v = 1  ; v <=n ; v++){

            if ( a[s][v] ==1 && d[v] == -1 ) {

                d[v] =d[s] +1;
                q.push(v);
            }
        }
    }
}
int main () {

    int  t ;
    if ( !(cin>> t )) return 0 ; 
    cin >> n >> u >> k ; 
    for ( int i = 1 ; i <=n ; i++){

        for ( int j = 1 ; j <=n ; j ++ ){

            cin >> a[i][j] ;
        }
    }
    bfs(u);
    vector<int> res;
    for ( int i = 1 ; i <=n ; i ++ ) {

        if ( i!=u && d[i]!=-1){

            if ( t == 1){

                if ( d[i] <= k) res.push_back(i);
            
            }
            else if ( t== 2) {

                if ( d[i] == k) res.push_back(i);
            }
        }
 
    }
    if ( res.empty() ){

        cout << 
    }
}