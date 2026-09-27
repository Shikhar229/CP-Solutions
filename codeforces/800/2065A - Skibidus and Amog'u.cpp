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
    string s;
    cin >> s;
    if(s.size() >= 2){
        int n= s.size();
        if(s[n-1] == 's' && s[n-2] == 'u'){
            cout << s.substr(0,n-2)+ 'i' << "\n";
        }
        else{
            cout << s << "\n";
        }

    }
    else{
        cout << s << "\n";
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