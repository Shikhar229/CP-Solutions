#include <bits/stdc++.h>
using namespace std;
#define ll long long



int main(){
    int n;
    cin >> n;
    vector<ll>a(n+1);

    for(int i = 1;i <= n; i++){
        cin >> a[i];
    }   
    ll xorv = 0;
    for(int i = 1;i <= n; i++){
        if( ((n-1)&(i-1)) == (i-1)){
            xorv ^= a[i];
        }

    }
    cout << xorv << "\n";
    
    
}