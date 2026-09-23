#include<bits/stdc++.h>
using namespace std;
int n ; 
int a [105][105];
bool chuaxet[105];
void dfs ( int u , bool in_ket_qua){

    if ( in_ket_qua) cout << u << " " ;
    chuaxet[u] = false ; 

    for ( int v = 1 ; v <=n ; v++ ) {

        if ( a[u][v] == 1 && chuaxet[v] ==true) {

            dfs ( v, in_ket_qua);
        }
    }
}



int main () {


    int t ; 
    if ( !(cin>>t)) return 0 ; 
    int u = -1 ;
    if ( t == 1 ) {

        cin >> n >> u ;

    }else if ( t == 2) {

        cin >> n ; 
    }
    for ( int i = 1 ; i <= n ; i ++){
        for ( int j = 1 ; j <=n ; j ++ ) {

            cin >> a[i][j];
        }
    }
    for ( int i = 1 ; i <=n ; i ++ ) chuaxet[i] =true;
    if ( t == 1) {

        dfs( u, true);
        cout << endl;

    }
    else if ( t ==2 ) {

        vector<int > r;
        for ( int i = 1 ; i <=n ; i ++ ) {

            if ( chuaxet[i] ==true){

                r.push_back(i);
                dfs(i , false);
            }
        }
        int k_minus_1 = r.size() -1 ;
        cout << k_minus_1<< endl;
        if ( k_minus_1 > 0 ) {

            for ( int i = 1 ; i < r.size() ; i ++ ) {

                cout << r[0]<<" " << r[i] << endl;
            }
        }
    }
    return 0 ; 
}