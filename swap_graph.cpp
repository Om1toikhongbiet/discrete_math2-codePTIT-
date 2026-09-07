#include<bits/stdc++.h>
using namespace std;
int main () {
    int n ; cin >> n ; 
    int a[n+1][n+1]={0};
    pair  < int , int > adj ;
    while ( cin >> adj.first>>adj.second ) {

        a[adj.first][adj.second] =1; 
        a[adj.second][adj.first]=1 ;
        
    }
    for ( auto x : a){

        cout << a<< " ";
    }
}