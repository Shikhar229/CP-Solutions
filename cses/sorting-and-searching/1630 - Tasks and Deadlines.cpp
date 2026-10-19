#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    int n;
    cin >> n;
    vector<pair<ll,ll>>a;
    for(int i = 0;i< n; i++){
        ll x,y;
        cin >>x >>y;
        a.push_back({x,y});
    }
    sort(a.begin(),a.end());
    ll ans = 0;

    ll time = 0;
    for(int i = 0;i < n; i++){
        time += a[i].first;
        ans += (a[i].second - time);
    }
    cout << ans << "\n";



}