#include<bits/stdc++.h>
using namespace std;
int n;
vector<vector<int>> adj;
vector<bool> visited ;
vector<vector<int>> components;
vector<int> current_comp;
void dfs ( int u ){

    visited[u]=true;
    current_comp.push_back(u) ;
    for ( int v = 1 ; v <=n ; v++){
        if ( adj[u][v] ==1 && !visited[v]){
            dfs(v);
        }
    }
}
int main () {
    if ( fopen("TK.INP","r")){
        freopen("TK.INP","r",stdin);
        freopen("TK.OUT","w",stdout);

    }else if (fopen("tk.inp","r")){

        freopen("tk.inp" , "r" , stdin);
        freopen ("tk.out" ,"w" ,stdout);
    }

    
    if ( !(cin>>n)) return 0 ; 
    adj.assign(n +1, vector<int>(n+1,0));
    visited.assign (n+1,false);
    for ( int i =1 ; i <=n ; i++){

        for ( int j = 1 ; j <=n ; j ++){

            cin>> adj[i][j];
        }
    }
    for ( int i = 1 ; i <=n ; i ++){

        if ( !visited[i]){

            current_comp.clear();
            dfs(i);
            sort(current_comp.begin(), current_comp.end());
            components.push_back(current_comp);
        }
    }
    cout<< components.size() << "\n";
    for ( int i = 0 ; i < components.size() ; i ++ ) {

        for ( int j = 0 ; j < components[i].size() ; j++){
            cout<<components[i][j];
            if ( j < components[i].size()){

                cout<<" ";
            }
        }
        cout<<"\n";
    }
    return 0 ; 
}