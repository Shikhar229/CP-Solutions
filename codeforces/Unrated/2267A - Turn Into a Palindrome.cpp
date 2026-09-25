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
    char c;
    cin >> c;
    string s;
    cin>> s;
    int i = 0;
    int j = n-1;
    int count = 0;
    while(i < j){
        if(s[i] != s[j]){
            if((s[i] == c && s[j] != c)|| (s[i] != c && s[j] == c)){
                count += 1;
            }
            else if(s[i] != c && s[j] != c){
                count+=2;
            }

        }
        i++;j--;

    }
    cout << count << "\n";


    


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