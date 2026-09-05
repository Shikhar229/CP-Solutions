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
    int n,k;
    cin >> n >> k;
    string s;
    cin  >> s;
    vector<int>prefix(s.size());
    if(s[0] == '0'){
        prefix[0] = 0;
    }
    else{
        prefix[0] = 1;
    }
    for(int i = 1;i < n; i++){
        prefix[i] = prefix[i-1] + (s[i] == '1');

    }
    int ans = 0;
    for(int i = k-1; i< n ;i+=k){
        int count = prefix[i];
        if(i-k >= 0){
            count -= prefix[i-k];
        }
        if(count == k){
            ans++;

        }
    }
    cout << ans << endl;
    
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}