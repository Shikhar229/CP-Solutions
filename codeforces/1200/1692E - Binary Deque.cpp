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
    int n,s;
    cin >> n >> s;
    vector<int>a(n);
    for(int i = 0;i < n; i++){
        cin >> a[i];
    }


    // ones of zeroes and ones
    // first remove or last ->remove
    // 0 have no contribuition to increase the sum

    
    

    int l = 0;
    ll sum = 0;
    int maxi = -1;
    // maxlen of the subarray whose sum is s
    for(int r = 0; r < n ;r++){
        sum += a[r];
        while(sum > s && l <= r){
            sum -= a[l];
            l++;
        }
        if(sum == s){
            maxi = max(maxi,r-l+1);
        }

    }
    if(maxi == -1){
        cout <<  -1 << "\n";

    }
    else{
        cout << n-maxi << "\n";
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

    return 0;
}