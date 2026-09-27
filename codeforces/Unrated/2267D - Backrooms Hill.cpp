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
    vector<int>a(n+1);
    for(int i = 1;i <= n; i++){
        cin >> a[i];
    }
    vector<int>pos(n+1);

    for(int i = 1; i <= n; i++){
        // ith index par jo hai 
        // us number ki pos[a[i]]
        pos[a[i]] = i% 2;
        
    }
    vector<int>ans(n+1);

    int left = 1;
    int right = n;

    bool found = true;

    for(int i = 1; i <= n ;i++){
        if(pos[i] == left % 2){
            left++;
            
        }
        else if(pos[i] == right%2){
            right--;
        }
        else{
            found = false;
            break;
            
        }

        
    
        
    }

    if(!found){
        cout << "NO\n";
    }
    else{
        cout << "YES\n";
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