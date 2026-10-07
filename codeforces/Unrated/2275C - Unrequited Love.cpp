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
    // 1 ind
    vector<ll>a(n+1);
    for(int i = 1;i <= n ;i++){
        cin >> a[i];
    }
    // map<int,int>mp;
    // for(int i = 0;i < n ;i+=5){
    //     if(i+4 < n){
    //         int x = a[i]+a[i+2]-a[i+4];
    //         mp[x]++;
    //         if(i+5 < n){
    //             int y = a[i+1]+a[i+3]-a[i+5];
    //             mp[y]++;
    //         }

    //     }
    // }

    // int s = 0;
    // for(auto it : mp){
    //     if(it.second > 1){
    //         int count = it.second * (it.second +1)/2;
    //         s += (count);
    //     }
    // }
    // cout << s << "\n";

    
    map<ll,ll>mp;
    vector<ll>b(n-3);
    for(int i = 1; i <= n-4 ;i++){
        ll val = a[i] + a[i+2] - a[i+4];
        b[i] = val;
        mp[b[i]]++;        
    }

    ll count = 0;
    for(auto it: mp){
        if(it.second > 1){
            count += (it.second *(it.second - 1))/2;


        }
    }


    ll er = 0;
    for(int i = 1; i <= n-4; i++){
        if(i + 2 <= n-4 && b[i] == b[i+2]){
            er++;
        }
        if(i+4 <= n-4 && b[i] == b[i+4]){
            er++;
        }

    }
    cout << count -er << "\n";
    
    
    
    
    


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