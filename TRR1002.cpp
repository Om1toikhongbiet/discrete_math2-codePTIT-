#include<bits/stdc++.h>
using namespace std;
int main () {
freopen("DT.INP", "r", stdin);
    freopen("DT.OUT", "w", stdout);

    int t ; cin >> t; 
    int n ; cin >> n ; 
    int a[n][n];
    int tong = 0 ;
    int verticals = 0 ;
    for ( int i = 0 ; i < n ; i ++){

        for ( int j = 0 ; j <n ; j++ ) {

            cin >> a[i][j];
            tong += a[i][j];

        }
        if (tong !=0) verticals++;
        tong = 0 ; 
    }
    int row = 0 ; 
    if ( t==1 ) {
        while ( row!=n){


            int count = 0 ; 
            for ( int    i = 0 ; i < n ; i ++ ) {
                if ( a[row][i]==1 ) count ++ ;
            }
            cout << count<<" "; row++;
        }
        
    }
    if ( t == 2) {
        cout<< n<<endl;
          while ( row!=n){


            int count = 0 ;
            
            vector<int> nearby;
            for ( int    i = 0 ; i < n ; i ++ ) {
                if ( a[row][i]==1 ) {count ++ ;
                nearby.push_back(i+1);}
                if ( count !=0)  ;
            }

            cout << count<<" ";
            for (auto x : nearby){
                cout<<x<<" ";
            }
            cout<<endl;

             row++;
             nearby.clear();
        }

    }
}