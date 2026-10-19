#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    ll n,t;
    cin >> n >> t;
    vector<ll>k(n);
    for(int i = 0;i <n; i++){
        cin >> k[i];
    }
    // for(int i = 0;i <n; i++){
    //     cout << k[i] <<" ";
    // }
    // cout << "\n";


    sort(k.begin(),k.end());
    ll l = 1;
    ll r = 1e18+1;

    ll ans = -1;
    while(l <= r){
        
        ll mid = l + (r-l)/2;
        ll count = 0;
        for(int i = 0;i < n; i++){
            count += (mid/k[i]);
            if(count >=t) break;
        }
        // cout << "chala" << " " << count << "\n";
        if(count >= t){
            ans = mid;
            r = mid-1;
            
        }
        else{
            l = mid+1;
        }
    }
    cout << ans << "\n";


    
}