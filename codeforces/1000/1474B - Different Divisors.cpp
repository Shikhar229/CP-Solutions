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
    int d;
    cin >> d;

    int a = -1;
    int st = d+1;

    while(true){
        if(isPrime(st)){
            a = st;
            break;
        
        }
        else{
            st++;
            
        }
    }
    a = st;

    int b = -1;

    int end = a+d;
    
    while(true){
        if(isPrime(end)){
            b = end;

            break;
        }
        else{
            end++;

        }
    }

    cout << a * b << endl;
    


    


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