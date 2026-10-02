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
    // a(i) = a(i+2) - a(i+1)
    vector<int>a(5,0);
    for(int i = 0;i < 5; i++){
        if(i == 2){
            continue;
        }
        else{
            int x;
            cin >> x;
            a[i] = x;

        }
    }
    
    // positive set kar liya ab 
    // koi bhi positive number set karna hai 
    // dekhna taaki us positive numbers ke mukable 
    // baaki positive numberse rakhu to hamesa kam hi aaye
    // to aisa rakh dunga ki 
    // 0 1 2 3 4
    // 0 to 2 tak hi check ho raha hai
    // to maximum fibonaaci to ham sabse bestcase me 
    // 3 hi bana sakte hai 
    // a[0] = a[2]-a[1];
    // a[1] = a[3]-a[2];
    // a[2] = a[4]-a[3];
    // a[2] ki wajah se dikkat aa rahi
    int d = a[0] + a[1];
    int b = a[3]-a[1];
    int c = a[4]-a[3];
    // cout << d << " "<< b << "  " << c << "\n";

    if(d == b && b == c)cout << 3 << "\n";
    else if(d==b || b == c || c == d)cout << 2 <<"\n";
    else cout << 1 << "\n"; 
    
    


    


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