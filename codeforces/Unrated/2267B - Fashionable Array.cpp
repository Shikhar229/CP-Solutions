#include <bits/stdc++.h>
using namespace std;

#define ll long long

const ll mod = 1e9 + 7;
const ll INF = 1000000000000000000LL;

ll binpow(ll a, ll b) {
    ll ans = 1;

    while (b > 0) {
        if (b & 1)
            ans = (ans * a) % mod;

        a = (a * a) % mod;
        b >>= 1;
    }

    return ans;
}

bool isPrime(ll n) {
    if (n < 2) return false;
    if (n == 2) return true;
    if (n % 2 == 0) return false;

    for (ll i = 3; i <= n / i; i += 2) {
        if (n % i == 0)
            return false;
    }

    return true;
}

void solve() {
    int n;
    cin >> n;
    vector<int>a(n);
    map<int,int,greater<int>>mp;
    for(int i = 0;i < n; i++){
        cin>> a[i];
        mp[a[i]]++;
    }

    vector<int>ans;

    while(!mp.empty()){
        vector<int>temp;
        for(auto x :mp){
            temp.push_back(x.first);
        }

        for(int x : temp){
            ans.push_back(x);
            mp[x]--;
            if(mp[x] == 0)mp.erase(x);
        }
      
    }
    for(int i = 0; i < ans.size();i++){
        cout << ans[i]<< " ";
    }
    cout << "\n";
    

    


}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    // solve();

    return 0;
}