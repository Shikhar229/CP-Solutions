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

    //1 2 3 4 5  6 7
    // worst case take 
    // 1 2 and 7
    // we would like to increase 
    // 1 and 2 and decrease the 6
    
    // 1 2 3 4 5 6 7
    // 3 3 3 4 5 5 5
    // any triplet we can take now

    // if smalest and second smallest > largest
    // entire array is valid
    // largest size valid subarray
    // x 
    // n-x ops
    int n ;
    cin >> n;


    vector<int>nums(n);
    for(int i = 0;i < n; i++){
        cin >> nums[i];
    }
    sort(nums.begin(),nums.end());
    int ans  = n;
    for(int i = 0; i+1 < n; i++){
        int val = nums[i] + nums[i+1];
        int j = lower_bound(nums.begin()+i+2, nums.end(),val) - nums.begin();

        int len = j-i;
        ans = min(ans,n-len);

    }
    cout << ans << "\n";

    
    

    


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