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
    // they have n item
    // split between them

    // ai cost
    // alice start

    // game ends when nothing left
    // a-b
    // alice wants to maximize score
    // bob minimizes it

    // bob can increase some ai

    // total increase less <= k

    ll n ,k;
    cin >> n >> k;
    vector<ll>a(n);
    for(auto & it: a) cin >> it;

    // if alice wants to maximize the score
    // it will always try to choose bigger ai
    // and bob also try to choose bigger ai
    // he wants to minimize it

    // interesting part is this bob increases some of ai
    // before the game started

    // let's sort the array first
    // because order of array does not
    // let me sort it first

    sort(a.begin(),a.end());
    // minimum score that bob can achieve ?
    // [6,10] ->  
    // bob will do like in his turn the number B
    // which I decreases will be maximum possible

    // turn 0 represent alice turn

    bool turn = 0;

    // bool turn =1 represent bob turns
    ll next = -1;

    ll alice = 0;
    ll bob = 0;


    for(int i = n-1; i >= 0;i--){
        if(turn == 0){
            next = a[i];
            turn = 1;
            alice += a[i];
            
        }
        else{
            // here bob turns
            int x = min(a[i]+k ,next);
            // we got how much we can increase
            int ops = x-a[i];
            a[i] = x;
            k -= ops;
            turn = 0;
            bob += a[i];

        }
        // cout << "iteration: "<< i << endl;
        // cout << alice << " "<< bob << endl;


    }
    cout << alice - bob << "\n";










    


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