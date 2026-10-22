#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    int n;
    ll x;
    
    cin >> n;
    cin >> x;
    vector<pair<ll,int>>a(n);
    
    for(int i = 0;i < n ; i++){
        cin >> a[i].first;
        a[i].second = i;
    }
    
    sort(a.begin(),a.end());
    bool found = false;
    for(int i = 0;i < n ; i++){
        ll w = a[i].first;
        for(int j = i+1; j < n ;j++){
            ll y = a[j].first;
            ll num = x - (w+y);
            int idx = lower_bound(a.begin()+j+1, a.end(),num,[](const pair<ll, int>& p, ll value) {
    return p.first < value;
})-a.begin();
            // cout << i << " " << j << " " << idx << "\n";

            if(idx <= n-1 && a[idx].first == num){
                found = true;
                cout << a[i].second+1 <<" " << a[j].second+1 <<" " << a[idx].second +1 <<"\n";
                break;


            }



        }
        if(found)break;
    }
    if(!found){
        cout << "IMPOSSIBLE\n";
    }


}