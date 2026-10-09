#include<bits/stdc++.h>
using namespace std; 
int main () { 

    /*edgelist to adjlist */
    int verticals , edge ; cin >> verticals>> edge ; 
    vector <int> adjlist[1500];
    for ( int i = 0 ; i < edge ; i ++ ) { 

        int n, m ; cin >> n>> m ; 
        adjlist[n].push_back(m);
        adjlist[m].push_back(n);
        
    }
    for ( int i = 1; i <=verticals; i ++ ) {

        cout << i<<" "; 
        for ( auto x : adjlist[i]){
            cout << x << " " ; 
        }
        cout << endl ; 
    }
}