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
    int n,k;
    cin >> n >> k;
    vector<ll>a(n);
    
    for(int i  = 0;i < n ; i++){
        cin >> a[i];
    }
    
    
    // for(int i  = 0;i < n ; i++){
    //     cout << a[i] << " ";
    // }
    
    

    if(k == 1){
        ll maxi = a[0] + a[n-1];
    
        
        if(n >= 3){
            ll m = 0;
            for(int i = 1 ; i< n-1; i++){
                m = max(m,a[i]);



            }
            cout << max({m+a[0], m + a[n-1],maxi})<<"\n";


        }
        else{
            cout <<maxi << "\n";
        }


       

    }
    else{
        sort(a.begin(),a.end());
        ll sum = 0;
        for(int i = n-1; i >= ((n-1)-k); i--){
            sum += a[i];

        }
        

        cout << sum << "\n";
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