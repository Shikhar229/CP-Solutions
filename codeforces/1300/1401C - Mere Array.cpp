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

    vector<ll>a(n);
    for(int i = 0; i < n ; i++){
        cin >> a[i];
    }
 
    ll mini = *min_element(a.begin(),a.end());

    vector<int>div;

    for(int i = 0;i < n; i++){
        if(a[i]% mini == 0){
            div.push_back(a[i]);

        }

    }
    int j = 0;

    sort(div.begin(),div.end());
    for(int i = 0;i < n; i++){
        if(a[i]% mini != 0){
            continue;

        }
        else{
            a[i] = div[j];
            j++;
        }
    }

    // for(int i = 0;i < n; i++){
    //     cout << a[i] << " ";
        
    // }
    bool found = false;
    for(int i = 1; i < n ;i++){
        if( a[i] < a[i-1] ){
            found = true;
            break;
        }
    }
    if(found)cout << "NO\n";
    else cout << "YES\n";

    




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