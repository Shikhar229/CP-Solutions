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
    vector<ll>p(n),s(n);
    for(int i = 0;i < n; i++){
        cin >> p[i];
    }
    for(int i = 0;i < n;i++){
        cin >> s[i];
    }
    // I have prefix gcd of array a
    // I have suffix gcd of array ans
    bool found = true;
    for(int i = 1;i < n; i++){
        if(p[i-1]% p[i] != 0){
            found =false;
            break;
        }
    }
    for(int i = 0; i < n -1; i++){
        if(s[i+1]%s[i] != 0){
            found = false;
            break;
        }
    }
    if(found == false) {
        cout << "NO\n";
        return;
    }

    vector<ll>a(n);
    for(int i = 0;i < n;  i++){
        a[i] = (p[i]*s[i])/__gcd(p[i],s[i]);
    }

    ll gp = a[0];

    
    for(int i = 0;i < n; i++){
        gp = __gcd(a[i],gp);
        if(gp != p[i]){
            found = false;
            break;
        }
        
    }
    ll gs = a[n-1];
    for(int i = n-1; i>= 0;i--){
        gs = __gcd(gs,a[i]);
        if(gs != s[i]){
            found = false;
            break;

        }
        
    }
    if(!found)cout << "NO\n";
    else cout << "YES\n";
    

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