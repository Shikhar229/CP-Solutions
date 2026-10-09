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
    vector<int>a(n);
    for(int i = 0;i <n ;i++){
        cin>> a[i];
    }
    vector<int>pos(n+1,-1);
    for(int i = 0;i < n; i++){
        pos[a[i]] = i;
    }
    set<int>prev;
    set<int>curr;
    int  count = 0;
    int ans = 0;

    priority_queue<int,vector<int>,greater<int>>min_heap;
    for(int i  = 0;i < n;i++){
        int val = a[i];

        if(curr.find(val) == curr.end()){
            // first time insert int
            curr.insert(val);
            min_heap.push(pos[val]);
            if(prev.find(val) != prev.end()){
                count++;
            }

        }
        int mini = min_heap.top();

        if(count == prev.size() && i < mini){
            ans++;
            prev = curr;
            curr.clear();
            while(!min_heap.empty()){
                min_heap.pop();
            }
            count = 0;
        }
    }
    ans++;
    cout << ans << "\n";
}
int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}
    


    



