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
    int n;
    cin >> n;
    vector<int>a(n);
    for(int i = 0;i <n; i++){
        cin >> a[i];
    }
    sort(a.begin(),a.end());

    ll ans = 0;
    for(int i = 0;i < n-2; i++){
        for(int j = i+1; j < n-1;j++){

            auto it = lower_bound(a.begin()+j+1, a.end(),a[i]+a[j]);
            ll count = it - (a.begin()+j+1);

            if(count == 0) continue;
            it = upper_bound(a.begin()+j+1, a.begin()+j +1+ count,a[n-1]-a[i]-a[j]);
            ans += (a.begin()+j+1 + count)-it;
            
        }
    }
    cout << ans << "\n";
   

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