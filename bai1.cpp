#include<bits/stdc++.h>
using namespace std ;
int n ; 
vector<vector<int>> adj;
vector<bool> visited;
vector<vector<int>> components;
void bfs( int start) {

    queue<int> q;
    vector<int> current_comp;
    q.push(start);
    visited[start]=true;
    while ( !q.empty()){

        int u = q.front();
        q.pop();
        current_comp.push_back(u);

        for ( int v = 1; v<= n ; v++){

            if ( adj[u][v] ==1 && !visited[v]){

                visited[v]=true;
                q.push(v);
            }
        }
    }
    sort(current_comp.begin(), current_comp.end());
    components.push_back(current_comp); 
}
int main () {

    freopen("TK.INP" ,"r", stdin);

    freopen("TK.OUT", "w" , stdout);
    
    if ( !(cin>>n)) return 0 ;
    adj.assign(n+1,vector<int>(n+1,0));
    visited.assign(n+1,false);
    for ( int i = 1; i <=n; i ++ ) {
        for ( int j =1 ; j <= n ; j ++ ) {

            cin>> adj[i][j];
        }

    }
    for ( int i = 1 ; i <= n ; i ++ ) {

        if ( !visited[i]){

            bfs(i);
        }
    }
   cout<<components.size()<<endl;
   for ( int i = 0 ; i < components.size(); i ++ ) {
        for ( int j = 0 ; j < components[i].size(); j ++ ){

            cout << components[i][j];
            if ( j < components[i].size() -1 ) {
                cout << " " ;
            }
        }
        cout << endl;
   }
      
    return 0 ;
}