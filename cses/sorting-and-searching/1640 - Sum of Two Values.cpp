#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    int n;
    cin >> n;
    ll x;
    cin >> x;
    vector<ll>a(n);
    for(int i = 0;i < n ; i++){
        cin >> a[i];
    }
    map<ll,ll>mp;

    bool found = false;



    for(int i = 0;i < n;i++){
        ll d = x-a[i];
        
        if(mp.find(d) != mp.end()){
            cout << mp[d]+1 <<" " << i+1;
            found = true;
            break;
        }
        else{
            mp[a[i]] = i;

        }

    }
    if(!found)cout << "IMPOSSIBLE";
    cout << "\n";
    
    



}