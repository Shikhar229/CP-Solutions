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
    // n casinos given numbered from 1 to n 
    // li,ri and reali // li <= reali <= ri
    // play at casino i if
    // current no. of coin x -> li <= x <= ri
    // after playing becomes reali
    // can visit in any order but only once
    int n;//no. of casinos
    cin>> n;
    int k; //initial no. of coins
    cin >> k;
    vector<vector<ll>>a(n,vector<ll>(3));
    for(int i = 0;i <n; i++){
        cin >> a[i][0] >> a[i][1] >> a[i][2];
    }
    sort(a.begin(),a.end());


    // I find a reali which is greater than x and fits in the range li-ri and we have found many possiblity then take the maximum ones
    // let's say I have x coins I will search which casino's have reali > x 
    
    // find those one's who have x < reali and fits in that range(x >= li) take the greatest in which it fits take those and remove x > li

    // I sort with the basis of li 
    int idx = 0;
    ll x = k;

    priority_queue<pair<ll,ll>>pq;
    while(true){

        while(idx < n  && x >= a[idx][0]){

            pq.push({a[idx][2],a[idx][1]});
            idx++;

        }

        while(!pq.empty() && pq.top().second < x){
            pq.pop();
        }

        if(pq.empty() || pq.top().first <= x){
            break;
            
        }
        x = pq.top().first;
        pq.pop();


    }
    cout << x << "\n";
        


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