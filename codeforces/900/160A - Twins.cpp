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
    int leftsum = 0;
    for(int i = 0;i < n; i++){
        cin >> a[i];
        leftsum+=a[i];
    }
    
    sort(a.begin(),a.end());
    int r;
    int rightsum = 0;
    for( r = n-1;r >= 0;r--){
        rightsum += a[r];
        leftsum-= a[r];
        if(rightsum > leftsum) break;

    }
    cout << n-r << "\n";

    
    
    
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}