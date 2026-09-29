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

ll ncr(ll n, ll r) {
    if (r > n - r)
        r = n - r;

    ll ans = 1;

    for (ll i = 1; i <= r; i++) {
        ans = ans * (n - i + 1) / i;
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
    int n,k;
    cin >> n >> k;
    vector<ll>a(n);
    for(int i = 0;i < n ;i++){
        cin >>a[i];
    }
    map<ll,ll>mp;
    for(int i = 0;i < n ;i++){
        mp[a[i]]++;
    }
    vector<pair<ll,ll>>vec;
    for(auto it : mp){
        vec.push_back({it.first, it.second});
    }
    // I would make a window of size k
    // iterate over the vec by window 
    int l = 0;
    int sum = 0;

    int maxi = 0;
    for(int r = 0; r < vec.size(); r++){

        // by ignoring consecutive 
        
        
        if(r >0 && vec[r].first != vec[r-1].first+1){
            l = r;
            sum = vec[r].second;
        }
        else{
            sum += vec[r].second;
        }
        
        if(r-l >= k){
            sum -= vec[r-k].second;
            l++;
            
        }
        maxi = max(maxi,sum);
        
    }
    cout << maxi << "\n";

    
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