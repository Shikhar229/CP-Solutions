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
    cin >>n;
    vector<int>s(n);

    int c1 = 0;
    int c2 = 0;
    int c3 = 0;
    int c4 = 0;
    for(int i = 0;i < n; i++){
        cin >> s[i];
        if(s[i] == 1){
            c1++;
        }
        else if(s[i] == 2){
            c2++;
        }
        else if(s[i] == 3){
            c3++;

        }
        else{
            c4++;
        }
    }
    int total = c4;
    int common = min(c1,c3);
    total += common;
    c1 -= common;
    c3 -= common;

    



    total += c2 /2;
    c2 = c2 % 2;

    if(c2){
        total++;
        c1 = max(0,c1-2);
    }
    total += c3;
    total += (c1 + 4- 1)/4;
    cout << total << "\n";

    // 1 hi bach sakta 2




}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}