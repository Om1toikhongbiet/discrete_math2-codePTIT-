#include<bits/stdc++.h>
using namespace std;
int n ; 
int a[105][105];
bool chuaxet[105];
void BFS ( int u ) {

    queue<int> q;
    q.push(u);
    chuaxet[u]= false;

    while (!q.empty()){

        int s = q.front();
        q.pop();
        for ( int v = 1 ; v <=n ; v++){

            if ( a[s][v] ==1 && chuaxet[v]==true){

                q.push(v);
                chuaxet[v]=false;
            }
        }
    }
}
int dem_lien_thong(){

    int dem = 0 ; 
    for ( int i = 0 ; i <= n ; i ++ ) {

        chuaxet[i]=true;
    }
    for ( int i = 1 ; i <= n ; i ++ ) {
        
        if (chuaxet[i] == true){
            
            dem++;
            BFS(i);
        }
    }
    return dem ;
    
}
int main () {
    freopen("TK.INP","r",stdin);
    freopen("TK.OUT","w" , stdout);
    cin>>n ;
    for ( int i = 1 ; i <= n ; i ++ ) {
        
        for ( int j =1  ;  j <=n ; j++){

            cin>>a[i][j];
        }
    }
    
    int k_batdau = dem_lien_thong() ;
    vector < pair<int , int >> canh_cau ;
    for ( int u = 1 ; u <= n; u ++ ){
        
        for ( int v = u +1 ; v<=n ; v++){
            
            if ( a[u][v] ==1){
                
                a[u][v] = 0 ; a[v][u] = 0 ; 
                int k_lucsau = dem_lien_thong() ;
                if ( k_lucsau > k_batdau){
                    
                    canh_cau.push_back({u,v});
                }
                a[u][v] =1  ; a[v][u] =1;
            }
        }
    }
    cout << canh_cau.size() << "\n";
    for (auto x : canh_cau){
        
        cout << x.first<< " " << x.second<< "\n";
    }
    
}












