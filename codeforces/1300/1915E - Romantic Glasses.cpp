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
    vector<ll>a(n+1);
    for(int i = 1;i <= n; i++){
        cin >> a[i];
    }

    // we want a subarray jisme
    // total amount of juice by luice and his partner
    // equal 

    // luice drinks odd numbered index
    // and partner even numbered index
    
    // drink count luica + and partner - if any index 
    // count == 0 yes print karenge otherwise no
    set<ll>st;
    st.insert(0);
    ll sum = 0;

    bool found = false;
    for(int i = 1;i <= n; i++){
        if(i%2 == 1){
            sum += a[i];
        }
        else{
            sum -= a[i];
        }

        if(st.count(sum)){
            found =true;
            
            break;

        }
        st.insert(sum);


    }

    if(found){
        cout << "YES\n";
    }
    else{
        cout << "NO\n";
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