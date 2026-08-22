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
    ll n;
    cin >> n;

    //  there is a matrix of  dim n*n
    // intially all cells empty

    // paint empty cell with no common side 
    // with previously painted cell

    // point:
    // adjacent is not allowed corner is allowed
    // what should students choose to win
    // no cell left to choose is looses

    if(n%2 == 0){
        cout << 2 << endl;
    }
    else{
        cout << 1 << endl;
    }


    

    
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    

    while (t--) {
        solve();
    }

    return 0;
}
