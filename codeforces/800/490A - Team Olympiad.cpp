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
    vector<int>a(n);
    for(int i = 0;i< n ;i++){
        cin >> a[i];
    }

    int t1 = count(a.begin(),a.begin()+n,1);
    int t2 = count(a.begin(),a.begin()+n,2);
    int t3 = count(a.begin(),a.begin()+n,3);

    int x = min({t1,t2,t3});

    cout << min({t1,t2,t3})<<  endl;
    vector<pair<int,int>>one;
    vector<pair<int,int>>two;
    vector<pair<int,int>>three;
    for(int i = 0;i < n; i++){
        int v = a[i];
        if(v == 1){
            if(one.size() < x){
                one.push_back({v,i});

            }

        }
        else if(v == 2){
            if(two.size() < x){
                two.push_back({v,i});
            }

        }
        else{
            if(three.size() < x){
                three.push_back({v,i});
            }

        }
    }

    for(int i = 0;i < x; i++){
        cout << one[i].second +1<< " " << two[i].second+1 << " " << three[i].second +1<< endl;
    }
    cout << endl;



    
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