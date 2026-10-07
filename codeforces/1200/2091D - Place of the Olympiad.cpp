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
    // we sit 10 people together but we can sat them in smaller group then it is not optimal way 
    // find smaller

    // s s s s s s ___ not valid
    // we have to find last s

    // higher bound = no. of columns
    // lower bound = 1
    ll n,m,k;
    cin >> n >> m >> k;
    ll i = 1;
    ll j = m;
    // 1 gap is needed 
    // I have mid = st + end /2
    // search size = mid+1

    ll ans = m;
    
    while(i <= j){
        
        ll c = k;
        ll mid = (i + j)/2;
        ll key = mid+1;
        ll group = m/key;
        ll rem = m%key;

        ll onerow = group * mid + min(rem,mid);
        ll total = onerow * n;

        if(total >= k){
            j = mid-1;
            
            ans = mid;
        }
        else{
            i = mid+1;
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