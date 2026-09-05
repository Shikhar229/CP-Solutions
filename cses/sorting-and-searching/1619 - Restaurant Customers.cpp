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
    vector<pair<int,int>>vec;

    for(int i = 0;i < n; i++){
        int a,b;
        cin >> a >> b;
        vec.push_back({a,+1});
        vec.push_back({b,-1});
        
    }
    sort(vec.begin(),vec.end());

    vector<int>prefix(vec.size());
    prefix[0] = vec[0].second;
    int maxi = 0;
    int curr = 0;
    for(int i = 0;i < vec.size();i++){
        curr += vec[i].second;
        maxi = max(maxi,curr);
    }
    cout << maxi << endl;


}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}