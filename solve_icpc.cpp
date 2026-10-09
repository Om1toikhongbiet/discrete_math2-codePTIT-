#include<bits/stdc++.h>
using namespace std; 
int matriz[1500][1500]= { 0 };
int main () {


    int verticals, many;


    /*bừa vl nhưng mà nó là code chuyển đồ thị : )))))))))))))))))
    */

    cin >> verticals>> many;
    pair <int,int> Glist[1500];
    for ( int i = 0 ; i < many; i ++ ) {
      
        
        cin>> Glist[i].first>> Glist[i].second;
        

    }
    for ( int i = 0 ; i < many ; i ++ ) {

        matriz [Glist[i].first-1][Glist[i].second-1] = 1 ;
        matriz [Glist[i].second-1][Glist[i].first-1] = 1 ;
    }
    int count = 0 ;
    for ( int i = 0  ; i < verticals; i ++ ) {
        for ( int j = 0 ; j < verticals; j ++ ) {

            cout << matriz[i][j] << " ";
        }
        cout << endl ; 

    }

}