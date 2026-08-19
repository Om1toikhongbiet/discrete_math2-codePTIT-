


#include<bits/stdc++.h>
using namespace std;

int n ;
int a[105][105];

void solvet1(){
    int degree = 0 ;
    for ( int i = 0 ; i < n ; i ++ ){
        // Để tính bậc thì phải đếm toàn bộ hàng, chạy j từ 0
        for ( int j = 0 ; j < n ; j ++){
            if ( a[i][j] ) degree++;
        }
        cout << degree << " "; 
        degree = 0 ;
    }
}

void solvet2() {
    int degree = 0 ;
    for ( int i = 0 ; i < n ; i ++ ) {
        // Chỉ đếm nửa trên để không bị lặp cạnh
        for ( int j = i + 1 ; j < n ; j ++ ) {
            if ( a[i][j]) degree++;
        }
    }
    
    // Fix thiếu dấu xuống dòng ở đây
    cout << n << " " << degree << "\n";
    
    for ( int i = 0 ; i < n ; i ++ ) {
        for ( int j = i + 1 ; j < n ; j ++ ) {
            if ( a[i][j]) cout << i + 1 << " " << j + 1 << "\n"; 
        }
    }
}

int main () {
    // Đọc ghi file
    freopen("DT.INP", "r", stdin);
    freopen("DT.OUT", "w", stdout);
    
    int t ; cin >> t;
    cin >> n; // Bỏ chữ int đi để dùng biến toàn cục
    
    for ( int i = 0 ; i < n ; i ++ ){
        for ( int j = 0 ; j < n ; j++){
            cin >> a[i][j]; // Fix nhập đúng tọa độ ô
        }
    }
    
    if ( t == 1 ) solvet1();
    if ( t == 2 ) solvet2();
    
    return 0; // Nên có return 0 ở cuối hàm main
}