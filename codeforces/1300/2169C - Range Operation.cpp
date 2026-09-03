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
        vector<ll>a(n+1);
        for(int i = 1;i <= n;i++) cin >> a[i];

        vector<ll>prefix(n+1);
        prefix[0] = 0;
        prefix[1] = a[1];
        for(int i = 2;i <= n ;i++){
            prefix[i] = prefix[i-1]+ a[i];
        }
        ll bestl = LLONG_MIN;
        ll gain = 0;
        for(int r = 1;r <= n;r++){
            ll currentl = r - (1LL * r * r) + prefix[r-1];
            bestl = max(bestl,currentl);
            ll currentr = 1LL * r * r+ r- prefix[r];
            gain = max(gain,currentr + bestl);
            

        
        }
        ll sum = 0;
        for(int i =1 ;i <= n;i++){
            sum += a[i];
        }
        cout << sum + gain << "\n";
    
    


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