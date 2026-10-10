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
    
    // 1st condition teeno ka maximum point alag alag index par simply take it 
    // 2 activity ka maximum collide
    // ai bi | bi ci | ai ci
    // take  max(c + a + second max of b ,c + b + second maximum of a)
    // if all collide then 
    // 3rd maximum
    // take ai then check for bi and ci they collide then 
    // take bi or ci 
    // take bi 

    // TC : - O(nlogn)
    vector<ll>a(n),b(n),c(n);
    for(int i = 0;i < n; i++){
      cin >> a[i];
    }
    for(int i = 0;i <n ; i++){
      cin >> b[i];
    }
    for(int i = 0;i < n; i++){
      cin >> c[i];
    }

    // sort by value take maximum 
    vector<pair<ll,int>>ap,bp,cp;
    for(int i = 0;i <n ; i++){
      ap.push_back({a[i],i});
    }
    for(int i = 0;i < n; i++){
      bp.push_back({b[i],i});
    }
    for(int i = 0;i < n; i++){
      cp.push_back({c[i],i});
    }
    sort(ap.begin(),ap.end(),greater<pair<ll,int>>());
    sort(bp.begin(),bp.end(),greater<pair<ll,int>>());
    sort(cp.begin(),cp.end(),greater<pair<ll,int>>());
    
    // teeno ke first three maximum chahiye store it 
    // either if the same value then we have the different index
    // I will take consider all possible comibination of these three
    // O(3x3x3)

    ll maxi = LLONG_MIN;
    for(int i = 0;i < 3 ; i++){
      auto& [ af,  as] = ap[i];
      for(int j = 0; j < 3 ; j++){
        auto& [bf, bs ] = bp[j];
        for(int k = 0; k < 3; k++){
          auto& [cf,cs] = cp[k];

          if(as != cs  && cs != bs && bs!= as){
            maxi = max(maxi,af+ bf + cf);
          }

        }
      }

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