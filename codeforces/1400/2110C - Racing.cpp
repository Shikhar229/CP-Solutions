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
    vector<int>d(n);
    for(int i = 0;i < n; i++){
        cin >> d[i];
    }

    
    vector<int>l(n),r(n);
    for(int i = 0;i< n; i++){
        cin >> l[i] >> r[i];
    }

    // jab bhi isme ye karna hai ki
    // har ek di ke correspondin height nikalni hai 
    // aur dekhna hai jo restriction usi ke andar ya barabar aa sakti height ya nahi 
    // agar aa sakti hai to wo d[i] ke values nikalenge
    // agar nahi aa sakti hai to -1 print kar denge
    // we do by backtracking 

    // here height[i] = d0 + d1 + d2 +.......+ di
    // so agar kisi ki variable cosider kare 
    // when d[i] -> -1 then we have a range 
    // we have to choose these variable like that it satisfies this condition
    // we will track minimum possible height before entering that level skipping -1's 
    // if say  minimum height means left bound is so small then we take some already having -1's in last vector to set to 1

    // if say minimum height is greater than rightbound then we have to decrease it then we do it by taking some last -1's to 0
    // so that it would decrease the maximum



    int left = 0;
    vector<int>last;
    for(int i = 0;i < n; i++){
        if(d[i] != -1){
            left += d[i];
        }
        else{
            last.push_back(i);
        }
        while(left < l[i]){
            if(last.empty()){
                cout << -1 << "\n";
                return;
            }
            d[last.back()] = 1;
            left++;
            last.pop_back();
        }
        while(left + last.size() > r[i]){
            if(last.empty()){
                cout << -1 << "\n";
                return;
            }
            d[last.back()] = 0;
            
            last.pop_back();
            
        }

    
    }
    for(int i = 0;i < n; i++){
        if(d[i] == -1) cout <<0 << " ";
        else cout << d[i] << " ";
    }
    cout << "\n";
    
    


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