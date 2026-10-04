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
    vector<ll>a(n);
    for(int i = 0;i < n; i++){
        cin >> a[i];
    }
    sort(a.begin(),a.end());
    if(n == 1){
        cout << 1 << "\n";
        return;
    }
    // when n is even numbers will not take an extra coordinate
    if(n%2 == 0){
        ll maxi = INT_MIN;
        for(int i = 0;i < n; i+=2){
            maxi = max(maxi,a[i+1]-a[i]);
        }
        cout << maxi << "\n";
    }
    else{
        //here we would definitely take an extra coordinate to make all pairs
        // make pairs where the gap is maximum we may conider it a coordinate for that to form pairs
        // ll maxi = INT_MIN;
        // for(int i = 0;i < n; i+=2){
        //     if(i+1 < n){
        //         maxi  = max(maxi,a[i+1]-a[i]);
        //     }

        // }
        // ll maxi2 = INT_MIN;
        // for(int i = n-1; i >= 0; i-=2){
        //     if(i-1 >= 0){
        //         maxi2 = max(maxi2, a[i]-a[i-1]);

        //     }
        // }
        // cout << min(maxi2, maxi) << "\n";

        // here beech me rakh sakte hai ki beech me aaye 

        ll mini = LLONG_MAX;
        for(int i =  0;i <  n; i++){
            vector<ll>b;
            for(int j = 0;j < i ; j++){
                b.push_back(a[j]);
            }
            for(int j = i+1;j< n; j++){
                b.push_back(a[j]);
            }

            ll maxi = LLONG_MIN;
            int m = n-1;

            for(int k = 0;k < m;k+=2){
                if(k+1 < m){
                    maxi = max(maxi,b[k+1]-b[k]);
                }

            }
            mini  = min(maxi, mini);
        

        }
        cout << mini << "\n";
        
        
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