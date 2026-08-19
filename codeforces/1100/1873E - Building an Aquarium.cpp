#include <bits/stdc++.h>
using namespace std;
#define ll long long


void solve(){

    // we can use atost x units of water

    int n;
    cin >> n;
    ll x;
    cin >> x;
    vector<ll>a(n);
    ll mini = LLONG_MAX;
    ll maxi = LLONG_MIN;


    for(int i = 0;i < n; i++){
        cin >> a[i];
        maxi = max(maxi,a[i]);
        mini = min(mini,a[i]);
    }
    // we want to fill the tank
    // the atmost water we can use x unit
    // we have to tell minimum and maximum height

    ll i = mini;
    ll j = maxi+x;

    ll ans = -1;
    while(i  <= j){
        ll mid = i + (j-i)/2;
        ll unit = 0;
        for(int i = 0;i < n ;i++){
            if(a[i] < mid){
                unit += (mid-a[i]);

            }
        }
        if(unit <= x){
            i = mid+1;
            ans = mid;
        }
        else{
            j = mid-1;
        }
        

    }
    cout << ans << endl;




}
int main(){
    int t;
    cin >> t;

    // maximum height of the tank can have, so you need at most x units 
    while(t--){
        solve();
    }

}

