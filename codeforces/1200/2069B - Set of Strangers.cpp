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
    cin >> n >>m;
    vector<vector<int>>a(n,vector<int>(m));

    for(int i = 0;i < n; i++){
        for(int j = 0; j < m ;j++){
            cin >> a[i][j];
        }
    }

    unordered_map<int,int>mp;


    for(int i = 0;i < n; i++){
        for(int j = 0; j < m ;j++){

            int curr = a[i][j];
            // check any neighbour is exactly same if same
            // then  mp[a[i][j]] = 2 if not found
            // then insert mp[a[i][j]] = 1
            
            
            
            
            bool f = false;

            if(i-1 >= 0){
                int top = a[i-1][j];
                
                if(curr == top){
                    mp[curr] = 2;
                    f = true;
                }

            }
            if(i+1 <= n-1){
                int bottom = a[i+1][j];
                if(curr == bottom){
                    mp[curr] = 2;
                    f = true;
                }

            }
            if(j-1 >= 0){
                int left = a[i][j-1];
                if(curr == left){
                    mp[curr] = 2;
                    f = true;
                }

            }
            if(j+1 <= m-1){
                int right = a[i][j+1];
                if(curr == right){
                    mp[curr] = 2;
                    f = true;
                }

            }
            

            if(f == false){
                if(mp.find(curr) == mp.end()){
                    mp[curr] = 1;
                }
            }
        

        }
    }
    int sum = 0;
    int maxi = -1;

    for(auto it : mp){
        int val = it.second;
        maxi = max(maxi,val);
        sum += val;


    }
    cout << sum-maxi << "\n";

    


}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    

    return 0;
}