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
    string t,s;
    cin >> t >> s;

    int i = 0;
    int j = 0;
    while(i < t.size() && j < s.size()){
        if(t[i] == s[j]){
            i++;
            j++;
        }
        else if(t[i] == '?'){
            t[i] = s[j];
            i++;
            j++;
        }
        else if(t[i]  != s[j]){
            i++;
            
        }
    }
    

    if(j >= s.size()){
        cout << "YES\n";
        
        while(i < t.size()){
            if(t[i] == '?'){
                t[i] = 'a';
            }
            i++;
        }
        cout << t << "\n";
    }
    else if(i >= t.size()){
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

    // solve();

    return 0;
}