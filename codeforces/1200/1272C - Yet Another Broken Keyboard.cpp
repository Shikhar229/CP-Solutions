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

    string s;
    cin >> s;
    s +=  "A";
    

    unordered_set<char>st;
    for(int i = 0;i < k ;i++){
        char x;
        cin >> x;
        
        st.insert(x);
    
    }
    
    

    // all the substring of s -> 

    ll sum = 0;
    int i = -1;
    for(int r = 0; r < n+1; r++){
        if(i == -1){
            if(st.count(s[r])){
                i = r;
            }
        }
        if(!st.count(s[r]) && i != -1){
            int len = r-i;

            ll curr = 1LL * (len)*(len+1)/2;
            i = -1;
            sum += curr;


            
        }

    }
    cout << sum << endl;





}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    

    while (t--) {
        solve();
    }

    return 0;
}