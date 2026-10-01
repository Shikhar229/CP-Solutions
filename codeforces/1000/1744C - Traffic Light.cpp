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
    char c;
    
    cin >> n;
    cin >> c;
    
    string s;
    cin >> s;
    
    s += s;
    if(c == 'g'){
        cout << 0 << "\n";

    }
    else{
        // pehle index jaha non g mila woh store karenge 
        // jab tak g na aa jaye tab tak count karte raho 
        // agar g se pehel current wala mil gaya
        // then kuch mat karo 
        // agar g mil gaya then store it maximum by comparing
        // and first wala reset 
        // fir tab r find karo next char c
        int maxi = 0;
        int cnt = 0;
        int f = -1;
        for(int i = 0;i < s.size(); i++){
            if(s[i] == c){
                if(f == -1){
                    f = i;
                    // store kar liya agar store nahi hai 
                    // to agar store hai to kuch nahi karna

                }
                cnt++;
                
            }
            else if(s[i] == 'g'){
                if(f != -1){
                    int diff = (i-f);
                    maxi = max(maxi,diff);
                    cnt = 0;
                    f = -1;

                }
                
                

            }
            else{
                cnt++;
            }
        }
        cout << maxi <<"\n";
    


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