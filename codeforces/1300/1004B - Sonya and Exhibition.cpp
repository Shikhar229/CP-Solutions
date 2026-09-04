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
    int n,m;
    cin >> n >> m;
    vector<pair<int,int>>vec;
    while(m--){
        int x,y;
        cin >> x >> y;
        vec.push_back({x,y});
    }
    string s = "";
    int time = n/2;
    int remain = n%2;
    for(int i= 1;i <= time; i++){
        string temp = "01";
        s += temp;
    }
    if(remain == 1){
        s += "0";
    }
    
    // int sum = 0;
    // for(int i = 0;i < vec.size();i++){
    //     int left = vec[i].first-1;
    //     int right = vec[i].second-1;

    //     int count0 = 0;

    //     for(int i = left ; i<= right; i++){
    //         if(s[i] == '0')count0++;

    //     }
    //     int count1 = (right-left+1)- count0;
    //     cout << count0 * count1 << endl;
    //     sum += count0*count1;
    // }
    cout << s << endl;
    // cout << sum << endl;
    


}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // int t;
    // cin >> t;
    // while (t--) {
    //     solve();
    // }

    solve();

    return 0;
}