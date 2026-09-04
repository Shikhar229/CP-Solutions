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
    int n,m;
    cin >> n >> m;
    ll k;
    cin >> k;
    vector<ll>a(n),b(m);
    for(auto & it : a) cin >> it;
    for(auto & it : b) cin >> it;
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());

    int i = 0;
    int j = 0;

    int count = 0;
    while(i <= n-1 && j  <= m-1){
        int low = b[j]-k;
        int high = b[j]+k;
        if(low <= a[i] && a[i] <= high ){
            count++;
            i++;j++;

        }
        else if(a[i] < low){
            i++;
        }
        else if(a[i] > high){
            j++;

        }
    }
    cout << count << "\n";



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