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

ll find(ll start){
    ll x = start;
    string s = "";
    while( x!=0){
        ll ld = x%10;
        if(ld == 4 || ld == 7) s += (ld+'0');
        x = x/10;
    }
    if(s.empty()) return -1;
    reverse(s.begin(), s.end());
    return stoll(s);
}

void solve() {
    ll a,b;
    cin >> a >> b;
    ll st = a+1;
    while(true){
        ll mask = find(st);
        if(mask == b){
            cout << st << endl;
            break;
        }
        st++;
    }
    


}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // int t;
    // cin >> t;
    // while (t--) {
    //     solve();
    // }

    solve();

    return 0;
}