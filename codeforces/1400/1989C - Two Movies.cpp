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
    vector<int>a(n),b(n);
    for(int i = 0;i < n; i++){
        cin >> a[i];
    }
    for(int i = 0; i < n; i++){
        cin >> b[i];
    }
    int x = 0;
    int y = 0;

    int pos = 0;
    int neg = 0;

    for(int i = 0;i < n; i++){
        // if(i == n-1){
        //     cout << x <<" " << y << endl;
        // }
        if(a[i] != b[i]){
            if(a[i] > b[i])x+=a[i];
            else y+=b[i];
        }
        else{
            if(a[i] == 1){
                pos++;
            }
            else if(a[i] == -1){
                neg++;
            }
            
        }
    }
    // cout << x << " " << y << endl;
    while(pos != 0){
        if(x >= y){
            y++;
        }
        else{
            x++;
        }
        pos--;
    }
    while(neg != 0){
        if(x >= y){
            x--;

        }
        else{
            y--;
        }
        neg--;
    }
    cout << min(x,y) << endl;

    


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