#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    int n;
    cin >> n;
    vector<ll>a(n);
    for(int i = 0;i < n; i++){
        cin >> a[i];
    }
    sort(a.begin(),a.end());
    // assign minimum book and maximum book
    ll maxi = *max_element(a.begin(),a.end());

    ll sum  = 0;
    for(int i = 0;i < n; i++){
        sum += a[i];
    }
    if(maxi > sum-maxi){
        cout << 2 * maxi << "\n";
    }
    else{
        cout << sum << "\n";
    }
    
    



}