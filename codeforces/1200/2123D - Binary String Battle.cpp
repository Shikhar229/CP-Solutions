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
    // alice chooses subsequence 
    // bob chooses substring

    // bob chooses on the constraint
    // if we some how do like that ki wo jo 
    // substring chunga usme 0 and 1 dono ho kisi bhi ek substring then wo convert hoke 11 ho jayega fir next turn mai 
    
    int n,k;
    cin >> n >> k;
    int cnt= 0;
   
    for(int i = 0;i < n; i++){
        char x;
        cin >> x;
        if(x-'0' == 1)cnt++;
    }
    // cout << cnt << "\n";
    if(cnt <= k || n < 2*k){
        cout << "Alice\n";
    }
    else{
        // bob can always choose one 
        cout << "Bob\n";
    }



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