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
int fact(int n)
{
    return n == 0 ? 1 : n * fact(n - 1);
}

void solve() {
    ll n;
    cin >> n;
    ll d;
    cin >> d;

    n = min(6LL ,n);
    int len = fact(n);
    int digit_sum = len* d;
    cout << 1 << " ";
    if(digit_sum % 3 == 0){
        cout << 3 << " ";
    }
    if(d == 5){
        cout << 5 << " ";
    }
    if(len % 6 == 0 or d == 7){
        cout << 7 <<" ";
    }
    if(digit_sum % 9 == 0){
        cout << 9 << " ";

    }
    cout << "\n";

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