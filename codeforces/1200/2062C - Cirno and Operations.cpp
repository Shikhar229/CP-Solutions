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
    // reverse the sequence or replace with 
    // a2-a1

    // If I have only positives element then no problem I will return the sum of all the elements
    // only negative elemenets create the issue what will create then 
    // we have to manage those by operation
    
        int n;
        cin >> n;
        vector<ll>a(n);
        ll maxi =0;
        
        for(int i = 0; i< n; i++){
            cin >> a[i];
            maxi += a[i];
            
        }
        if(n == 1){
            cout << maxi << "\n";
            return;
        }
        int m= n;
        vector<ll>temp = a;
        while(m >= 1){
            // int curr = 0;

            vector<ll>b;
            for(int i = 1;i < temp.size(); i++){
                b.push_back(temp[i]-temp[i-1]);
            }
            temp = b;
            ll curr = 0;
            for(int i = 0;i < b.size(); i++){
                curr+= b[i];
            }

            maxi = max({curr,maxi,-curr});
            
            m--;
            
        }
        cout << maxi << "\n";
    
    
    


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