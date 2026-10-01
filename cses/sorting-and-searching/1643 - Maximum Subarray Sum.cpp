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
   
    vector<ll>a(n);
    for(int i = 0;i < n; i++){
        cin >> a[i];
    }
    ll sum = a[0];
    ll maxi = a[0];

    for(int i = 1;i < n; i++){
        if(a[i] > sum + a[i]){
            sum = a[i];
            maxi = max(maxi,sum);
        }
        else{
            sum += a[i];
            maxi = max(maxi,sum);
        }
        
        
    }
    cout << maxi <<"\n";
    
    
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // int t;
    // cin >> t;

    // while (t--) {
    //     solve();
    // }
    solve()
;
    return 0;
}